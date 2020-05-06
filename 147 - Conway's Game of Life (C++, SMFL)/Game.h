#pragma once
#include <SFML/Graphics.hpp>

#include <unordered_map>

class Game
{
public:
	Game();
	~Game()
	{
		delete[] field;
		delete[] lifeField;
		delete[] otherWorld;
	}
	void draw(sf::RenderWindow& window, float z, float& t, float d,bool r,bool s);
	void update();
	char getState(int state, int yCoord, int xCoord, bool t);
	void restart();

	sf::Text iterationText;
private:
	int** field;
	int** lifeField;
	int** otherWorld;

	int fieldHeight;
	int fieldWidth;
	int lifeFieldHeight;
	int lifeFieldWidth;
	float zoom;
	bool toggle;
	bool isPressed;
	int iteration;
	bool step;
	sf::Texture texture;
	sf::Texture texturebackground;
	sf::Texture textureframe;
	sf::Sprite square;
	sf::Sprite background;
	sf::Sprite frameHor;
	sf::Sprite frameVer;
	sf::Sprite downBar;
};


