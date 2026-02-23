#include"Headers.h"
#include"Button.h"


void Button::createButton(int x, int y, int width, int height, std::string tag) {
	Button::bX = x;
	Button::bY = y;
	Button::bWidth = width;
	Button::bHeight = height;
	Button::butttonTag = tag;
	

	sf::Vector2f position = sf::Vector2f(bX, bY);
	sf::Vector2f size = sf::Vector2f(bWidth, bHeight);

	Button::button.setPosition(position);
	Button::button.setFillColor(Button::normal);
	Button::button.setSize(size);
	Button::button.setOutlineThickness(Button::outlineThickness);
	Button::button.setOutlineColor(white);
}

void Button::setButtonTitle(std::string buttinTitle, int xTitle, int yTitle, int fontSize)
{
	if (!font.loadFromFile("TWOFOLD uncomplete DeSigN.ttf"))
	{
		std::cerr << "Nie zaladowano czcionki!\t";
		exit(1);
	}


	Button::buttonTitle.setFont(font);
	Button::buttonTitle.setString(buttinTitle);
	Button::buttonTitle.setCharacterSize(fontSize);
	Button::buttonTitle.setFillColor(sf::Color(255, 255, 255));
	Button::buttonTitle.setStyle(sf::Text::Bold);
	Button::buttonTitle.setPosition(Button::bX+xTitle, Button::bY+yTitle);
}


bool Button::isButtonClicked(sf::Vector2i &mouse) const{
	if (Button::buttonActive && Button::bX < mouse.x && (Button::bX + Button::bWidth)>mouse.x && Button::bY < mouse.y && (Button::bY + Button::bHeight)>mouse.y) 
		{
		return true;
		}
	else
	{
		return false;
	}

}


void Button::buttonMarked(bool state)
{
	if(state)
	Button::button.setFillColor(Button::black);
	else
		Button::button.setFillColor(Button::normal);
}


