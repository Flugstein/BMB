void doIncrement(){
	int x = x+1;
}

void createThreads(int threads, long operations){
	
	std::thread first (doIncrement);

	first.detach();
}
