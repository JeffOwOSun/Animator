/*
* ObjFile.h
*
* Author: Qi Haozhi, Sun Yushi
* Copyright (c) 2015 Qi Haozhi, Sun Yushi
*
* You can star the project via:
* https://github.com/Oh233/Animator OR
* https://github.com/JeffOwOSun/Animator
*/

#ifndef OBJ_UTIL_H
#define OBJ_UTIL_H

class Triangle
{
public:
	enum TriangleMode { VERTICES = 0, NORMALS = 1, TEXTURE = 2 };
	
	Triangle();
	int containsEdge(int n1, int n2) const;
	int findNeighborIndex(int) const;
	int getVertexIndex(int) const;

	int v[3];	// index to vertices
	int n[3];	// index to normals
	int t[3];	// index to triangle neighbours

	int mode;
};

class SplitData
{
public:
	SplitData(int i, int c, int n, int _t1, int _t2) : index(i), callee(c), newPoint(n), t1(_t1), t2(_t2) {}
	int index, callee, newPoint, t1, t2;
};

#endif