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
	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 cameraDirection;
	glm::vec3 view;
	GLfloat angle[2];//0-влево-вправо 1-вверх-вниз
public:
	// конструктор по умолчанию
	Camera1(void);
	Camera1(float r, float fi, float thet);
	// деструктор ‐ сохранение новых параметров камеры
	~Camera1(void);
	// установка признаков нажатых клавиш
	void GoR(float right);
	void GoL(float right);
	void GoD(float up);
	void GoU(float up);
	// функция для установки матрицы камеры
	void apply();
	//void setPosition();
	void GoFN(float farAw);
	void SpinLR(float SLR);
	void SpinUD(float UD);
	void updateCameraVectors();
};

