#pragma once
#include "Headers.h"
#include "Board.h"
#include<cstdlib>

#include<ctime>

class Enemy:public Board {
	int playerShipDamaged = -1;
	int strikeDirection = -1;
	int playerShipStart = -1;
	

public:
	double enmeyStrikeTimer;
	bool enemyTurn = false;


	//tworzy plansze wroga i wyœwietla j¹ w podanym miejscu
	void createEnemyBoard();

	//zawiera pêtle i korzysta z metody buttonAction() z klasy Button
	void enemyBoardAction(sf::Vector2i& mouse, Board& playerBoard);

	void setEnemyShip(int shipLenght);
	void enemyStrike(Board& playerBoard);
};
