#pragma once

#include "Board.h"
#include "Button.h"
#include"Enemy.h"

class SetShipsScene {
	int direction = 1, setShipType = 4;
	Button vertically, horizontally, playButton, clearButton;
	Button setOne, setTwo, setThree, setFour;

	bool fourSet = false,
		three1Set = false, three2Set = false,
		two1Set = false, two2Set = false, two3Set = false,
		one1Set = false, one2Set = false, one3Set = false, one4Set = false;

	sf::Text typeButtonsInfo, directionButtonsInfo, setInfo;
	sf::Font font;


public:
	Board playerBoard = Board();

	



	SetShipsScene();
	void displaySetShipsScene(sf::RenderWindow& window) ;

	void setShipsSceneAction(sf::Vector2i& mouse, int& actualScene, Enemy& enemy);


	bool setShipOnClickedPosition(int shipLenght, int threes[], int position);

	void showMarkedDirection();
	void showMarkedShipType();
	void deactivateShipTypeButtons();
};
