#include "GraphicObj.h"
GraphicObject::GraphicObject(void)
{
};
void GraphicObject::setPosition(float x, float y, float z)
{ 
	position = glm::vec3(x, y, z);
};
void GraphicObject::setAngle(float a)
{
	angle = a;
};
void GraphicObject::setÑolor(float r, float g, float b)
{
	color = glm::vec3(r, g, b);
};
void GraphicObject::draw(void)
{
	glPushMatrix();
	glColor3fv(glm::value_ptr(color));
	//glTranslatef(position[0], position[1], position[2]);
	//glRotatef(angle,0.0,1.0,0.0);
	this->modelMatrix = glm::translate(position) * glm::rotate(glm::radians(angle), glm::vec3(0.0, 1.0, 0.0));
	glMultMatrixf(glm::value_ptr(this->modelMatrix));
	glutWireTeapot(1);
	glPopMatrix();
};

