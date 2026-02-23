#include "Board.h"



void Board::createBoard() {

	int buttonIndex = 0;
	char column = 'a', row = '1';
	std::string tag, rowString;
	for (int i = 0; i < 10; i++) {

		if (row == ':')
			rowString = "10";
		else
			rowString = row;

		for (int j = 0; j < 10; j++) {
			BoardButton boardButton;

			tag = "";

			if (column == 'k')
				column = 'a';

			tag = tag + column + rowString;

			boardButton.outlineThickness = 2;
			boardButton.createButton((Board::xBoard + j * Board::widthButton), (Board::yBoard + i * Board::heightButton), Board::widthButton, Board::heightButton,  tag); //wska¿niki!!!
			Board::board[buttonIndex] = boardButton;


			buttonIndex++;
			column = (char)(column + 1);
		}
		row = (char)(row + 1);
	}


	if (!font.loadFromFile("TWOFOLD uncomplete DeSigN.ttf")) {
		std::cerr << "Nie zaladowano czcionki!\t";
		exit(1);
	}
		

	Board::strikeInfo.setFont(font);
	Board::strikeInfo.setCharacterSize(50);
	Board::strikeInfo.setStyle(sf::Text::Bold);
	
}

void Board::displayBoard(sf::RenderWindow& window) const{
	for (int i = 0; i < 100; i++) {
		window.draw(Board::board[i].button);
	}

}

void Board::setBoardPosition(int x, int y)
{
	Board::xBoard = x;
	Board::yBoard = y;

}


void Board::isShipDestroyed(int i)
{


	Board::board[i].boardButtonAction(1);
	Board::setStrikeInfo(2);
	
	if (Board::board[i].belonging == "four") {
		
		
		

		if (!Board::board[Board::four[0]].buttonActive && !Board::board[Board::four[1]].buttonActive && !Board::board[Board::four[2]].buttonActive && !Board::board[Board::four[3]].buttonActive)
		{
			
			Board::fourDestroyed = true;
			Board::board[Board::four[0]].boardButtonAction(2);
			Board::board[Board::four[1]].boardButtonAction(2);
			Board::board[Board::four[2]].boardButtonAction(2);
			Board::board[Board::four[3]].boardButtonAction(2);

			Board::setStrikeInfo(3);
		}
	}
	if (Board::board[i].belonging == "three1") {
		if (!Board::board[Board::three1[0]].buttonActive && !Board::board[Board::three1[1]].buttonActive && !Board::board[Board::three1[2]].buttonActive) {
			
			
			Board::three1Destroyed = true;
			Board::board[Board::three1[0]].boardButtonAction(2);
			Board::board[Board::three1[1]].boardButtonAction(2);
			Board::board[Board::three1[2]].boardButtonAction(2);

			Board::setStrikeInfo(3);
			
		}
	}
	if (Board::board[i].belonging == "three2") {
		if (!Board::board[Board::three2[0]].buttonActive && !Board::board[Board::three2[1]].buttonActive && !Board::board[Board::three2[2]].buttonActive) {
			
			Board::three2Destroyed = true;
			Board::board[Board::three2[0]].boardButtonAction(2);
			Board::board[Board::three2[1]].boardButtonAction(2);
			Board::board[Board::three2[2]].boardButtonAction(2);

			Board::setStrikeInfo(3);
			
		}
	}
	if (Board::board[i].belonging == "two1") {
		if (!Board::board[Board::two1[0]].buttonActive && !Board::board[Board::two1[1]].buttonActive) {
			
			
			Board::two1Destroyed = true;
			Board::board[Board::two1[0]].boardButtonAction(2);
			Board::board[Board::two1[1]].boardButtonAction(2);

			Board::setStrikeInfo(3);
		
		}
	}
	if (Board::board[i].belonging == "two2") {
		if (!Board::board[Board::two2[0]].buttonActive && !Board::board[Board::two2[1]].buttonActive) {
			

			Board::two2Destroyed = true;
			Board::board[Board::two2[0]].boardButtonAction(2);
			Board::board[Board::two2[1]].boardButtonAction(2);

			Board::setStrikeInfo(3);
			
		}
	}
	if (Board::board[i].belonging == "two3") {
		if (!Board::board[Board::two3[0]].buttonActive && !Board::board[Board::two3[1]].buttonActive) {
	

			Board::two3Destroyed = true;
			Board::board[Board::two3[0]].boardButtonAction(2);
			Board::board[Board::two3[1]].boardButtonAction(2);

			Board::setStrikeInfo(3);
			
		}
	}
	if (Board::board[i].belonging == "one1") {
		Board::one1Destroyed = true;
			Board::board[Board::one1].boardButtonAction(2);

			Board::setStrikeInfo(3);

	}
	if (Board::board[i].belonging == "one2") {
		Board::one2Destroyed = true;
			Board::board[Board::one2].boardButtonAction(2);

			Board::setStrikeInfo(3);
			
	}
	if (Board::board[i].belonging == "one3") {
		Board::one3Destroyed = true;
		Board::board[Board::one3].boardButtonAction(2);

		Board::setStrikeInfo(3);
	}
	if (Board::board[i].belonging == "one4") {
		Board::one4Destroyed = true;
		Board::board[Board::one4].boardButtonAction(2);

		Board::setStrikeInfo(3);
		
	}
	
		
}

void Board::setStrikeInfo(int state)
{
	switch (state) {
	case 1:
		Board::strikeInfo.setString("MISS");
		Board::strikeInfo.setFillColor(sf::Color(0,0,0));
		Board::strikeInfo.setPosition(Board::xBoard + 190, 750);
		break;
	case 2:
		Board::strikeInfo.setString("HIT\n");
		Board::strikeInfo.setFillColor(sf::Color(255, 180, 0));
		Board::strikeInfo.setPosition(Board::xBoard + 213, 750);
		break;
	case 3:
		Board::strikeInfo.setString("SHIP WRECKED");
		Board::strikeInfo.setFillColor(sf::Color(255, 0, 0));
		Board::strikeInfo.setPosition(Board::xBoard + 72, 750);
		break;
	default:
		Board::strikeInfo.setString("");
	}
}




bool Board::isShipAround(int random) const
{
	if (Board::board[random].shipPlaced ||
		
		Board::isShipOnLeft(random) ||
		Board::isShipBelow(random) ||
		Board::isShipOnRight(random) ||
		Board::isShipAbove(random) ||
		(!Board::isRightEdgeTile(random) && Board::isShipAbove(random + 1)) ||		//prawy gorny róg
		(!Board::isRightEdgeTile(random) && Board::isShipBelow(random + 1)) ||		//prawy dolny róg
		(!Board::isLeftEdgeTile(random) && Board::isShipAbove(random - 1)) ||		//lewy górny róg
		(!Board::isLeftEdgeTile(random) && Board::isShipBelow(random - 1)))			//lewy dolny róg
	{		
		return true;
	}
	else
		return false;
}

bool Board::isShipOnLeft(int random) const{
	if ((random) % 10 != 0 && Board::board[random - 1].shipPlaced)
		return	true;
	else
		return false;
}

bool Board::isShipOnRight(int random) const
{
	if ((random + 1) % 10 != 0 && Board::board[random + 1].shipPlaced)
		return	true;
	else
		return false;
}

bool Board::isShipAbove(int random) const
{
	if ((random) > 9 && Board::board[random - 10].shipPlaced)
		return	true;
	else
		return false;
}

bool Board::isShipBelow(int random) const
{
	if (random < 90 && Board::board[random + 10].shipPlaced)
		return	true;
	else
		return false;
}



bool Board::isRightEdgeTile(int random) const
{
	if (((random + 1) % 10 == 0))
		return true;
	else
		return false;
}

bool Board::isLeftEdgeTile(int random) const
{
	if ((random % 10 == 0))
		return true;
	else
		return false;;
}

bool Board::isUpperEdgeTile(int random) const
{
	if (random < 10)
		return	true;
	else
		return false;
}

bool Board::isLowerEdgeTile(int random) const
{
	if (random > 89)
		return	true;
	else
		return false;
}

bool Board::chooseShipsPosition(int shipLenght, int random, int direction, int *threes)
{
	int left = 0, up = 0;
	bool shipIsPlaced = false;

	if (!(Board::board[random].shipPlaced) && !(Board::isShipAround(random))) {		//sprawdzenie czy nie jest ju¿ w tym miejscu postawiony statek
		shipIsPlaced = true;
		threes[0] = random;															//zapisanie indexu
																					 //  dla n-1 n=2		pion=0 poziom=1


		if (direction == 1) {
			for (int right = 0; right < (shipLenght - 1); right++) {
				if (!(Board::isRightEdgeTile(random + right- left)) &&					//sprawdzenie : czy random+right jest praw¹ krawêdz¹ (+right- left ¿eby zawsze patrzylo na krawedz//(taki wyj¹tek ¿eby nie przeskakiwa³o do nowej lini
					!(Board::isShipOnRight(random + right- left)) &&						// czy po prawej random jest statek
					!(Board::isShipAbove(random + right -left+ 1)) &&					// czy w prawym górnym random jest statek
					!(Board::isShipBelow(random + right - left+ 1)) &&					// czy w prawym dolnym jest statek

					(Board::isRightEdgeTile(random + right -left + 1) ||					//czy kafelek z prawej nie jest krawêdzi¹
						(!(Board::isShipOnRight(random + right -left + 1)) &&				// czy po prawej statki nie beda siê stykaæ
							!(Board::isShipAbove(random + right -left + 2)) &&			// czy po prawej od góry statki nie beda siê stykaæ
							!(Board::isShipBelow(random + right -left + 2)))))			//czy po prawej od do³u statki nie beda siê stykaæ
				{
					threes[right + 1] = random + right + 1;
				}
				else
				{
					if (!(Board::isLeftEdgeTile(random - left)) &&					//sprawdzenie : czy random jest lew¹ krawêdz¹
						!(Board::isShipOnLeft(random - left)) &&					// czy po lewej random jest statek
						!(Board::isShipAbove(random - left - 1)) &&					// czy w lewym górnym random jest statek
						!(Board::isShipBelow(random - left - 1)) &&					// czy w lewym dolnym jest statek

						(Board::isLeftEdgeTile(random - left - 1) ||				//czy kafelek z lewej nie jest krawêdzi¹
							(!(Board::isShipOnLeft(random - left - 1)) &&			// czy po lewej statki nie beda siê stykaæ
								!(Board::isShipAbove(random - left - 2)) &&			// czy po lewej od góry statki nie beda siê stykaæ
								!(Board::isShipBelow(random - left - 2)))))			//czy po lewej od do³u statki nie beda siê stykaæ
					{
						threes[right + 1] = random - left - 1;
						left++;
					}
					else {
						shipIsPlaced = false;
						break;
					}
				}
			}
		}
		if (direction == 0 ) {
			for (int down = 0; down < ((shipLenght - 1) * 10); down = down + 10) {
				if (!(Board::isLowerEdgeTile(random + down - up)) &&						//sprawdzenie : czy random jest doln¹ krawêdz¹
					!(Board::isShipBelow(random + down - up)) &&							// czy z do³u random jest statek
					!(Board::isShipOnLeft(random + down -up + 10)) &&					// czy w lewym dolnym random jest statek
					!(Board::isShipOnRight(random + down + 10)) &&					// czy w prawym dolnym jest statek

					(Board::isLowerEdgeTile(random + down - up+ 10) ||					//czy kafelek z do³u nie jest krawêdzi¹
						(!(Board::isShipBelow(random + down - up+ 10)) &&				// czy po z do³u statki nie beda siê stykaæ
							!(Board::isShipOnLeft(random + down - up+ 20)) &&			// czy po lewej od do³u statki nie beda siê stykaæ
							!(Board::isShipOnRight(random + down - up + 20)))))			//czy po prawej od do³u statki nie beda siê stykaæ
				{
					threes[(down / 10) + 1] = random + down + 10;
				}
				else
				{

					if (!(Board::isUpperEdgeTile(random - up)) &&					//sprawdzenie : czy random jest górn¹ krawêdz¹
						!(Board::isShipAbove(random - up)) &&						// czy z góry random jest statek
						!(Board::isShipOnLeft(random - up - 10)) &&					// czy w lewym górnym random jest statek
						!(Board::isShipOnRight(random - up - 10)) &&				// czy w prawym gornym jest statek

						(Board::isUpperEdgeTile(random - up - 10) ||				//czy kafelek z z góry nie jest krawêdzi¹
							(!(Board::isShipAbove(random - up - 10)) &&				// czy z góry statki nie beda siê stykaæ
								!(Board::isShipOnLeft(random - up - 20)) &&			// czy po lewej od góry statki nie beda siê stykaæ
								!(Board::isShipOnRight(random - up - 20)))))		//czy po prawej od góry statki nie beda siê stykaæ
					{
						threes[(down / 10) + 1] = random - up - 10;
						up = up + 10;
					}
					else {
						shipIsPlaced =false;
						break;
					}
				}
			}
		}
	}
	return shipIsPlaced;

}

void Board::saveShipsPosition(int shipLenght, int threes[]) 
{
	switch (shipLenght) {
	case 4:
		Board::board[threes[0]].shipPlaced = true;
		Board::board[threes[1]].shipPlaced = true;
		Board::board[threes[2]].shipPlaced = true;
		Board::board[threes[3]].shipPlaced = true;

		Board::four[0] = threes[0];
		Board::four[1] = threes[1];
		Board::four[2] = threes[2];
		Board::four[3] = threes[3];

		Board::board[threes[0]].belonging = "four";		//zapisanie przynale¿noœci
		Board::board[threes[1]].belonging = "four";
		Board::board[threes[2]].belonging = "four";
		Board::board[threes[3]].belonging = "four";

		break;
	case 3:
		Board::board[threes[0]].shipPlaced = true;
		Board::board[threes[1]].shipPlaced = true;
		Board::board[threes[2]].shipPlaced = true;

		if (Board::three1[0] == -1) {					//zapisanie indeksów
			Board::three1[0] = threes[0];
			Board::three1[1] = threes[1];
			Board::three1[2] = threes[2];

			Board::board[threes[0]].belonging = "three1";
			Board::board[threes[1]].belonging = "three1";
			Board::board[threes[2]].belonging = "three1";
		}
		else {
			Board::three2[0] = threes[0];
			Board::three2[1] = threes[1];
			Board::three2[2] = threes[2];

			Board::board[threes[0]].belonging = "three2";
			Board::board[threes[1]].belonging = "three2";
			Board::board[threes[2]].belonging = "three2";
		}


		break;
	case 2:

		Board::board[threes[0]].shipPlaced = true;
		Board::board[threes[1]].shipPlaced = true;

		if (Board::two1[0] == -1) {					//zapisanie indeksow
			Board::two1[0] = threes[0];
			Board::two1[1] = threes[1];

			Board::board[threes[0]].belonging = "two1";
			Board::board[threes[1]].belonging = "two1";


		}
		else {
			if (Board::two2[0] == -1) {
				Board::two2[0] = threes[0];
				Board::two2[1] = threes[1];

				Board::board[threes[0]].belonging = "two2";
				Board::board[threes[1]].belonging = "two2";
			}
			else {
				Board::two3[0] = threes[0];
				Board::two3[1] = threes[1];

				Board::board[threes[0]].belonging = "two3";
				Board::board[threes[1]].belonging = "two3";
			}
		}


		break;
	case 1:

		Board::board[threes[0]].shipPlaced = true;

		if (Board::one1 == -1)							//zapamiêtanie indeksów
		{
			Board::one1 = threes[0];
			Board::board[threes[0]].belonging = "one1";

		}
		else {
			if (Board::one2 == -1)
			{
				Board::one2 = threes[0];
				Board::board[threes[0]].belonging = "one2";
			}
			else {
				if (Board::one3 == -1)
				{
					Board::one3 = threes[0];
					Board::board[threes[0]].belonging = "one3";
				}
				else
				{
					Board::one4 = threes[0];
					Board::board[threes[0]].belonging = "one4";
				}
			}
		}

		break;
	}
}

void Board::showSetShips(int shipLenght, int threes[]) 
{
	switch (shipLenght) {
	case 4:
		Board::board[threes[0]].button.setFillColor(Board::board[threes[0]].black);
		Board::board[threes[1]].button.setFillColor(Board::board[threes[0]].black);
		Board::board[threes[2]].button.setFillColor(Board::board[threes[0]].black);
		Board::board[threes[3]].button.setFillColor(Board::board[threes[0]].black);
		break;
	case 3:
		Board::board[threes[0]].button.setFillColor(Board::board[threes[0]].black);
		Board::board[threes[1]].button.setFillColor(Board::board[threes[0]].black);
		Board::board[threes[2]].button.setFillColor(Board::board[threes[0]].black);
		break;
	case 2:
		Board::board[threes[0]].button.setFillColor(Board::board[threes[0]].black);
		Board::board[threes[1]].button.setFillColor(Board::board[threes[0]].black);
		break;
	case 1:
		Board::board[threes[0]].button.setFillColor(Board::board[threes[0]].black);
		break;
	}
}







