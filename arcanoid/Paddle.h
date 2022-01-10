#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Paddle : public sf::Drawable
{
public:
	void paddleInitate();
	int getPaddleLeftX();
	int getPaddleRightX();
	int getPaddleUpY();
	int getPaddleDownY();
	void moveRight();
	void moveLeft();

private:
	sf::RectangleShape shape;
	const float sizeX{ 120 };
	const float sizeY{ 12 };
	const float startPaddlePositionX{ 450 };
	const float startPaddlePositionY{ 855 };
	sf::Vector2f paddleSize{ sizeX, sizeY };
	const float moveY{ 0 };
	const float moveX{ 10 };
	sf::Vector2f moveR{ moveX, moveY };
	sf::Vector2f moveL{ -moveX, moveY };

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};