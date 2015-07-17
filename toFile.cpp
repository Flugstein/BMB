#include <fstream>
using namespace std;

void toFile(uint64_t time, uint8_t threads){
	
    fstream f;
    f.open("test.dat", ios::app);
    f << time << " " << threads << endl;
    f.close();

}
