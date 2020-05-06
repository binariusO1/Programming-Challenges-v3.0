#include "Button.h"

Button::Button(float w, float h)
{
	this->colorDefault = sf::Color::Green;
	this->colorPressed = sf::Color::White;

	this->buttonWidth = w;
	this->buttonHeight = h;
	this->isPressed = false;
	this->press = false;

	this->buttonShape.setOrigin({ 0,0 });
	this->buttonShape.setFillColor(colorDefault);
	this->buttonShape.setSize({ buttonWidth, buttonHeight });
}
void Button::Press()
{
	if(isPressed)
	this->isPressed = false;
	else
	this->isPressed = true;
}
bool Button::GetState()
{
	if (isPressed) {
		//this->isPressed = false;
		return true;
	}
	else {
		return false;
	}
}
bool Button::GetStateAndReset()
{
	if (isPressed) {
		this->isPressed = false;
		return true;
	}
	else {
		return false;
	}
}
void Button::setPosition(float x, float y)
{
	this->buttonShape.setPosition(x, y);
}

void Button::update(sf::RenderWindow& window)
{
	auto mx = sf::Mouse::getPosition(window).x;
	auto my = sf::Mouse::getPosition(window).y;
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	if ( (mx <= (buttonShape.getPosition().x + buttonWidth) && mx >= (buttonShape.getPosition().x)) &&
		my <= (buttonShape.getPosition().y + buttonHeight) && my >= (buttonShape.getPosition().y) && press == false
		//&& (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		)
	{
		if ( (sf::Mouse::isButtonPressed(sf::Mouse::Left)) )
		{
			Press();
			press = true;
		}

	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && press == true)
		press = false;

	this->buttonShape.setFillColor(colorDefault);
	window.draw(this->buttonShape);

	if(isPressed)
	window.draw(this->textButtonPressed);
	else
	window.draw(this->textButtonDefault);
}
/*
void Button::setTextButton1(const char* txt,sf::Font & f, int s, sf::Color & c)
{
	this->textButtonDefault.setString(txt);
	this->textButtonDefault.setFont(f);
	this->textButtonDefault.setCharacterSize(s);
	this->textButtonDefault.setFillColor(c);
}
void Button::setTextButton2(const char* txt, sf::Font& f, int s, sf::Color& c)
{
	this->textButtonPressed.setString(txt);
	this->textButtonPressed.setFont(f);
	this->textButtonPressed.setCharacterSize(s);
	this->textButtonPressed.setFillColor(c);
}
*/