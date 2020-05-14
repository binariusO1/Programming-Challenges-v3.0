#include <iostream>
#include <cmath>

using namespace std;

void draw(float radius)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	float k;
	float m = 2;
	for (int i = -radius; i <= radius; i++) {
		for (int j = -radius; j <= radius ; j++) {
			k = ((i * m) / radius) * ((i * m) / radius) + (j / radius) * (j / radius);

			if (k < 1.08)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}


int main() {

	float radius;
	cin >> radius;
	draw(radius);	
}