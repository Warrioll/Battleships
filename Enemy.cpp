#include "Enemy.h"


 void Enemy::createEnemyBoard(){
	Board::setBoardPosition(900, 200);
	Board::createBoard();


	std::srand(time(NULL));
	Enemy::setEnemyShip(4);
	
	Enemy::setEnemyShip(3);
	Enemy::setEnemyShip(3);
	
	Enemy::setEnemyShip(2);
	Enemy::setEnemyShip(2);
	Enemy::setEnemyShip(2);
	
	Enemy::setEnemyShip(1);
	Enemy::setEnemyShip(1);
	Enemy::setEnemyShip(1);
	Enemy::setEnemyShip(1);
	

}

 void Enemy::enemyBoardAction(sf::Vector2i& mouse, Board &playerBoard)
 {
	 for (int i = 0; i < 100; i++) {

		 if (Board::board[i].isButtonClicked(mouse)) {
			 Board::board[i].buttonActive = false;

			 if (Board::board[i].shipPlaced) {
				 Board::isShipDestroyed(i);
			 }
			 else
			 {
				 Board::board[i].boardButtonAction(0);
				 Enemy::enemyTurn = true;

				 Board::setStrikeInfo(1);
				 playerBoard.setStrikeInfo(0);
			 }

			 Enemy::enmeyStrikeTimer = clock(); 
		 }
	 }

 }

void Enemy::setEnemyShip(int shipLenght)
{
	int random, direction, threes[4];

	do {
		for (int i = 0;i < 4;i++) {
			threes[i] = -1;
		}
		random = rand() % 100;
		direction = rand() % 2;
	} while (!(Board::chooseShipsPosition(shipLenght,random,direction,threes)));
	Enemy::saveShipsPosition(shipLenght, threes);
}

void Enemy::enemyStrike(Board& playerBoard)
{
	int strike;
	int direction=-1;
	
	
	if (Enemy::enemyTurn) {
		if (Enemy::playerShipDamaged == -1) {
			do {
				strike = rand() % 100;
			} while (!(playerBoard.board[strike].buttonActive));
		}
		else {


			bool aimed = true;
			if ((Board::isLeftEdgeTile(Enemy::playerShipDamaged) || !playerBoard.board[Enemy::playerShipDamaged - 1].buttonActive) &&
				(Board::isRightEdgeTile(Enemy::playerShipDamaged) || !playerBoard.board[Enemy::playerShipDamaged + 1].buttonActive) &&
				(Board::isUpperEdgeTile(Enemy::playerShipDamaged) || !playerBoard.board[Enemy::playerShipDamaged - 10].buttonActive) &&
				(Board::isUpperEdgeTile(Enemy::playerShipDamaged) || !playerBoard.board[Enemy::playerShipDamaged - 10].buttonActive)) {
				if (Enemy::playerShipDamaged == Enemy::playerShipStart) {
					do {
						strike = rand() % 100;
					} while (!(playerBoard.board[strike].buttonActive));
					aimed = false;
				}
				else {
					Enemy::playerShipDamaged = Enemy::playerShipStart;
					

					switch (Enemy::strikeDirection) {
					case 0:
						Enemy::strikeDirection = 1;
						break;
					case 1:
						Enemy::strikeDirection = 0;
						break;
					case 2:
						Enemy::strikeDirection = 3;
						break;
					case 3:
						Enemy::strikeDirection = 2;
						break;
					}
				}
			}
			if(aimed){
				aimed = false;
				while (!aimed) {
					if (Enemy::strikeDirection == -1) {
						direction = rand() % 4;
					}
					else
						direction = Enemy::strikeDirection;

					switch (direction) {
					case 0:
						if (!(Board::isLeftEdgeTile(Enemy::playerShipDamaged)) && playerBoard.board[Enemy::playerShipDamaged - 1].buttonActive) {
							strike = Enemy::playerShipDamaged - 1;
							aimed = true;
						}
						else
							Enemy::strikeDirection = -1;
						break;
					case 1:
						if (!(Board::isRightEdgeTile(Enemy::playerShipDamaged)) && playerBoard.board[Enemy::playerShipDamaged + 1].buttonActive) {
							strike = Enemy::playerShipDamaged + 1;
							aimed = true;
						}
						else
							Enemy::strikeDirection = -1;
						break;

					case 2:
						if (!(Board::isUpperEdgeTile(Enemy::playerShipDamaged)) && playerBoard.board[Enemy::playerShipDamaged - 10].buttonActive) {
							strike = Enemy::playerShipDamaged - 10;
							aimed = true;
						}
						else
							Enemy::strikeDirection = -1;

						break;
					case 3:
						if (!(Board::isLowerEdgeTile(Enemy::playerShipDamaged)) && playerBoard.board[Enemy::playerShipDamaged + 10].buttonActive) {
							strike = Enemy::playerShipDamaged + 10;
							aimed = true;
						}
						else
							Enemy::strikeDirection = -1;
						break;
					}

				}
		}
			}
					

		
		if (playerBoard.board[strike].shipPlaced && playerBoard.board[strike].buttonActive) {
			playerBoard.board[strike].buttonActive = false;
			Enemy::enmeyStrikeTimer = clock();
			if (Enemy::playerShipDamaged == -1)
				Enemy::playerShipStart = strike;
			Enemy::playerShipDamaged = strike;
			Enemy::strikeDirection = direction;
			playerBoard.isShipDestroyed(strike);
			if (playerBoard.board[strike].belonging == "four" && playerBoard.fourDestroyed)
			{
				Enemy::playerShipDamaged = -1;
				Enemy::strikeDirection = -1;
			}
			if (playerBoard.board[strike].belonging == "three1" && playerBoard.three1Destroyed)
			{
				Enemy::playerShipDamaged = -1;
				Enemy::strikeDirection = -1;
				Enemy::playerShipStart= -1;
			}
			if (playerBoard.board[strike].belonging == "three2" && playerBoard.three2Destroyed)
			{
				Enemy::playerShipDamaged = -1;
				Enemy::strikeDirection = -1;
				Enemy::playerShipStart = -1;
			}
			if (playerBoard.board[strike].belonging == "two1" && playerBoard.two1Destroyed)
			{
				Enemy::playerShipDamaged = -1;
				Enemy::strikeDirection = -1;
				Enemy::playerShipStart = -1;
			}
			if (playerBoard.board[strike].belonging == "two2" && playerBoard.two2Destroyed)
			{
				Enemy::playerShipDamaged = -1;
				Enemy::strikeDirection = -1;
				Enemy::playerShipStart = -1;
			}
			if (playerBoard.board[strike].belonging == "two3" && playerBoard.two3Destroyed)
			{
				Enemy::playerShipDamaged = -1;
				Enemy::strikeDirection = -1;
				Enemy::playerShipStart = -1;
			}
			if (playerBoard.board[strike].belonging == "one1" && playerBoard.one1Destroyed)
			{
				Enemy::playerShipDamaged = -1;
				Enemy::strikeDirection = -1;
				Enemy::playerShipStart = -1;
			}
			if (playerBoard.board[strike].belonging == "one2" && playerBoard.one2Destroyed)
			{
				Enemy::playerShipDamaged = -1;
				Enemy::strikeDirection = -1;
				Enemy::playerShipStart = -1;
			}
			if (playerBoard.board[strike].belonging == "one3" && playerBoard.one3Destroyed)
			{
				Enemy::playerShipDamaged = -1;
				Enemy::strikeDirection = -1;
				Enemy::playerShipStart = -1;
			}
			if (playerBoard.board[strike].belonging == "one4" && playerBoard.one4Destroyed)
			{
				Enemy::playerShipDamaged = -1;
				Enemy::strikeDirection = -1;
				Enemy::playerShipStart = -1;
				
			}
			//dorobiæ tutaj sprawdzanie czy zniszczony itp
		}
		else {
			playerBoard.board[strike].buttonActive = false;
			playerBoard.board[strike].boardButtonAction(0);
			Enemy::enemyTurn = false;
			Board::setStrikeInfo(0);

			playerBoard.setStrikeInfo(1);

			//Enemy::strikeDirection = -1;

			//swich do zostawienia tylko tam trzeba zabezpieczenia porobic
			
			if (Enemy::playerShipDamaged != -1 || !(Enemy::playerShipDamaged == Enemy::playerShipStart)) {
				switch (Enemy::strikeDirection) {
				case 0:
					Enemy::strikeDirection = 1;
					break;
				case 1:
					Enemy::strikeDirection = 0;
					break;
				case 2:
					Enemy::strikeDirection = 3;
					break;
				case 3:
					Enemy::strikeDirection = 2;
					break;
				}
				Enemy::playerShipDamaged = Enemy::playerShipStart;
			}

		}
	}


}




