#pragma once

#include <Windows.h>
#include <stdio.h>

#include "glew-2.2.0/include/GL/glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

#include "GLM/glm.hpp"

#include "GraphicObject.h"

extern int passabilityMap[21][21];



enum class MoveDirection { STOP, LEFT, RIGHT, UP, DOWN };

class GameObject
{
public:
	GameObject();
	glm::vec3 getPosition3d();
	// ��������� ������������� ������������ �������
	void setGraphicObject(const GraphicObject& graphicObject);

	// ��������� ���������� ���������
	void setPosition(int x, int y);

	// ��������� ������� ���������� ���������
	glm::vec2 getPositon();

	void setPrevState(MoveDirection);

	// ����� �������� ������� �� �����
	void draw(void);

	// ������ �������� � ��������� ����������� � ��������� ��������� 
	// �������� ������������ ������������ ����������� ������ � �������
	void move(MoveDirection direction, float speed = 3.0f);

	// ��������� �������� ������� (������� ����������� �������)
	// ����� ���������� ���������� � ������� simulation
	void simulate(float sec);

	// �������� �� ��, ��� ������ � ��������� ������ ��������
	bool isMoving();

	MoveDirection getPrevState();

private:
	// ���������� ����������
	glm::vec2 position;
	// ����������� ������
	GraphicObject graphicObject;
	// ��������� ������� (�������� ����������� �����������)
	MoveDirection state;
	// �������� � ����������� (�� 0.0 �� 1.0)
	float progress;
	// �������� �����������
	float speed;
	MoveDirection prevState;
};