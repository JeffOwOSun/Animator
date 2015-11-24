
#include "MengMeiHead.h"

#define point1 0.0f, 0.0f, 0.0f
#define point2 0.5f, 0.3f, 0.0f
#define point3 0.7f, 0.9f, 0.4f
#define point4 -0.5f, 0.3f, 0.0f
#define point5 -0.7f, 0.9f, 0.4f
#define point6 0.6f, 1.2f, 0.3f
#define point7 -0.6f, 1.2f, 0.3f
#define point8 0.0f, 1.5f, 0.0f

#define point9 0.7f, 0.9f, -0.3f
#define point10 -0.7f, 0.9f, -0.3f
#define point11 0.0f, 1.1f, -0.6f
#define point12 0.6f, 1.2f, -0.1f
#define point13 -0.6f, 1.2f, -0.1f
#define point14 0.0f, 1.5f, 0.0f

#define point15 0.0f, 0.3f, 0.3f
#define point16 0.0f, 1.2f, 0.3f

#define HT1 -0.3f, 0.0f, -0.1f
#define HT2 -0.12f, 0.0f, 0.15f
#define HT3 0.0f, 0.0f, 0.2f
#define HT4 0.12f, 0.0f, 0.15f
#define HT5 0.3f, 0.0f, -0.1f

#define HT11 -0.25f, 0.6f, -0.1f
#define HT12 -0.225f, 0.6f, 0.05f
#define HT13 -0.15f, 0.6f, 0.1f
#define HT14 -0.1f, 0.6f, 0.14f
#define HT15 0.0f, 0.6f, 0.15f
#define HT16 0.1f, 0.6f, 0.14f
#define HT17 0.15f, 0.6f, 0.1f
#define HT18 0.225f, 0.6f, 0.05f
#define HT19 0.25f, 0.6f, -0.1f

// center of face
#define HT20 0.0f, 0.7f, 0.3f
#define HT21 0.0f, 1.0f, 0.3f
#define HT22 0.0f, 1.3f, 0.3f
#define HT23 0.0f, 1.6f, 0.34f
#define HT24 0.0f, 1.8f, 0.4f
#define HT25 0.0f, 2.3f, 0.3f
#define HT26 0.0f, 2.9f, 0.3f

// first left of face 
#define HT30 0.45f, 1.1f, 0.16f
#define HT31 0.3f, 1.4f, 0.16f
#define HT32 0.45f, 1.7f, 0.16f
#define HT33 0.45f, 1.5f, 0.15f
#define HT34 1.0f, 1.3f, 0.14f
#define HT35 0.9f, 1.7f, 0.14f
#define HT36 1.3f, 1.7f, 0.13f

// first right of face 
#define HT40 0.6f, 0.9f, 0.0f
#define HT41 1.2f, 1.1f, -0.07f
#define HT42 1.8f, 1.6f, -0.15f
#define HT43 1.9f, 2.5f, -0.25f
#define HT44 2.0f, 3.4f, -0.25f

#define HT50 0.7f, 2.1f, 0.01f
#define HT51 1.5f, 2.1f, 0.0f

#define HT60 0.5f, 2.35f, 0.15f 
#define HT61 0.4f, 2.73f, 0.2f
#define HT65 0.65f, 3.4f, 0.1f
#define HT62 0.7f, 2.8f, 0.1f
#define HT63 1.45f, 2.8f, 0.05f
#define HT66 0.75f, 2.7f, -0.01f
#define HT64 1.58f, 2.7f, -0.06f
#define HT67 0.62f, 2.51f, 0.15f

#define HHT0 -0.5f, 4.92f, 0.3f
#define HHT1 0.1f, 5.0f, 0.3f
#define HHT2 0.6f, 4.85f, 0.3f
#define HHT3 1.0f, 4.5f, 0.3f
#define HHT4 1.5f, 4.2f, 0.3f
#define HHT5 1.7f, 3.9f, 0.3f
#define HHT6 1.8f, 3.45f, 0.3f
#define HHT7 1.9f, 2.25f, 0.3f
#define HHT8 1.9f, 1.65f, 0.3f
#define HHT9 1.8f, 0.95f, 0.3f
#define HHT10 1.75f, 0.6f, 0.3f


#define HHT20 -0.4f, 5.6f, -0.2f
#define HHT21 0.1f, 5.7f, -0.2f
#define HHT22 0.7f, 5.45f, -0.2f
#define HHT23 0.85f, 5.4f, -0.2f
#define HHT24 1.65f, 4.8f, -0.2f
#define HHT25 1.8f, 4.05f, -0.2f
#define HHT26 2.2f, 2.85f, -0.2f
#define HHT27 2.3f, 1.7f, -0.2f
#define HHT28 2.1f, 0.8f, -0.2f
#define HHT29 2.0f, 0.7f, -0.2f
#define HHT30 1.8f, 0.6f, -0.2f

#define HHT40 -0.4f, 5.8f, -0.9f
#define HHT41 0.1f, 5.9f, -0.9f
#define HHT42 0.7f, 5.55f, -0.9f
#define HHT43 0.85f, 5.5f, -0.9f
#define HHT44 1.65f, 5.0f, -0.9f
#define HHT45 1.8f, 4.25f, -0.9f
#define HHT46 2.2f, 3.05f, -0.9f
#define HHT47 2.3f, 1.9f, -0.9f
#define HHT48 2.1f, 1.0f, -0.9f
#define HHT49 2.0f, 0.9f, -0.9f
#define HHT50 1.8f, 0.8f, -0.9f

#define HHT60 -0.4f, 5.9f, -1.5f
#define HHT61 0.1f, 6.0f, -1.5f
#define HHT62 0.7f, 5.65f, -1.5f
#define HHT63 0.85f, 5.6f, -1.5f
#define HHT64 1.65f, 5.1f, -1.5f
#define HHT65 1.8f, 4.35f, -1.5f
#define HHT66 2.2f, 3.15f, -1.5f
#define HHT67 2.3f, 2.0f, -1.5f
#define HHT68 2.1f, 1.1f, -1.5f
#define HHT69 2.0f, 1.0f, -1.5f
#define HHT70 1.8f, 0.9f, -1.5f

#define HHT80 -0.4f, 5.92f, -2.0f
#define HHT81 0.1f, 6.02f, -2.0f
#define HHT82 0.7f, 5.67f, -2.0f
#define HHT83 0.85f, 5.62f, -2.0f
#define HHT84 1.65f, 5.12f, -2.0f
#define HHT85 1.8f, 4.37f, -2.0f
#define HHT86 2.2f, 3.17f, -2.0f
#define HHT87 2.3f, 2.02f, -2.0f
#define HHT88 2.1f, 1.12f, -2.0f
#define HHT89 2.0f, 1.02f, -2.0f
#define HHT90 1.8f, 0.92f, -2.0f




MengMeiHead::MengMeiHead() : Model(HEAD)
{
	m_leftEye = new MengMeiEye(LEFTEYE);
	m_leftEye->getController()->setTransX(0.3f)->setTransY(0.85f)->setTransZ(0.35f)->setRotateX(-90)->setRotateY(90);
	addChild(m_leftEye);
	printf("add left eye");

	m_rightEye = new MengMeiEye(RIGHTEYE);
	m_rightEye->getController()->setTransX(-0.3f)->setTransY(0.85f)->setTransZ(0.35f)
		->setRotateX(-90)->setRotateY(90);
	addChild(m_rightEye);
	printf("add right eye");
}

void MengMeiHead::onDraw()
{
	glPushMatrix();
	glTranslated(0.0f, 2.0f, 0.0f);

	drawTorus(0.6f, 0.15f);
	glPopMatrix();

	drawTriangle(point1, point2, point3);
	drawTriangle(point1, point4, point5);
	drawTriangle(point1, point3, point15);
	drawTriangle(point1, point15, point5);
	drawTriangle(point3, point6, point8);
	drawTriangle(point7, point5, point8);
	drawTriangle(point5, point16, point8);
	drawTriangle(point3, point8, point16);
	drawTriangle(point5, point3, point16);
	drawTriangle(point5, point15, point3);

	drawTriangle(point1, point2, point9);
	drawTriangle(point4, point1, point10);
	drawTriangle(point1, point9, point11);
	drawTriangle(point10, point1, point11);

	drawTriangle(point2, point3, point9);
	drawTriangle(point4, point5, point10);
	drawTriangle(point9, point12, point11);
	drawTriangle(point11, point10, point13);
	drawTriangle(point12, point11, point14);
	drawTriangle(point11, point13, point14);

	drawTriangle(point10, point5, point13);
	drawTriangle(point13, point5, point14);
	drawTriangle(point9, point3, point12);
	drawTriangle(point12, point3, point14);

	// stop draw Others, hair third
	//drawTriangle(HHT60, HHT81, HHT80);
	//drawTriangle(HHT60, HHT61, HHT81);

	//drawTriangle(HHT61, HHT82, HHT81);
	//drawTriangle(HHT61, HHT62, HHT82);

	//drawTriangle(HHT62, HHT83, HHT82);
	//drawTriangle(HHT62, HHT63, HHT83);

	//drawTriangle(HHT63, HHT84, HHT83);
	//drawTriangle(HHT63, HHT64, HHT84);

	//drawTriangle(HHT64, HHT85, HHT84);
	//drawTriangle(HHT64, HHT65, HHT85);

	//drawTriangle(HHT65, HHT86, HHT85);
	//drawTriangle(HHT65, HHT66, HHT86);

	//drawTriangle(HHT66, HHT87, HHT86);
	//drawTriangle(HHT66, HHT67, HHT87);

	//drawTriangle(HHT67, HHT88, HHT87);
	//drawTriangle(HHT67, HHT68, HHT88);

	//drawTriangle(HHT68, HHT89, HHT88);
	//drawTriangle(HHT68, HHT69, HHT89);

	//drawTriangle(HHT69, HHT90, HHT89);
	//drawTriangle(HHT69, HHT70, HHT90);


	//// stop draw Others, hair third
	//drawTriangle(HHT40, HHT61, HHT60);
	//drawTriangle(HHT40, HHT41, HHT61);

	//drawTriangle(HHT41, HHT62, HHT61);
	//drawTriangle(HHT41, HHT42, HHT62);

	//drawTriangle(HHT42, HHT63, HHT62);
	//drawTriangle(HHT42, HHT43, HHT63);

	//drawTriangle(HHT43, HHT64, HHT63);
	//drawTriangle(HHT43, HHT44, HHT64);

	//drawTriangle(HHT44, HHT65, HHT64);
	//drawTriangle(HHT44, HHT45, HHT65);

	//drawTriangle(HHT45, HHT66, HHT65);
	//drawTriangle(HHT45, HHT46, HHT66);

	//drawTriangle(HHT46, HHT67, HHT66);
	//drawTriangle(HHT46, HHT47, HHT67);

	//drawTriangle(HHT47, HHT68, HHT67);
	//drawTriangle(HHT47, HHT48, HHT68);

	//drawTriangle(HHT48, HHT69, HHT68);
	//drawTriangle(HHT48, HHT49, HHT69);

	//drawTriangle(HHT49, HHT70, HHT69);
	//drawTriangle(HHT49, HHT50, HHT70);

	//// stop draw Others, hair second
	//drawTriangle(HHT20, HHT41, HHT40);
	//drawTriangle(HHT20, HHT21, HHT41);

	//drawTriangle(HHT21, HHT42, HHT41);
	//drawTriangle(HHT21, HHT22, HHT42);

	//drawTriangle(HHT22, HHT43, HHT42);
	//drawTriangle(HHT22, HHT23, HHT43);

	//drawTriangle(HHT23, HHT44, HHT43);
	//drawTriangle(HHT23, HHT24, HHT44);

	//drawTriangle(HHT24, HHT45, HHT44);
	//drawTriangle(HHT24, HHT25, HHT45);

	//drawTriangle(HHT25, HHT46, HHT45);
	//drawTriangle(HHT25, HHT26, HHT46);

	//drawTriangle(HHT26, HHT47, HHT46);
	//drawTriangle(HHT26, HHT27, HHT47);

	//drawTriangle(HHT27, HHT48, HHT47);
	//drawTriangle(HHT27, HHT28, HHT48);

	//drawTriangle(HHT28, HHT49, HHT48);
	//drawTriangle(HHT28, HHT29, HHT49);

	//drawTriangle(HHT29, HHT50, HHT49);
	//drawTriangle(HHT29, HHT30, HHT50);


	//// stop draw Others, hair first
	//drawTriangle(HHT0, HHT21, HHT20);
	//drawTriangle(HHT0, HHT1, HHT21);

	//drawTriangle(HHT1, HHT22, HHT21);
	//drawTriangle(HHT1, HHT2, HHT22);

	//drawTriangle(HHT2, HHT23, HHT22);
	//drawTriangle(HHT2, HHT3, HHT23);

	//drawTriangle(HHT3, HHT24, HHT23);
	//drawTriangle(HHT3, HHT4, HHT24);

	//drawTriangle(HHT4, HHT25, HHT24);
	//drawTriangle(HHT4, HHT5, HHT25);

	//drawTriangle(HHT5, HHT26, HHT25);
	//drawTriangle(HHT5, HHT6, HHT26);

	//drawTriangle(HHT6, HHT27, HHT26);
	//drawTriangle(HHT6, HHT7, HHT27);

	//drawTriangle(HHT7, HHT28, HHT27);
	//drawTriangle(HHT7, HHT8, HHT28);

	//drawTriangle(HHT8, HHT29, HHT28);
	//drawTriangle(HHT8, HHT9, HHT29);

	//drawTriangle(HHT9, HHT30, HHT29);
	//drawTriangle(HHT9, HHT10, HHT30);


	//// face upper first layer from center to left
	//drawTriangle(HT24, HT32, HT25);
	//drawTriangle(HT25, HT32, HT50);
	//drawTriangle(HT32, HT35, HT50);
	//drawTriangle(HT35, HT36, HT50);
	//drawTriangle(HT36, HT51, HT50);
	//drawTriangle(HT36, HT42, HT51);
	//drawTriangle(HT25, HT50, HT60);
	//drawTriangle(HT25, HT60, HT61);
	//drawTriangle(HT25, HT61, HT26);
	//drawTriangle(HT26, HT61, HT65);
	//drawTriangle(HT61, HT62, HT65);
	//drawTriangle(HT62, HT63, HT65);
	//drawTriangle(HT51, HT42, HT43);
	//drawTriangle(HT43, HT44, HT63);
	//drawTriangle(HT63, HT44, HT65);
	//drawTriangle(HT50, HT51, HT66);
	//drawTriangle(HT51, HT64, HT66);
	//drawTriangle(HT66, HT64, HT62);
	//drawTriangle(HT64, HT63, HT62);
	//drawTriangle(HT51, HT43, HT64);
	//drawTriangle(HT43, HT63, HT64);
	//drawTriangle(HT60, HT67, HT61);
	//drawTriangle(HT67, HT62, HT61);
	//drawTriangle(HT60, HT66, HT67);
	//drawTriangle(HT67, HT66, HT62);
	//drawTriangle(HT60, HT50, HT66);

	////face second layer, from center to left
	//drawTriangle(HT20, HT40, HT30);
	//drawTriangle(HT40, HT34, HT30);
	//drawTriangle(HT40, HT41, HT34);
	//drawTriangle(HT41, HT42, HT34);
	//drawTriangle(HT41, HT42, HT34);
	//drawTriangle(HT34, HT42, HT36);


	//// face first layer, from center to left
	//drawTriangle(HT20, HT30, HT21);
	//drawTriangle(HT21, HT30, HT31);
	//drawTriangle(HT21, HT31, HT22);
	//drawTriangle(HT22, HT31, HT23);
	//drawTriangle(HT31, HT32, HT23);
	//drawTriangle(HT23, HT32, HT24);
	//drawTriangle(HT30, HT33, HT31);
	//drawTriangle(HT31, HT33, HT32);
	//drawTriangle(HT30, HT34, HT33);
	//drawTriangle(HT33, HT35, HT32);
	//drawTriangle(HT33, HT34, HT35);
	//drawTriangle(HT34, HT36, HT35);

	//
	//

	//// neck-layer, 头最下面一层，底层4，上层9
	//drawTriangle(HT1, HT12, HT11);
	//drawTriangle(HT2, HT13, HT12);
	//drawTriangle(HT12, HT1, HT2);
	//drawTriangle(HT2, HT14, HT13);
	//drawTriangle(HT2, HT3, HT15);
	//drawTriangle(HT15, HT14, HT2);
	//drawTriangle(HT3, HT4, HT15);
	//drawTriangle(HT4, HT16, HT15);
	//drawTriangle(HT4, HT17, HT16);
	//drawTriangle(HT4, HT5, HT17);
	//drawTriangle(HT5, HT18, HT17);
	//drawTriangle(HT5, HT19, HT18);

}