#include "Slider.h"
#include <sstream>	//double precision for to_string()


#include <iostream>
using namespace std;
//shape.setcale


Slider::Slider(float h, float w, float posx, float posy, bool f, bool sit, float mul)	: situation(sit) , fill(f)
{
	height = h;
	width = w;

	//(posy) |
	//		 V
	//////////////////////////////////////////////////////
	//													//
	//////////////////////////////////////////////////////
//->//(0,0) = Origin
	//(posx)

	//background
	backgroundShape.setOrigin({ height,width });
	backgroundShape.setPosition(posx, posy);
	backgroundShape.setSize({ height, width });
	backgroundShape.setFillColor(backgroundColor);

	//TODO: Add initial value
	actualPosButton = (posx + buttonWidth/2.f);
	pathButton = width - buttonWidth;
	fillWidth = (actualPosButton - posx);

	buttonColor = sf::Color::Blue;
	backgroundColor = sf::Color::White;

	//button
	buttonShape.setSize({ height + buttonAddonHeight, buttonWidth });
	buttonShape.setFillColor(buttonColor);
	buttonShape.setOrigin((height + buttonAddonHeight) / 2.f, buttonWidth /2.f);
	buttonShape.setPosition(actualPosButton, posy - height / 2.f);

	if (fill == true) {
		fillShape.setOrigin(0, 0);
		fillShape.setPosition(posx, posy);
		fillColor = sf::Color::Cyan;
		fillShape.setSize({ height, fillWidth });
		fillShape.setFillColor(fillColor);
	}
	//cout << "actualPosButton: " << actualPosButton;
	//cout << endl;
	//if (situation == false) {
		backgroundShape.setRotation(90.f);
		buttonShape.setRotation(90.f);
		fillShape.setRotation(-90.f);
	//}

	//TODO:
	// VERTIAL BAR

	//initialize some values
	fontSize = 12, maxValue = 100, minValue = 0, multipleS = mul, precision = 2;
	buttonHeightlight = false;
}

//TODO:
// Draw - eee?
void Slider::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	//NOTE:
	//the order of display elements is: BACKGROUND->SHAPE_A->SHAPE_A
	//the lower, the newest element display
	target.draw(this->backgroundShape, state);
	if (this->fill == true)
		target.draw(this->fillShape, state);
	target.draw(this->buttonShape, state);
	target.draw(this->description, state);
	target.draw(this->value, state);
}
void Slider::setPosition(float x, float y)
{
	this->actualPosButton = x;
	this->buttonShape.setPosition(this->actualPosButton, y);
	this->backgroundShape.setPosition(x,y);
	if (this->fill == true)
		this->fillShape.setPosition(backgroundShape.getPosition().x, backgroundShape.getPosition().y);
}

void Slider::update(sf::RenderWindow& window , float scroll)
{
	//////////////////////////////////////////////////////////
	///			heightlight and move button options
	//////////////////////////////////////////////////////////

	const int hv = 30; //HeightlightValue
	float smallmultiple = 0.02f;

	if (maxValue - minValue < 50 && multipleS == 1.f)
	{
		//smallmultiple =  (float)(maxValue - minValue)/1000;
		smallmultiple = (float)(1 / (maxValue - minValue));
	}
	else if (multipleS != 1.f)
	{
		smallmultiple = 1 / multipleS;
	}
	//cout << multipleS << endl;
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && 
	//cout << sf::Mouse::getPosition(window).x << " " << (backgroundShape.getPosition().x - (width / 2.f));
	//cout << endl;
	auto mx = sf::Mouse::getPosition(window).x;
	auto my = sf::Mouse::getPosition(window).y;
	auto bx = backgroundShape.getPosition().x;
	auto by = backgroundShape.getPosition().y;
	auto btx = buttonShape.getPosition().x;
	auto bty = buttonShape.getPosition().y;
	const float buffer = smallmultiple*pathButton;

	if ((mx >= (bx +(buttonWidth/2.f)- buffer) &&
		mx <= (bx + width - (buttonWidth / 2.f)+ buffer) &&
		my <= (by + buttonAddonHeight / 2.f) &&
		my >= (by - (height + buttonAddonHeight / 2.f)))
		&& buttonHeightlight == false && isMousePressed == false)
	{

		//cout << "  " << ( mx - backgroundShape.getPosition().x - buttonWidth / 2.f) ;
		//cout <<" ab: " << actualPosButton;
		//cout << endl;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) )
		{
			//this->actualPosButton = float(sf::Mouse::getPosition(window).x);
			//if(buttonHeightlight == false)
			//{
				if (buttonColor.r < 255 - hv) this->buttonColor.r += hv; else this->buttonColor.r = 255;
				if (buttonColor.g < 255 - hv) this->buttonColor.g += hv; else this->buttonColor.g = 255;
				if (buttonColor.b < 255 - hv) this->buttonColor.b += hv; else this->buttonColor.b = 255;
				buttonShape.setFillColor(this->buttonColor);
				buttonHeightlight = true;
				isMousePressed = true;
			//}
			//cout << "actualPosButton1: " << actualPosButton;
			//cout << endl;
		}
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonHeightlight == true )
	{
		//this->actualPosButton = float(sf::Mouse::getPosition(window).x);
		if (mx > actualPosButton + buffer) {
			while (mx > actualPosButton + buffer && (mx <= (bx + width - (buttonWidth / 2.f)) + buffer)) 
			this->actualPosButton += pathButton * smallmultiple;
		}
		else if (mx < actualPosButton - buffer) {
			while (mx < actualPosButton - buffer && mx >= (bx + (buttonWidth / 2.f) - buffer))
			this->actualPosButton -= pathButton * smallmultiple;
		}

		//this->actualPosButton = (float(sf::Mouse::getPosition(window).x) - backgroundShape.getPosition().x - buttonWidth / 2.f)
		//	* smallmultiple;// *pathButton;
		//cout << "actualPosButton2: " << actualPosButton;
		//cout << endl;
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonHeightlight == true) 
	{
		this->buttonColor.r -= hv;
		this->buttonColor.g -= hv;
		this->buttonColor.b -= hv;
		buttonShape.setFillColor(this->buttonColor);
		buttonHeightlight = false;
		isMousePressed = false;
	}

	if (!(sf::Mouse::isButtonPressed(sf::Mouse::Left)) && 
		mx >= (bx + (buttonWidth / 2.f)) &&
		mx <= (bx + width - (buttonWidth / 2.f)) &&
		my <= (by + (buttonAddonHeight / 2.f)+10) &&
		my >= ((by - (height + buttonAddonHeight / 2.f))-10) && scroll!=0
		&& 
			(
			actualPosButton >= ( bx + (buttonWidth / 2.f)) && actualPosButton <= (bx + width - (buttonWidth / 2.f))
			)
		)
	{
		//cout << "actualPosButton3: " << actualPosButton;
		//cout << endl;
		//maxValue

		//cout << " sm: " << smallmultiple << " aposbt: " << actualPosButton << endl;
		//this->actualPosButton += scroll * (smallmultiple * actualPosButton);
		this->actualPosButton += scroll * smallmultiple * pathButton;

		if ( actualPosButton > (bx + width- (buttonWidth / 2.f)) )
			this->actualPosButton = bx + (width - (buttonWidth / 2.f));

		if (actualPosButton < (bx + (buttonWidth / 2.f)))
			this->actualPosButton = (bx + (buttonWidth / 2.f));

		//this->buttonShape.move(vector)
		//this->buttonShape.setPosition(float(sf::Mouse::getPosition(window).x), backgroundShape.getPosition().y);
		//this->buttonShape.setPosition(backgroundShape.getPosition().x+scroll, backgroundShape.getPosition().y);
		//cout << "actualPosButton: " << actualPosButton - backgroundShape.getPosition().x - (buttonWidth / 2.f);
		//cout << " SCROLL: " << " " << bx - ((width / 2.f) - (buttonWidth / 2.f))<< " " << actualPosButton << " ";
		//float pos = width - (buttonWidth );
		//cout << " pos: " << pos << endl;
		//float prc = (width - buttonWidth) / 100;
		//cout << " prc: " << prc << endl;
		//cout << " percent: " << ( actualPosButton - backgroundShape.getPosition().x - (buttonWidth / 2.f)) / prc << endl;

	}
	
	this->buttonShape.setPosition(this->actualPosButton , backgroundShape.getPosition().y - height / 2.f );
	this->fillWidth = actualPosButton  - backgroundShape.getPosition().x-buttonWidth/2.f;
	fillShape.setSize({ this->height, fillWidth });

	//////////////////////////////////////////////////////////
	///			update text section
	//////////////////////////////////////////////////////////

	value.setString(this->to_string_with_precision(this->getValue()));
	value.setOrigin((float)value.getLocalBounds().width, 0);
	value.setPosition(backgroundShape.getPosition().x + width, backgroundShape.getPosition().y+2);
}

void Slider::setBackgroundColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 alpha )
{
	this->backgroundColor.r = r;
	this->backgroundColor.g = g;
	this->backgroundColor.b = b;
	this->backgroundColor.a = alpha;
	backgroundShape.setFillColor(this->backgroundColor);
}

void Slider::setButtonColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 alpha )
{
	this->buttonColor.r = r;
	this->buttonColor.g = g;
	this->buttonColor.b = b;
	this->buttonColor.a = alpha;
	buttonShape.setFillColor(this->buttonColor);
}

void Slider::setFillColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 alpha )
{
	this->fillColor.r = r;
	this->fillColor.g = g;
	this->fillColor.b = b;
	this->fillColor.a = alpha;
	fillShape.setFillColor(this->fillColor);
}

//description
void Slider::displayDescription(const char * desc, sf::Font & f, unsigned int height)
{
	font = f;
	fontSize = height;

	description.setString(desc);
	description.setFont(font);
	description.setCharacterSize(fontSize);
	description.setFillColor(sf::Color::White);
	description.setOrigin({ 0,0 });
	description.setPosition( backgroundShape.getPosition().x , backgroundShape.getPosition().y+2);
}

void Slider::displayValue(double min, double max,int prec)
{
	minValue = min;
	maxValue = max;
	precision = prec;
	value.setString( this->to_string_with_precision(this->getValue()) );
	value.setFont(font);
	value.setCharacterSize(fontSize);
	value.setFillColor(sf::Color::White);
	value.setOrigin((float)value.getLocalBounds().width, 0);
	value.setPosition(backgroundShape.getPosition().x + width, backgroundShape.getPosition().y+2);

}
double Slider::getValue()
{
	multiple = (((double)actualPosButton - (double)backgroundShape.getPosition().x - (double)(buttonWidth / 2.f)) / ((double)width - (double)buttonWidth));
	double valueScreen = minValue + multiple * (maxValue - minValue);
	return valueScreen;//ceil(valueScreen);
}

std::string Slider::to_string_with_precision(double a_value)
{
	std::ostringstream out;
	out.precision( this->precision );
	out << std::fixed << a_value;
	return out.str();
}

void Slider::setDisplayColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 alpha=255)
{
	this->textColor.r = r;
	this->textColor.g = g;
	this->textColor.b = b;
	this->textColor.a = alpha;
	this->description.setFillColor(this->textColor);
	this->value.setFillColor(this->textColor);
}

bool Slider::isMousePressed=false;