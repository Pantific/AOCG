#pragma once

#include <Windows.h>
#include <stdio.h>

#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

#include "GLM/glm.hpp"

#include "GraphicObject.h"

class GameObject
{
public:
	GameObject();

	// ��������� ������������� ������������ �������
	void setGraphicObject(const GraphicObject& graphicObject);

	// ��������� ���������� ���������
	void setPosition(int x, int y);

	// ��������� ������� ���������� ���������
	glm::vec2 getPositon();

	// ����� �������� ������� �� �����
	void draw(void);

private:
	// ���������� ����������
	glm::vec2 position;
	// ����������� ������
	GraphicObject graphicObject;
	Mesh mesh;
};