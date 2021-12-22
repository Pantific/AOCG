#pragma once
#include <Windows.h>
#include<iostream>
#include "glew-2.2.0/include/GL/glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "Il\il.h"
#include "Il\ilu.h"
#include "Il\ilut.h"

// ПЕРЕЧИСЛЕНИЕ ДЛЯ ОПРЕДЕЛЕНИЯ РЕЖИМА ФИЛЬТРАЦИИ
enum class TextureFilter {
	POINT, // ТОЧЕЧНАЯ
	BILINEAR, // БИЛИНЕЙНАЯ
	TRILINEAR, // ТРИЛИНЕЙНАЯ
	ANISOTROPIC // АНИЗТОРОПНАЯ
};

class Texture
{
public:
	// загрузка текстуры из внешнего файла
	void load(std::string filename);
	// применение текстуры (привзяка к текстурному блоку и установка параметров)
	void apply();
	// отключение текстурирования для всех текстурных блоков
	static void disableAll();
private:
	// идентификатор (индекс) текстурного объекта
	GLuint texIndex;
};

