#pragma once
#include"Headers.h"
#include "Enemy.h"
#include"Board.h"

class BoardScene  {

	sf::Text turnInfo;
	sf::Font font;

public:
	Enemy enemy;
	Board* playerBoard;
	
	

	BoardScene(Board& playerBoard);

	void displayBoardScene(sf::RenderWindow& window, int& actualScene, bool& playerWin);
	
	void boardSceneAction(sf::Vector2i& mouse);


};