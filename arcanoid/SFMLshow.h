#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Lives.h"
#include "Level.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class SFMLshow
{
public:
	Paddle paddle;
	Ball ball;
	Lives lives[3];
	Level level;
	void showGame();
	
private:
	static const int X{ 900 };
	static const int Y{ 930 };
};

