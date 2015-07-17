#include <fstream>
#include <iostream>
using namespace std;

void toFile(long time, int threads){
	
  ofstream file;
  file.open("graph.dat",std::ios_base::app);
  if (file.is_open())
  {
    file << time << " " << threads << "\n";
    file.close();
  }
  else cout << "Unable to open file";

}
