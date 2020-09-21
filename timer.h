#pragma once
#include <iostream>
#include<chrono>
using namespace std;
using namespace chrono;

class Timer
{

public:

	std::chrono::time_point<std::chrono::high_resolution_clock> stamp_time;
	std::string key;

	//Constructor
	Timer(std::string key =""): key(key)
	{
		std::cerr << "Timer Object: " << key << std::endl;
		stamp_time = std::chrono::high_resolution_clock::now();
	}


	~Timer()
	{
		std::chrono::time_point<std::chrono::high_resolution_clock> stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - stamp_time);
		std::cerr << "Timer Object Destroyed: " << key << "  \n"
			  << "Duration Elapsed:  " //<< duration.count() << " µs    "
			 //<< "= " << (double)duration.count()*0.001 << " ms    "
			 //<< "= " 
			 << (double)duration.count()*0.000001 << " s\n"
			 << std::endl;
	}

}; //End of class Timer