/*
# programming challenge
# Text to Morse
# C++
# binariusO1
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string letters[26] = {
		".-",
		"-...",
		"-.-.",
		"-..",
		".",
		"..-.",
		"--.",
		"....",
		"..",
		".---",
		"-.-",
		".-..",
		"--",
		"-.",
		"---",
		".--.",
		"--.-",
		".-.",
		"...",
		"-",
		"..-",
		"...-",
		".--",
		"-..-",
		"-.--",
		"--.."
	};
	string numbers[10] = {
	"-----",
	".----",
	"..---",
	"...--",
	"....-",
	".....",
	"-....",
	"--...",
	"---..",
	"----."
	};
	string a;

	while (getline(cin, a))
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] >= 97)
				cout << letters[a[i] - 97] << "/";
			else if (a[i] >= 65)
				cout << letters[a[i] - 65] << "/";
			else if (a[i] >= 48)
				cout << numbers[a[i] - 48] << "/";
			else
				cout << "/";
		}
		cout << endl;
	}
}