#include"Headers.h"
#include "BoardButton.h"

BoardButton::BoardButton()
{
	Button::normal = BoardButton::boardButtonBlue; 

}

void BoardButton::boardButtonAction(int state){
	
		
		switch (state) {
		case 0:
				Button::button.setFillColor(BoardButton::missColor);
				break;
			case 1:
				Button::button.setFillColor(BoardButton::hitColor);
				break;
			case 2:
				Button::button.setFillColor(BoardButton::dystroyedColor);
				break;
			case 3:
				Button::button.setFillColor(BoardButton::setColor);
				break;
		
	}
}
