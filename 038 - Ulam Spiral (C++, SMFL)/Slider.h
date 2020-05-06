////////////////////////////////////////////////////////////
//
// Version: Pre-Alpha
// Date: 28-04-2020
// for SFML - Simple and Fast Multimedia Library
// Copyright (C) 2020 BinariusO1 https://github.com/binariusO1
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#pragma once
#include <SFML/Graphics.hpp>

////////////////////////////////////////////////////////////
/// \brief Simply slider class
///
////////////////////////////////////////////////////////////

class Slider : public sf::Drawable
{
public:
////////////////////////////////////////////////////////////
/// \
/// \param modeWidth        Width in pixels
/// \param modeHeight       Height in pixels
/// \param modeWidth        Position X in pixels
/// \param modeHeigh        Position Y in pixels
/// \bool position			1-vertical, 0-hotizontal
/// \bool fill				1-yes, 0-no
///	\
////////////////////////////////////////////////////////////
	Slider(float h, float w, float posx, float posy, bool fill = true, bool sit = false,float mul=1.f);
	Slider() = delete;
	virtual ~Slider() = default;

///###############################################################################################
//////////////////////////////////////////////////////////////////////////////////////////////////
/// \SLIDE BAR APPERANCE
//////////////////////////////////////////////////////////////////////////////////////////////////
///###############################################################################################

////////////////////////////////////////////////////////////
/// \brief Change position of slider bar
/// \
////////////////////////////////////////////////////////////
	void setPosition(float x, float y);

////////////////////////////////////////////////////////////
/// \brief Draw slider bar
/// \
////////////////////////////////////////////////////////////
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

////////////////////////////////////////////////////////////
/// \brief Update slider bar
/// \      Mouse Wheel Scroll should be catch in window event, and provide scroll value to the update function.
/// \      It is possible by use 'sf::Event::MouseWheelMoved' For example:
///		while (window.isOpen()) {
///			float scroll = 0;															
///			while (window.pollEvent(Event)) {
///				if (Event.type == sf::Event::MouseWheelMoved)
///					scroll += Event.mouseWheel.delta;
///			}
///			window.clear();
///			window.draw(slider1), slider1.update(window, scroll);
///		}
////////////////////////////////////////////////////////////
	void update(sf::RenderWindow& window, float scroll);

////////////////////////////////////////////////////////////
/// \brief Set color button bar in RGB
/// \
////////////////////////////////////////////////////////////
	void setButtonColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 alpha= (sf::Uint8)255);

////////////////////////////////////////////////////////////
/// \brief Set color of background bar in RGB
/// \
////////////////////////////////////////////////////////////
	void setBackgroundColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 alpha= (sf::Uint8)255);

////////////////////////////////////////////////////////////
/// \brief Set color of fill bar in RGB
/// \
////////////////////////////////////////////////////////////
	void setFillColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 alpha=(sf::Uint8)255);


///###############################################################################################
//////////////////////////////////////////////////////////////////////////////////////////////////
/// \TEXT DISPLAY SECTION
//////////////////////////////////////////////////////////////////////////////////////////////////
///###############################################################################################

////////////////////////////////////////////////////////////
/// \brief Display text under slidebar
/// \
////////////////////////////////////////////////////////////
	void displayDescription(const char* desc, sf::Font & font, unsigned int height);

	////////////////////////////////////////////////////////////
/// \brief Display Value under slidebar
/// \
////////////////////////////////////////////////////////////
	void displayValue(double min = 0, double max = 100,int prec=2);

////////////////////////////////////////////////////////////
/// \brief Get actual Value
/// \
////////////////////////////////////////////////////////////
	double getValue();

	////////////////////////////////////////////////////////////
/// \brief Set color Description and Value in RGB
/// \
////////////////////////////////////////////////////////////
	void setDisplayColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 alpha);
	
private:
	float height;
	float width;
	float buttonWidth{ 8 };
	float buttonAddonHeight{ 8 };
	float actualPosButton;
	float pathButton;
	bool buttonHeightlight;
	static bool isMousePressed;
	float fillWidth;
	double minValue;
	double maxValue;
	double multiple;
	double multipleS;
	int precision;
	unsigned int fontSize;
	sf::Color buttonColor;
	sf::Color backgroundColor;
	sf::Color fillColor;
	sf::Color textColor;
	sf::Font font;
	sf::Text description;
	sf::Text value;
	
	bool fill=false;
	bool situation;
	sf::RectangleShape buttonShape;
	sf::RectangleShape backgroundShape;
	sf::RectangleShape fillShape;

	std::string to_string_with_precision(double a_value);
};

