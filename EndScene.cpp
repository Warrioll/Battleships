#include "EndScene.h"

EndScene::EndScene()
{
	//EndScene::quitButton.createButton(500, 750, 600, 100, "quitButton");
	//EndScene::quitButton.setButtonTitle("EXIT", 230, 12, 70);

	EndScene::quitButton.createButton(200, 750, 1200, 80, "next");
	EndScene::quitButton.setButtonTitle("E x i t", 520, 10, 50);


	if (!font.loadFromFile("TWOFOLD uncomplete DeSigN.ttf"))
	{
		std::cerr << "Nie zaladowano czcionki!\t";
		exit(1);
	}


	EndScene::title.setFont(font);	
	EndScene::title.setCharacterSize(120);
	EndScene::title.setStyle(sf::Text::Bold);
	

	
}

void EndScene::displayEndScene(sf::RenderWindow& window, Board& playerBoard, Enemy& enemyBoard)
{
	if (EndScene::playerWin) {
		EndScene::title.setString("VICTORY");
		EndScene::title.setFillColor(sf::Color(255, 0, 0));
		EndScene::title.setPosition(590, 40);
	}
	else {
		EndScene::title.setString("DEFEAT");		
		EndScene::title.setFillColor(sf::Color(0, 0, 0));
		EndScene::title.setPosition(600, 40);
	}

	window.draw(EndScene::quitButton.button);
	window.draw(EndScene::quitButton.buttonTitle);
	playerBoard.displayBoard(window);
	enemyBoard.displayBoard(window);
	
	window.draw(EndScene::title);

}

void EndScene::endSceneAction(sf::Vector2i &mouse)
{
	if (EndScene::quitButton.isButtonClicked(mouse)) {
		exit(0);
	}
}
