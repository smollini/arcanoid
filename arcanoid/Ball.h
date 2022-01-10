#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Ball : public sf::Drawable
{
public:
	void ballInitate();
	void move();
	void bounceWall();
	void bouncePaddle(int PLX, int PRX, int PUY, int PDY);
	bool bounceObstacles(int OLX, int ORX, int OUY, int ODY);
	int getDownBallY();
	int getUpBallY();
	int getBallLeftX();
	int getBallRightX();
	sf::Vector2f getBallVelocity();

private:
	sf::RectangleShape shape;
	const float sizeX{ 15 };
	const float sizeY{ 15 };
	sf::Vector2f ballSize{ sizeX, sizeY };
	static const int startX{ 300 };
	static const int startY{ 650 };
	const float ballVelocity{ 1 };
	sf::Vector2f velocity{ ballVelocity, ballVelocity };
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};