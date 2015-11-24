#include "feedbackModel.h"

FeedbackModel::FeedbackModel(ModelNames name) : Model(name) {}

void FeedbackModel::onDraw() {
	
	GLfloat feedBuffer[1024];
	GLint size;
	glFeedbackBuffer(1024, GL_3D_COLOR, feedBuffer);
	glRenderMode(GL_FEEDBACK);
	glBegin(GL_POINTS);
	glVertex3d(0, 0, 0);
	glEnd();
	size = glRenderMode(GL_RENDER);
	GLint count = size;
	GLfloat token;
	GLfloat* buffer = feedBuffer;
	while (count > 0) {
		token = buffer[size - count]; count--;
		if (token == GL_PASS_THROUGH_TOKEN) {
			printf("GL_PASS_THROUGH_TOKEN\n");
			printf("  %4.2f\n", buffer[size - count]);
			count--;
		}
		else if (token == GL_POINT_TOKEN) {
			printf("GL_POINT_TOKEN\n");
			print3DcolorVertex(size, &count, buffer);
		}
		else if (token == GL_LINE_TOKEN) {
			printf("GL_LINE_TOKEN\n");
			print3DcolorVertex(size, &count, buffer);
			print3DcolorVertex(size, &count, buffer);
		}
		else if (token == GL_LINE_RESET_TOKEN) {
			printf("GL_LINE_RESET_TOKEN\n");
			print3DcolorVertex(size, &count, buffer);
			print3DcolorVertex(size, &count, buffer);
		}
	}
}