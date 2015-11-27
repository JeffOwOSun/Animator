#include "ObjUtil.h"

Triangle::Triangle()
{
	for (int i = 0; i < 3; ++i)
	{
		v[i] = n[i] = t[i] = -1;
	}
}

int Triangle::containsEdge(int n1, int n2) const
{
	for (int i = 0; i < 3; ++i)
	{
		int next_i = (i + 1) % 3;
		if (v[i] == n1 && v[next_i] == n2) return i;
	}
	return -1;
}

int Triangle::findNeighborIndex(int n) const
{
	for (int i = 0; i < 3; ++i)
	{
		if (t[i] == n) return i;
	}

	// not found
	return -1;
}

int Triangle::getVertexIndex(int n) const
{
	for (int i = 0; i < 3; ++i)
	{
		if (v[i] == n) return i;
	}

	// not found
	return -1;
}