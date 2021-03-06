#include"Header.h"
#include"GraphicObj.h"
#include"Light.h"
#include"PhongMaterial.h"
#include"Camera.h"
// функция вызывается каждые 20 мс
LARGE_INTEGER oldValue, newValue;
GraphicObject GrOb[4];
Camera camera(22.5,45.0,70.52);
float sec=0;
float secLR = 0;
float secUD = 0;
float secFN = 0;
std::shared_ptr<PhongMaterial>materials[4];
Light light;
float Fr()
{
	QueryPerformanceCounter(&newValue);
	float Simulation_Time_Passed = (QueryPerformanceFrequency(&oldValue) - QueryPerformanceFrequency(&newValue)) / QueryPerformanceFrequency(&newValue);
	//return Simulation_Time_Passed;
	return 0.17;
}
void Simulation()
{
	sec = Fr();
	// ПЕРЕМЕЩЕНИЕ КАМЕРЫ
	bool CameraLeft = GetAsyncKeyState(VK_LEFT);
	bool CameraRight = GetAsyncKeyState(VK_RIGHT);
	bool CameraUp = GetAsyncKeyState(VK_UP);
	bool CameraDown = GetAsyncKeyState(VK_DOWN);
	bool CameraForward = GetAsyncKeyState(VK_ADD);
	bool CameraBackward = GetAsyncKeyState(VK_SUBTRACT);
		if (CameraLeft == 1)
		{
			secLR = sec * (-1);
			std::cout << "L\n";
			camera.GoLR(secLR);
		}
		if (CameraRight == 1)
		{
			secLR = sec;
			std::cout << "R\n";
			camera.GoLR(secLR);
		}
		if (CameraDown == 1)
		{
			secUD = sec * (-1);
			std::cout << "D\n";
			camera.GoUD(secUD);
		}
		if (CameraUp == 1)
		{
			secUD = sec;
			std::cout << "U\n";
			camera.GoUD(secUD);
		}
		if (CameraBackward == 1)
		{
			secFN = sec * (-1);
			std::cout << "Add\n";
			camera.GoFN(secFN);
		}
		if (CameraForward == 1)
		{
			secFN = sec;
			std::cout << "Far\n";
			camera.GoFN(secFN);
		}
		// ПЕРЕРИСОВАТЬ ОКНО
	glutPostRedisplay();
}
// функция вызывается при перерисовке окна
// в том числе и принудительно, по командам glutPostRedisplay
void Display(void)
{
	QueryPerformanceCounter(&oldValue);
	// отчищаем буфер цвета
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// включаем тест глубины
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// включаем режим расчета освещения
	glEnable(GL_LIGHTING);	
	// устанавливаем камеру
	camera.apply();
	light.apply(GL_LIGHT0);
	for (int i = 0; i < 4; i++)
	{
		GrOb[i].draw();
	}
	glDisable(GL_LIGHTING);
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
	// функция, которая вызывается постояно
	glutIdleFunc(Simulation);
	// устанавливаем функцию, которая будет вызываться при нажатии на клавишу
	glutKeyboardFunc(KeyboardFunc);
	// основной цикл обработки сообщений ОС
// задание всех параметров одного материала
	GrOb[0].setPosition(4.0, 0.0, 0.0);
	GrOb[0].setСolor(1.0, 0.0, 0.0);
	GrOb[0].setAngle(180);
	GrOb[1].setPosition(-4.0, 0.0, 0.0);
	GrOb[1].setСolor(1.0, 1.0, 1.0);
	GrOb[1].setAngle(0);
	GrOb[2].setPosition(0.0, 0.0, 4.0);
	GrOb[3].setPosition(0.0, 0.0, -4.0);
	GrOb[2].setAngle(-90);
	GrOb[3].setAngle(90);
	GrOb[2].setСolor(0.0, 1.0, 0.0);
	GrOb[3].setСolor(0.0, 0.0, 1.0);
	std::shared_ptr<PhongMaterial>mat =std::make_shared<PhongMaterial>();
	for (int i = 0; i < 4; i++)
	{
		materials[i] = std::make_shared<PhongMaterial>();
	}
	materials[0]->load("Color\\material_1.txt");
	materials[1]->load("Color\\material_2.txt");
	materials[2]->load("Color\\material_3.txt");
	materials[3]->load("Color\\material_4.txt");
	for (int i = 0; i < 4; i++)
	{
		GrOb[i].setLightMaterial(materials[i]);
	}
	light.setAmbient(glm::vec4(0.5, 1.0, 1.0, 1.0));
	light.setPosition(glm::vec4(1.0, 1.0, 1.0, 1.0));
	light.setDiffuse(glm::vec4(0.75, 0.75, 0.75, 1.0));
	light.setSpecular(glm::vec4(0.5, 0.5, 0.5, 1.0));
	QueryPerformanceCounter(&oldValue);
	glutMainLoop();

}