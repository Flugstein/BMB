#include <sstream>
#include <iostream>
#include <fstream>
#include <time.h>
#include <thread>

using namespace std;

void main(){

	double time1=0.0, tstart; //meassurement variables
	uint8_t timeout;
	uint64_t threads, operations, throughput;
	
	cout << ":: thread runtime test ::" << endl << endl;
	
	cout << "threads:" << endl;
	cin >> threads;

	cout << "operations:" << endl;
	cin >> operations;
	
	cout << "max. calculation time:" << endl;
	cin >> timeout;
	
	createThreads(threads);
}



void stop(){





}


