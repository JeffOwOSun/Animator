#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

#include<vector>
#include"modelerglobals.h"
#include"modelerapp.h"
#include"model\model.h"

class IK
{
public:
	static void optimize();
private:
	//Make it impossible to instantiate
	IK() {};
	/**
	* Apply IKOptimize using gradient descent with momentum
	* by minimizing the cost. Output is modified directly to the slider values
	*/
	static void optimizeGradientDesc();
	/**
	* optimize using simulated annealing
	*/
	static void optimizeAnneal();
	/**
	* This function only calculates one step of the IKOptimize iterations.
	*/
	static void oneStepGradeintDesc();

	//The Overall Cost Function
	static double costFunction();
	//The statusQuo
	static double targetCost();
	//The statusQuoCost function
	static double statusQuoCost();
	//stores and save the statusQuo for statusQuoCost calculation
	static void saveStatusQuo();
	static std::vector<double> statusQuo;

	//parameters for the learning
	static const int maxNumIteration = 1000;
	static const double epselon;
	static const double targetCostCoeff;
	static const double statusQuoCoeff;
	
	//parameters for gradientDescent
	static const double delta;
	static const double learningRate;
	static const double inertia;
	static const double magnifying;
	static std::vector<double> momentum;

	//parameters for simulated annealing
	static const double temperatureMax;
	static const double temperatureStep;
	static std::vector<double> currState;
	static void saveCurrState();
	static void loadCurrState();

	static const int vectorLength = NUMCONTROLS - LEVEL_OF_DETAIL - 1;
	static const int startPos = LEVEL_OF_DETAIL + 1;
	static const int endPos = NUMCONTROLS;
};
#endif //INVERSE_KINEMATICS_H