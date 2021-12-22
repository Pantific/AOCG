#include "GraphicObj.h"
GraphicObject::GraphicObject()
{
	this->color = glm::vec3(1, 1, 1);
	this->angle = 0;
	this->modelMatrix = glm::mat4(0);
	this->position = glm::vec3(0, 0, 0);
};
void GraphicObject::setPosition(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
	recalculateModelMatrix();
};
void GraphicObject::setAngle(float a)
{
	angle = a;
	recalculateModelMatrix();
};
void GraphicObject::setСolor(float r, float g, float b)
{
	color = glm::vec3(r, g, b);
};
void GraphicObject::draw(void)
{
	glPushMatrix();
	glColor3fv(glm::value_ptr(color));
	//glTranslatef(position[0], position[1], position[2]);
	//glRotatef(angle,0.0,1.0,0.0);
	//this->modelMatrix = glm::translate(position) * glm::rotate(glm::radians(angle), glm::vec3(0.0, 1.0, 0.0));
	if (material != nullptr) {
		material->apply();
	}
	glMultMatrixf(glm::value_ptr(this->modelMatrix));
	glutSolidTeapot(1);
	glPopMatrix();
};

void GraphicObject::recalculateModelMatrix()
{
	modelMatrix[0][0] = cos(glm::radians(angle));
	modelMatrix[0][1] = 0;
	modelMatrix[0][2] = sin(glm::radians(angle));
	modelMatrix[0][3] = 0;

	modelMatrix[1][0] = 0;
	modelMatrix[1][1] = 1;
	modelMatrix[1][2] = 0;
	modelMatrix[1][3] = 0;

	modelMatrix[2][0] = -sin(glm::radians(angle));
	modelMatrix[2][1] = 0;
	modelMatrix[2][2] = cos(glm::radians(angle));
	modelMatrix[2][3] = 0;

	modelMatrix[3][0] = position[0];
	modelMatrix[3][1] = position[1];
	modelMatrix[3][2] = position[2];
	modelMatrix[3][3] = 1;
}

void GraphicObject::setLightMaterial(std::shared_ptr<PhongMaterial> mt) {
	this->material = mt;
}

