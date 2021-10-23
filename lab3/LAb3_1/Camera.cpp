#include "Camera.h"
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include "GL/freeglut.h"
#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include<iostream>

Camera::~Camera()
{

};

Camera::Camera()
{
	this->spherical = glm::vec3(20, 20, 20);
}
Camera::Camera(float r, float fi, float thet)
{
	this->spherical = glm::vec3(r, fi, thet);
}

/*void Camera::setPosition()
{

}*/

void Camera::apply()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float sinFi = sin(glm::radians(this->spherical.y));
	float cosFi = cos(glm::radians(this->spherical.y));
	float sinThet = sin(glm::radians(this->spherical.z));
	float cosThet = cos(glm::radians(this->spherical.z));

	this->position = glm::vec3(
		(this->spherical.x * sinThet * cosFi),
		(this->spherical.x * sinThet * sinFi),
		(this->spherical.x * cosThet)
	);

	std::cout << position.x << " " << position.y << " " << position.z<<"\n";
	//std::cout << spherical.x << " " << spherical.y << " " << spherical.z << "\n";
	gluLookAt(position.x, position.y, position.z, 0, 0, 0, 0, 1, 0);
};

void Camera::GoLR(float right)
{ 
	int F = 1;
	if (spherical.z <0)
	{
		spherical.z = 180;
		F = 1;
	}
	if (spherical.z > 180)
	{
		spherical.x = 0;
		F = -1;
	}
	spherical.z +=right*F;

}
void Camera::GoUD(float up)
{
	int F = 1;
	if (spherical.z < -90)
	{
		spherical.z = 90;
		F = 1;
	}
	if (spherical.z > 90)
	{
		spherical.x = -90;
		F = -1;
	}
	spherical.y += up*F;

}
void Camera::GoFN(float farAw)
{
	spherical.x += farAw;
}
