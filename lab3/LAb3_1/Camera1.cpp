#include "Camera1.h"
Camera1::~Camera1()
{

};

Camera1::Camera1()
{
	cameraPos = glm::vec3(0,0,0);
	cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	view = glm::vec3(0,0,0);
	angle[0] = 0;
	angle[1] = 0;
};
Camera1::Camera1(float x, float y, float z)
{
}

/*void Camera::setPosition()
{

}*/

void Camera1::apply()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//std::cout<<cameraPos.x<<" " << cameraPos.y << " " << cameraPos.z << "\n";
	std::cout << view.x <<view.y<<" " << " " << view.z << "\n";
	gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z,view.x,view.y,view.z,0.0, 1.0, 0.0);
};

void Camera1::GoL(float right)
{
	cameraPos -= glm::normalize(glm::cross(view, glm::vec3(0.0,1.0,0.0))) * right;
	
}
void Camera1::GoR(float right)
{
	cameraPos += glm::normalize(glm::cross(view, glm::vec3(0.0, 1.0, 0.0))) * right;

}
void Camera1::GoD(float up)
{
	cameraPos -= up * view;
}
void Camera1::GoU(float up)
{
	cameraPos += up * view;
}
void Camera1::SpinUD(float farAw)
{
	angle[1] += farAw;
	view.y = cos(angle[1])*10;

}
void Camera1::SpinLR(float farAw)
{
	angle[0] += farAw;
	float x, z;
	view.x = sin(angle[0])*100;
	view.z =cos(angle[0])*100;

}
/*void Camera1::updateCameraVectors()
{
	// Calculate the new Front vector
	glm::vec3 front;
	front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
	front.y = sin(glm::radians(this->Pitch));
	front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
	this->view = glm::normalize(front);
	// Also re-calculate the Right and Up vector
	this->Right = glm::normalize(glm::cross(this->Front, this->WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	this->Up = glm::normalize(glm::cross(this->Right, this->Front));
}*/

