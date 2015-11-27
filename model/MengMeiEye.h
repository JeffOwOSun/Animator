
#ifndef MENGMEI_EYE_H
#define MENGMEI_EYE_H

#include "model.h"
class MengMeiEye : public Model
{
public:
	MengMeiEye(ModelNames name);
	void onDraw();

private:
	GLuint m_texture;
};


#endif
