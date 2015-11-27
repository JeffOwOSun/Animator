
#include "MengMeiHand.h"
#include "../MetaBall.h"
// bottom of shoutao
#define P1 -1.0f, 0.0f, 0.5f
#define P2 -1.0f, 0.35f, 0.2f
#define P3 -1.0f, 0.35f, -0.2f
#define P4 -1.0f, 0.0f, -0.5f
#define P5 -1.0f, -0.35f, -0.2f
#define P6 -1.0f, -0.35f, 0.2f

#define P7 -0.5f, 0.0f, 0.4f
#define P8 -0.5f, 0.28f, 0.15f
#define P9 -0.5f, 0.28f, -0.15f
#define P10 -0.5f, 0.0f, -0.4f
#define P11 -0.5f, -0.28f, -0.15f
#define P12 -0.5f, -0.28f, 0.15f

#define P13 -0.4, 0.0f, 0.2f
#define P14 -0.4, 0.2f, 0.07f
#define P15 -0.4, 0.2f, -0.07f
#define P16 -0.4, 0.0f, -0.2f
#define P17 -0.4, -0.2f, -0.07f
#define P18 -0.4, -0.2f, 0.07f

#define P19 -0.3, 0.0f, 0.2f
#define P20 -0.3, 0.2f, 0.07f
#define P21 -0.3, 0.2f, -0.07f
#define P22 -0.3, 0.0f, -0.2f
#define P23 -0.3, -0.2f, -0.07f
#define P24 -0.3, -0.2f, 0.07f


void MengMeiHand::onDraw()
{
	
	drawTriangle(P2, P1, P7);
	drawTriangle(P7, P8, P2);
	drawTriangle(P2, P8, P9);
	drawTriangle(P9, P3, P2);
	drawTriangle(P3, P9, P10);
	drawTriangle(P10, P4, P3);
	drawTriangle(P4, P10, P11);
	drawTriangle(P11, P5, P4);
	drawTriangle(P5, P11, P12);
	drawTriangle(P12, P6, P5);
	drawTriangle(P1, P6, P12);
	drawTriangle(P12, P7, P1);

	drawTriangle(P7, P13, P14);
	drawTriangle(P14, P8, P7);
	drawTriangle(P8, P14, P15);
	drawTriangle(P15, P9, P8);
	drawTriangle(P9, P15, P16);
	drawTriangle(P16, P10, P9);
	drawTriangle(P10, P16, P17);
	drawTriangle(P17, P11, P10);
	drawTriangle(P11, P17, P18);
	drawTriangle(P18, P12, P11);
	drawTriangle(P12, P18, P13);
	drawTriangle(P13, P7, P12);

	drawTriangle(P13, P19, P20);
	drawTriangle(P20, P14, P13);
	drawTriangle(P14, P20, P21);
	drawTriangle(P21, P15, P14);
	drawTriangle(P15, P21, P22);
	drawTriangle(P22, P16, P15);
	drawTriangle(P16, P22, P23);
	drawTriangle(P23, P17, P16);
	drawTriangle(P17, P23, P24);
	drawTriangle(P24, P18, P17);
	drawTriangle(P18, P24, P19);
	drawTriangle(P19, P13, P18);

}

MengMeiHand::MengMeiHand(ModelNames name) : Model(name) {}