/*
 * BezierCurveEvaluator.h
 *
 * Author: Qi Haozhi, Sun Yushi
 * Copyright (c) 2015 Qi Haozhi, Sun Yushi
 *
 * You can star the project via:
 * https://github.com/Oh233/Animator OR
 * https://github.com/JeffOwOSun/Animator
 */

#ifndef BEZIER_CURVE_EVALUATOR_H
#define BEZIER_CURVE_EVALUATOR_H

#include "../curveevaluator.h"

class BezierCurveEvaluator : public CurveEvaluator 
{
public:
	/*
	 * Override to get a bezier curve according to control Points
	 */
	void evaluateCurve(const std::vector<Point>& controlPoints,
						std::vector<Point>& evaluatedPoints,
						const float& animationLength,
						const bool& beWrap) const override;
};


#endif