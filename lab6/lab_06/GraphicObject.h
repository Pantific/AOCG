﻿#pragma once

#include <Windows.h>
#include <stdio.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

#include <iostream>
#include "Material.h"
#include "Mesh.h"

// КЛАСС ДЛЯ ПРЕДСТАВЛЕНИЯ ОДНОГО ГРАФИЧЕСКОГО ОБЪЕКТА 
class GraphicObject
{
public:
	// Матрица модели (расположение объекта) ‐ чтоб не вычислять каждый раз  	Glfloat modelMatrix[16]; 
	// Цвет модели  	Glfloat color[3]; public: 
	// Конструктор 
	GraphicObject();
	GraphicObject(float x, float y, float z, float a, float r, float g, float b);
	// Задать позицию объекта 
	void setPosition(float x, float y, float z);
	// Задать угол поворота в градусах относительно оси OY 
	void setAngle(float a);
	// Задать цвет модели 
	void setСolor(float r, float g, float b);
	// Задать путь файла
	void setPath(std::string path);
	// Вывести объект 
	void draw();
	// Установить используемый материал
	void setMaterial(std::shared_ptr <PhongMaterial> material);
	// Установить используемый меш
	void setMesh(std::shared_ptr <Mesh> mesh);
private:
	// Позиция и угол поворота для объекта  
	GLfloat position[3];
	GLfloat angle;
	GLfloat M[16];
	GLfloat	color[3];

	std::string path;
	std::shared_ptr <PhongMaterial> material;
	std::shared_ptr <Mesh> mesh;
};
