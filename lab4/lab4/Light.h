#pragma once
#include <windows.h>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include "GL/freeglut.h"
#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include<iostream>
// ����� ��� ������ � ���������� �����
class Light
{
public:
	// ������������
	Light();
	Light(glm::vec3 position);
	Light(float x, float y, float z);
	// ������� ��������� ���������� ��������� �����
	void setPosition(glm::vec3 position);
	void setAmbient(glm::vec4 color);
	void setDiffuse(glm::vec4 color);
	void setSpecular(glm::vec4 color);
	// ��������� ���� ���������� ��������� ����� � �������� �������
	// ������ ������� ������ ���������� ����� ��������� ������,
	// �.�. ����� ��������������� ������� ��������� �����
	void apply(GLenum LightNumber = GL_LIGHT0);
private:
	// ������� ��������� �����
	glm::vec3 position;
	// ������� ������������ ��������� �����
	glm::vec4 ambient;
	// ��������� ������������
	glm::vec4 diffuse;
	// ���������� ������������
	glm::vec4 specular;
};

