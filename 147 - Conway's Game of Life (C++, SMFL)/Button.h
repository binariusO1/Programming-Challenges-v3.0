#pragma once
#include <SFML/Graphics.hpp>
class Button
{
public:
	////////////////////////////////////////////////////////////
/// \
/// \param w        Width in pixels
/// \param h       Height in pixels
///	\
////////////////////////////////////////////////////////////
	Button(float w, float h);
	~Button() = default;
	void Press();
	
///###############################################################################################
//////////////////////////////////////////////////////////////////////////////////////////////////
/// \BUTTON SET
//////////////////////////////////////////////////////////////////////////////////////////////////
///###############################################################################################

	void setPosition(float x, float y);
	void update(sf::RenderWindow& window);

	//void setTextButton1(const char* txt, sf::Font& f, int s, sf::Color& c);
	//void setTextButton2(const char* txt, sf::Font& f, int s, sf::Color& c);
///###############################################################################################
//////////////////////////////////////////////////////////////////////////////////////////////////
/// \BUTTON GET
//////////////////////////////////////////////////////////////////////////////////////////////////
///###############################################################################################

	bool GetState();
	bool GetStateAndReset();
	sf::Text textButtonDefault;
	sf::Text textButtonPressed;
	sf::Color colorDefault;
	sf::Color colorPressed;
private:
	float buttonWidth;
	float buttonHeight;
	bool isPressed;
	bool press;

	sf::RectangleShape buttonShape;




};

