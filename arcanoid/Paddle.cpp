#include "Paddle.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

void Paddle::paddleInitate()
{
	shape.setSize(paddleSize);
	shape.setFillColor(sf::Color::Green);
	shape.setOrigin(sizeX / 2, sizeY / 2);
	shape.setPosition(startPaddlePositionX, startPaddlePositionY);
}

int Paddle::getPaddleLeftX()
{
	sf::Vector2f center = shape.getPosition();
	return center.x - sizeX / 2;
}

int Paddle::getPaddleRightX()
{
	sf::Vector2f center = shape.getPosition();
	return center.x + sizeX / 2;
}

int Paddle::getPaddleUpY()
{
	sf::Vector2f center = shape.getPosition();
	return center.y - sizeY;
}

int Paddle::getPaddleDownY()
{
	sf::Vector2f center = shape.getPosition();
	return center.y + sizeY;
}

void Paddle::moveRight()
{
	shape.move(moveR);
}

void Paddle::moveLeft()
{
	shape.move(moveL);
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}
