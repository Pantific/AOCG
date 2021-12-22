#include "Camera.h"
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

	float sinThet = sin(glm::radians(this->spherical.y));
	float cosThet = cos(glm::radians(this->spherical.y));
	float sinFi = sin(glm::radians(this->spherical.z));
	float cosFi = cos(glm::radians(this->spherical.z));

	this->position = glm::vec3(
		(this->spherical.x * sinThet * cosFi),
		(this->spherical.x * cosThet),
		(this->spherical.x * sinThet * sinFi)
	);

	//std::cout << position.x << " " << position.y << " " << position.z<<"\n";
	std::cout << spherical.x << " " << spherical.y << " " << spherical.z << "\n";
	gluLookAt(position.x, position.y, position.z, 0, 0, 0, 0, 1, 0);
};

void Camera::GoLR(float right)
{ 
	int f=1;
	if (spherical.z > 360)
	{
		spherical.z = 0;
		f = -1;
	}
	if (spherical.z < -360)
	{
		spherical.z = 360;
		f = 1;
	}
	spherical.z +=right*f;
}
void Camera::GoUD(float up)
{
	int f = 1;
	if (spherical.y > 360)
	{
		spherical.y = 0;
		f = 1;
	}
	if (spherical.y < -180)
	{
		spherical.y = 180;
		f = -1;
	}
	spherical.y += up*f;

}
void Camera::GoFN(float farAw)
{
	spherical.x += farAw;
}
