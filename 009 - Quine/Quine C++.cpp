/*
Programing challenge
2020-05-18 binariusO1
Quine C++4)
*/
#include<iostream>
using namespace std;
int main() 
{
char sep = 34;
string word[] = {
	"    ",
	"#include<iostream>",
	"using namespace std;",
	"int main()",
	"{",
	"char sep = 34;",
	"string word[] = {",
	"}",
	"for(int i = 1; i <= 6; i++)",
	"cout << word[i] << endl;",
	"for(int i = 0; i <= 14; i++)",
	"cout << word[0] + sep + word[i] + sep + ',' << endl;",
	"for(int i = 8; i <= 14; i++)",
	"cout << word[i] << endl;",
	"}"
};
for (int i = 1; i <= 6; i++)
cout << word[i] << endl;
for (int i = 0; i <= 14; i++)
cout << word[0] + sep + word[i] + sep + ',' << endl;
for (int i = 8; i <= 14; i++)
cout << word[i] << endl;
}
