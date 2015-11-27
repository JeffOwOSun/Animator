/*
* C2InterpolatingEvaluator.h
*
* Author: Qi Haozhi, Sun Yushi
* Copyright (c) 2015 Qi Haozhi, Sun Yushi
*
* You can star the project via:
* https://github.com/Oh233/Animator OR
* https://github.com/JeffOwOSun/Animator
*/

#ifndef C2INTERPOLATING_CURVE_EVALUATOR_H
#define C2INTERPOLATING_CURVE_EVALUATOR_H

#include "../curveevaluator.h"

class C2InterpolatingEvaluator : public CurveEvaluator
{
public:
	/*
	* Override to get a bezier curve according to control Points
	*/
	void evaluateCurve(const std::vector<Point>& controlPoints,
		std::vector<Point>& evaluatedPoints,
		const float& animationLength,
		const bool& beWrap) const override;
private:
	/*
	 * Helper function, otherwise to long to write together
	 */
	void _evaluate(const int p1, const int p2, const float& animationLength,
		const std::vector<Point>& controlPointsCopy, std::vector<Point>& evaluatedPoints,
		const std::vector<float>& derivativePoints) const;
	void _evaluateDerivative(vector<float>& derivative,
		vector<Point> controlPointsCopy, int controlN) const;
};

#endif