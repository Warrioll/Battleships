#pragma once
#include "Headers.h"
#include "Button.h"

class BoardButton : public Button {
	//kolory
	 sf::Color boardButtonBlue = sf::Color(0, 100, 255);
	 sf::Color hitColor = sf::Color(255, 180, 0);
	 sf::Color missColor = sf::Color(200, 255, 255);
	 sf::Color setColor = sf::Color(0, 0, 0);
	 sf::Color dystroyedColor = Button::normal;

public:

	//okreœla czy w danym polu jest statek
	bool shipPlaced = false;
	std::string belonging = "none";

	

	//konstruktor ustawia inne kolory przyciskow
	BoardButton();

	//sprawdza czy statek jest postawiony w danym miejscu i zmienia kolor
	void boardButtonAction( int state);
};
