#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Obstacles.h"

using namespace std;

class Level
{
public:
	Obstacles obstacles[30];
	void level();
	int levelN{ 30 };
	int getObstaclesDownY(int a);
	int getObstaclesUpY(int a);
	int getObstaclesLeftX(int a);
	int getObstaclesRightX(int a);
	void deleteObstacleL1(int minX, int maxX);
	void deleteObstacleL2(int minX, int maxX);
	void deleteObstacleL3(int minX, int maxX);
	void deleteObstacleL4(int minX, int maxX);
	void deleteObstacleL5(int minX, int maxX);
	bool win();

private:
	int space{ 30 };

};

