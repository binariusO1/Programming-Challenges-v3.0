#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Menu
{
public:
	Menu(float width, float height);
	~Menu() = default;

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int StatusKey(RenderWindow& window,sf::Event & event);
	int getPressedItem() { return selectedItemIndex; }
	void isNewGame();
	const char* inscription;
private:
	int selectedItemIndex;
	bool pc;
	static const int numberOfItems=3;
	Uint8 flashText;
	bool boolAlpha;
	Font menuFont;

	Text textMenu[numberOfItems] = {};
	Text textGameName;
	Text textGameScripts;
	Color colorNameFont;
};

