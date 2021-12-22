#pragma once
#include"Header.h"
// КЛАСС ДЛЯ РАБОТЫ С ИСТОЧНИКОМ СВЕТА
class Light
{
public:
	// конструкторы
	Light();
	Light(glm::vec3 position);
	Light(float x, float y, float z);
	// задание различных параметров источника света
	void setPosition(glm::vec3 position);
	void setAmbient(glm::vec4 color);
	void setDiffuse(glm::vec4 color);
	void setSpecular(glm::vec4 color);
	// установка всех параметров источника света с заданным номером
	// данная функция должна вызываться после установки камеры,
	// т.к. здесь устанавливается позиция источника света
	void apply(GLenum LightNumber = GL_LIGHT0);
private:
	// позиция источника света
	glm::vec3 position;
	// фоновая составляющая источника света
	glm::vec4 ambient;
	// диффузная составляющая
	glm::vec4 diffuse;
	// зеркальная составляющая
	glm::vec4 specular;
};

