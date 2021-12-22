#include "Simulation.h"
#include <random>
// получение времени симуляции в секундах
float getSimulationTime()
{
	oldSimTick = newSimTick;
	QueryPerformanceCounter(&newSimTick);
	return (float(newSimTick.QuadPart - oldSimTick.QuadPart)) / frequency.QuadPart;
}

// симуляция камеры
void cameraSimulation(float simulationTime)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		camera.leftRight(simulationTime, 0);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		camera.leftRight(simulationTime, 1);
	}
	if (GetAsyncKeyState(VK_UP))
	{
		camera.upDown(simulationTime, 0);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		camera.upDown(simulationTime, 1);
	}
	if (GetAsyncKeyState(VK_ADD))
	{
		camera.zoomInOut(simulationTime, 0);
	}
	if (GetAsyncKeyState(VK_SUBTRACT))
	{
		camera.zoomInOut(simulationTime, 1);
	}
}

void gameObjectSimulation(float simulationTime)
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (mapObjects[i][j] != nullptr)
			{
				mapObjects[i][j].get()->simulate(simulationTime);
			}
		}
	}

	player.get()->simulate(simulationTime);
}

void movePlayer()
{
	if (GetAsyncKeyState(65) && !player.get()->isMoving() && passabilityMap[int(player.get()->getPositon().x - 1)][int(player.get()->getPositon().y)] == 0)
	{
		//std::cout << player.get()->getPositon().x << std::endl;
		player.get()->move(MoveDirection::LEFT, 1.0f);
	}
	if (GetAsyncKeyState(65) && !player.get()->isMoving() && passabilityMap[int(player.get()->getPositon().x - 1)][int(player.get()->getPositon().y)] == 1
		&& passabilityMap[int(player.get()->getPositon().x - 2)][int(player.get()->getPositon().y)] == 0)
	{
		player.get()->move(MoveDirection::LEFT, 1.0f);
		mapObjects[int(player.get()->getPositon().x - 1)][int(player.get()->getPositon().y)].get()->move(MoveDirection::LEFT, 1.0f);
		mapObjects[int(player.get()->getPositon().x - 2)][int(player.get()->getPositon().y)] = mapObjects[int(player.get()->getPositon().x - 1)][int(player.get()->getPositon().y)];
		mapObjects[int(player.get()->getPositon().x - 1)][int(player.get()->getPositon().y)] = nullptr;
		passabilityMap[int(player.get()->getPositon().x - 1)][int(player.get()->getPositon().y)] = 0;
		passabilityMap[int(player.get()->getPositon().x - 2)][int(player.get()->getPositon().y)] = 1;
	}


	if (GetAsyncKeyState(68) && !player.get()->isMoving() && passabilityMap[int(player.get()->getPositon().x + 1)][int(player.get()->getPositon().y)] == 0)
	{
		//std::cout << player.get()->getPositon().x << std::endl;
		player.get()->move(MoveDirection::RIGHT, 1.0f);
	}
	if (GetAsyncKeyState(68) && !player.get()->isMoving() && passabilityMap[int(player.get()->getPositon().x + 1)][int(player.get()->getPositon().y)] == 1
		&& passabilityMap[int(player.get()->getPositon().x + 2)][int(player.get()->getPositon().y)] == 0)
	{
		player.get()->move(MoveDirection::RIGHT, 1.0f);
		mapObjects[int(player.get()->getPositon().x + 1)][int(player.get()->getPositon().y)].get()->move(MoveDirection::RIGHT, 1.0f);
		mapObjects[int(player.get()->getPositon().x + 2)][int(player.get()->getPositon().y)] = mapObjects[int(player.get()->getPositon().x + 1)][int(player.get()->getPositon().y)];
		mapObjects[int(player.get()->getPositon().x + 1)][int(player.get()->getPositon().y)] = nullptr;
		passabilityMap[int(player.get()->getPositon().x + 1)][int(player.get()->getPositon().y)] = 0;
		passabilityMap[int(player.get()->getPositon().x + 2)][int(player.get()->getPositon().y)] = 1;
	}


	if (GetAsyncKeyState(87) && !player.get()->isMoving() && passabilityMap[int(player.get()->getPositon().x)][int(player.get()->getPositon().y - 1)] == 0)
	{
		//std::cout << player.get()->getPositon().x << std::endl;
		player.get()->move(MoveDirection::UP, 1.0f);
	}
	if (GetAsyncKeyState(87) && !player.get()->isMoving() && passabilityMap[int(player.get()->getPositon().x)][int(player.get()->getPositon().y - 1)] == 1
		&& passabilityMap[int(player.get()->getPositon().x)][int(player.get()->getPositon().y - 2)] == 0)
	{
		player.get()->move(MoveDirection::UP, 1.0f);
		mapObjects[int(player.get()->getPositon().x)][int(player.get()->getPositon().y - 1)].get()->move(MoveDirection::UP, 1.0f);
		mapObjects[int(player.get()->getPositon().x)][int(player.get()->getPositon().y - 2)] = mapObjects[int(player.get()->getPositon().x)][int(player.get()->getPositon().y - 1)];
		mapObjects[int(player.get()->getPositon().x)][int(player.get()->getPositon().y - 1)] = nullptr;
		passabilityMap[int(player.get()->getPositon().x)][int(player.get()->getPositon().y - 1)] = 0;
		passabilityMap[int(player.get()->getPositon().x)][int(player.get()->getPositon().y - 2)] = 1;
	}


	if (GetAsyncKeyState(83) && !player.get()->isMoving() && passabilityMap[int(player.get()->getPositon().x)][int(player.get()->getPositon().y + 1)] == 0)
	{
		//std::cout << player.get()->getPositon().x << std::endl;
		player.get()->move(MoveDirection::DOWN, 1.0f);
	}
	if (GetAsyncKeyState(83) && !player.get()->isMoving() && passabilityMap[int(player.get()->getPositon().x)][int(player.get()->getPositon().y + 1)] == 1
		&& passabilityMap[int(player.get()->getPositon().x)][int(player.get()->getPositon().y + 2)] == 0)
	{
		player.get()->move(MoveDirection::DOWN, 1.0f);
		mapObjects[int(player.get()->getPositon().x)][int(player.get()->getPositon().y + 1)].get()->move(MoveDirection::DOWN, 1.0f);
		mapObjects[int(player.get()->getPositon().x)][int(player.get()->getPositon().y + 2)] = mapObjects[int(player.get()->getPositon().x)][int(player.get()->getPositon().y + 1)];
		mapObjects[int(player.get()->getPositon().x)][int(player.get()->getPositon().y + 1)] = nullptr;
		passabilityMap[int(player.get()->getPositon().x)][int(player.get()->getPositon().y + 1)] = 0;
		passabilityMap[int(player.get()->getPositon().x)][int(player.get()->getPositon().y + 2)] = 1;
	}


}

void simulation()
{
	// определение времени симуляции
	float simulationTime = getSimulationTime();

	// симуляция камеры
	cameraSimulation(simulationTime);

	// симуляция всех игровых объектов (их плавное перемещение)
	gameObjectSimulation(simulationTime);

	// симуляция монстров
	//monstersSimulation(simulationTime);

	// перемещение главного героя
	movePlayer();

	// перемещение источников света
	//lightMoving();

	// устанавливаем признак того, что окно нуждается в перерисовке
	glutPostRedisplay();
}
inline glm::ivec2 getOffset(MoveDirection dir) {
	glm::ivec2 offset = glm::ivec2(0.0, 0.0);
	switch (dir) {
	case MoveDirection::UP: {
		offset.x = -1;
		offset.y = 0;
	}; break;
	case MoveDirection::DOWN: {
		offset.x = 1;
		offset.y = 0;
	}; break;
	case MoveDirection::LEFT: {
		offset.x = 0;
		offset.y = -1;
	}; break;
	case MoveDirection::RIGHT: {
		offset.x = 0;
		offset.y = 1;
	}; break;
	}
	return offset;
}
inline MoveDirection getDir(glm::ivec2 offset) {
	MoveDirection dir = MoveDirection::STOP;
	if (offset == glm::ivec2(-1, 0))
		dir = MoveDirection::UP;
	else if (offset == glm::ivec2(1, 0))
		dir = MoveDirection::DOWN;
	else if (offset == glm::ivec2(0, -1))
		dir = MoveDirection::LEFT;
	else if (offset == glm::ivec2(0, 1))
		dir = MoveDirection::RIGHT;
	return dir;
}

inline std::vector<MoveDirection> getPossibleDirs(std::vector<MoveDirection>& wrongDirs) {
	std::vector<MoveDirection> possibleDirs;
	for (int i = 1; i <= 4; i++)
		if (std::find(wrongDirs.begin(), wrongDirs.end(), static_cast<MoveDirection>(i)) == wrongDirs.end())
			possibleDirs.push_back(static_cast<MoveDirection>(i));
	return possibleDirs;
}
inline void moveMonster(std::shared_ptr<GameObject>& monsterObj, std::mt19937& mersenneRand) {
	if (!monsterObj->isMoving() && monsterObj != nullptr) {
		glm::ivec2 offset;
		glm::ivec3 position = monsterObj->getPosition3d();
		MoveDirection dir;
		if (monsterObj->getPrevState() != MoveDirection::STOP) {
			dir = monsterObj->getPrevState();
			offset = getOffset(dir);
		}
		else {
			dir = static_cast<MoveDirection>(mersenneRand() % 4 + 1);
			offset = getOffset(dir);
		}
		if (monsterObj->getPrevState() != MoveDirection::STOP) {
			if (passabilityMap[position.x + offset.x][position.z + offset.y] == static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x + offset.y][position.z + offset.x] == static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x - offset.y][position.z - offset.x] == static_cast<int>(GameObjectType1::EMPTY)) {
				std::vector<MoveDirection> possibleDirs;
				std::vector<MoveDirection> wrongDirs = { getDir(glm::ivec2(-offset.x,-offset.y)) };
				possibleDirs = getPossibleDirs(wrongDirs);
				dir = possibleDirs[mersenneRand() % 3];
			}
			else if (passabilityMap[position.x + offset.x][position.z + offset.y] == static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x + offset.y][position.z + offset.x] == static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x - offset.y][position.z - offset.x] != static_cast<int>(GameObjectType1::EMPTY)) {
				std::vector<MoveDirection> possibleDirs;
				std::vector<MoveDirection> wrongDirs = { getDir(glm::ivec2(-offset.x,-offset.y)), getDir(glm::ivec2(-offset.y,-offset.x)) };
				possibleDirs = getPossibleDirs(wrongDirs);
				dir = possibleDirs[mersenneRand() % 2];
			}
			else if (passabilityMap[position.x + offset.x][position.z + offset.y] == static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x + offset.y][position.z + offset.x] != static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x - offset.y][position.z - offset.x] == static_cast<int>(GameObjectType1::EMPTY)) {
				std::vector<MoveDirection> possibleDirs;
				std::vector<MoveDirection> wrongDirs = { getDir(glm::ivec2(-offset.x,-offset.y)), getDir(glm::ivec2(offset.y,offset.x)) };
				possibleDirs = getPossibleDirs(wrongDirs);
				dir = possibleDirs[mersenneRand() % 2];
			}
			else if (passabilityMap[position.x + offset.x][position.z + offset.y] != static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x + offset.y][position.z + offset.x] != static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x - offset.y][position.z - offset.x] == static_cast<int>(GameObjectType1::EMPTY)) {
				dir = getDir(glm::ivec2(-offset.y, -offset.x));
			}
			else if (passabilityMap[position.x + offset.x][position.z + offset.y] != static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x + offset.y][position.z + offset.x] == static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x - offset.y][position.z - offset.x] != static_cast<int>(GameObjectType1::EMPTY)) {
				dir = getDir(glm::ivec2(offset.y, offset.x));
			}
			else if (passabilityMap[position.x + offset.x][position.z + offset.y] != static_cast<int>(GameObjectType1::EMPTY) &&
				(passabilityMap[position.x + offset.y][position.z + offset.x] == static_cast<int>(GameObjectType1::EMPTY) ||
					passabilityMap[position.x - offset.y][position.z - offset.x] == static_cast<int>(GameObjectType1::EMPTY))) {
				std::vector<MoveDirection> possibleDirs;
				std::vector<MoveDirection> wrongDirs = { getDir(glm::ivec2(offset.x,offset.y)), getDir(glm::ivec2(-offset.x,-offset.y)) };
				possibleDirs = getPossibleDirs(wrongDirs);
				dir = possibleDirs[mersenneRand() % 2];
			}
			else if (passabilityMap[position.x + offset.x][position.z + offset.y] != static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x - offset.x][position.z - offset.y] != static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x + offset.y][position.z + offset.x] != static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x - offset.y][position.z - offset.x] != static_cast<int>(GameObjectType1::EMPTY)) {
				return;
			}
			else if ((passabilityMap[position.x + offset.x][position.z + offset.y] != static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x + offset.y][position.z + offset.x] != static_cast<int>(GameObjectType1::EMPTY) &&
				passabilityMap[position.x - offset.y][position.z - offset.x] != static_cast<int>(GameObjectType1::EMPTY)) &&
				(passabilityMap[position.x - offset.x][position.z - offset.y] == static_cast<int>(GameObjectType1::EMPTY))) {
				switch (dir) {
				case MoveDirection::UP: dir = MoveDirection::DOWN; break;
				case MoveDirection::DOWN: dir = MoveDirection::UP; break;
				case MoveDirection::LEFT: dir = MoveDirection::RIGHT; break;
				case MoveDirection::RIGHT: dir = MoveDirection::LEFT; break;
				}
			}
			offset = getOffset(dir);
		}
		if (passabilityMap[position.x + offset.x][position.z + offset.y] == static_cast<int>(GameObjectType1::EMPTY)) {
			if (player != nullptr) {
				glm::ivec3 playerPosition = player->getPosition3d();
				if ((playerPosition.x == position.x + offset.x && playerPosition.z == position.z + offset.y)) {
					player->setGraphicObject(GraphicObject());
					player.reset();
				}
			}
			monsterObj->setPrevState(dir);
			monsterObj->move(dir);
		}
	}
}