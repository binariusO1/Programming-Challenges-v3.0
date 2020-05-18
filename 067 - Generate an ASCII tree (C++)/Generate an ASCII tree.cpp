/*
Programing challenge
2020-05-18 binariusO1
Generate an ASCII simple tree
*/

#include <iostream>
#include <vector>
using namespace std;

void draw_conicalA(unsigned height)
{
	//draw core
	std::vector<std::vector<std::string>> arr;

	std::string sign = " ";
	unsigned trunk = height * 0.1;
	unsigned width = height * 1.2;
	for (unsigned i = 0; i < height; i++)
	{
		std::vector<std::string> v1;
		for (unsigned j = 0; j < width; j++)
		{
			if(j>= width/2-trunk/2 && j<= width / 2 + trunk/2 && (i>0.8*height))
				v1.push_back("#");
			else if( (i <= 0.8 * height) && 
				j >= (width / 2)-i/1.5 && j <= (width / 2)+i/1.5
				)
				v1.push_back("o");
			else
			v1.push_back(sign);
			
		}
		arr.push_back(v1);
	}
	for (unsigned i = 0; i < arr.size(); i++)
	{
		for (unsigned j = 0; j < arr[i].size(); j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}
}

void draw_conicalB(unsigned height)
{
	//draw core
	std::vector<std::vector<std::string>> arr;

	std::string sign = " ";
	unsigned trunk = height * 0.1;
	unsigned width = height * 1.2;
	for (unsigned i = 0; i < height; i++)
	{
		std::vector<std::string> v1;
		for (unsigned j = 0; j < width; j++)
		{
			if (j >= width / 2 - trunk / 2 && j <= width / 2 + trunk / 2 && (i > 0.8 * height))
				v1.push_back("#");
			else if ((i <= 0.75 * height) &&
				(j >= 0.1 * width && (j >= (width / 2)-1 - i / 0.5)) && (j <= 0.9 * width && (j <= (width / 2)+1 + i /0.5))
				)
				v1.push_back("o");
			else if ( (i >= 0.75 * height && i <= 0.8 * height) &&
				(j >= 0.15 * width && (j >= (width / 2) - 1 - i / 0.5)) && (j <= 0.85 * width && (j <= (width / 2) + 1 + i / 0.5))
				)
				v1.push_back("o");
			else
				v1.push_back(sign);

		}
		arr.push_back(v1);
	}
	for (unsigned i = 0; i < arr.size(); i++)
	{
		for (unsigned j = 0; j < arr[i].size(); j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}
}

void draw_umbrella(unsigned height)
{
	//draw core
	std::vector<std::vector<std::string>> arr;

	std::string sign = " ";
	unsigned trunk = height * 0.1;
	unsigned width = height * 1.2;
	for (unsigned i = 0; i < height; i++)
	{
		std::vector<std::string> v1;
		for (unsigned j = 0; j < width; j++)
		{
			if (j >= width / 2 - trunk / 2 && j <= width / 2 + trunk / 2 && (i > 0.2 * height))
				v1.push_back("#");
			else if ((i <= 0.25 * height) &&
				(j >= 0.00 * width && (j >= (width / 2) - 1 - i / 0.2)) && (j <= 1 * width && (j <= (width / 2) + 1 + i / 0.2))
				)
				v1.push_back("o");
			else if ((i >= 0.25 * height && i <= 0.3 * height) &&
				(j >= 0.15 * width && (j >= (width / 2) - 1 - i / 0.5)) && (j <= 0.85 * width && (j <= (width / 2) + 1 + i / 0.5))
				)
				v1.push_back("o");
			else
				v1.push_back(sign);

		}
		arr.push_back(v1);
	}
	for (unsigned i = 0; i < arr.size(); i++)
	{
		for (unsigned j = 0; j < arr[i].size(); j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{
	draw_conicalA(25);
	cout << endl << endl;
	draw_conicalB(25);
	cout << endl << endl;
	draw_umbrella(25);
}