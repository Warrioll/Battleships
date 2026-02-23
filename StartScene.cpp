#include "StartScene.h"

StartScene::StartScene()
{
	StartScene::startButton.createButton(500, 600, 600, 150, "startButton");
	StartScene::startButton.setButtonTitle("PLAY", 185, 20, 100);
	if (!font.loadFromFile("TWOFOLD uncomplete DeSigN.ttf"))
	{
		std::cerr << "Nie zaladowano czcionki!\t";
		exit(1);
	}

	
	StartScene::title.setFont(font);
	StartScene::title.setString("BATTLESHIPS");
	StartScene::title.setCharacterSize(200);
	StartScene::title.setFillColor(sf::Color(255, 255, 255));
	StartScene::title.setStyle(sf::Text::Bold);
	StartScene::title.setPosition(175, 150);


}

void StartScene::displayStartScene(sf::RenderWindow& window) const
{
	
	window.draw(StartScene::startButton.button);
	window.draw(StartScene::startButton.buttonTitle);
	window.draw(StartScene::title);
	
}

void StartScene::startSceneAction(sf::Vector2i &mouse, int &actualScene, BoardScene &boardScene)
{
	if (StartScene::startButton.isButtonClicked(mouse)) {
		actualScene = 2;
		
	}
}

