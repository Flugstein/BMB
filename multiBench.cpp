#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

void benchFunc();

int main(){

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

    for(thread_local uint32_t i; i < 1000; i++){
        x++;
    }

    cout << x << endl;
}
