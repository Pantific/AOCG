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
	float sinFi = sin(glm::radians(this->spherical.y));
	float cosFi = cos(glm::radians(this->spherical.y));
	float sinThet = sin(glm::radians(this->spherical.z));
	float cosThet = cos(glm::radians(this->spherical.z));

	this->position = glm::vec3(
		(this->spherical.x * sinThet * cosFi),
		(this->spherical.x * sinThet * sinFi),
		(this->spherical.x * cosThet)
	);
	//glMatrixMode
	//glLoadIdentity
	std::cout << position.x << " " << position.y << " " << position.z<<"\n";
	gluLookAt(position.x, position.y, position.z, 0, 0, 0, 0, 1, 0);
};

void Camera::GoLR(float right)
{ 
	spherical.y +=right;
}
void Camera::GoUD(float up)
{
	spherical.z += up;
}
