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

#define SEGMENT 30

#include "CatmullRomCurveEvaluator.h"

void CatmullRomCurveEvaluator::evaluateCurve(const std::vector<Point>& controlPoints,
	std::vector<Point>& evaluatedPoints,
	const float& animationLength,
	const bool& beWrap) const
{
	evaluatedPoints.clear();
	evaluatedPoints.push_back(Point(0, controlPoints.front().y));

	vector<Point> controlPointsCopy(controlPoints);
	controlPointsCopy.push_back(Point(0, controlPoints.front().y));
	controlPointsCopy.insert(controlPointsCopy.end(), controlPoints.begin(), controlPoints.end());
	controlPointsCopy.push_back(Point(animationLength, controlPoints.back().y));

	const Mat4d basis = Mat4d(
		-1, 3, -3, 1,
		2, -5, 4, -1,
		-1, 0, 1, 0,
		0, 2, 0, 0) / 2.0;

	for (size_t cnt = 0; cnt + 3 < controlPointsCopy.size(); ++cnt)
	{
		const Vec4d param_x(controlPointsCopy[cnt].x, controlPointsCopy[cnt + 1].x,
			controlPointsCopy[cnt + 2].x, controlPointsCopy[cnt + 3].x);
		const Vec4d param_y(controlPointsCopy[cnt].y, controlPointsCopy[cnt + 1].y,
			controlPointsCopy[cnt + 2].y, controlPointsCopy[cnt + 3].y);
		
		for (int i = 0; i < SEGMENT; ++i)
		{
			const double t = i / (double) SEGMENT;
			const Vec4d param_time(t*t*t, t*t, t, 1); 
			Point eval_point(param_time * basis * param_x, param_time*basis*param_y);
			// avoid wave curve occurs
			if (evaluatedPoints.empty() || eval_point.x > evaluatedPoints.back().x)
			{
				evaluatedPoints.push_back(eval_point);
			}
		}
	}

	// avoid slope interpolate at the end
	if (controlPoints.back().x > evaluatedPoints.back().x)
	{
		evaluatedPoints.push_back(controlPoints.back());
	}

	evaluatedPoints.push_back(Point(animationLength, controlPoints.back().y));
}	