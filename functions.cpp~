#include <thread>

void doIncrement(int x){
	x = x+1;
}

void createThreads(int threads, long operations, long x){
	
	std::thread first (doIncrement);

	first.detach();
}
