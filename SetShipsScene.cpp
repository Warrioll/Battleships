#include "SetShipsScene.h"

SetShipsScene::SetShipsScene()
{
	SetShipsScene::playerBoard.setBoardPosition(200,200);
	SetShipsScene::playerBoard.createBoard();

	SetShipsScene::horizontally.createButton(1000, 350, 350, 80, "horizontally");
	SetShipsScene::horizontally.setButtonTitle("Horizontally", 30,20,40);

	SetShipsScene::vertically.createButton(1000, 450, 350, 80, "vertically");
	SetShipsScene::vertically.setButtonTitle("Vertically", 55, 20, 40);

	SetShipsScene::clearButton.createButton(1000, 620, 350, 80, "clearButton");
	SetShipsScene::clearButton.setButtonTitle("Clear board", 37, 18, 40);
	

	SetShipsScene::playButton.createButton(200, 750, 1200, 80, "next");
	SetShipsScene::playButton.setButtonTitle("P l a y", 520, 10, 50);
	SetShipsScene::playButton.button.setFillColor(SetShipsScene::playButton.clicked);
	SetShipsScene::playButton.buttonActive = false;


	if (!font.loadFromFile("TWOFOLD uncomplete DeSigN.ttf"))
	{
		std::cerr << "Nie zaladowano czcionki!\t";
		exit(1);
	}

	SetShipsScene::setInfo.setFont(font);
	SetShipsScene::setInfo.setString("Set your ships");
	SetShipsScene::setInfo.setCharacterSize(40);
	SetShipsScene::setInfo.setFillColor(sf::Color(255, 255, 255));
	//StartScene::title.setStyle(sf::Text::Bold);
	SetShipsScene::setInfo.setPosition(303, 100);

	SetShipsScene::typeButtonsInfo.setFont(font);
	SetShipsScene::typeButtonsInfo.setString("Ship lenght");
	SetShipsScene::typeButtonsInfo.setCharacterSize(30);
	SetShipsScene::typeButtonsInfo.setFillColor(sf::Color(255, 255, 255));
	SetShipsScene::typeButtonsInfo.setPosition(1087, 110);

	SetShipsScene::directionButtonsInfo.setFont(font);
	SetShipsScene::directionButtonsInfo.setString("Direction");
	SetShipsScene::directionButtonsInfo.setCharacterSize(30);
	SetShipsScene::directionButtonsInfo.setFillColor(sf::Color(255, 255, 255));
	SetShipsScene::directionButtonsInfo.setPosition(1105, 295);


	SetShipsScene::setOne.createButton(1000, 170, 50, 50, "setOne");
	SetShipsScene::setTwo.createButton(1100, 170, 50, 50, "setTwo");
	SetShipsScene::setThree.createButton(1200, 170, 50, 50, "setThree");
	SetShipsScene::setFour.createButton(1300, 170, 50, 50, "setFour");
	
	SetShipsScene::setOne.setButtonTitle("1", 15,5,35);
	SetShipsScene::setTwo.setButtonTitle("2", 15,5,35);
	SetShipsScene::setThree.setButtonTitle("3", 15,5,35);
	SetShipsScene::setFour.setButtonTitle("4", 15,5,35);


	SetShipsScene::showMarkedDirection();
	SetShipsScene::showMarkedShipType();
}

void SetShipsScene::displaySetShipsScene(sf::RenderWindow& window)
{
	SetShipsScene::playerBoard.displayBoard(window);

	//SetShipsScene::deactivateShipTypeButtons();


	window.draw(SetShipsScene::setInfo);
	window.draw(SetShipsScene::typeButtonsInfo);
	window.draw(SetShipsScene::directionButtonsInfo);

	window.draw(SetShipsScene::horizontally.button);
	window.draw(SetShipsScene::horizontally.buttonTitle);
	
	window.draw(SetShipsScene::vertically.button);
	window.draw(SetShipsScene::vertically.buttonTitle);

	window.draw(SetShipsScene::clearButton.button);
	window.draw(SetShipsScene::clearButton.buttonTitle);
	
	window.draw(SetShipsScene::playButton.button);
	window.draw(SetShipsScene::playButton.buttonTitle);


	window.draw(SetShipsScene::setOne.button);
	window.draw(SetShipsScene::setOne.buttonTitle);

	window.draw(SetShipsScene::setTwo.button);
	window.draw(SetShipsScene::setTwo.buttonTitle);

	window.draw(SetShipsScene::setThree.button);
	window.draw(SetShipsScene::setThree.buttonTitle);

	window.draw(SetShipsScene::setFour.button);
	window.draw(SetShipsScene::setFour.buttonTitle);
}

void SetShipsScene::showMarkedDirection() {
	switch (SetShipsScene::direction) {
	case 1:
		SetShipsScene::horizontally.buttonMarked(true);
		SetShipsScene::vertically.buttonMarked(false);
		break;
	case 0:
		SetShipsScene::horizontally.buttonMarked(false);
		SetShipsScene::vertically.buttonMarked(true);
		break;
	}
}

void SetShipsScene::showMarkedShipType()
{
	switch (SetShipsScene::setShipType) {
	case 1:
		if(SetShipsScene::setOne.buttonActive)
			SetShipsScene::setOne.buttonMarked(true);
		if (SetShipsScene::setTwo.buttonActive)
			SetShipsScene::setTwo.buttonMarked(false);
		if (SetShipsScene::setThree.buttonActive)
			SetShipsScene::setThree.buttonMarked(false);
		if (SetShipsScene::setFour.buttonActive)
			SetShipsScene::setFour.buttonMarked(false);
		break;
	case 2:
		if (SetShipsScene::setOne.buttonActive)
			SetShipsScene::setOne.buttonMarked(false);
		if (SetShipsScene::setTwo.buttonActive)
			SetShipsScene::setTwo.buttonMarked(true);
		if (SetShipsScene::setThree.buttonActive)
			SetShipsScene::setThree.buttonMarked(false);
		if (SetShipsScene::setFour.buttonActive)
			SetShipsScene::setFour.buttonMarked(false);
		break;
	case 3:
		if (SetShipsScene::setOne.buttonActive)
			SetShipsScene::setOne.buttonMarked(false);
		if (SetShipsScene::setTwo.buttonActive)
			SetShipsScene::setTwo.buttonMarked(false);
		if (SetShipsScene::setThree.buttonActive)
			SetShipsScene::setThree.buttonMarked(true);
		if (SetShipsScene::setFour.buttonActive)
			SetShipsScene::setFour.buttonMarked(false);
		break;
	case 4:
		if (SetShipsScene::setOne.buttonActive)
			SetShipsScene::setOne.buttonMarked(false);
		if (SetShipsScene::setTwo.buttonActive)
			SetShipsScene::setTwo.buttonMarked(false);
		if (SetShipsScene::setThree.buttonActive)
			SetShipsScene::setThree.buttonMarked(false);
		if (SetShipsScene::setFour.buttonActive)
			SetShipsScene::setFour.buttonMarked(true);
		break;
	}
}

void SetShipsScene::deactivateShipTypeButtons()
{

	if (SetShipsScene::one1Set && SetShipsScene::one2Set && SetShipsScene::one3Set && SetShipsScene::one4Set) {
		SetShipsScene::setOne.button.setFillColor(SetShipsScene::playButton.clicked);
		SetShipsScene::setOne.buttonActive = false;
	}
	else {
		SetShipsScene::setOne.buttonActive = true;
		SetShipsScene::showMarkedShipType();
	}

	if (SetShipsScene::two1Set && SetShipsScene::two2Set && SetShipsScene::two3Set) {
		SetShipsScene::setTwo.button.setFillColor(SetShipsScene::playButton.clicked);
		SetShipsScene::setTwo.buttonActive = false;
	}
	else {
		SetShipsScene::setTwo.buttonActive = true;
		SetShipsScene::showMarkedShipType();
	}

	if (SetShipsScene::three1Set && SetShipsScene::three2Set) {
		SetShipsScene::setThree.button.setFillColor(SetShipsScene::playButton.clicked);
		SetShipsScene::setThree.buttonActive = false;
	}
	else {
		SetShipsScene::setThree.buttonActive = true;
		SetShipsScene::showMarkedShipType();
	}

	if (SetShipsScene::fourSet ) {
		SetShipsScene::setFour.button.setFillColor(SetShipsScene::playButton.clicked);
		SetShipsScene::setFour.buttonActive = false;
	}
	else {
		SetShipsScene::setFour.buttonActive = true;
		SetShipsScene::showMarkedShipType();
	}

}

void SetShipsScene::setShipsSceneAction(sf::Vector2i &mouse, int &actualScene, Enemy &enemy)
{
	
	int threes[4];
	if (SetShipsScene::horizontally.isButtonClicked(mouse))
		SetShipsScene::direction = 1;
	
	if (SetShipsScene::vertically.isButtonClicked(mouse))
		SetShipsScene::direction = 0;



	if (SetShipsScene::setOne.isButtonClicked(mouse))
		SetShipsScene::setShipType = 1;
	if (SetShipsScene::setTwo.isButtonClicked(mouse))
		SetShipsScene::setShipType = 2;
	if (SetShipsScene::setThree.isButtonClicked(mouse))
		SetShipsScene::setShipType = 3;
	if (SetShipsScene::setFour.isButtonClicked(mouse))
		SetShipsScene::setShipType = 4;

	SetShipsScene::showMarkedDirection();
	SetShipsScene::showMarkedShipType();

	if (SetShipsScene::playButton.isButtonClicked(mouse)) {
		enemy.createEnemyBoard();
		actualScene = 3;
	}
	for (int i = 0; i < 100; i++) {
		
		if (SetShipsScene::playerBoard.board[i].isButtonClicked(mouse) ) {
			
			switch (SetShipsScene::setShipType)
			{
			case 1:
				if ((!SetShipsScene::one4Set || !SetShipsScene::one3Set || !SetShipsScene::one2Set || !SetShipsScene::one1Set) && SetShipsScene::setShipOnClickedPosition(1, threes, i)) {
					if (!SetShipsScene::one4Set)
						SetShipsScene::one4Set = true;
					else {
						if (!SetShipsScene::one3Set)
							SetShipsScene::one3Set = true;
						else{
							if (!SetShipsScene::one2Set)
								SetShipsScene::one2Set = true;
							else
								SetShipsScene::one1Set = true;
				}
								}
				}
				break;
			case 2:
				if ((!SetShipsScene::two1Set || !SetShipsScene::two2Set || !SetShipsScene::two3Set) && SetShipsScene::setShipOnClickedPosition(SetShipsScene::setShipType, threes, i)) {
					if(!SetShipsScene::two1Set)
						SetShipsScene::two1Set = true;
					else {
						if (!SetShipsScene::two2Set)
							SetShipsScene::two2Set = true;
						else
							SetShipsScene::two3Set = true;
					}
				}
				break;
			case 3:
				if ((!SetShipsScene::three1Set || !SetShipsScene::three2Set) && SetShipsScene::setShipOnClickedPosition(SetShipsScene::setShipType, threes, i)) {
					if (!SetShipsScene::three1Set)
						SetShipsScene::three1Set = true;
					else
						SetShipsScene::three2Set = true;
				}
				break;
			case 4:
				if (!SetShipsScene::fourSet  && SetShipsScene::setShipOnClickedPosition(SetShipsScene::setShipType, threes, i)) {
					if (!SetShipsScene::fourSet)
						SetShipsScene::fourSet = true;
				}
				break;
			default:
				break;
			}
		}

		}


		if (SetShipsScene::clearButton.isButtonClicked(mouse)) {
			for (int i = 0; i < 100; i++) {
				SetShipsScene::playerBoard.board[i].buttonActive = true;
				SetShipsScene::playerBoard.board[i].shipPlaced = false;
				SetShipsScene::playerBoard.board[i].button.setFillColor(SetShipsScene::playerBoard.board[i].normal);
			}
			SetShipsScene::one1Set = false;
			SetShipsScene::one2Set = false;
			SetShipsScene::one3Set = false;
			SetShipsScene::one4Set = false;
			
			SetShipsScene::two1Set = false;
			SetShipsScene::two2Set = false;
			SetShipsScene::two3Set = false;
			
			SetShipsScene::three1Set = false;
			SetShipsScene::three2Set = false;
			
			SetShipsScene::fourSet = false;

			for (int i = 0; i < 4; i++) {
				SetShipsScene::playerBoard.four[i] = -1;
			}
			for (int i = 0; i < 3; i++) {
				SetShipsScene::playerBoard.three1[i] = -1;
			}
			for (int i = 0; i < 3; i++) {
				SetShipsScene::playerBoard.three2[i] = -1;
			}
			for (int i = 0; i < 2; i++) {
				SetShipsScene::playerBoard.two1[i] = -1;
			}
			for (int i = 0; i < 2; i++) {
				SetShipsScene::playerBoard.two2[i] = -1;
			}
			SetShipsScene::playerBoard.one1 = -1;
			SetShipsScene::playerBoard.one2 = -1;
			SetShipsScene::playerBoard.one3 = -1;
			SetShipsScene::playerBoard.one4 = -1;
		}

		SetShipsScene::deactivateShipTypeButtons();

		if (SetShipsScene::one1Set &&
			SetShipsScene::one2Set&&
			SetShipsScene::one3Set&&
			SetShipsScene::one4Set&&
			
			SetShipsScene::two1Set&&
			SetShipsScene::two2Set&&
			SetShipsScene::two3Set&&
			
			SetShipsScene::three1Set&&
			SetShipsScene::three2Set&&
			
			SetShipsScene::fourSet)
		{
			SetShipsScene::playButton.buttonActive = true;
			SetShipsScene::playButton.button.setFillColor(SetShipsScene::playButton.normal);
		}
		else {
			SetShipsScene::playButton.buttonActive = false;
			SetShipsScene::playButton.button.setFillColor(SetShipsScene::playButton.clicked);
		}
	}
	


bool SetShipsScene::setShipOnClickedPosition(int shipLenght, int threes[], int position)
{

	if (SetShipsScene::playerBoard.chooseShipsPosition(shipLenght, position, SetShipsScene::direction, threes)) {
		SetShipsScene::playerBoard.saveShipsPosition(shipLenght, threes);
		SetShipsScene::playerBoard.showSetShips(shipLenght, threes);
		return true;
	}
	else {
		return false;
	}
}
