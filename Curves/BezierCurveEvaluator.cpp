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

#include "BezierCurveEvaluator.h"
#include "../vec.h"
#include "../mat.h"

#define SEGMENT 30

void BezierCurveEvaluator::evaluateCurve(
	const std::vector<Point>& controlPoints,
	std::vector<Point>& evaluatedPoints,
	const float& animationLength,
	const bool& beWrap) const
{
	evaluatedPoints.clear();

	float x_start = 0.0;
	float y_start = controlPoints[0].y;

	size_t cnt;
	const Mat4d basis(
		-1, 3, -3, 1,
		3, -6, 3, 0,
		-3, 3, 0, 0,
		1, 0, 0, 0);

	for (cnt = 0; cnt + 3 < controlPoints.size(); cnt += 3)
	{
		// push starting and ending points first
		evaluatedPoints.push_back(controlPoints[cnt]);
		evaluatedPoints.push_back(controlPoints[cnt + 3]);
		const Vec4d px(controlPoints[cnt].x, controlPoints[cnt + 1].x,
			controlPoints[cnt + 2].x, controlPoints[cnt + 3].x);
		const Vec4d py(controlPoints[cnt].y, controlPoints[cnt + 1].y,
			controlPoints[cnt + 2].y, controlPoints[cnt + 3].y);

		for (int i = 0; i < SEGMENT; ++i)
		{
			const double t = i / (double)SEGMENT;
			const Vec4d param_time(t*t*t, t*t, t, 1);
			evaluatedPoints.push_back(Point(param_time * basis * px, param_time * basis * py));
		}
	
	}

	// the starting point should not be used to generate Bezier Curve
	evaluatedPoints.push_back(Point(x_start, y_start));

	float x_end = animationLength;
	for (; cnt < controlPoints.size(); cnt++)
	{
		evaluatedPoints.push_back(controlPoints[cnt]);
	}

	// insert end point at last
	evaluatedPoints.push_back(Point(x_end, controlPoints[cnt-1].y));
}