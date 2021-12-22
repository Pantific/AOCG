#pragma once
#include <Windows.h>
#include<iostream>
#include "glew-2.2.0/include/GL/glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "Il\il.h"
#include "Il\ilu.h"
#include "Il\ilut.h"

// ������������ ��� ����������� ������ ����������
enum class TextureFilter {
	POINT, // ��������
	BILINEAR, // ����������
	TRILINEAR, // �����������
	ANISOTROPIC // ������������
};

class Texture
{
public:
	// �������� �������� �� �������� �����
	void load(std::string filename);
	// ���������� �������� (�������� � ����������� ����� � ��������� ����������)
	void apply();
	// ���������� ��������������� ��� ���� ���������� ������
	static void disableAll();
private:
	// ������������� (������) ����������� �������
	GLuint texIndex;
};

