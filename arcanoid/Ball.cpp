#include "Ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

void Ball::ballInitate()
{
	shape.setSize( ballSize );
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(sizeX/2, sizeY/2);
	shape.setPosition(startX, startY);
}

void Ball::move()
{
	this->shape.move(velocity);
}

void Ball::bounceWall()
{
	sf::Vector2f center= shape.getPosition();
	if (center.y + sizeY/2 >= 930)
	{
		this->velocity.y = -ballVelocity;
	}
	else if (center.x + sizeX/2 >= 900)
	{
		this->velocity.x = -ballVelocity;
	}
	else if (center.y - sizeY/2 <= 30)
	{
		this->velocity.y = ballVelocity;
	}
	else if (center.x - sizeX/2 <= 0)
	{
		this->velocity.x = ballVelocity;
	}
}

void Ball::bouncePaddle(int PLX, int PRX, int PUY, int PDY)
{
	int BLX = getBallLeftX();	
	int BRX = getBallRightX();
	int BDY = getDownBallY();
	int BUY = getUpBallY();
	if (PUY == BDY && PLX <= BRX && PRX >= BLX)			velocity.y = -ballVelocity;
	else if (PDY == BUY  && PLX <= BRX && PRX >= BLX)	velocity.y =  ballVelocity;
	else if (PUY < BDY && PDY > BUY && PLX == BRX)		velocity.x = -ballVelocity;
	else if (PUY < BDY && PDY > BUY && PRX == BLX)		velocity.x =  ballVelocity;
}

bool Ball::bounceObstacles(int OLX, int ORX, int OUY, int ODY)
{
	int BLX = getBallLeftX();
	int BRX = getBallRightX();
	int BDY = getDownBallY();
	int BUY = getUpBallY();
	if (OUY == BDY && OLX <= BRX && ORX >= BLX)
	{
		velocity.y = -ballVelocity;
		return true;
	}
	else if (ODY == BUY && OLX <= BRX && ORX >= BLX)
	{
		velocity.y = ballVelocity;
		return true;
	}
	else if (OUY < BDY && ODY > BUY && OLX == BRX)
	{
		velocity.x = -ballVelocity;
		return true;
	}
	else if (OUY < BDY && ODY > BUY && ORX == BLX)
	{
		velocity.x = ballVelocity;
		return true;
	}
	else return false;
}

int Ball::getBallLeftX()
{
	sf::Vector2f center = shape.getPosition();
	return center.x - sizeX / 2;
}

int Ball::getBallRightX()
{
	sf::Vector2f center = shape.getPosition();
	return center.x + sizeX / 2;
}

sf::Vector2f Ball::getBallVelocity()
{
	return velocity;
}

int Ball::getDownBallY()
{
	sf::Vector2f center = shape.getPosition();
	return center.y + sizeY / 2;
}

int Ball::getUpBallY()
{
	sf::Vector2f center = shape.getPosition();
	return center.y - sizeY / 2;
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}
