#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<iostream>
#include "Slider.h"
#include "Game.h"
#include "Button.h"

using namespace std;
using namespace sf;

int main()
{

	//window settings
	RenderWindow window{ VideoMode{1200,1000},"Game of Life" };
	window.setFramerateLimit(60);

	Font font;
	if (!font.loadFromFile("8bit.ttf"))
	{
		//(...) throw something
	}
	Slider slider1(10, 200, 750, 950, 1, 1, 8);
	Slider slider2(10, 200, 300, 950, 1, 1, 5);
	slider1.setBackgroundColor(140, 140, 140);
	slider1.setButtonColor(180, 180, 180);
	slider1.setFillColor(80, 80, 80);
	slider2.setBackgroundColor(140, 140, 140);
	slider2.setButtonColor(180, 180, 180);
	slider2.setFillColor(80, 80, 80);
	slider1.displayDescription("zoom out", font, 12);
	slider2.displayDescription("speed", font, 12);
	slider1.displayValue(0,8,0,false);
	slider2.displayValue(1, 51, 0,false);

	Button button1(150, 40);
	button1.setPosition(100, 925);
	button1.colorDefault=sf::Color{ 140, 140, 140,255 };
	button1.colorPressed = sf::Color{ 180, 180, 180,255 };

	Button button2(150, 40);
	button2.setPosition(550, 925);
	button2.colorDefault = sf::Color{ 140, 140, 140,255 };
	button2.colorPressed = sf::Color{ 180, 180, 180,255 };

	button1.textButtonDefault.setString("RESTART");
	button1.textButtonDefault.setFont(font);
	button1.textButtonDefault.setCharacterSize(18);
	button1.textButtonDefault.setFillColor(sf::Color::Black);
	button1.textButtonDefault.setPosition(135, 934);
	button1.textButtonPressed.setString("RESTART");
	button1.textButtonPressed.setFont(font);
	button1.textButtonPressed.setCharacterSize(18);
	button1.textButtonPressed.setFillColor(sf::Color::White);
	button1.textButtonPressed.setPosition(135, 934);

	button2.textButtonDefault.setString("NEXT");
	button2.textButtonDefault.setFont(font);
	button2.textButtonDefault.setCharacterSize(18);
	button2.textButtonDefault.setFillColor(sf::Color::Black);
	button2.textButtonDefault.setPosition(600, 934);
	button2.textButtonPressed.setString("NEXT");
	button2.textButtonPressed.setFont(font);
	button2.textButtonPressed.setCharacterSize(18);
	button2.textButtonPressed.setFillColor(sf::Color::White);
	button2.textButtonPressed.setPosition(600, 934);

	Game game;
	game.iterationText.setCharacterSize(18);
	game.iterationText.setFillColor(sf::Color::White);
	game.iterationText.setFont(font);
	game.iterationText.setPosition(980, 934);
	//window.setKeyRepeatEnabled(false);

	float timer = 0;
	float delay = 0.05f;
	Clock clock;

	Event eventMain;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		float scroll = 0;

		window.clear(Color::Black);
		while (window.pollEvent(eventMain))
		{
			if (eventMain.type == Event::KeyPressed)
			{
				if (eventMain.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
			else if(eventMain.type == sf::Event::MouseWheelMoved)
			{
				scroll += eventMain.mouseWheel.delta;
			}

			else if (eventMain.type == Event::Closed) {
				window.close();
				return 0;
			}
		}

		delay = (float)(1/slider2.getValue());
		//cout << slider2.getValue() << endl;
		if ((int)(round(slider2.getValue())) == 11) {
			delay = 0.85f;
			//cout << delay << endl;
		}
		else if ((int)(round(slider2.getValue())) == 21) {
			delay = 0.6f;
			//cout << delay << endl;
		}
		else if ((int)(round(slider2.getValue())) == 31) {
			delay = 0.35f;
			//cout << delay << endl;
		}
		else if ((int)(round(slider2.getValue())) == 41) {
			delay = 0.2f;
			//cout << delay << endl;
		}
		game.draw(window, (float)slider1.getValue(), timer, delay, button1.GetStateAndReset(), button2.GetStateAndReset());

		button1.update(window);
		button2.update(window);

		window.draw(slider1);
		slider1.update(window, scroll);
		window.draw(slider2);
		slider2.update(window, scroll);

		window.display();

	}
	return 0;
}