
#include "MengMeiLowerLeg.h"

#define LLP1 -0.4f, -0.13f, 2.7f
#define LLP2 -0.4f, 0.23f, 2.7f
#define LLP3 0.0f, 0.43f, 2.7f
#define LLP4 0.4f, 0.23f, 2.7f
#define LLP5 0.4f, -0.13f, 2.7f
#define LLP6 0.0f, -0.43f, 2.7f

#define LLP11 -0.45f, -0.18f, 2.0f
#define LLP12 -0.45f, 0.28f, 2.2f
#define LLP13 0.0f, 0.43f, 1.9f
#define LLP14 0.45f, 0.23f, 1.8f
#define LLP15 0.45f, -0.13f, 1.8f
#define LLP16 0.0f, -0.49f, 1.9f

#define LLP21 -0.49f, -0.23f, 0.8f
#define LLP22 -0.49f, 0.33f, 0.8f
#define LLP23 0.0f, 0.43f, 0.8f
#define LLP24 0.48f, 0.23f, 0.8f
#define LLP25 0.48f, -0.13f, 0.8f
#define LLP26 0.0f, -0.5f, 0.8f

#define LLP31 -0.55f, -0.25f, 0.1f
#define LLP32 -0.55f, 0.35f, 0.1f
#define LLP33 0.0f, 0.43f, 0.1f
#define LLP34 0.4f, 0.23f, 0.1f
#define LLP35 0.4f, -0.13f, 0.1f
#define LLP36 0.0f, -0.43f, 0.1f

#define LLP43 0.0f, 0.48f, 1.2f
#define LLP44 0.51f, 0.23f, 1.0f
#define LLP45 0.51f, -0.13f, 1.0f
#define LLP46 0.0f, -0.55f, 1.2f

MengMeiLowerLeg::MengMeiLowerLeg(ModelNames name) : Model(name)
{
}

void MengMeiLowerLeg::onDraw()
{
	// Layer 3->4
	drawTriangle(LLP21, LLP22, LLP32);
	drawTriangle(LLP32, LLP31, LLP21);
	drawTriangle(LLP22, LLP23, LLP33);
	drawTriangle(LLP33, LLP32, LLP22);
	drawTriangle(LLP23, LLP24, LLP34);
	drawTriangle(LLP34, LLP33, LLP23);
	drawTriangle(LLP24, LLP25, LLP35);
	drawTriangle(LLP35, LLP34, LLP24);
	drawTriangle(LLP25, LLP26, LLP36);
	drawTriangle(LLP36, LLP35, LLP25);
	drawTriangle(LLP26, LLP21, LLP31);
	drawTriangle(LLP31, LLP36, LLP26);

	// Layer 2->3
	drawTriangle(LLP11, LLP12, LLP22);
	drawTriangle(LLP22, LLP21, LLP11);
	
	//shou
	drawTriangle(LLP22, LLP12, LLP13);
	drawTriangle(LLP22, LLP13, LLP43);
	drawTriangle(LLP22, LLP23, LLP43);

	drawTriangle(LLP23, LLP24, LLP43);
	drawTriangle(LLP24, LLP44, LLP43);
	drawTriangle(LLP43, LLP44, LLP14);
	drawTriangle(LLP14, LLP13, LLP43);
	drawTriangle(LLP24, LLP25, LLP44);
	drawTriangle(LLP25, LLP45, LLP44);
	drawTriangle(LLP44, LLP45, LLP15);
	drawTriangle(LLP15, LLP14, LLP44);
	drawTriangle(LLP25, LLP26, LLP45);
	drawTriangle(LLP26, LLP46, LLP45);
	drawTriangle(LLP45, LLP46, LLP16);
	drawTriangle(LLP16, LLP15, LLP45);

	//wei
	drawTriangle(LLP21, LLP11, LLP16);
	drawTriangle(LLP21, LLP16, LLP46);
	drawTriangle(LLP21, LLP26, LLP46);





	// Layer 1->2
	drawTriangle(LLP1, LLP2, LLP12);
	drawTriangle(LLP12, LLP11, LLP1);
	drawTriangle(LLP2, LLP3, LLP13);
	drawTriangle(LLP13, LLP12, LLP2);
	drawTriangle(LLP3, LLP4, LLP14);
	drawTriangle(LLP14, LLP13, LLP3);
	drawTriangle(LLP4, LLP5, LLP15);
	drawTriangle(LLP15, LLP14, LLP4);
	drawTriangle(LLP5, LLP6, LLP16);
	drawTriangle(LLP16, LLP15, LLP5);
	drawTriangle(LLP6, LLP1, LLP11);
	drawTriangle(LLP11, LLP16, LLP6);




	/*glPushMatrix();
	drawCylinder(4.0f, 0.5f, 0.4f);
	glPopMatrix();*/
}