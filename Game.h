#pragma once
#include"Headers.h"
#include"StartScene.h"
#include"BoardScene.h"
#include"SetShipsScene.h"
#include"EndScene.h"

class Game
{
	int actualScene = 1;

	sf::RenderWindow window;

	StartScene startScene = StartScene();
	SetShipsScene setShipsScene = SetShipsScene();
	BoardScene boardScene = BoardScene(setShipsScene.playerBoard);
	EndScene endScene = EndScene();

	sf::Vector2i mousePosition;

	float backgroundGreen = 155;
	int backgroundColorTimer = 1;
	bool backgroundWave = true;


//public:
	
	void displayBackground();
	void displayActualScene();
	void mouseLeftClick();

public:
	Game();
	void gameLoop();
};

