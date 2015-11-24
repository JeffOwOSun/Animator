#include "generalModel.h"
#include <cassert>

GeneralModel::GeneralModel(ModelNames name, ShapeType type) :Model(name), m_shape_type(type), m_texturePath("") {}

//the onDraw function of the general model
void GeneralModel::onDraw() {
	//apply texture first
	if (m_texturePath != "") {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, m_texture);
		drawTexture(std::string("./res/MengMeiBody.jpg"), m_texture);
	}

	//draw the simple object
	switch (m_shape_type) {
	case SPHERE_SHAPE:
		assert(m_params.size() == 1);
		drawSphere(m_params[0]);
		break;
	case BOX_SHAPE:
		assert(m_params.size() == 3);
		drawBox(m_params[0], m_params[1], m_params[2]);
		break;
	case TEXTURE_BOX_SHAPE:
		assert(m_params.size() == 3);
		drawTextureBox(m_params[0], m_params[1], m_params[2]);
		break;
	case CYLINDER_SHAPE:
		assert(m_params.size() == 3);
		drawCylinder(m_params[0], m_params[1], m_params[2]);
		break;
	case TRIANGLE_SHAPE:
		assert(m_params.size() == 9);
		drawTriangle(
			m_params[0], m_params[1], m_params[2],
			m_params[3], m_params[4], m_params[5],
			m_params[6], m_params[7], m_params[8]);
		break;
	}

	//close the texture, if any
	if (m_texturePath != "")
		glDisable(GL_TEXTURE_2D);

#ifdef _DEBUG
	//draw the reference coordinate system
	setAmbientColor(0.1f, 0.1f, 0.1f);
	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_RED);
	drawBox(10, .01f, .01f);
	glPopMatrix();

	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);
	drawBox(.01f, 10, .01f);
	glPopMatrix();

	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_BLUE);
	drawBox(.01f, .01f, 10);
	glPopMatrix();
	
	setDiffuseColor(1.0f, 1.0f, 1.0f);
#endif
}

void GeneralModel::setParam(float r) {
	m_params.push_back(r);
}
void GeneralModel::setParam(float a, float b, float c) {
	m_params.push_back(a);
	m_params.push_back(b);
	m_params.push_back(c);
}
void GeneralModel::setParam(
	float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3) {
	m_params.push_back(x1);
	m_params.push_back(y1);
	m_params.push_back(z1);
	m_params.push_back(x2);
	m_params.push_back(y2);
	m_params.push_back(z2);
	m_params.push_back(x3);
	m_params.push_back(y3);
	m_params.push_back(z3);
}
void GeneralModel::setTexture(std::string path)
{
	m_texturePath = path;
}