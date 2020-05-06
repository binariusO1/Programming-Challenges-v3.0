#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Slider.h"
#include "Ulam Spiral.h"
#include <iostream>


int main()
{
	sf::RenderWindow window{ sf::VideoMode{1200,1000},"Collatz conjecture" };
	window.setFramerateLimit(60);

	sf::Font font;
	if (!font.loadFromFile("8bit.ttf"))
	{
		//(...) throw something
	}
	Slider slider1(10,800, 50,950,true,false,400);
	slider1.setButtonColor(128, 128, 128);
	slider1.setBackgroundColor(255, 255, 255);
	slider1.setFillColor(176, 255, 230);
	slider1.displayDescription("Size: ", font, 12);
	slider1.displayValue(1, 801,0);
	
	UlamSpiral tree(1200, 960, 9);

	sf::Event Event;
	while (window.isOpen()) {
		float scroll = 0;
		while (window.pollEvent(Event)) {
			
			if (Event.type == sf::Event::MouseWheelMoved) {
				scroll+= Event.mouseWheel.delta;
			}
			if (Event.type == sf::Event::KeyPressed ) {
				if (Event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
			if (Event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();

		window.draw(slider1);
		slider1.update(window, scroll);

		window.draw(tree);
		tree.update(window, (unsigned)slider1.getValue());

		window.display();
		window.clear(sf::Color::Black);
	}
	return 0;
}