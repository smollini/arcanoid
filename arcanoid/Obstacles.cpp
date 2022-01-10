#include "Obstacles.h"

void Obstacles::initate(int x)
{
	shape.setSize(obstaclesSize);
	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(x, positionY);
}

int Obstacles::getObstaclesDownY()
{
	sf::Vector2f center = shape.getPosition();
	return center.y + sizeY / 2;
}

int Obstacles::getObstaclesUpY()
{
	sf::Vector2f center = shape.getPosition();
	return center.y - sizeY / 2;
}

int Obstacles::getObstaclesLeftX()
{
	sf::Vector2f center = shape.getPosition();
	return center.x - sizeX / 2;
}

int Obstacles::getObstaclesRightX()
{
	sf::Vector2f center = shape.getPosition();
	return center.x + sizeX / 2;
}

void Obstacles::deleteObstacle1()
{
	shape.setPosition(-50, -50);
}

void Obstacles::deleteObstacle2()
{
	if (shape.getFillColor() == sf::Color::Magenta)
	{
		shape.setFillColor(sf::Color::Blue);
	}
	else if (shape.getFillColor() == sf::Color::Blue)
	{
		shape.setPosition(-50, -50);
	}
	else;
}

void Obstacles::deleteObstacle3()
{
	if (shape.getFillColor() == sf::Color::Magenta)
	{
		shape.setFillColor(sf::Color::Blue);
	}
	else if (shape.getFillColor() == sf::Color::Blue)
	{
		shape.setFillColor(sf::Color::Cyan);
	}
	else if (shape.getFillColor() == sf::Color::Cyan)
	{
		shape.setPosition(-50, -50);
	}
}

void Obstacles::deleteObstacle4()
{
	if (shape.getFillColor() == sf::Color::Magenta)
	{
		shape.setFillColor(sf::Color::Blue);
	}
	else if (shape.getFillColor() == sf::Color::Blue)
	{
		shape.setFillColor(sf::Color::Cyan);
	}
	else if (shape.getFillColor() == sf::Color::Cyan)
	{
		shape.setFillColor(sf::Color::Green);
	}
	else if (shape.getFillColor() == sf::Color::Green)
	{
		shape.setPosition(-50, -50);
	}
}

void Obstacles::deleteObstacle5()
{
	if (shape.getFillColor() == sf::Color::Magenta)
	{
		shape.setFillColor(sf::Color::Blue);
	}
	else if (shape.getFillColor() == sf::Color::Blue)
	{
		shape.setFillColor(sf::Color::Cyan);
	}
	else if (shape.getFillColor() == sf::Color::Cyan)
	{
		shape.setFillColor(sf::Color::Green);
	}
	else if (shape.getFillColor() == sf::Color::Green)
	{
		shape.setFillColor(sf::Color::Red);
	}
	else if (shape.getFillColor() == sf::Color::Red)
	{
		shape.setPosition(-50, -50);
	}
}

bool Obstacles::checkPosition()
{
	if (shape.getPosition().x == -50) return true;
	else return false;
}

void Obstacles::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}
