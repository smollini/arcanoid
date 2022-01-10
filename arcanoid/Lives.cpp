#include "Lives.h"

void Lives::heatrInitate(int a, int b)
{
	shape.setRadius(radius);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(a, b);
}

bool Lives::dead(int a)
{
	if (a >= 930)
	{
		if (hearts > 0) hearts--;
		return true;
	}
}

void Lives::showDead()
{
	this->shape.setFillColor(sf::Color::Transparent);
}

bool Lives::isTransparent()
{
	if (shape.getFillColor() == sf::Color::Transparent) return true;
	else return false;
}

void Lives::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}
