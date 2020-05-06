#include "Menu.h"
#include <iostream>
using namespace sf;
using namespace std;

Menu::Menu(float width, float height) : inscription("Play")
{
	if (!menuFont.loadFromFile("Arcade.ttf"))
	{
		//(...) throw something
	}
	textGameName.setFont(menuFont);
	textGameName.setCharacterSize(150);
	textGameName.setFillColor(Color::White);
	textGameName.setString("Tetris");
	textGameName.setPosition( (width / 4)-100, 0);//168

	textMenu[0].setFont(menuFont);
	textMenu[0].setCharacterSize(100);
	textMenu[0].setFillColor(Color::White);
	textMenu[0].setString(inscription);
	textMenu[0].setPosition( Vector2f(width/2-200 , (height/ (numberOfItems+1)*1)-0) );

	textMenu[1].setFont(menuFont);
	textMenu[1].setCharacterSize(100);
	textMenu[1].setFillColor(Color::Cyan);
	textMenu[1].setString("New Game");
	textMenu[1].setPosition(Vector2f(width / 2-200, (height / (numberOfItems + 1)*2)-50));

	textMenu[2].setFont(menuFont);
	textMenu[2].setCharacterSize(100);
	textMenu[2].setFillColor(Color::Cyan);
	textMenu[2].setString("Exit");
	textMenu[2].setPosition(Vector2f(width / 2-200, (height / (numberOfItems + 1) * 3)-100));

	selectedItemIndex = 0;
	
	textGameScripts.setFont(menuFont);
	textGameScripts.setCharacterSize(30);
	textGameScripts.setString("by Binarius01");
	textGameScripts.setPosition( (width / 2 - 50) , ((height / (numberOfItems + 1) * 3) +80) );//168
	pc = true;
	boolAlpha = true;
	flashText = 255;
}

void Menu::draw(RenderWindow& window)
{
	window.draw(textGameName);
	textMenu[0].setString(inscription);
	for (unsigned i = 0; i < numberOfItems; i++)
	{
		if (pc == true && i == 1) {
		}
		else
			window.draw(textMenu[i]);
	}
	if (pc == false) {
		this->inscription = "Continue";
	}
	else {
		this->inscription = "Play";
	}
	window.draw(textGameScripts);

	textMenu[selectedItemIndex].setFillColor(sf::Color(255, 255, 255, flashText));

	if (boolAlpha == true) {
		flashText-=4;
		if (flashText <= 100) {
			boolAlpha = false;
		}
	}
	else {
			flashText += 4;
		if (flashText >= 255) {
				boolAlpha = true;
		}
	}
}
void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		textMenu[selectedItemIndex].setFillColor(Color::Cyan);
		selectedItemIndex--;
		if (pc == true)
			selectedItemIndex--;
		textMenu[selectedItemIndex].setFillColor(Color::White);
	}
}
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < numberOfItems)
	{
		textMenu[selectedItemIndex].setFillColor(Color::Cyan);
		selectedItemIndex++;
		if (pc == true)
			selectedItemIndex++;
		textMenu[selectedItemIndex].setFillColor(Color::White);
	}
}

int Menu::StatusKey(RenderWindow& window,sf::Event& event)
{
	if (event.type == Event::KeyPressed){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			this->MoveUp();
			return 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			this->MoveDown();
			return 0;
		}
		if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space){
			switch (this->getPressedItem()){
			case 0:
				cout << "New game" << endl;
				if (pc == false) {
				}
				else {
					pc = false;
					this->inscription = "Continue";
				}
				return 2;
				break;
			case 1:
				cout << "New game" << endl;
				return 1;
				break;
			case 2:
				window.close();
				return 0;
				break;
			default:
				break;
			}
		}
		if (event.key.code == sf::Keyboard::Escape){
			window.close();
			return 0;
		}
	}
	else if (event.type == Event::Closed){
		window.close();
		return 0;
	}
	else{
		return 0;
	}
	return 0;
}
void Menu::isNewGame()
{
	this->pc = false;
	this->inscription = "Continue";

	for (unsigned i = 0; i < numberOfItems; i++)
	{
		textMenu[i].setFillColor(Color::Cyan);
	}
	selectedItemIndex = 0;
	textMenu[0].setFillColor(Color::White);
}