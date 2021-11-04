#include "Light.h"
Light::Light(glm::vec3 position)
{
	this->position = position;
	ambient = glm::vec4(1);
	diffuse = glm::vec4(1);
	specular = glm::vec4(1);
};

Light::Light() : Light(glm::vec3(0)) {};

Light::Light(float x, float y, float z) : Light(glm::vec3(x, y, z)) {  };

void Light::setPosition(glm::vec3 position)
{
	this->position = position;
}

void Light::setAmbient(glm::vec4 color)
{
	ambient = color;
}

void Light::setDiffuse(glm::vec4 color)
{
	diffuse = color;
}

void Light::setSpecular(glm::vec4 color)
{
	specular = color;
}
