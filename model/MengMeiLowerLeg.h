#ifndef MENGMEI_LOWERLEG_H
#define MENGMEI_LOWERLEG_H

#include "model.h"
#include "MengMeiFoot.h"

class MengMeiLowerLeg : public Model
{
public:
	MengMeiLowerLeg(ModelNames name);
	void onDraw();

private:
	Model* m_foot;

};

#endif