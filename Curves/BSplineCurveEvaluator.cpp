/*
* BezierCurveEvaluator.cpp
*
* Author: Qi Haozhi, Sun Yushi
* Copyright (c) 2015 Qi Haozhi, Sun Yushi
*
* You can star the project via:
* https://github.com/Oh233/Animator OR
* https://github.com/JeffOwOSun/Animator
*/

#include "BSplineCurveEvaluator.h"
#include "BezierCurveEvaluator.h"

void BSplineCurveEvaluator::evaluateCurve(
	const std::vector<Point>& controlPoints,
	std::vector<Point>& evaluatedPoints,
	const float& animationLength,
	const bool& beWrap) const
{
	evaluatedPoints.clear();
	evaluatedPoints.push_back(Point(0, controlPoints.front().y));
	evaluatedPoints.push_back(Point(animationLength, controlPoints.back().y));

	// a hack to make the endpoints controllable
	vector<Point> controlPointsCopy;
	controlPointsCopy.push_back(controlPoints.front());
	controlPointsCopy.push_back(controlPoints.front());
	controlPointsCopy.insert(controlPointsCopy.end(), controlPoints.begin(), controlPoints.end());
	controlPointsCopy.push_back(controlPoints.back());
	controlPointsCopy.push_back(controlPoints.back());

	const Mat4d basis = Mat4d(
		1, 4, 1, 0,
		0, 4, 2, 0,
		0, 2, 4, 0,
		0, 1, 4, 1) / 6.0;

	BezierCurveEvaluator bezierCurveEvaluator;
	for (size_t cnt = 0; cnt + 3 < controlPointsCopy.size(); ++cnt)
	{
		Vec4d param_x(controlPointsCopy[cnt].x, controlPointsCopy[cnt + 1].x,
			controlPointsCopy[cnt + 2].x, controlPointsCopy[cnt + 3].x);
		Vec4d param_y(controlPointsCopy[cnt].y, controlPointsCopy[cnt + 1].y,
			controlPointsCopy[cnt + 2].y, controlPointsCopy[cnt + 3].y);
		param_x = basis * param_x;
		param_y = basis * param_y;
		vector<Point> param_control;
		for (int i = 0; i < 4; ++i)
		{
			param_control.push_back(Point(param_x[i], param_y[i]));
		}
		vector<Point> param_evaluated;
		bezierCurveEvaluator.evaluateCurve(param_control, param_evaluated, animationLength, false);
		evaluatedPoints.insert(evaluatedPoints.end(), param_evaluated.begin(), param_evaluated.end());
	}

}