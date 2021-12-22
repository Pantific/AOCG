#pragma once
#include"Header.h"
// КЛАСС ДЛЯ РАБОТЫ С КАМЕРОЙ
//x=r y=theta z=fi
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
	void GoFN(float farAw);
};

