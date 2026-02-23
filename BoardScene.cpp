#include "BoardScene.h"

BoardScene::BoardScene(Board &playerBoard)
{
	BoardScene::playerBoard = &playerBoard;


	if (!font.loadFromFile("TWOFOLD uncomplete DeSigN.ttf"))
	{
		std::cerr << "Nie zaladowano czcionki!\t";
		exit(1);
	}

	BoardScene::turnInfo.setFont(font);
	BoardScene::turnInfo.setCharacterSize(30);
	BoardScene::turnInfo.setFillColor(sf::Color(255, 255, 255));
	BoardScene::turnInfo.setStyle(sf::Text::Bold);
}

void BoardScene::displayBoardScene(sf::RenderWindow &window, int &actualScene, bool & playerWin)
{
	if (BoardScene::enemy.fourDestroyed &&
		BoardScene::enemy.three1Destroyed &&
		BoardScene::enemy.three2Destroyed &&
		BoardScene::enemy.two1Destroyed &&
		BoardScene::enemy.two2Destroyed &&
		BoardScene::enemy.two3Destroyed &&
		BoardScene::enemy.one1Destroyed &&
		BoardScene::enemy.one2Destroyed &&
		BoardScene::enemy.one3Destroyed &&
		BoardScene::enemy.one4Destroyed) {
		actualScene = 4;
		playerWin = true;
	}
	else {
		double delay = clock();

		if (BoardScene::enemy.enemyTurn) {
			BoardScene::turnInfo.setString("Opponent turn");
			BoardScene::turnInfo.setPosition(340, 90);

		}
		else {
			BoardScene::turnInfo.setString("Your turn");
			BoardScene::turnInfo.setPosition(1078, 90);
		}
		window.draw(turnInfo);

	
		if (BoardScene::enemy.enemyTurn && ((delay / CLOCKS_PER_SEC - BoardScene::enemy.enmeyStrikeTimer / CLOCKS_PER_SEC) >= 1)) {
			
			
			
			BoardScene::enemy.enemyStrike(*playerBoard);
			
			
		}
		BoardScene::playerBoard->displayBoard(window);
		BoardScene::enemy.displayBoard(window);
		if (BoardScene::playerBoard->fourDestroyed &&
			BoardScene::playerBoard->three1Destroyed &&
			BoardScene::playerBoard->three2Destroyed && 
			BoardScene::playerBoard->two1Destroyed &&
			BoardScene::playerBoard->two2Destroyed &&
			BoardScene::playerBoard->two3Destroyed &&
			BoardScene::playerBoard->one1Destroyed &&
			BoardScene::playerBoard->one2Destroyed &&
			BoardScene::playerBoard->one3Destroyed &&
			BoardScene::playerBoard->one4Destroyed) {
			actualScene = 4;
			playerWin = false;
		}


	}
	
	window.draw(BoardScene::playerBoard->strikeInfo);
	window.draw(BoardScene::enemy.strikeInfo);
}


void BoardScene::boardSceneAction(sf::Vector2i& mouse) 
{
	if (!BoardScene::enemy.enemyTurn)
		BoardScene::enemy.enemyBoardAction(mouse, *BoardScene::playerBoard);
	

}
