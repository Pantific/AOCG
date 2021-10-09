#pragma once
#include <windows.h>
#include "GL/freeglut.h"
#include <cmath>
#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

class GraphicObject
{
private:
	// Позиция и угол поворота для объекта
	glm::vec3 position;
	GLfloat angle;
	// Матрица модели (расположение объекта) ‐ чтоб не вычислять каждый раз
	glm::mat4 modelMatrix;
	// Цвет модели
	glm::vec3 color;
public:
	// Конструктор
	GraphicObject(void);
	// Задать позицию объекта
	void setPosition(float x, float y, float z);
	// Задать угол поворота в градусах относительно оси OY
	void setAngle(float a);
	// Задать цвет модели
	void setСolor(float r, float g, float b);
	// Вывести объект
	void draw(void);
};

