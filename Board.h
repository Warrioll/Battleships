#pragma once
#include "Headers.h"
#include "BoardButton.h"

class Board {
	int xBoard = 0, yBoard = 0;
	const int widthButton = 50, heightButton = 50;

	

	sf::Font font;

public:

	int one1 = -1, one2 = -1, one3 = -1, one4 = -1;
	int two1[2] = { -1,-1 }, two2[2] = { -1,-1 }, two3[2] = { -1,-1 };
	int three1[3] = { -1,-1, -1 }, three2[3] = { -1,-1,-1 };
	int four[4] = { -1,-1,-1,-1 };
	
	//BoardButton *board[100];
	BoardButton board[100];

	

	bool fourDestroyed = false,
		three1Destroyed = false, three2Destroyed = false,
		two1Destroyed = false, two2Destroyed = false, two3Destroyed = false,
		one1Destroyed = false, one2Destroyed = false, one3Destroyed = false, one4Destroyed = false;
	

	sf::Text strikeInfo;
	



	//zawiera petle i algorytm tworzacy plansze (u¿ywa metody createButton z klasy Button)
	void createBoard();

	//ustawia pozycjê planszy ??musi byæ przed create?? chyba trzeba wskazniki ¿eby nie
	void setBoardPosition(int x, int y);

	//zawiera petle u¿ywaj¹cej metody draw() do rysowania kwadratów
	void displayBoard(sf::RenderWindow& window) const;

	//jêsli ca³y statek zosta³ zniszczony oznacza pola jako zniszczony statek//, i ustawia komunikat o trafieniu
	void isShipDestroyed(int i);//, sf::Text& info); //, sf::Text& strikeInfo);

	// ustawia komunnikat strike info
	void setStrikeInfo(int state);




	//sprawdza czy wokól kratki nie ma postawionych innych statków
	bool isShipAround(int random) const;

	//sprawdzaja czy w danym kierunku nie ma statku
	bool isShipOnLeft(int random) const;
	//sprwadza czy jest po³o¿ony statek na prawo od random
	bool isShipOnRight(int random) const;
	//sprwadza czy  jest po³o¿ony statek ponad random
	bool isShipAbove(int random)const;
	//sprwadza czy jest po³o¿ony statek poni¿ej random
	bool isShipBelow(int random) const;

	//sprawdza czy kafelek (o wspó³¿êdnej random) jest przy prawej krawêdzi
	bool isRightEdgeTile(int random) const;
	//sprawdza czy kafelek (o wspó³¿êdnej random) jest przy lewej krawêdzi
	bool isLeftEdgeTile(int random)const ;
	//sprawdza czy kafelek (o wspó³¿êdnej random) jest przy górnej krawêdzi
	bool isUpperEdgeTile(int random) const;
	//sprawdza czy kafelek (o wspó³¿êdnej random) jest przy dolnej krawêdzi
	bool isLowerEdgeTile(int random)const;

	
	//sprawdza czy mo¿e ustawiæ statek w podanym kierunku (direction=1 poziomo/direction=0 pionowo)
	//bazuj¹c na wspó³¿êdnej random i liczbie masztów (shipLenght). Koordynaty umieszcza w tablicy threes 
	// UWAGA: funkcja zapisuje koordynaty w tablicy threes nie zale¿nie od tego co zwraca a wiêc czy rezyltacie false nie nale¿y u¿ywaæ wyników zapisanych w threes
	bool chooseShipsPosition(int shipLenght, int random, int direction, int *threes);

	//zapisuje koordynaty i przynale¿noœæ kafelków do statku o podanej d³ugosæi (shipLenght) z przekazanej tablicy threes
	void saveShipsPosition(int shipLenght, int threes[]);

	//ustawia kolor kafelkow na czarny zeby bylo widac gdzie sa ustaione
	void showSetShips(int shipLenght, int threes[]) ;

	};


