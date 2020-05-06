#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

struct Point {
	int x, y;
};

class Game
{
public:
	Game();
	~Game()
	{
		delete[] field;
	}
	int draw(RenderWindow& window,float & t, float d);
	int StatusKey(RenderWindow& window, sf::Event& event);
	void showScore();
	void showPoints();
	void restart();
	bool check();
	int points;
private:
	Texture texture;
	Texture frame;
	Text score;
	Text scorePoints;
	Sprite shape;
	Sprite nextShape;
	Sprite shapeFrame;
	Text next;
	Font font;
	Font font2;

	const int fieldHeight = 22;
	const int fieldWidth = 10;
	int** field;
	int dx;
	bool rotate;
	float delay;
	int colorNum;
	int actualFigure;
	int nextFigure;
	bool pause;
	const int figures[7][4]=
	{
	{ 1,3,5,7 },// |
	{ 2,4,5,7 },
	{ 3,5,4,6 },
	{ 3,5,4,7 },// T
	{ 2,3,5,7 },
	{ 3,5,7,6 },
	{ 2,3,4,5 }	// []
	};
	Point a[4] = {};
	Point b[4] = {};
	Point c[4] = {};

};

