#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	if (!font.loadFromFile("8bit.ttf"))
	{
		//(...) throw something
	}
	if (!font2.loadFromFile("Arcade.ttf"))
	{
		//(...) throw something
	}
	next.setFont(font);
	next.setCharacterSize(28);
	next.setFillColor(Color::White);
	next.setString("NEXT");
	next.setPosition(374, 451);//168

	this->texture.loadFromFile("texture.png");
	this->shape.setTexture(texture);
	this->shape.setTextureRect(IntRect(0, 0, 30, 30));
	this->frame.loadFromFile("frame.png");
	this->shapeFrame.setTexture(frame);

	this->dx = 0;
	this->rotate = false;
	this->colorNum = 0;
	delay = 0;
	pause = false;
	this->nextShape.setTexture(texture);
	this->nextShape.setTextureRect(IntRect(0, 0, 30, 30));
	restart();
}
int Game::draw(RenderWindow& window, float & t, float d)
{

	if(pause==false){
		srand((unsigned int)time(0));
		/////////////////////////////////////
		for (int i = 0; i < 4; i++) {
			b[i] = a[i];
			a[i].x += dx;

		}
		if (!check()) {
			for (int i = 0; i < 4; i++) {
				a[i] = b[i];
			}
		}
		/////////////////////////////////////
		if (this->rotate)
		{
			if (actualFigure != 6) 
			{
				Point p = a[1];
				if(actualFigure == 4)
					p = a[2];

				for (int i = 0; i < 4; i++){
					int x = a[i].y - p.y;
					int y = a[i].x - p.x;
					a[i].x = p.x - x;
					a[i].y = p.y + y;
				}
				if (!check()) {
					for (int j = 0; j < 4; j++) {
						a[j] = b[j];
					}
				}
			
			}
		}
		/////////////////////////////////////
		if (t > d){
			for (int i = 0; i < 4; i++){
				b[i] = a[i];
				a[i].y += 1;
			}
			if (!check()){

				for (int i = 0; i < 10; i++){
					if (field[2][i] == 1)
						return 4;
				}
				for (int i = 0; i < 4; i++){
					a[i].x = c[i].x;
					a[i].y = c[i].y;
				}
				this->actualFigure = nextFigure;

				for (int i = 0; i < 4; i++)
					field[b[i].y][b[i].x] = colorNum + 1;

				colorNum = 0;
				int n = rand() % 7;
				for (int i = 0; i < 4; i++)
				{
					c[i].x = figures[n][i] % 2+4;
					c[i].y = figures[n][i] / 2+1;
				}
				points += 4;
				this->nextFigure = n;
			}
			t = 0;
		}
		/////////////////////////////////////
		int k = fieldHeight - 1;
		int line = 0;
		for (int i = fieldHeight - 1; i > 1; i--){
			int count = 0;

			for (int j = 0; j < fieldWidth; j++){
				if (field[i][j]) {
					count++;
				}
				field[k][j] = field[i][j];
			}
			if (count < fieldWidth)
				k--;
			else
				line++;
		}

		if (line == 1)
			points += 40;
		else if (line == 2)
			points += 100;
		else if (line == 3)
			points += 300;
		else if (line == 4)
			points += 1200;
		line = 0;

	 }
	dx = 0, rotate = false;
	/////////////////////////////////////
	window.clear(sf::Color::Black);
	window.draw(this->shapeFrame);
	window.draw(this->next);
	window.draw(this->score);
	showPoints();
	window.draw(this->scorePoints);
	/////////////////////////////////////
	for (int i = 1; i < fieldHeight; i++){
		for (int j = 0; j < fieldWidth; j++){
			if (field[i][j] == 0) 
				continue;
			shape.setTextureRect(IntRect(field[i][j]*30,0,30,30));
			shape.setPosition((float)(j * 30), (float)(i * 30));
			shape.move(28, -29);	//starting point
			window.draw(this->shape);
		}
	}
		
	for (int i = 0; i < 4; i++){
		shape.setTextureRect(IntRect(colorNum * 30, 0, 30, 30));
		shape.setPosition((float)(a[i].x * 30), (float)(a[i].y * 30));
		shape.move(28, -29); 	//starting point
		window.draw(this->shape);

		nextShape.setTextureRect(IntRect(2 * 30, 0, 30, 30));
		nextShape.setPosition((float)(c[i].x * 30), (float)(c[i].y * 30));
		nextShape.move(388-120, 481);	//starting point
		window.draw(this->nextShape);
	}
	if (pause == true) {

		Text text;
		text.setFont(font);
		text.setCharacterSize(100);
		text.setString("PAUSE");
		text.setPosition((100), (660 / 2));
		text.setFillColor(Color::White);
		window.draw(text);
	}
	return 2;
}
int Game::StatusKey(RenderWindow& window, sf::Event& event)
{


	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape){
			return 0;
		}
		else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Space) {
			this->rotate = true;
			return 2;
		}
		else if (event.key.code == sf::Keyboard::Left) {
			dx = -1;
			return 2;
		}
		else if (event.key.code == sf::Keyboard::Right) {
			dx = 1;
			return 2;
		}
		else if (event.key.code == sf::Keyboard::P) {
			if (pause == false)
				pause = true;
			else
				pause = false;
			return 2;
		}
		else return 2;
	}
	else if (event.type == Event::Closed)
	{
		window.close();
		return 0;
	}
	return 2;
}
bool Game::check()
{
	for (int i = 0; i < 4; i++) 
	{
			if (a[i].x < 0 || a[i].x >= fieldWidth || a[i].y >= fieldHeight) {
				return 0;
			}
			else if (field[a[i].y][a[i].x]){
				cout << "~!" << endl;
				return 0;
			}
	}
	return 1;
};
void Game::restart()
{
	srand((unsigned int)time(NULL));

	delete[] field;

	this->field = new int* [fieldHeight];
	for (int i = 0; i < fieldHeight; ++i)
		field[i] = new int[fieldWidth] {};
	int n = rand() % 7;
	for (int i = 0; i < 4; i++)
	{
		a[i].x = figures[n][i] % 2+4;
		a[i].y = figures[n][i] / 2+1;
	}
	this->actualFigure = n;

	n = rand() % 7;
	for (int i = 0; i < 4; i++)
	{
		c[i].x = figures[n][i] % 2+4;
		c[i].y = figures[n][i] / 2+1;
	}
	this->nextFigure = n;
	points = 4;
	showPoints();
	showScore();
	this->pause = false;
}
void Game::showScore()
{
	score.setFont(font);
	score.setCharacterSize(30);
	score.setString("SCORE");
	score.setPosition((374), (200));
	score.setFillColor(Color::White);
}
void Game::showPoints()
{
	scorePoints.setFont(font);
	scorePoints.setCharacterSize(30);
	scorePoints.setString(to_string(points));
	scorePoints.setPosition((374), (240));
	scorePoints.setFillColor(Color::White);
}