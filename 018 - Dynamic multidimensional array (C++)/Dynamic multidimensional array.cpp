/*
# programming challenge
# Dynamic multidimensional array
# C++
# binariusO1
*/

#include <iostream>

using namespace std;

int main()
{
	unsigned width = 20;
	unsigned height = 20;

	int** mArray;

	for (int i = 0; i < height; ++i)
		mArray[i] = new int[width];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			mArray[i][j] = 1;
		}
	}
}
