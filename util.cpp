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

size_t get_cache_line_size() {
    FILE* fp;
    unsigned int ret= 0;

    fp = fopen("/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size", "r");
    if(fp) {
        fscanf(fp, "%d", &ret);
        fclose(fp);
    }
    return ret;
}
