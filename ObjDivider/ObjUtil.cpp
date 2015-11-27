#include "ObjUtil.h"

Triangle::Triangle()
{
	for (int i = 0; i < 3; ++i)
	{
		v[i] = n[i] = t[i] = -1;
	}
}