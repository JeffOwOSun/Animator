
#ifndef MENGMEI_HAND_H
#define MENGMEI_HAND_H

#include "model.h"

class MengMeiHand : public Model
{
public:
	void onDraw();
	MengMeiHand();
private:
	GLuint m_texture;
};

#endif