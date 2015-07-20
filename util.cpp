#include <fstream>
#include <iostream>
using namespace std;

void toFile(long ops_per_time, int threads){
	
  ofstream file;
  file.open("graph.dat",std::ios_base::app);
  if (file.is_open())
  {
    file << threads << " " << ops_per_time << "\n";
    file.close();
  }
  else cout << "Unable to open file";

}

