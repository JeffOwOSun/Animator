#include "indicatorModel.h"

IndicatorModel::IndicatorModel() : Model() {}

void IndicatorModel::onDraw() {
	setDiffuseColor(COLOR_RED);
	drawSphere(0.5f);
	setDiffuseColor(1.0f, 1.0f, 1.0f);
}