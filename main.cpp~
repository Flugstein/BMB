#include <sstream>
#include <iostream>
#include <fstream>
#include <ctime>
#include <thread>

#include "functions.hpp"

using namespace std;



//void destroyThreads(){
//	first.detach();
//}


int main(){

//	double time1=0.0, tstart; //meassurement variables
	int timeout;
	long threads, operations, throughput, nr_of_operations=0, x=0;
	
	std::cout << ":: thread runtime test ::" << endl << endl;
	
	std::cout << "threads:" << endl;
	std::cin >> threads;

	std::cout << "operations:" << endl;
	std::cin >> operations;
	
	std::cout << "max. calculation time:" << endl;
	std::cin >> timeout;
	
	nr_of_operations = (operations / threads);

	clock_t begin = clock();
	createThreads(threads,nr_of_operations,x);
	clock_t end = clock();
 	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

//	destroyThreads();

	std::cout << elapsed_secs << endl;

	return 0;
}
