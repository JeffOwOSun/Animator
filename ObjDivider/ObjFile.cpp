/*
* ObjFile.cpp
*
* Author: Qi Haozhi, Sun Yushi
* Copyright (c) 2015 Qi Haozhi, Sun Yushi
*
* You can star the project via:
* https://github.com/Oh233/Animator OR
* https://github.com/JeffOwOSun/Animator
*/

#include "ObjFile.h"
#include <fstream>
#include <iostream>
#include <string>

ObjFile::ObjFile(string file)
{
	std::ifstream ifs(file.c_str());
	if (!ifs)
	{
		std::cout << "ObjFile::ObjFile: file " << file << " could not be read! \n";
		exit(1);
	}

	// clear cached data
	normals_.clear();
	vertices_.clear();
	triangles_.clear();

	int vertex_num, face_num;
	std::string temp;
	ifs >> temp >> vertex_num >> temp >> face_num;
	normals_.reserve(vertex_num);
	vertices_.reserve(vertex_num);
	triangles_.reserve(face_num);

	for (int i = 0; i < vertex_num; ++i)
	{
		float bar_x, bar_y, bar_z;
		ifs >> bar_x >> bar_y >> bar_z;
		vertices_.push_back(Vec3f(bar_x, bar_y, bar_z));
	}

	for (int i = 0; i < face_num; ++i)
	{
		int num_index; ifs >> num_index;
		if (num_index != 3)
		{
			std::cout << "Only triangles are supported, terminating now \n";
			exit(1);
		}
		// store information of obj file to triangle
		Triangle t;
		ifs >> t.v[0] >> t.v[1] >> t.v[2];
		for (int i = 0; i < 3; ++i) t.n[i] = t.v[i];
		triangles_.push_back(t);
	}
}

GLuint ObjFile::createModel(bool flat)
{
	glBegin(GL_TRIANGLES);

	for (vector<Triangle>::const_iterator it = triangles_.begin(); it != triangles_.end(); ++it)
	{
		for (int k = 0; k < 3; ++k)
		{
			if (flat)
			{
				Vec3f normal = (vertices_[it->v[1]] - vertices_[it->v[0]]) 
					^ (vertices_[it->v[2]] - vertices_[it->v[0]]);
				normal.normalize();
				glNormal3fv((float*)&normal);
			}
			else
			{
				glNormal3fv((float*) &normals_[it->n[k]]);
			}
			glVertex3fv((float*)&vertices_[it->v[k]]);
		}
	}

	glEnd();
	return 1;
}