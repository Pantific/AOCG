#pragma once
#include"Header.h"
#include<fstream>
// ����� ��� ������ � ����������
class PhongMaterial
{
public:
	// ����������� �� ���������
	PhongMaterial();
	// ������� ���������� ���������
	void setAmbient(glm::vec4 color);
	void setDiffuse(glm::vec4 color);
	void setSpecular(glm::vec4 color);
	void setEmission(glm::vec4 color);
	void setShininess(float p);
	// �������� ���������� ��������� �� �������� ���������� �����
	void load(std::string filename);
	// ��������� ���� ���������� ���������
	void apply();
private:
	// ������� ������������
	glm::vec4 ambient;
	// ��������� ������������
	glm::vec4 diffuse;
	// ���������� ������������
	glm::vec4 specular;
	// ������������
	glm::vec4 emission;
	// ������� ����������������
	float shininess;
};

