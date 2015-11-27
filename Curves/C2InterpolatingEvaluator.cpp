/*
* C2InterpolatingEvaluator.cpp
*
* Author: Qi Haozhi, Sun Yushi
* Copyright (c) 2015 Qi Haozhi, Sun Yushi
*
* You can star the project via:
* https://github.com/Oh233/Animator OR
* https://github.com/JeffOwOSun/Animator
*/

#define SEGMENT 30

#include "C2InterpolatingEvaluator.h"

void C2InterpolatingEvaluator::evaluateCurve(const std::vector<Point>& controlPoints,
	std::vector<Point>& evaluatedPoints,
	const float& animationLength,
	const bool& beWrap) const
{
	evaluatedPoints.clear();

	vector<Point> controlPointsCopy;
	evaluatedPoints.push_back(Point(0, controlPoints.front().y));
	controlPointsCopy.insert(controlPointsCopy.end(), controlPoints.begin(), controlPoints.end());
	controlPointsCopy.push_back(Point(controlPointsCopy.front().x + animationLength,
		controlPointsCopy.front().y));


	vector<float> derivativePoints(controlPointsCopy.size(), 0.0);
	int controlN = controlPoints.size() - 1;
	
	this->_evaluateDerivative(derivativePoints, controlPointsCopy, controlN);

	for (int i = 0; i < controlN; i++) 
	{
		this->_evaluate(i, i + 1, animationLength, 
			controlPointsCopy, evaluatedPoints, derivativePoints);
	}

	evaluatedPoints.push_back(Point(animationLength, evaluatedPoints.back().y));
}

void C2InterpolatingEvaluator::_evaluate(const int p1, const int p2, const float& animationLength,
	const std::vector<Point>& controlPointsCopy, std::vector<Point>& evaluatedPoints,
	const std::vector<float>& derivativePoints) const
{
	Mat4d basis = Mat4d(
		2.0, -2.0, 1.0, 1.0,
		-3.0, 3.0, -2.0, -1.0,
		0.0, 0.0, 1.0, 0.0,
		1.0, 0.0, 0.0, 0.0
		);

	Vec4d vec = basis * Vec4d(
		controlPointsCopy[p1].y,
		controlPointsCopy[p2].y,
		derivativePoints[p1],
		derivativePoints[p2]
		);

	for (int i = 0; i < SEGMENT; ++i)
	{
		double t = i / (double)SEGMENT;
		float eval_y = Vec4d(t*t*t, t*t, t, 1) * vec;

		float len = controlPointsCopy[p2].x - controlPointsCopy[p1].x;
		// still quick fix ?
		if (len < 0) len += animationLength;
		float eval_x = controlPointsCopy[p1].x + t * len;
		eval_x = fmod(eval_x, animationLength);
		evaluatedPoints.push_back(Point(eval_x, eval_y));
	}
}

void C2InterpolatingEvaluator::_evaluateDerivative(vector<float>& derivative, 
	vector<Point> controlPointsCopy, int controlN) const
{
	vector<float> gamma(controlPointsCopy.size(), 0.0);
	vector<float> delta(controlPointsCopy.size(), 0.0);

	gamma[0] = 0.5f;
	for (int i = 1; i < controlN; ++i)
	{
		gamma[i] = 1.0f / (4.0f - gamma[i - 1]);
	}
	gamma[controlN] = 1.0 / (2.0f - gamma[controlN - 1 - 1]);

	delta[0] = 1.5 * (controlPointsCopy[1].y - controlPointsCopy[0].y);
	for (int i = 1; i < controlN; i++) 
	{
		delta[i] = gamma[i] * (3 * (controlPointsCopy[i + 1].y - controlPointsCopy[i - 1].y) - delta[i - 1]);
	}
	delta[controlN] = gamma[controlN] *
		(3 * (controlPointsCopy[controlN].y - controlPointsCopy[controlN - 1].y) - delta[controlN]);

	derivative[controlN] = delta[controlN];
	for (int i = controlN - 1; i >= 0; i--) 
	{
		derivative[i] = delta[i] - gamma[i] * derivative[i + 1];
	}
}
