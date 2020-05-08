/*
# programming challenge
# Tetris
# C++ 17
# binariusO1
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include "Menu.h"
#include "Game.h"

using namespace std;
using namespace sf;

void GameOverScreen(RenderWindow& window)
{
	Font font;
	if (!font.loadFromFile("Arcade.ttf"))
	{
		//(...) throw something
	}
	Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setString("GAME OVER");
	text.setPosition((135), (660/2));
	text.setFillColor(Color::White);
	window.draw(text);
}
/*
void YouWinScreen(RenderWindow& window)
{
	Font font;
	if (!font.loadFromFile("Arcade.ttf"))
	{
		//(...) throw something
	}
	Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setString("YOU WIN");
	text.setPosition((600 / 2), (300));
	text.setFillColor(Color::White);
	window.draw(text);
}

void Stage(RenderWindow& window,int number)
{
	std::string s = "Stage " + std::to_string(number);
	char const* pchar = s.c_str();
	Font font;
	if (!font.loadFromFile("Arcade.ttf"))
	{
		//(...) throw something
	}
	Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setString(pchar);
	text.setPosition((600 / 2), (300));
	text.setFillColor(Color::White);
	window.draw(text);
}
*/
int main()
{
	//window settings
	RenderWindow window{ VideoMode{520,660},"Tetris" };
	window.setFramerateLimit(60);
	int statusWindow = 0;
	//menu settings
	Menu menu((float)window.getSize().x , (float)window.getSize().y);
	Game game;
	float timer = 0;
	float delay = 0.40f,delayC;
	delayC = delay;
	Clock clock;

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("Tetris.ogg"))
		return -1;

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	//sound.setPlayingOffset(sf::seconds(1.f));
	sound.setVolume(50.f);
	sound.setLoop(true);

	//window.setKeyRepeatEnabled(false);

	Event eventMenu;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		window.clear(Color::Black);

		while (window.pollEvent(eventMenu))
		{
			//0 MENU
			if(statusWindow == 0)
			{
				statusWindow = menu.StatusKey(window, eventMenu);
			}
			//2 GAME
			else if (statusWindow == 2)
			{
				statusWindow = game.StatusKey(window, eventMenu);
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.03f;
		else  delay = delayC;

		if(statusWindow==0) menu.draw(window);
		if (statusWindow == 1)
		{
				window.display();
				sleep(seconds(0.1f));
			menu.isNewGame();
			game.restart();
			statusWindow = 2;

		}
		if (statusWindow == 4)
		{
			for (int i = 0; i < 10; i++) {
				GameOverScreen(window);
				window.display();
				sleep(seconds(0.1f));
			}

			menu.isNewGame();
			game.restart();
			statusWindow = 0;

		}
		if (statusWindow == 2) {
			statusWindow = game.draw(window, timer, delay);
			if (game.points > 1000)
				delayC = 0.36f;
			if (game.points > 10000)
				delayC = 0.30f;
			if (game.points > 100000)
				delayC = 0.26f;
			if (game.points > 1000000)
				delayC = 0.22f;
		}

		window.display();

	}
	return 0;
}
