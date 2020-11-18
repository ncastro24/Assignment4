//main file for office simulation
#include <iostream>
using namespace std;
#include "OfficeSim.h"

int main(int argc, char** argv){
  if (argc == 2){
    OfficeSim s(argv[1]);
    s.fileInput();
    s.runSim();
    s.stats();
  }
  else{
    cout << "ERROR" << endl;
  }
}
