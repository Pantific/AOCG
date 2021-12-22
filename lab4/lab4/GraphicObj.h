#pragma once
#include"Header.h"
#include"PhongMaterial.h"
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
	// Используемый материал
	std::shared_ptr<PhongMaterial> material;
	//std::vector<std::shared_ptr<PhongMaterial>> materials;
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
	void recalculateModelMatrix();
	// Установка используемого материала
	void setLightMaterial(std::shared_ptr<PhongMaterial>);
};

