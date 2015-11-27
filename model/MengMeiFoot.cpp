
#include "MengMeiFoot.h"

#define FTP1 -0.5f, -0.4f, -1.3f
#define FTP2 -0.5f, 0.4f, -1.3f
#define FTP3 0.0f, 0.6f, -1.3f
#define FTP4 0.5f, 0.4f, -1.3f
#define FTP5 0.5f, -0.4f, -1.3f
#define FTP6 0.0f, -0.6f, -1.3f

#define FTP7 -0.5f, -0.4f, -1.0f
#define FTP8 -0.5f, 0.4f, -1.0f
#define FTP9 0.0f, 0.6f, -1.0f
#define FTP10 0.5f, 0.4f, -1.0f
#define FTP11 0.5f, -0.4f, -1.0f
#define FTP12 0.0f, -0.6f, -1.0f

#define FTP13 -0.6f, -0.5f, -0.8f
#define FTP14 -0.6f, 0.5f, -0.8f
#define FTP15 0.0f, 0.7f, -0.8f
#define FTP16 0.6f, 0.5f, -0.8f
#define FTP17 0.6f, -0.5f, -0.8f
#define FTP18 0.0f, -0.7f, -0.8f

#define FTP19 -0.5f, -0.4f, -0.5f
#define FTP20 -0.5f, 0.4f, -0.5f
#define FTP21 0.0f, 0.6f, -0.5f
#define FTP22 0.5f, 0.4f, -0.5f
#define FTP23 0.5f, -0.4f, -0.5f
#define FTP24 0.0f, -0.6f, -0.5f

#define FTP25 -0.78f, -0.58f, -0.49f
#define FTP26 -0.92f, 0.0f, -0.51f
#define FTP27 -0.78f, 0.58f, -0.48f
#define FTP28 0.0f, 0.78f, -0.52f
#define FTP29 0.78f, 0.58f, -0.5f
#define FTP30 0.92f, 0.0f, -0.48f
#define FTP31 0.78f, -0.58f, -0.5f
#define FTP32 0.0f, -0.78f, -0.51f

#define FTP33 -0.73f, -0.53f, 0.35f
#define FTP34 -0.87f, 0.0f, 0.35f
#define FTP35 -0.73f, 0.53f, 0.35f
#define FTP36 0.0f, 0.73f, 0.35f
#define FTP37 0.73f, 0.53f, 0.35f
#define FTP38 0.87f, 0.0f, 0.35f
#define FTP39 0.73f, -0.53f, 0.35f
#define FTP40 0.0f, -0.73f, 0.35f

#define FTP41 -0.73f, -0.53f, 1.0f
#define FTP42 -0.87f, 0.0f, 1.0f
#define FTP43 -0.58f, 0.65f, 1.0f
#define FTP44 0.0f, 0.75f, 1.0f
#define FTP45 0.73f, 0.65f, 1.0f
#define FTP46 0.92f, 0.0f, 1.0f
#define FTP47 0.73f, -0.65f, 1.0f
#define FTP48 0.0f, -0.75f, 1.0f

#define FTP49 -2.1f, 0.0f, 0.2f

#define FTP51 -1.75f, -0.85f, 0.45f
#define FTP52 -2.45f, -0.5f, 0.52f
#define FTP53 -2.75f, 0.0f, 0.55f
#define FTP54 -2.45f, 0.5f, 0.52f
#define FTP55 -1.75f, 0.75f, 0.45f

#define FTP61 -0.73f, -0.53f, 1.5f
#define FTP62 -0.87f, 0.0f, 1.5f
#define FTP63 -0.58f, 0.65f, 1.5f
#define FTP64 0.0f, 0.75f, 1.5f
#define FTP65 0.73f, 0.65f, 1.5f
#define FTP66 0.92f, 0.0f, 1.5f
#define FTP67 0.73f, -0.65f, 1.5f
#define FTP68 0.0f, -0.75f, 1.5f

#define FTP71 -1.85f, -0.89f, 1.5f
#define FTP72 -2.55f, -0.6f, 1.5f
#define FTP73 -2.85f, 0.0f, 1.5f
#define FTP74 -2.55f, 0.6f, 1.5f
#define FTP75 -1.85f, 0.85f, 1.5f

void MengMeiFoot::onDraw()
{
	//bottom
	drawTriangle(FTP61, FTP62, FTP63);
	drawTriangle(FTP61, FTP63, FTP64);
	drawTriangle(FTP61, FTP64, FTP65);
	drawTriangle(FTP61, FTP65, FTP66);
	drawTriangle(FTP61, FTP66, FTP67);
	drawTriangle(FTP61, FTP67, FTP68);
	drawTriangle(FTP62, FTP71, FTP72);
	drawTriangle(FTP62, FTP72, FTP73);
	drawTriangle(FTP62, FTP73, FTP74);
	drawTriangle(FTP62, FTP74, FTP75);
	drawTriangle(FTP61, FTP71, FTP62);
	drawTriangle(FTP62, FTP75, FTP63);

	//left and right side of shoe
	drawTriangle(FTP33, FTP41, FTP51);
	drawTriangle(FTP51, FTP41, FTP71);
	drawTriangle(FTP41, FTP61, FTP71);
	drawTriangle(FTP35, FTP43, FTP55);
	drawTriangle(FTP55, FTP43, FTP75);
	drawTriangle(FTP43, FTP63, FTP75);

	drawTriangle(FTP51, FTP71, FTP72);
	drawTriangle(FTP72, FTP52, FTP51);
	drawTriangle(FTP52, FTP72, FTP73);
	drawTriangle(FTP73, FTP53, FTP52);
	drawTriangle(FTP53, FTP73, FTP74);
	drawTriangle(FTP74, FTP54, FTP53);
	drawTriangle(FTP54, FTP74, FTP75);
	drawTriangle(FTP75, FTP55, FTP54);

	drawTriangle(FTP41, FTP42, FTP62);
	drawTriangle(FTP62, FTP61, FTP41);
	drawTriangle(FTP42, FTP43, FTP63);
	drawTriangle(FTP63, FTP62, FTP42);
	drawTriangle(FTP43, FTP44, FTP64);
	drawTriangle(FTP64, FTP63, FTP43);
	drawTriangle(FTP44, FTP45, FTP65);
	drawTriangle(FTP65, FTP64, FTP44);
	drawTriangle(FTP45, FTP46, FTP66);
	drawTriangle(FTP66, FTP65, FTP45);
	drawTriangle(FTP46, FTP47, FTP67);
	drawTriangle(FTP67, FTP66, FTP46);
	drawTriangle(FTP47, FTP48, FTP68);
	drawTriangle(FTP68, FTP67, FTP47);
	drawTriangle(FTP48, FTP41, FTP61);
	drawTriangle(FTP61, FTP68, FTP48);

	drawTriangle(FTP49, FTP33, FTP51);
	drawTriangle(FTP49, FTP51, FTP52);
	drawTriangle(FTP49, FTP52, FTP53);
	drawTriangle(FTP49, FTP53, FTP54);
	drawTriangle(FTP49, FTP54, FTP55);
	drawTriangle(FTP49, FTP55, FTP35);

	drawTriangle(FTP1, FTP2, FTP8);
	drawTriangle(FTP8, FTP7, FTP1);
	drawTriangle(FTP2, FTP3, FTP9);
	drawTriangle(FTP9, FTP8, FTP2);
	drawTriangle(FTP3, FTP4, FTP10);
	drawTriangle(FTP10, FTP9, FTP3);
	drawTriangle(FTP4, FTP5, FTP11);
	drawTriangle(FTP11, FTP10, FTP4);
	drawTriangle(FTP5, FTP6, FTP12);
	drawTriangle(FTP12, FTP11, FTP5);
	drawTriangle(FTP6, FTP1, FTP7);
	drawTriangle(FTP7, FTP12, FTP6);


	drawTriangle(FTP7, FTP8, FTP14);
	drawTriangle(FTP14, FTP13, FTP7);
	drawTriangle(FTP8, FTP9, FTP15);
	drawTriangle(FTP15, FTP14, FTP8);
	drawTriangle(FTP9, FTP10, FTP16);
	drawTriangle(FTP16, FTP15, FTP9);
	drawTriangle(FTP10, FTP11, FTP17);
	drawTriangle(FTP17, FTP16, FTP10);
	drawTriangle(FTP11, FTP12, FTP18);
	drawTriangle(FTP18, FTP17, FTP11);
	drawTriangle(FTP12, FTP7, FTP13);
	drawTriangle(FTP13, FTP18, FTP12);

	drawTriangle(FTP13, FTP14, FTP20);
	drawTriangle(FTP20, FTP19, FTP13);
	drawTriangle(FTP14, FTP15, FTP21);
	drawTriangle(FTP21, FTP20, FTP14);
	drawTriangle(FTP15, FTP16, FTP22);
	drawTriangle(FTP22, FTP21, FTP15);
	drawTriangle(FTP16, FTP17, FTP23);
	drawTriangle(FTP23, FTP22, FTP16);
	drawTriangle(FTP17, FTP18, FTP24);
	drawTriangle(FTP24, FTP23, FTP17);
	drawTriangle(FTP18, FTP13, FTP19);
	drawTriangle(FTP19, FTP24, FTP18);

	drawTriangle(FTP19, FTP25, FTP26);
	drawTriangle(FTP20, FTP19, FTP26);
	drawTriangle(FTP26, FTP27, FTP20);
	drawTriangle(FTP21, FTP20, FTP27);
	drawTriangle(FTP27, FTP28, FTP21);
	drawTriangle(FTP21, FTP22, FTP28);
	drawTriangle(FTP22, FTP29, FTP28);
	drawTriangle(FTP22, FTP29, FTP30);
	drawTriangle(FTP30, FTP22, FTP23);
	drawTriangle(FTP23, FTP30, FTP31);
	drawTriangle(FTP24, FTP23, FTP31);
	drawTriangle(FTP31, FTP32, FTP24);
	drawTriangle(FTP19, FTP24, FTP32);
	drawTriangle(FTP32, FTP25, FTP19);

	drawTriangle(FTP25, FTP26, FTP34);
	drawTriangle(FTP34, FTP33, FTP25);
	drawTriangle(FTP26, FTP27, FTP35);
	drawTriangle(FTP35, FTP34, FTP26);
	drawTriangle(FTP27, FTP28, FTP36);
	drawTriangle(FTP36, FTP35, FTP27);
	drawTriangle(FTP28, FTP29, FTP37);
	drawTriangle(FTP37, FTP36, FTP28);
	drawTriangle(FTP29, FTP30, FTP38);
	drawTriangle(FTP38, FTP37, FTP29);
	drawTriangle(FTP30, FTP31, FTP39);
	drawTriangle(FTP39, FTP38, FTP30);
	drawTriangle(FTP31, FTP32, FTP40);
	drawTriangle(FTP40, FTP39, FTP31);
	drawTriangle(FTP32, FTP25, FTP33);
	drawTriangle(FTP33, FTP40, FTP32);

	drawTriangle(FTP33, FTP34, FTP42);
	drawTriangle(FTP42, FTP41, FTP33);
	drawTriangle(FTP34, FTP35, FTP43);
	drawTriangle(FTP43, FTP42, FTP34);
	drawTriangle(FTP35, FTP36, FTP44);
	drawTriangle(FTP44, FTP43, FTP35);
	drawTriangle(FTP36, FTP37, FTP45);
	drawTriangle(FTP45, FTP44, FTP36);
	drawTriangle(FTP37, FTP38, FTP46);
	drawTriangle(FTP46, FTP45, FTP37);
	drawTriangle(FTP38, FTP39, FTP47);
	drawTriangle(FTP47, FTP46, FTP38);
	drawTriangle(FTP39, FTP40, FTP48);
	drawTriangle(FTP48, FTP47, FTP39);
	drawTriangle(FTP40, FTP33, FTP41);
	drawTriangle(FTP41, FTP48, FTP40);

	drawTriangle(FTP33, FTP49, FTP34);
	drawTriangle(FTP35, FTP34, FTP49);

	//drawSphere(0.5f);
}

MengMeiFoot::MengMeiFoot(ModelNames name) :Model(name) {}