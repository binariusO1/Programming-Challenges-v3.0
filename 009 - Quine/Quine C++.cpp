/*
Programing challenge
2020-05-18 binariusO1
Quine C++4)
*/
#include <iostream>
using namespace std;
int main()
{
	cout << "#include <iostream>" << endl;
	cout << "using namespace std;" << endl;
	cout << "int main()" << endl;
	cout << "{" << endl;
	cout << "cout<<" << '"' << "Hello World" << '"' <<"endl;" << endl;
	cout << "}" << endl;
}