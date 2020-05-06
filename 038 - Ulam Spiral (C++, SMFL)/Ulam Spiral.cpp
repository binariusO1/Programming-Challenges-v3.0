#include "Ulam Spiral.h"
//#include <iostream>
#include <vector>
using namespace std;
UlamSpiral::UlamSpiral(float X, float Y, unsigned size)
{
	startingPointX = X;
	startingPointY = Y;
	sizeUlam = size;
}
void UlamSpiral::draw(sf::RenderTarget& target, sf::RenderStates state) const
{


}
void UlamSpiral::update(sf::RenderWindow& window, unsigned size)
{
	if (size % 2 == 0)
		size++;
	sizeUlam = size;

	//UlamSpiral ulam;
	create(size);

	int** a = new int* [sizeUlam];
	for (unsigned i = 0; i < sizeUlam; ++i)
		a[i] = new int[sizeUlam] {};
	float XX = (float)(startingPointX- size)/2;
	float YY = (float)(startingPointY- size)/2;

	int num = 0;
	for (unsigned i = 0; i < sizeUlam; i++)
	{
		for (unsigned j = 0; j < sizeUlam; j++)
		{
			if (this->_lst[num] == 1)
			{
				sf::Vertex line =
				{ sf::Vertex(sf::Vector2f(XX + i, YY + j), sf::Color::White) };
				window.draw(&line, 1, sf::Points);
			}
			num++;
		}
	}
	delete[] a;
}
void UlamSpiral::create(unsigned n, unsigned startWith ) 
{
	_lst.clear();
	if (!(n & 1)) n++;
	_mx = n;
	unsigned v = n * n;
	_wd = static_cast<unsigned>(log10(static_cast<long double>(v))) + 1;
	for (unsigned u = 0; u < v; u++)
		_lst.push_back(-1);

	arrange(startWith);
}
bool UlamSpiral::isPrime(unsigned u) {
	if (u < 4) return u > 1;
	if (!(u % 2) || !(u % 3)) return false;

	unsigned q = static_cast<unsigned>(sqrt(static_cast<long double>(u))),
		c = 5;
	while (c <= q) {
		if (!(u % c) || !(u % (c + 2))) return false;
		c += 6;
	}
	return true;
}
void UlamSpiral::arrange(unsigned s) {
	unsigned stp = 1, n = 1, posX = _mx >> 1,
		posY = posX, stC = 0;
	int dx = 1, dy = 0;

	while (posX < _mx && posY < _mx) {
		_lst.at(posX + posY * _mx) = isPrime(s) ? 1 : 0;
		s++;

		if (dx) {
			posX += dx;
			if (++stC == stp) {
				dy = -dx;
				dx = stC = 0;
			}
		}
		else {
			posY += dy;
			if (++stC == stp) {
				dx = dy;
				dy = stC = 0;
				stp++;
			}
		}
	}
}