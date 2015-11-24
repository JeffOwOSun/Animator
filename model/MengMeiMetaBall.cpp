
#include "MengMeiMetaBall.h"

MengMeiMetaBall::MengMeiMetaBall() :Model(HEAD)
{

}

void MengMeiMetaBall::onDraw()
{
	anim_cnt = anim_cnt + 5;
	anim_cnt = anim_cnt % TOTAL_FRAME;
	MetaBall* mb = new MetaBall(1);
	if (isAnimating())
	{
		double progress = 0.0, progress2 = 0.0;
		if (anim_cnt < 50)
		{
			progress = (double)anim_cnt / (double)50;
			progress2 = (double)anim_cnt / (double)100;
		}
		else if (anim_cnt < 100)
		{

			progress = (100 - (double)anim_cnt) / (double)50;
			progress2 = (double)anim_cnt / (double)100;
		}
		else if (anim_cnt < 150)
		{
			progress = (double)(anim_cnt - 100) / (double)50;
			progress2 = (200 - (double)anim_cnt) / (double)100;
		}
		else if (anim_cnt <= 200)
		{
			progress = (double)(200 - anim_cnt) / (double)50;
			progress2 = (200 - (double)anim_cnt) / (double)100;
		}

		mb->addBallRel(0, 0, 2.0, 2.0);
		mb->addBallRel(-4 * progress2, -4 * progress2, 2.0, 2.0);
		mb->addBallRel(4 * progress2, 4 * progress2, 2.0, 2.0);
		mb->addBallRel(-4 * progress2, 4 * progress2, 2.0, 2.0);
		mb->addBallRel(4 * progress2, -4 * progress2, 2.0, 2.0);
		mb->addBallRel(4 * progress, 0 * progress, 2.0, 2.0);
		mb->addBallRel(0 * progress, 4 * progress, 2.0, 2.0);
		mb->addBallRel(-4 * progress, 0 * progress, 2.0, 2.0);
		mb->addBallRel(0 * progress, -4 * progress, 2.0, 2.0);
		mb->cal();
		mb->draw(30);
	}
	else
	{
		mb->addBallRel(0, 0, 2.0, 2.0);
		mb->cal();
		mb->draw(30);
	}
	delete mb;
}