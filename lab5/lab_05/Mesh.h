#pragma once

#include <Windows.h>
#include <stdio.h>

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

struct Vertex
{
	Vertex();

	// �������������� ����������
	GLfloat coord[3];
	// ������ �������
	GLfloat normal[3];
	// ���������� ���������� �������� ����������� ����� 
	GLfloat texturCoord[3];
};

class Mesh
{
public:
	Mesh();
	void load(std::string filename);
	void draw();

private:
	std::vector <Vertex> vertices;
};