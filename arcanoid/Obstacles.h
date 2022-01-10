#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Obstacles : public sf::Drawable
{
public:
	void initate(int x);
	int getObstaclesDownY();
	int getObstaclesUpY();
	int getObstaclesLeftX();
	int getObstaclesRightX();
	void deleteObstacle1();
	void deleteObstacle2();
	void deleteObstacle3();
	void deleteObstacle4();
	void deleteObstacle5();
	bool checkPosition();

private:
	sf::RectangleShape shape;
	int sizeX{ 29 };
	int sizeY{ 18 };
	sf::Vector2f obstaclesSize{ sizeX, sizeY };
	int positionY{ 90 };
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};
