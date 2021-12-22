#include "PhongMaterial.h"

PhongMaterial::PhongMaterial()
{

};

void PhongMaterial::setAmbient(glm::vec4 color)
{
	this->ambient = color;
}

void PhongMaterial::setDiffuse(glm::vec4 color)
{
	this->diffuse = color;
}

void PhongMaterial::setSpecular(glm::vec4 color)
{
	this->specular = color;
}

void PhongMaterial::setEmission(glm::vec4 color)
{
	this->emission = color;
}

void  PhongMaterial::setShininess(float p)
{
	this->shininess = p;
}
void PhongMaterial::load(std::string fileName)
{
	double a;
	std::ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		std::cout << "File not open\n";
	}
	else
	{
		double buf[4];
		std::string str;
		fin >> str;
		for (int i = 0; i < 4; i++)
		{
			fin>>buf[i];
		}
		this->setDiffuse(glm::vec4(buf[0],buf[1],buf[2],buf[3]));
		fin >> str;
		for (int i = 0; i < 4; i++)
		{
			fin >> buf[i];
		}
		this->setAmbient(glm::vec4(buf[0], buf[1], buf[2], buf[3]));
		fin >> str;
		for (int i = 0; i < 4; i++)
		{
			fin >> buf[i];
		}
		this->setSpecular(glm::vec4(buf[0], buf[1], buf[2], buf[3]));
		fin >> str;
		for (int i = 0; i < 4; i++)
		{
			fin >> buf[i];
		}
		this->setEmission(glm::vec4(buf[0], buf[1], buf[2], buf[3]));
		fin >> str;
		fin >> buf[0];
		this->setShininess(buf[0]);
	}
	fin.close();
}
void PhongMaterial::apply()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, (GLfloat*)&ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, (GLfloat*)&diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat*)&specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, (GLfloat*)&emission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, (GLfloat*)&shininess);
}