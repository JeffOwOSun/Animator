
#include "MengMeiEye.h"

void MengMeiEye::onDraw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_texture);
		drawTexture(std::string("./res/MengMeiEye.jpg"), m_texture);
		drawSphere(0.15f);
	glDisable(GL_TEXTURE_2D);
}

MengMeiEye::MengMeiEye(ModelNames name) : Model(name) {}