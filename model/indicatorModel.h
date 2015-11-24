#ifndef INDICATOR_MODEL_H
#define INDICATOR_MODEL_H

#include "model.h"

class IndicatorModel: public Model{
public:
	IndicatorModel(ModelNames name);
	void onDraw();
};

#endif //INDICATOR_MODEL_H