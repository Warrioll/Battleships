#include "Game.h"

Game::Game()
{
	Game::window.create(sf::VideoMode(1600, 900, 32), "BATTLESHIPS", sf::Style::Titlebar | sf::Style::Close);	//Titlebar -brak rozszeszania + fixed bard , Close wyœwietlanie przycisku do zamkniêcia
}

void Game::displayBackground() {
	if (Game::backgroundWave)
		Game::backgroundGreen += 0.05;				//blue to predkosc
	else
		Game::backgroundGreen -= 0.05;

	if (Game::backgroundColorTimer == 2000) {					//iB to czas
		if (Game::backgroundWave == true)
			Game::backgroundWave = false;
		else
			Game::backgroundWave = true;
		Game::backgroundColorTimer = 0;
	}
	Game::backgroundColorTimer += 1;
	window.clear(sf::Color(0, Game::backgroundGreen, 255));
}

void Game::displayActualScene() {

	switch (Game::actualScene) {
	case 1:
		(Game::startScene).displayStartScene(Game::window);
		break;
	case 2:
		(Game::setShipsScene).displaySetShipsScene(Game::window);
		break;
	case 3:
		Game::boardScene.displayBoardScene(Game::window, Game::actualScene, Game::endScene.playerWin);
		break;
	case 4:
		Game::endScene.displayEndScene(Game::window, *(Game::boardScene.playerBoard), Game::boardScene.enemy);
		break;
	default:
		exit(0);
		break;
	}

}

void Game::mouseLeftClick()
{
	switch (Game::actualScene) {
	case 1:
		//(*boardScene) = BoardScene();
		startScene.startSceneAction(Game::mousePosition, Game::actualScene, Game::boardScene);
		break;
	case 2:
		setShipsScene.setShipsSceneAction(Game::mousePosition, Game::actualScene, Game::boardScene.enemy);
		break;
	case 3:
		boardScene.boardSceneAction(Game::mousePosition);
		break;
	case 4:
		endScene.endSceneAction(Game::mousePosition);
		break;
	default:
		exit(0);
		break;
	}
}

void Game::gameLoop()
{
	sf::Event event;
	while (window.isOpen()) {


		while (window.pollEvent(event)) {

			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				mousePosition = sf::Mouse::getPosition(window);
				mouseLeftClick();
				break;

			}

		}

		window.clear();

		displayBackground();
		displayActualScene();

		window.display();



	}

	//double endTime = clock();
	//std::cout << "start: " << startTime << "\n" << "end: " << endTime << "\n" << "czas trwania: " << (endTime - startTime) / CLOCKS_PER_SEC << std::endl;

}
