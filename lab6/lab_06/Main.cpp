#include <Windows.h>
#include <stdio.h>

#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>

#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>

#include "GraphicObject.h"
#include "Camera.h"

#include "Light.h"
#include "Material.h"

#include "Mesh.h"
#include "GameObject.h"

#include "GameObjectFactory.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "rapidjson-master/include/rapidjson/rapidjson.h"

// ������� ��������� ������� ������
void KeyboardFunc(unsigned char key, int x, int y)
{
	// printf("Key code is %i\n", (unsigned int)key);
};

LARGE_INTEGER newTick;
LARGE_INTEGER oldTick;
LARGE_INTEGER freq;

LARGE_INTEGER newSimTick;
LARGE_INTEGER oldSimTick;


Camera camera(45, 35, 45);
Light light(25.0f, 25.0f, 0.0f);
GraphicObject gr[25];

GameObjectFactory gameObjectFactory;

GameObject gm[21][21];

GameObject plane;

const GLfloat SIZE_ = 1.0f;

std::shared_ptr <GameObject> mapObjects[21][21];
std::shared_ptr <GameObject> player;

int passabilityMap[21][21] = {
 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
 3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,0,3,
 3,0,2,1,2,0,2,0,2,2,2,1,2,0,2,0,2,0,2,2,3,
 3,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,1,0,0,0,3,
 3,0,1,0,2,2,1,2,2,0,2,0,2,2,2,1,2,0,2,0,3,
 3,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,2,0,3,
 3,0,2,2,1,1,2,0,2,0,2,2,2,2,2,0,2,2,2,0,3,
 3,0,2,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,0,3,
 3,0,2,0,2,2,2,0,2,0,2,2,1,2,2,2,1,2,2,0,3,
 3,0,0,0,2,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,3,
 3,2,2,2,2,0,2,2,2,0,2,0,2,2,2,2,2,2,2,0,3,
 3,0,0,0,2,0,0,0,1,0,2,0,0,0,2,0,0,0,0,0,3,
 3,0,2,0,2,2,2,0,2,1,2,0,2,2,2,0,2,2,2,2,3,
 3,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,2,0,0,0,3,
 3,2,2,2,2,0,2,2,2,0,2,2,2,0,1,0,2,2,2,0,3,
 3,0,0,0,0,0,2,0,2,0,0,0,2,0,1,0,0,0,2,0,3,
 3,0,2,0,2,1,2,0,2,0,2,2,2,0,2,2,2,0,2,0,3,
 3,0,1,0,1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,3,
 3,0,2,1,2,0,2,2,2,2,2,0,2,0,2,0,2,2,2,2,3,
 3,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,3,
 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
};

double getSimulationTime()
{
	oldSimTick = newSimTick;
	QueryPerformanceCounter(&newSimTick);
	return (double(newSimTick.QuadPart - oldSimTick.QuadPart)) / freq.QuadPart;
}


float fpsCount = 0;

void outputFramesPerSecond()
{
	QueryPerformanceCounter(&newTick);

	double delta = double(newTick.QuadPart - oldTick.QuadPart) / freq.QuadPart;
	std::string msg;
	if (delta >= 1.0)
	{
		msg += "FPS: ";
		msg += std::to_string((double)fpsCount / delta);
		const char* ch = msg.c_str();
		glutSetWindowTitle(ch);
		fpsCount = 0;
		oldTick = newTick;
	}

}

// ������� ���������� ��� ����������� ����
// � ��� ����� � �������������, �� �������� glutPostRedisplay
void Display(void)
{
	QueryPerformanceCounter(&newTick);
	// ������������� ������ 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	camera.apply();
	camera.updateCoords();

	light.apply();
	
	// �������� ����� ����� 
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// �������� ���� �������  	
	glEnable(GL_DEPTH_TEST);

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (mapObjects[i][j].get() != nullptr)
			{
				mapObjects[i][j].get()->draw();
			}
		}
	}

	plane.draw();
	player.get()->draw();

	// std::cout << mapObjects[0][0];

	// ����� ��������� � ������� ������� 
	glutSwapBuffers();
	outputFramesPerSecond();

	fpsCount++;
};

// �������, ���������� ��� ��������� �������� ����
void Reshape(int w, int h)
{
	// ���������� ����� ������� ���������, ������ ���� ������� ����
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	// ���������� ������� �������� � ���������� ��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
};

// ������� ���������� ������ 20 ��
void Simulation()
{
	double deltaTime = getSimulationTime();

	if (GetAsyncKeyState(VK_LEFT))
	{
		camera.leftRight(getSimulationTime(), 0);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		camera.leftRight(getSimulationTime(), 1);
	}
	if (GetAsyncKeyState(VK_UP))
	{
		camera.upDown(getSimulationTime(), 0);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		camera.upDown(getSimulationTime(), 1);
	}
	if (GetAsyncKeyState(VK_ADD))
	{
		camera.zoomInOut(getSimulationTime(), 0);
	}
	if (GetAsyncKeyState(VK_SUBTRACT))
	{
		camera.zoomInOut(getSimulationTime(), 1);
	}

	glutPostRedisplay();
};

void initData()
{
	gameObjectFactory.init("data/GameObjectsDescription.json");

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			switch (passabilityMap[i][j])
			{
			case 1:
				mapObjects[i][j] = gameObjectFactory.create(GameObjectType::LIGHT_OBJECT, i - 10, j - 10);
				break;
			case 2:
				mapObjects[i][j] = gameObjectFactory.create(GameObjectType::HEAVY_OBJECT, i - 10, j - 10);
				break;
			case 3:
				mapObjects[i][j] = gameObjectFactory.create(GameObjectType::BORDER_OBJECT, i - 10, j - 10);
				break;
			default:
				mapObjects[i][j] = nullptr;
				break;
			}
		}
	}

	player = gameObjectFactory.create(GameObjectType::PLAYER, 9, -9);

	GraphicObject gr(0, -0.6, 0, 0, 0, 0, 0);
	std::shared_ptr <Mesh> planeMesh = std::make_shared<Mesh>();
	planeMesh.get()->load("data\\meshes\\HighPolyPlane.obj");
	std::shared_ptr <PhongMaterial> planeMaterial = std::make_shared<PhongMaterial>();
	planeMaterial.get()->load("data\\materials\\PlaneMaterial.txt");
	gr.setMaterial(planeMaterial);
	gr.setMesh(planeMesh);
	plane.setGraphicObject(gr);
}


int main(int argc, char** argv)
{
	light.setAmbient(glm::vec4(1.0f, 1.0f, 1.0f, 0.0f));
	light.setDiffuse(glm::vec4(1.0f, 1.0f, 1.0f, 0.0f));
	light.setSpecular(glm::vec4(1.0f, 1.0f, 1.0f, 0.0f));
	initData();
	
	// ������������� ���������� GLUT
	glutInit(&argc, argv);
	QueryPerformanceFrequency(&freq);
	// �������� ����:
	// 1. ������������� ������� ����� ���� ����
	glutInitWindowPosition(200, 200);
	// 2. ������������� ������ ����
	glutInitWindowSize(600, 600);
	// 3. ������� ����
	glutCreateWindow("LR-1");
	glColor3f(1.0, 0.0, 0.0);
	// ������������� �������, ������� ����� ���������� ��� ����������� ����
	glutDisplayFunc(Display);
	// ������������� �������, ������� ����� ���������� ��� ��������� �������� ����n
	glutReshapeFunc(Reshape);
	// ������������� ������� ������� ����� ������� ����� 20 ��
	// ������������� �������, ������� ����� ���������� ��� ������� �� �������
	glutKeyboardFunc(KeyboardFunc);
	// �������� ���� ��������� ���������� ��
	glutIdleFunc(Simulation);

	QueryPerformanceCounter(&newTick);
	QueryPerformanceFrequency(&freq);
	newSimTick = newTick;
	glutMainLoop();
}