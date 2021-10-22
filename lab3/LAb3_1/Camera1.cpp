#include "Camera1.h"
Camera1::~Camera1()
{

};

Camera1::Camera1()
{
	this->position = glm::vec3(20, 20, 20);
}
Camera1::Camera1(float x, float y, float z)
{
	this->position = glm::vec3(x, y, z);
}

/*void Camera::setPosition()
{

}*/

void Camera1::apply()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(position.x, position.y, position.z, 0, 0, 0, 0, 1, 0);
};

void Camera1::GoLR(float right)
{
	position.z += right;

}
void Camera1::GoUD(float up)
{
	position.y += up;

}

