/*
Programing challenge
2020-05-10
binariusO1
Prime number (without multi-threading)
time: around 18.4s for max = 2 000 000 000 
*/


#include <iostream>
#include <vector>
#include "time_counter.h"
using namespace std;

void SieveOfEratosthenes(int max)
{
	vector<bool> prime(static_cast<unsigned>(max + 1), true);
	int i = 2;
	int m = int(sqrt(max));
	timecounter t1;
	t1.start();
	for (int p = 2; (p) <= m; p++)
	{
		if (prime[i] == true)
		{
			for (int j = p * p; j <= max; j += p)
				prime[j] = false;
		}
		i++;

	}
	t1.finish();
	//#pragma omp single
		//for (int p = 2; p <= max; p++)
		//	if (prime[p])
		//		cout << p << " ";
		//cout << endl;
	t1.show_result();
}

int main()
{
	int max;
	cin >> max;
	SieveOfEratosthenes(max);
	return 0;
}