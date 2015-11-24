
#include <FL/gl.h>
#include "modelController.h"
#include <cmath>
#include <cstdio>
#define PI 3.14159265

void modelController::Control()
{
	glTranslatef(trans.x, trans.y, trans.z);
	glRotatef(rotate.z, 0.0f, 0.0f, 1.0f);
	glRotatef(rotate.y, 0.0f, 1.0f, 0.0f);
	glRotatef(rotate.x, 1.0f, 0.0f, 0.0f);
}

Mat4f modelController::getMatrix()
{
	Mat4f result;

	//translation matrix;
	//CAUTION: DON'T USE *=, which is per element multiplication
	result = result * Mat4f(
		1, 0, 0, trans.x,
		0, 1, 0, trans.y,
		0, 0, 1, trans.z,
		0, 0, 0, 1);

	//rotationZ
	float rad = rotate.z * PI / 180;
	result = result * Mat4f(
		cos(rad), -sin(rad), 0, 0,
		sin(rad), cos(rad), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	//rotationY
	rad = rotate.y * PI / 180;
	result = result * Mat4f(
		cos(rad), 0, sin(rad), 0,
		0, 1, 0, 0,
		-sin(rad), 0, cos(rad), 0,
		0, 0, 0, 1);

	//rotationX
	rad = rotate.x * PI / 180;
	result = result * Mat4f(
		1, 0, 0, 0,
		0, cos(rad), -sin(rad), 0,
		0, sin(rad), cos(rad), 0,
		0, 0, 0, 1);

	return result;
}