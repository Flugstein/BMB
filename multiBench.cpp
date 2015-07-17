#include <thread>
#include <iostream>
#include <chrono>
#include <sstream>
#include <string>
using namespace std;

uint thread_count;

void benchFunc();

int main(int argc, char* argv[]){

	if(argc < 2) {
		cerr << "At least 2 Argument is needed to execute the program properly" << endl;
		return 1;
	}

	string argument;
	for (int i = 1; i < argc; i++) {
		stringstream ss(argv[i]);
    	getline(ss, argument, '=');

		if(argument == "threads") {
			getline(ss, argument);
			thread_count = stoi(argument);
		}
	}

    auto begin= chrono::high_resolution_clock::now();

    thread first(benchFunc);
    thread second(benchFunc);
    
    first.join();
    second.join();

    auto end= chrono::high_resolution_clock::now();
    auto duration= chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

    cout << "total time [ns]: " << duration << endl;

    return 0;
}

void benchFunc(){
    thread_local int x;

    for(thread_local uint32_t i; i < 10000; i++){
        x++;
    }

    cout << x << endl;
}
