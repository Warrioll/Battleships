#pragma once
#include"Button.h"
#include"BoardScene.h"


class StartScene {
	sf::Text title;
	
	sf::Font font;
	Button startButton = Button();

public:
	
	



	StartScene();
	void displayStartScene(sf::RenderWindow& window) const;
	
	void startSceneAction(sf::Vector2i& mouse, int& actualScene, BoardScene& boardScene);
};
