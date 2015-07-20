#include <thread>
#include <iostream>
#include <chrono>
#include <sstream>
#include <string>
#include <vector>
#include <inttypes.h>

#include "util.cpp"
using namespace std;

uint16_t thread_count;
uint64_t operations;
string mode;
string o_filename;

uint32_t* x_storage;

void no_sharing(uint16_t thread_no);
void false_sharing(uint16_t thread_no);


int main(int argc, char* argv[]){
    
	string argument;
	for (int i = 1; i < argc; i++) {
		stringstream ss(argv[i]);
    	getline(ss, argument, '=');
        
        if (argument == "-threads" || argument == "-t"){
            getline(ss, argument);
			thread_count = stoi(argument);
        }
        else if (argument == "-operations" || argument == "-op"){
            getline(ss, argument);
            operations = stoi(argument);
        }
        else if (argument == "-mode" || argument == "-m") {
            getline(ss, argument);
            mode = argument; 
        }
        else if (argument == "-output_name" || argument == "-o") {
            getline(ss, argument);
            o_filename = argument; 
        }
	}
    
	if (thread_count == 0){
		cout << "error: need at least 1 thread" << endl;
        return 1;
    }
    if (thread_count == 0){
		cout << "error: need at least 1 operation" << endl;
        return 1;
    }
    if (o_filename == ""){
        o_filename= "graph";
    }
    
    

    x_storage= (uint32_t*) malloc(sizeof(uint32_t)*thread_count);
    vector<thread> threads;


    auto begin= chrono::high_resolution_clock::now();

    if(mode == "no_sharing"){
    	for(uint16_t i = 0; i < thread_count; i++) {
	    	threads.push_back(thread(no_sharing, i));
    	}
    }
    else if(mode == "false_sharing"){
        for(uint16_t i = 0; i < thread_count; i++) {
	    	threads.push_back(thread(false_sharing, i));
    	}
    }
    else{
        cout << "error: wrong mode" << endl;
        return 1;
    }

    for (auto& th : threads) th.join();

    auto end= chrono::high_resolution_clock::now();
    auto duration= chrono::duration_cast<chrono::nanoseconds>(end-begin).count();
    
    free(x_storage);

    uint64_t operations_per_sec;
    operations_per_sec = (((double)thread_count * (double)operations)/(double)duration)
                                                                        * 1000000000.0; 

    toFile(operations_per_sec, thread_count, o_filename);

    return 0;
}

void no_sharing(uint16_t thread_no){

    thread_local uint x;

    for(thread_local uint64_t i = 0; i < operations; i++){
        x++;
    }
}

void false_sharing(uint16_t thread_no){

    for(thread_local uint64_t i = 0; i < operations; i++){
        x_storage[thread_no]++;
    }
}
