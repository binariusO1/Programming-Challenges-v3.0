/*
2020-04-02 binariusO1
Programing challenge
Higher-Lower
*/
#include <iostream>
#include <windows.h>	//Sleep()
#include <time.h>		//rand()

#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif

using namespace std;
int main()
{
	srand(time(NULL));
	time_t current = time(NULL);
	int S = 0;
	char N;
	int rand_0 = 0;
	int T = (rand() % 100 + 0);
	while (1)
	{
		cout << "Score: " << S << endl;
		cout << "Current random number: " << T << endl;
		rand_0 = (rand() % 100 + 0);
		cout << "\n\nHigher/lower? (h/l)\n";
		cin >> N;
		if ((N == 'h' && T < rand_0) || (N == 'l' && T >= rand_0))
		{
			S++;
			cout << "\nGOOD!";
		}
		else
		{
			S = 0;
			cout << "\nWRONG!";
		}
		T = rand_0;
		Sleep(800);
		if (system("CLS")) system("clear");
		cin.ignore();
		cin.clear();
	}
}
