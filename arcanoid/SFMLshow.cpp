#include "SFMLshow.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace std;

void SFMLshow::showGame()
{
	sf::Font font;
	if (!font.loadFromFile("C:/Users/ignac/Desktop/programowanie/Programowanie obiektowe/czcionki/arial.ttf"))
		exit(-1);
	sf::Text text1("Level 1", font, 20);
	text1.setPosition(300, 0);
	sf::Text text2("Level 2", font, 20);
	text2.setPosition(300, 0);
	sf::Text text3("Level 3", font, 20);
	text3.setPosition(300, 0);
	sf::Text text4("Level 4", font, 20);
	text4.setPosition(300, 0);
	sf::Text text5("Level 5", font, 20);
	text5.setPosition(300, 0);
	int levelOfTheGame{ 1 };
	start:
	ball.ballInitate();
	level.level();
	for (int i = 0; i < lives[0].hearts; i++)
	{
		lives[i].heatrInitate(30 * i, 0);
	}
	paddle.paddleInitate();
	sf::RenderWindow window(sf::VideoMode(X, Y), "Arcanoid");
	window.setFramerateLimit(200);
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{
				paddle.moveLeft();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{
				paddle.moveRight();
			}
		}
		ball.bounceWall();
		ball.bouncePaddle(paddle.getPaddleLeftX(), paddle.getPaddleRightX(), paddle.getPaddleUpY(), paddle.getPaddleDownY());
		for (int i = 0; i < level.levelN; i++)
		{
			if (ball.bounceObstacles(level.getObstaclesLeftX(i), level.getObstaclesRightX(i), level.getObstaclesUpY(i), level.getObstaclesDownY(i)) == true)
			{
				if (levelOfTheGame == 1)
				{
					level.deleteObstacleL1(ball.getBallLeftX(), ball.getBallRightX());
				}
				else if (levelOfTheGame == 2)
				{
					level.deleteObstacleL2(ball.getBallLeftX(), ball.getBallRightX());
				}
				else if (levelOfTheGame == 3)
				{
					level.deleteObstacleL3(ball.getBallLeftX(), ball.getBallRightX());	
				}
				else if (levelOfTheGame == 4)
				{
					level.deleteObstacleL4(ball.getBallLeftX(), ball.getBallRightX());
				}
				else if (levelOfTheGame == 5)
				{
					level.deleteObstacleL5(ball.getBallLeftX(), ball.getBallRightX());
				}
				else window.close();
			}
		}
		ball.move();
		if (lives[0].dead(ball.getDownBallY()) == true) lives[lives[0].hearts].showDead();
		if (lives[0].isTransparent() == true && lives[1].isTransparent() == true && lives[2].isTransparent() == true)
		{
			window.clear(sf::Color::Black);																																																																																																																																																																																																																																													
			sf::Text text1("YOU LOOSE", font, 20);
			window.draw(text1);
			window.display();
			Sleep(3000);
			window.close();
		}
		window.draw(ball);
		for (int i = 0; i < lives[0].hearts; i++)
		{
			window.draw(lives[i]);
		}
		for (int i = 0; i < level.levelN; i++)
		{
			window.draw(level.obstacles[i]);
		}
		switch (levelOfTheGame)
		{
		case 1: window.draw(text1);
			break;
		case 2: window.draw(text2);
			break;
		case 3: window.draw(text3);
			break;
		case 4: window.draw(text4);
			break;
		case 5: window.draw(text5);
			break;
		}
		window.draw(paddle);
		window.display();
		if (level.win() == true)
		{
			if (levelOfTheGame <= 4)
			{
				levelOfTheGame++;
				goto start;
			}
			else if (levelOfTheGame == 5)
			{
				window.clear(sf::Color::Black);
				sf::Text text1("YOU WIN", font, 20);
				window.draw(text1);
				window.display();
				Sleep(3000);
				window.close();
			}
			else window.close();
		}
	}
}
