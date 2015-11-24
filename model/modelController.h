/**
* This file serves as controller for model
* Handles the incremental transformation of the coordinate system between models
*/

#ifndef MODEL_CONTROLLER_H
#define MODEL_CONTROLLER_H

#include"..\mat.h"

class modelController
{
public:
	modelController() : trans({ 0, 0, 0 }), rotate({ 0, 0, 0 })
	{}

	void Control();

	modelController* setTransX(const float x)
	{
		trans.x = x;
		return this;
	}

	modelController* setTransY(const float y)
	{
		trans.y = y;
		return this;
	}

	modelController* setTransZ(const float z)
	{
		trans.z = z;
		return this;
	}

	modelController* setTrans(const float x, const float y, const float z)
	{
		trans.x = x;
		trans.y = y;
		trans.z = z;
		return this;
	}

	modelController* setRotateX(const float x)
	{
		rotate.x = x;
		return this;
	}

	modelController* setRotateY(const float y)
	{
		rotate.y = y;
		return this;
	}

	modelController* setRotateZ(const float z)
	{
		rotate.z = z;
		return this;
	}

	float getTransX()
	{
		return trans.x;
	}

	modelController* setRotate(const float x, const float y, const float z)
	{
		rotate.x = x;
		rotate.y = y;
		rotate.z = z;
		return this;
	}

	Mat4f getMatrix();

private:
	struct {
		float x, y, z;
	} trans;

	struct {
		float x, y, z;
	} rotate;
};


#endif