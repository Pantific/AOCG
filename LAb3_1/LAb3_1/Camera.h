﻿#pragma once
#include <windows.h>
#include <cmath>
#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
// КЛАСС ДЛЯ РАБОТЫ С КАМЕРОЙ
class Camera
{
	// необходимые свойства
	glm::vec3 position;
	glm::vec3 spherical;
public:
	// конструктор по умолчанию
	Camera(void);
	Camera(float r, float fi, float thet);
	// деструктор ‐ сохранение новых параметров камеры
	~Camera(void);
	// установка признаков нажатых клавиш
	void GoLR(float right);
	void GoUD(float up);
	// функция для установки матрицы камеры
	void apply();
	//void setPosition();
};
