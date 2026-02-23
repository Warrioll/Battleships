#pragma once
#include"Headers.h"
#include"Button.h"
#include"Board.h"
#include"Enemy.h"


class EndScene {
	

	Button quitButton;
	//Button playAgainButton;

	sf::Text title;
	sf::Font font;

public:
	bool playerWin=false;

	EndScene();
	void displayEndScene(sf::RenderWindow& window, Board& playerBoard, Enemy& enemyBoard);
	
	void endSceneAction(sf::Vector2i& mouse);
};
