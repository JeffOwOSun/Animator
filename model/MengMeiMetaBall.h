
#ifndef MENGMEI_METABALL_H
#define MENGMEI_METABALL_H

#include "model.h"
#include "../MetaBall.h"
class MengMeiMetaBall : public Model
{
public:
	MengMeiMetaBall();
	void onDraw();
private:
	GLuint m_texture;
};

#endif