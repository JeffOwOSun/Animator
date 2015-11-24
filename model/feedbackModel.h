#ifndef FEEDBACK_MODEL_H
#define FEEDBACK_MODEL_H

#include <Fl/gl.h>
#include "model.h"

class FeedbackModel : public Model
{
public:
	FeedbackModel(ModelNames name);
	void onDraw();
private:
	inline void print3DcolorVertex(GLint size, GLint *count,
		GLfloat *buffer)
	{
		int i;

		printf("  ");
		for (i = 0; i < 7; i++) {
			printf("%4.2f ", buffer[size - (*count)]);
			*count = *count - 1;
		}
		printf("\n");
	}
};

#endif //FEEDBACK_MODEL_H