#pragma once
#include <windows.h>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include "GL/freeglut.h"
#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include<iostream>
class Camera1
{

	// необходимые свойства
	glm::vec3 position;
public:
	// конструктор по умолчанию
	Camera1(void);
	Camera1(float r, float fi, float thet);
	// деструктор ‐ сохранение новых параметров камеры
	~Camera1(void);
	// установка признаков нажатых клавиш
	void GoLR(float right);
	void GoUD(float up);
	// функция для установки матрицы камеры
	void apply();
	//void setPosition();
};

