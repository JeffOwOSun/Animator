/**
* \file The header file for GeneralModel
* this is a great model because it handles everything needed for all general shapes
* defined in modelerdraw
*/

#ifndef GENERAL_MODEL_H
#define GENERAL_MODEL_H

#include"model.h"

class GeneralModel : public Model
{
public:
	enum ShapeType{
		SPHERE_SHAPE,
		BOX_SHAPE,
		TEXTURE_BOX_SHAPE,
		CYLINDER_SHAPE,
		TRIANGLE_SHAPE,
		NUM_OF_SHAPE
	};

	GeneralModel(ModelNames name, ShapeType type);
	
	//the drawing function
	void onDraw();
	
	//methods to set the painting parameters
	void setParam(float r);
	void setParam(float a, float b, float c);
	void setParam(
		float x1, float y1, float z1,
		float x2, float y2, float z2,
		float x3, float y3, float z3);
	
	//sets the texture to use
	void setTexture(string path);
private:
	ShapeType m_shape_type;
	std::vector<float> m_params;
	std::string m_texturePath;
	GLuint m_texture;
};

#endif //GENERAL_MODEL_H