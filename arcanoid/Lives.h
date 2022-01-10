#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Lives : public sf::Drawable
{
public:
	void heatrInitate(int a, int b);
	bool dead(int a);
	int hearts{ 3 };
	void showDead();
	bool isTransparent();

private:
	sf::CircleShape shape;
	int radius{ 10 };
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

