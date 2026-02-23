#pragma once
#include"Headers.h"

class Button {
	//wspó³¿êdne przycisku (lewy górny róg)
	int bX, bY;

	//rozmiary przysiku
	int bWidth, bHeight;

	//tag przycisku
	std::string butttonTag;

	
	sf::Font font;

public:
	

	
	//gruboœæ ramki przycisków
	int outlineThickness = 5;

	//s³u¿y do okreœlenia czy przycisk zosta³ niedawno naciœniêty	// (wykorzystywany przy animacji przycisku)
	bool buttonActive = true;

	

	//kolory przycisków
	sf::Color normal = sf::Color(255, 0, 0);
	sf::Color clicked = sf::Color(200, 200, 200);
	sf::Color white = sf::Color(255, 255, 255);
	sf::Color black = sf::Color(0, 0, 0);

	sf::RectangleShape button;

	
	sf::Text buttonTitle;


	//------------------------- METODY -----------------------------------//


	//ustawia wartoœci pól na te podane w parametrach i tworzy przycisk
	void createButton(int x, int y, int width, int height, std::string tag);

	//odpowiada za wyswietlenie txt na przycisku
	void setButtonTitle(std::string buttinTitle, int xTitle, int yTitle, int fontSize);

	//sprawdza czy przycisk nacisniety
	//bool isButtonClicked(sf::Vector2i* mouse);
	bool isButtonClicked(sf::Vector2i& mouse) const;

	//zmienia kolor przyciuski na taki by by³o waidomo ¿e jest wybrany
	void buttonMarked(bool state);

};
