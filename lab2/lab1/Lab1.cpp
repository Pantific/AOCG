#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "GL/freeglut.h"
#include <iostream>
#include"GraphicObj.h"
// функция вызывается каждые 20 мс

GraphicObject GrOb[4];


void Simulation(int value)
{
	// устанавливаем признак того, что окно нуждается в перерисовке
	glutPostRedisplay();
	// эта же функция будет вызвана еще раз через 20 мс
	glutTimerFunc(20, Simulation, 0);
}
// функция вызывается при перерисовке окна
// в том числе и принудительно, по командам glutPostRedisplay
void Display(void)
{
	// отчищаем буфер цвета
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// включаем тест глубины
	glEnable(GL_DEPTH_TEST);
	// устанавливаем камеру
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(15, 15, 7.5, 0, 0, 0, 0, 1, 0);
	for (int i = 0; i < 4; i++)
	{
		GrOb[i].draw();
	}
	// смена переднего и заднего буферов
	glutSwapBuffers();
}
// Функция обработки нажатия клавиш
void KeyboardFunc(unsigned char key, int x, int y)
{
	std::cout << "Key is " << key<<"\n";
};
void Reshape(int w, int h)
{
	// установить новую область просмотра, равную всей области окна
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	// установить матрицу проекции с правильным аспектом
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
};
int main(int argc, char* argv[])
{

	// инициализация библиотеки GLUT
	glutInit(&argc, argv);
	// инициализация дисплея (формат вывода)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	// создание окна:
// 1. устанавливаем верхний левый угол окна
	glutInitWindowPosition(200, 200);
	// 2. устанавливаем размер окна
	glutInitWindowSize(600, 600);
	// 3. создаем окно
	glutCreateWindow("laba2");
	// устанавливаем функцию, которая будет вызываться для перерисовки окна
	glutDisplayFunc(Display);
	// устанавливаем функцию, которая будет вызываться при изменении размеров окна
	glutReshapeFunc(Reshape);
	// устанавливаем функцию которая будет вызвана через 20 мс
	glutTimerFunc(20, Simulation, 0);
	// устанавливаем функцию, которая будет вызываться при нажатии на клавишу
	glutKeyboardFunc(KeyboardFunc);
	// основной цикл обработки сообщений ОС
	GrOb[0].setPosition(4.0, 0.0, 0.0);
	GrOb[0].setСolor(1.0, 0.0, 0.0);
	GrOb[0].setAngle(180);
	GrOb[1].setPosition(-4.0, 0.0, 0.0);
	GrOb[1].setСolor(1.0, 1.0, 1.0);
	GrOb[1].setAngle(0);
	GrOb[2].setPosition(0.0, 0.0, 4.0);
	GrOb[3].setPosition(0.0, 0.0, -4.0);
	GrOb[2].setAngle(90);
	GrOb[3].setAngle(-90);
	GrOb[2].setСolor(0.0, 1.0, 0.0);
	GrOb[3].setСolor(0.0, 0.0, 1.0);
	glutMainLoop();

}