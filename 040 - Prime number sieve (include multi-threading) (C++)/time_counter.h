#pragma once
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono; // see §35.2
class timecounter
{
public:
	std::chrono::time_point<struct std::chrono::steady_clock, class std::chrono
		::duration<__int64, struct std::ratio<1, 1000000000> > > t0;
	std::chrono::time_point<struct std::chrono::steady_clock, class std::chrono
		::duration<__int64, struct std::ratio<1, 1000000000> > > t1;

	timecounter()
	{
		t0 = high_resolution_clock::now();
		t1 = high_resolution_clock::now();
	}
	~timecounter() = default;
	void start()
	{

		t0 = high_resolution_clock::now();
		//cout << typeid(t0).name() << endl;
	}
	void finish()
	{
		t1 = high_resolution_clock::now();

	}
	void show_result()
	{
		//auto int_ms = duration_cast<std::chrono::milliseconds>(t1 - t0);
		//cout << int_ms.count() << endl;

		std::chrono::duration<double> elapsed_seconds = t1 - t0;
		std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";



	}
};