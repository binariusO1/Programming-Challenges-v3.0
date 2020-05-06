#include "Game.h"
#include <iostream>
using namespace std;
Game::Game()
{

	this->texture.loadFromFile("texture.tga");
	this->square.setTexture(texture);
	this->square.setTextureRect(sf::IntRect(10, 0, 10, 10));

	this->texturebackground.loadFromFile("background.tga");
	this->background.setTexture(texturebackground);
	this->background.setTextureRect(sf::IntRect(0, 0, 44, 44));

	this->textureframe.loadFromFile("frame.tga");
	this->frameVer.setTexture(textureframe);
	this->frameVer.setTextureRect(sf::IntRect(0, 0, 24, 900-4+50));

	this->frameHor.setTexture(textureframe);
	this->frameHor.setTextureRect(sf::IntRect(0, 0, 1200, 24));

	this->downBar.setTexture(textureframe);
	this->downBar.setTextureRect(sf::IntRect(0, 0, 1200, 200));

	//7 275 elements
	this->fieldHeight = 296/4;
	this->fieldWidth = 384/4;
	this->field = new int* [fieldHeight];
	for (int i = 0; i < fieldHeight; ++i)
		field[i] = new int[fieldWidth];

	//116 400 elements
	this->lifeFieldHeight = 296+4;
	this->lifeFieldWidth = 384+4;
	this->lifeField = new int* [lifeFieldHeight];
	for (int i = 0; i < lifeFieldHeight; ++i)
		lifeField[i] = new int[lifeFieldWidth];

	this->otherWorld = new int* [lifeFieldHeight];
	for (int i = 0; i < lifeFieldHeight; ++i)
		otherWorld[i] = new int[lifeFieldWidth];
	//
	//	initialize some values
	//
	toggle = true;
	zoom = 1;
	iteration = 0;
	restart();
}
void Game::draw(sf::RenderWindow& window, float z, float& t, float d,bool r,bool s)
{
	zoom = round(z);

	//equalization
	int tre[] = { 0,44,44 + 40,44 + 40 + 36,44 + 40 + 36 + 32,44 + 40 + 36 + 32 + 28,
	44 + 40 + 36 + 32 + 28 + 24,44 + 40 + 36 + 32 + 28 + 24 + 20,44 + 40 + 36 + 32 + 28 + 24 + 20 + 16,
	44 + 40 + 36 + 32 + 28 + 24 + 20 + 16 + 12, 44 + 40 + 36 + 32 + 28 + 24 + 20 + 16 + 8 };
	int comX[] = { 2,4,6,8,10,12,14,16,18 };
	int comY[] = { 2,4,6,8,10,12,14,16,18 };

	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidth; j++) {
			if (field[i][j] == 0)
				continue;
			this->background.setTextureRect(sf::IntRect(tre[(int)zoom], 0, (int)(44 - zoom * 4), (int)(44 - zoom * 4)));//11,
			background.setPosition((float)(j * (44 - zoom * 4)), (float)(i * (44 - zoom * 4)));
			background.move(28 - 3-((((8 - zoom) * (fieldWidth*4)) / 2)), 
				((20+9 +  (zoom * 4) - 36) - (((8 - zoom) * (fieldHeight*4) / 2))
				));
			window.draw(this->background);
		}
	}
	if (r == true)
		restart();
	else
	{
		for (int i = 0; i < lifeFieldHeight; i++) {
			for (int j = 0; j < lifeFieldWidth; j++) {
				if (lifeField[i][j] == 0 && otherWorld[i][j] == 0)
					continue;
				if ((lifeField[i][j] == 1 && iteration%2==1 && otherWorld[i][j] == 0) || (otherWorld[i][j] == 1 && iteration % 2 == 0 && lifeField[i][j] == 0))
					continue;
				//if ()
				//	continue;
				this->square.setTextureRect(sf::IntRect(11, 0, (int)(10 - zoom), (int)(10 - zoom)));//11,
				square.setPosition((float)(j * (11 - zoom)), (float)(i * (11 - zoom)));
				square.move(25-18 -6- (((8 - zoom) * (fieldWidth * 2)) ) + comX[(int)zoom]
					, ((17-17+6-1 + (zoom * 4) - 36) - ((8 - zoom) * (fieldHeight * 2))+ comY[(int)zoom]
					));
				window.draw(this->square);
			}
		}
		if ((t > d&& d != 1) || (s==1 && d==1 )) 
		{
			update();
			iteration++;
			t = 0;
		}
	}
	
	//equalization
	int sX[] = { 141,136,129,121,111,97,77,49,0 };
	int sY[] = { 112,108,103,96,88,77,62,38,0 };
	int moX[] = { 1,0,3,1,0,0,3,0,0 };
	int moY[] = { 0,0,-1,1,0,0,-1,2,0 };
	auto mx = sf::Mouse::getPosition(window).x;
	auto my = sf::Mouse::getPosition(window).y;
	int Cmx = sf::Mouse::getPosition(window).x - 20+moX[(int)zoom];
	int Cmy = sf::Mouse::getPosition(window).y - 19+moY[(int)zoom];

	if ((mx <= (1200-23-1) && mx >= (26)) &&
		my >= (19+7) && my <= (912) && isPressed == false
		)
	{
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			int fx = (int)(Cmy / (11 - zoom)) + sY[(int)zoom];
			int fy = (int)(Cmx / (11 - zoom)) + sX[(int)zoom];
			//cout << "Cmy: " << Cmy/3 << " " << "Cmx" << Cmx/3 << endl;
			if (lifeField[fx][fy] == 0) {
				lifeField[fx][fy] = 1;
				otherWorld[fx][fy] = 1;
			}
			else {
				lifeField[fx][fy] = 0;
				otherWorld[fx][fy] = 0;
			}
			isPressed = true;
		}

	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && isPressed == true)
		isPressed = false;

	//delete bounds [2][width/heigth]
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < lifeFieldWidth; j++) {
			if (lifeField[i][j] == 1 && otherWorld[i][j] == 1) {
				lifeField[i][j] = 0;
				otherWorld[i][j] = 0;
			}

		}
	}
	for (int i = lifeFieldHeight - 2; i < lifeFieldHeight; i++) {
		for (int j = 0; j < lifeFieldWidth; j++) {
			if (lifeField[i][j] == 1 && otherWorld[i][j] == 1) {
				lifeField[i][j] = 0;
				otherWorld[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < lifeFieldHeight; i++) {
		for (int j = 0; j < 2; j++) {
			if (lifeField[i][j] == 1 && otherWorld[i][j] == 1) {
				lifeField[i][j] = 0;
				otherWorld[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < lifeFieldHeight; i++) {
		for (int j = lifeFieldWidth - 2; j < lifeFieldWidth; j++) {
			if (lifeField[i][j] == 1 && otherWorld[i][j] == 1) {
				lifeField[i][j] = 0;
				otherWorld[i][j] = 0;
			}
		}
	}

	////////////////////////////////
	frameVer.setPosition(0,0);
	window.draw(this->frameVer);
	frameVer.setPosition(1200-23, 0);
	window.draw(this->frameVer);
	frameHor.setPosition(0, 0);
	window.draw(this->frameHor);
	downBar.setPosition(0, 900-4-5+22);
	window.draw(this->downBar);

	std::string it = to_string(iteration);
	std::string f = "iteration: " +it;
	this->iterationText.setString(f);

	window.draw(this->iterationText);
}

////////////////////////////////////////////////////////////////

void Game::update() {
	if (toggle) {
		for (int i = 0; i < lifeFieldHeight; i++) {
			for (int j = 0; j < lifeFieldWidth; j++) {
				otherWorld[i][j] = getState(lifeField[i][j], i, j, toggle);
			}
		}
		toggle = !toggle;
	}
	else {
		for (int i = 0; i < lifeFieldHeight; i++) {
			for (int j = 0; j < lifeFieldWidth; j++) {
				lifeField[i][j] = getState(otherWorld[i][j], i, j, toggle);
			}
		}
		toggle = !toggle;
	}
}

char Game::getState(int state, int yCoord, int xCoord, bool t) {
	this->toggle = t;
	int neighbors = 0;
	if (toggle) {
		for (int i = yCoord - 1; i <= yCoord + 1; i++) {
			for (int j = xCoord - 1; j <= xCoord + 1; j++) {
				if (i == yCoord && j == xCoord) {
					continue;
				}
				if (i > -1 && i < lifeFieldHeight && j > -1 && j < lifeFieldWidth) {
					if (lifeField[i][j] == 1) {
						neighbors++;
					}
				}
			}
		}
	}
	else {
		for (int i = yCoord - 1; i <= yCoord + 1; i++) {
			for (int j = xCoord - 1; j <= xCoord + 1; j++) {
				if (i == yCoord && j == xCoord) {
					continue;
				}
				if (i > -1 && i < lifeFieldHeight && j > -1 && j < lifeFieldWidth) {
					if (otherWorld[i][j] == 1) {
						neighbors++;
					}
				}
			}
		}
	}
	if (state == 1) {
		return (neighbors > 1 && neighbors < 4) ? 1 : 0;
	}
	else {
		return (neighbors == 3) ? 1 : 0;
	}
}
void Game::restart()
{
	isPressed = false;
	toggle = true;
	iteration = 0;

	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidth; j++) {
			field[i][j] = 1;
		}
	}

	for (int i = 0; i < lifeFieldHeight; i++) {
		for (int j = 0; j < lifeFieldWidth; j++) {
			otherWorld[i][j] = 0;
		}
	}
	for (int i = 0; i < lifeFieldHeight; i++) {
		for (int j = 0; j < lifeFieldWidth; j++) {
			lifeField[i][j] = 0;
		}
	}

	//Gliders test
	/*
	lifeField[296 / 2]		[384 / 2 + 1]	= 1;
	lifeField[296 / 2 + 1]	[384 / 2 + 2]	= 1;
	lifeField[296 / 2 + 2]	[384 / 2]		= 1;
	lifeField[296 / 2 + 2]	[384 / 2 + 1]	 = 1;
	lifeField[296 / 2 + 2]	[384 / 2 + 2]	= 1;

	lifeField[96 / 2][384 / 2 + 1] = 1;
	lifeField[96 / 2 + 1][384 / 2 + 0] = 1;
	lifeField[96 / 2 + 2][384 / 2] = 1;
	lifeField[96 / 2 + 2][384 / 2 + 1] = 1;
	lifeField[96 / 2 + 2][384 / 2 + 2] = 1;

	lifeField[76 / 2][384 / 2 + 1] = 1;
	lifeField[76 / 2 + 1][384 / 2 + 2] = 1;
	lifeField[76 / 2 + 2][384 / 2] = 1;
	lifeField[76 / 2 + 2][384 / 2 + 1] = 1;
	lifeField[76 / 2 + 2][384 / 2 + 2] = 1;

	lifeField[46 / 2+2][384 / 2 + 1] = 1;
	lifeField[46 / 2 + 1][384 / 2 + 2] = 1;
	lifeField[46 / 2 + 0][384 / 2] = 1;
	lifeField[46 / 2 + 0][384 / 2 + 1] = 1;
	lifeField[46 / 2 + 0][384 / 2 + 2] = 1;
	*/
}
