#include <thread>
#include <iostream>
#include <chrono>
#include <sstream>
#include <string>
#include <vector>

#include "util.hpp"
using namespace std;

uint thread_count;

uint* x_storage;

void benchFunc(uint16_t thread_no);


int main(int argc, char* argv[]){

	if(argc < 2) {
		cerr << "At least 2 Argument are needed to execute the program properly" << endl;
		return 1;
	}

	string argument;
	for (int i = 1; i < argc; i++) {
		stringstream ss(argv[i]);
    	getline(ss, argument, '=');

		if(argument == "-threads" || argument == "-t") {
			getline(ss, argument);
			thread_count = stoi(argument);
		}
	}

	if(thread_count == 0)
		return 1;
    

    x_storage= (uint*) malloc(sizeof(uint)*thread_count);
    vector<thread> threads;


    auto begin= chrono::high_resolution_clock::now();

	for(uint16_t i = 0; i < thread_count; i++) {
		threads.push_back(thread(benchFunc, i));
	}	
    for (auto& th : threads) th.join();

    auto end= chrono::high_resolution_clock::now();
    auto duration= chrono::duration_cast<chrono::nanoseconds>(end-begin).count();
    

    //TODO manuel input of operations
    uint64_t operations_per_sec;
    operations_per_sec = (((double)thread_count * 10000.0)/(double)duration) * 1000000000.0; 

    toFile(operations_per_sec, thread_count);

    return 0;
}

void benchFunc(uint16_t thread_no){

    //thread_local uint x;

    for(thread_local uint32_t i; i < 10000; i++){
        //x++;
        x_storage[thread_no]++;
    }
}
