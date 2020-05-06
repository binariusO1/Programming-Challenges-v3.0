#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class UlamSpiral : public sf::Drawable
{
public:
////////////////////////////////////////////////////////////
/// \
/// \X,Y        Starting point
///	\size		Size
////////////////////////////////////////////////////////////
	UlamSpiral(float X, float Y, unsigned size);
	virtual ~UlamSpiral() = default;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	void update(sf::RenderWindow& window,unsigned size);

private:

	float startingPointX;
	float startingPointY;
	unsigned sizeUlam;
	std::vector<unsigned> _lst;
	unsigned _mx, _wd;
	void create(unsigned n, unsigned startWith = 1);
	bool isPrime(unsigned u);
	void arrange(unsigned s);
};

