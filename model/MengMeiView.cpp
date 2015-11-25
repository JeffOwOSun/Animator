#include "MengMeiView.h"
//#include "..\InverseKinematics.h"
//for debug use
#include <ctime>

void MengMeiView::draw()
{
	ModelerView::draw();
	printf("MengMeiView::draw() %d\n", time(0));

	glScaled(0.5,0.5,0.5);
	glTranslated(0.0, 2.0, 0.0);

	//if (VAL(LSYS_SHOW) > 0) {
	//	//draw the lsystem
	//	LSystem* lsys;
	//	switch ((int)VAL(LSYS_TYPE)) {
	//	case 0:
	//		lsys = &m_treeLSystem;
	//		break;
	//	case 1:
	//		lsys = &m_plantLSystem;
	//		break;
	//	}
	//	//calculate the lsys tree with given parameters
	//	lsys->evolve(VAL(LSYS_DEPTH));
	//	//draw the lsys tree following the calculated string
	//	lsys->draw(VAL(LSYS_DEPTH));
	//}
	//else {
#ifdef _DEBUG
		printf("MengMeiView::draw() %d\n", time(0));
		//Draw the axis
		setAmbientColor(0.1f, 0.1f, 0.1f);
		glPushMatrix();
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_RED);
		drawBox(100, .1f, .1f);
		glPopMatrix();

		glPushMatrix();
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_GREEN);
		drawBox(.1f, 100, .1f);
		glPopMatrix();

		glPushMatrix();
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_BLUE);
		drawBox(.1f, .1f, 100);
		glPopMatrix();

		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(1.0f, 1.0f, 1.0f);
#endif
		/*ModelNames modelName = LEFTFOOT;
		Vec3f origin = Model::m_modelList[LEFTFOOT]->getOrigin();
		printf("%d:\n\tx: %f\n\ty: %f\n\tz: %f\n", modelName, origin[0], origin[1], origin[2]);
		*/
		//DO INVERSE KINEMATICS

		//if (VAL(INVERSE_KINEMATICS)) {
		//	if (!IKLastState) {
		//		//retrieve the current location of parts
		//		std::vector<double> constrains;
		//		ModelNames handles[] = { HEAD, LEFTHAND, RIGHTHAND, LEFTFOOT, RIGHTFOOT };
		//		for (auto handle : handles) {
		//			Vec3f constrain = Model::m_modelList[handle]->getOrigin();
		//			constrains.push_back(constrain[0]);
		//			constrains.push_back(constrain[1]);
		//			constrains.push_back(constrain[2]);
		//		}
		//		//set the constrains to be the current location of parts
		//		const int startPos = HEAD_CSTRN_X;
		//		for (int i = 0; i + startPos <= RFOOT_CSTRN_Z; ++i) {
		//			SET(i + startPos, constrains[i]);
		//		}
		//		IKLastState = true;
		//	}

		//	//draw the constraint points
		//	Model::m_modelList[HEADCONSTRAINT]->Draw();
		//	Model::m_modelList[LHANDCONSTRAINT]->Draw();
		//	Model::m_modelList[RHANDCONSTRAINT]->Draw();
		//	Model::m_modelList[LFOOTCONSTRAINT]->Draw();
		//	Model::m_modelList[RFOOTCONSTRAINT]->Draw();

		//	//get the optimized parameters
		//	IK::optimize();
		//}
		//else {
		//	IKLastState = false;
		//}
		m_MengMei.Draw(VAL(LEVEL_OF_DETAIL));
	//}
}

void MengMeiView::onLighting()
{
	GLfloat pos0[] = { VAL(LIGHT0_X), VAL(LIGHT0_Y), VAL(LIGHT0_Z), 0.0f };
	GLfloat diffuse0[] = { VAL(LIGHT0_R), VAL(LIGHT0_G), VAL(LIGHT0_B) };
	GLfloat pos1[] = { VAL(LIGHT1_X), VAL(LIGHT1_Y), VAL(LIGHT1_Z), 0.0f };
	GLfloat diffuse1[] = { VAL(LIGHT1_R), VAL(LIGHT1_G), VAL(LIGHT1_B) };

	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
}