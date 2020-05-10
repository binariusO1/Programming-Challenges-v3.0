/*
Programing challenge
2020-05-10
binariusO1
Prime number (with multi-threading omp)
time: around 16.5s for max = 2 000 000 000 
*/

#include <omp.h>
#include <iostream>
#include <vector>
#include "time_counter.h"
using namespace std;

void SieveOfEratosthenes(int max)
{

	omp_set_num_threads(4);
	vector<bool> prime(static_cast<unsigned>(max + 1), true);
	int i = 2;
	int m = int(sqrt(max));
	timecounter t1;
	t1.start();

#pragma omp parallel for schedule(dynamic,4)
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