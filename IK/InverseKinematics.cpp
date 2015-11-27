/**
 * InverseKinematics.cpp
 * Contains the implementation of inverse kinematics calculation
 * and an sample metric function that operates upon the sample model
 */

#include<exception>
#include"InverseKinematics.h"
#include<cstdlib>
#include<ctime>
#include<random>
#include<cassert>

using namespace std;

std::vector<double> IK::momentum = std::vector<double>(vectorLength, 0.0);
std::vector<double> IK::statusQuo = std::vector<double>(vectorLength, 0.0);
std::vector<double> IK::currState = std::vector<double>(vectorLength, 0.0);

const double IK::epselon = 0.00001;
const double IK::targetCostCoeff = 8;
const double IK::statusQuoCoeff = 3;

const double IK::delta = 0.1;
const double IK::learningRate = 0.1;
const double IK::inertia = 1 - learningRate;
const double IK::magnifying = 1.2;

const double IK::temperatureMax = 1.0;
const double IK::temperatureStep = 0.003;

void IK::optimize() {
	srand(time(NULL));
	//store statusQuo
	saveStatusQuo();
	optimizeAnneal();
	optimizeGradientDesc();
}

void IK::optimizeAnneal() {
	//random generator and uniform distribution
	std::default_random_engine gen;
	std::uniform_real_distribution<double> rand(0.0, 1.0);

	//cost of current state
	double lastCost = costFunction(), cost;
	saveCurrState();

	for (double temp = temperatureMax; temp > 0; temp -= temperatureStep) {
		//get a neighborhood state
		for (int i = startPos; i < endPos; ++i) {
			RANDOMIZE(i, 0.03, 0.0);
		}
		cost = costFunction();
#ifdef _DEBUG
		printf("temp: %.2f cost: %f lastCost: %f\n", temp, cost, lastCost);
#endif
		if (cost < lastCost) {
			//remember this state
			saveCurrState();
			lastCost = cost;
		}
		else {
			if (rand(gen) < exp(-(cost - lastCost) / temp)) {
				//accept the worse solution
				saveCurrState();
				lastCost = cost;
			}
			else {
				//reject the worse solution by loading previous statusQuo
				loadCurrState();
			}
		}
	}
}

void IK::optimizeGradientDesc() {
	//reset the momentum vector
	std::fill(momentum.begin(), momentum.end(), 0.0);

	//remember the last Cost function so that one can break off whenever it stables
	double lastCost = costFunction(), thisCost = 0;

	/*
	//randomize the initial value of controls
	for (int i = startPos; i < endPos; ++i) {
		RANDOMIZE(i, 0.3, 0.1);
	}*/
	
	//optimize
	for (int i = 0; i < maxNumIteration; ++i) {
		oneStepGradeintDesc();
		thisCost = costFunction();
		//for debug use
#ifdef _DEBUG
		printf("cost%d: %f\n", i, thisCost);
#endif
		//break if the change is small enough
		if (abs(lastCost - thisCost) < epselon) break;
		lastCost = thisCost;
	}
}

void IK::oneStepGradeintDesc() {
	//Calculate the derivative using numerical method
	/**
	* The delta value signifying an increment.
	*/
	
	//the gradient vector
	vector<double> gradient;
	//calculate gradient
	for (int i = startPos; i < endPos; ++i) {
		//backup parameter i
		double x = VAL(i);
		STEPUP(i);
		double plusCost = costFunction();
		SET(i, x);
		STEPDOWN(i);
		double minusCost = costFunction();
		SET(i, x); //restore parameter
		//calculate
		double deltaY = plusCost - minusCost;
		double derivative = deltaY / (2 * delta);
		gradient.push_back(magnifying * derivative);
	}
	for (int i = 0; i < momentum.size(); ++i) {
		momentum[i] = inertia * momentum[i] + learningRate * gradient[i];
	}
	//subtract the gradient from parameters
	for (int i = startPos; i < endPos; ++i) {
		SET(i, VAL(i) - /*learningRate * */momentum[i - startPos]);
	}
}

double IK::targetCost() {
	//Calculate the cost. Call refreshParameters() to make sure internal control parameters are 
	//up to date with sliders
	//head cost
	Model::m_modelList[HEAD]->refreshParameters();
	Vec3f headPos = Model::m_modelList[HEAD]->getOrigin();
	Vec3f headConstraint(VAL(HEAD_CSTRN_X), VAL(HEAD_CSTRN_Y), VAL(HEAD_CSTRN_Z));
	double headCost = (headPos - headConstraint).length2();

	//left hand cost
	Model::m_modelList[LEFTHAND]->refreshParameters();
	Vec3f leftHandPos = Model::m_modelList[LEFTHAND]->getOrigin();
	Vec3f leftHandConstraint(VAL(LHAND_CSTRN_X), VAL(LHAND_CSTRN_Y), VAL(LHAND_CSTRN_Z));
	double leftHandCost = (leftHandPos - leftHandConstraint).length2();

	//right hand cost
	Model::m_modelList[RIGHTHAND]->refreshParameters();
	Vec3f rightHandPos = Model::m_modelList[RIGHTHAND]->getOrigin();
	Vec3f rightHandConstraint(VAL(RHAND_CSTRN_X), VAL(RHAND_CSTRN_Y), VAL(RHAND_CSTRN_Z));
	double rightHandCost = (rightHandPos - rightHandConstraint).length2();

	//left foot cost
	Model::m_modelList[LEFTFOOT]->refreshParameters();
	Vec3f leftFootPos = Model::m_modelList[LEFTFOOT]->getOrigin();
	Vec3f leftFootConstraint(VAL(LFOOT_CSTRN_X), VAL(LFOOT_CSTRN_Y), VAL(LFOOT_CSTRN_Z));
	double leftFootCost = (leftFootPos - leftFootConstraint).length2();

	//right foot cost
	Model::m_modelList[RIGHTFOOT]->refreshParameters();
	Vec3f rightFootPos = Model::m_modelList[RIGHTFOOT]->getOrigin();
	Vec3f rightFootConstraint(VAL(RFOOT_CSTRN_X), VAL(RFOOT_CSTRN_Y), VAL(RFOOT_CSTRN_Z));
	double rightFootCost = (rightFootPos - rightFootConstraint).length2();
#ifdef _DEBUG
	//printf("head %f lHand %f rhand %f lfoot %f rfoot %f\n", headCost, leftHandCost, rightHandCost, leftFootCost, rightFootCost);
#endif
	return headCost + leftHandCost + rightHandCost + leftFootCost + rightFootCost;
}

double IK::statusQuoCost() {
	const int numParam = vectorLength;
	double cost = 0;
	for (int i = 0; i < numParam; ++i) {
		//get the range of the control
		double range = RANGE(startPos + i);
		//normalize the difference
		double difference = abs(VAL(i + startPos) - statusQuo[i]) / range;
		cost += difference;
	}
	//take an average
	//cost /= numParam;
	
	//the final cost will be a number smaller than 1
	return cost;
}

double IK::costFunction() {
	double target = targetCostCoeff > 0 ? targetCost() : 0.0;
	double statusQuo = statusQuoCoeff > 0 ? statusQuoCost() : 0.0;
#ifdef _DEBUG
	//printf("targetCost %f, statusQuoCost %f ", target, statusQuo);
#endif
	return targetCostCoeff * target + statusQuoCoeff * statusQuo;
}

void IK::saveStatusQuo() {
	for (int i = 0; i < vectorLength; ++i) {
		statusQuo[i] = (VAL(startPos + i));
	}
}

void IK::saveCurrState() {
	for (int i = 0; i < vectorLength; ++i) {
		currState[i] = (VAL(startPos + i));
	}
}

void IK::loadCurrState() {
	for (int i = 0; i < vectorLength; ++i) {
		SET(startPos + i, currState[i]);
	}
}