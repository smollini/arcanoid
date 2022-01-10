#include "Level.h"

void Level::level()
{
	for (int i = 0; i < levelN; i++)
	{
		obstacles[i].initate(i * space);
	}
}

int Level::getObstaclesDownY(int a)
{
	return obstacles[a].getObstaclesDownY();
}

int Level::getObstaclesUpY(int a)
{
	return obstacles[a].getObstaclesUpY();
}

int Level::getObstaclesLeftX(int a)
{
	return obstacles[a].getObstaclesLeftX();
}

int Level::getObstaclesRightX(int a)
{
	return obstacles[a].getObstaclesRightX();
}

void Level::deleteObstacleL1( int minX, int maxX )
{
	for (int i = 0; i < levelN; i++)
	{	
		if (minX <= getObstaclesRightX(i) && maxX >= getObstaclesLeftX(i))
		{
			obstacles[i].deleteObstacle1();
		}
	}
}

void Level::deleteObstacleL2(int minX, int maxX)
{
	for (int i = 0; i < levelN; i++)
	{
		if (minX <= getObstaclesRightX(i) && maxX >= getObstaclesLeftX(i))
		{
			obstacles[i].deleteObstacle2();
		}
	}
}

void Level::deleteObstacleL3(int minX, int maxX)
{
	for (int i = 0; i < levelN; i++)
	{
		if (minX <= getObstaclesRightX(i) && maxX >= getObstaclesLeftX(i))
		{
			obstacles[i].deleteObstacle3();
		}
	}
}

void Level::deleteObstacleL4(int minX, int maxX)
{
	for (int i = 0; i < levelN; i++)
	{
		if (minX <= getObstaclesRightX(i) && maxX >= getObstaclesLeftX(i))
		{
			obstacles[i].deleteObstacle4();
		}
	}
}

void Level::deleteObstacleL5(int minX, int maxX)
{
	for (int i = 0; i < levelN; i++)
	{
		if (minX <= getObstaclesRightX(i) && maxX >= getObstaclesLeftX(i))
		{
			obstacles[i].deleteObstacle5();
		}
	}
}

bool Level::win()
{
	int x{ 0 };
	for (int i = 0; i < levelN; i++)
	{
		if (obstacles[i].checkPosition() == true) x++;
	}
	if (x == levelN) return true;
	else return false;
}
