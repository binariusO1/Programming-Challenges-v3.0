/*
# programming challenge
# Morse to text
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
	std::string a;
	std::string temp;
	while (getline(cin, a))
	{
		for (unsigned i = 0; i < a.size(); i++)
		{
			temp += a[i];
			if (a[i] == 47||a[i]==32 || i == a.size()-1) 
			{
				if(a[i]==47 || a[i]==32)
				temp.pop_back();
				for (unsigned j = 0; j < 26; j++)
				{
					if (temp == letters[j]) {
						cout << (char)(65 + j);
						break;
					}
				}
				for (unsigned j = 0; j < 10; j++)
				{
					if (temp == numbers[j]) {
						cout << (char)(48 + j);
						break;
					}
				}
				temp.clear();
			}
}
		cout << endl;
		temp.clear();
	}
}