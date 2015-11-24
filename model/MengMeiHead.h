
#ifndef MENGMEI_HEAD_H
#define MENGMEI_HEAD_H

#include "model.h"
#include "MengMeiEye.h"

class MengMeiHead : public Model
{
public:
	MengMeiHead();
	void onDraw();
private:
	Model* m_leftEye;
	Model* m_rightEye;
};

#endif