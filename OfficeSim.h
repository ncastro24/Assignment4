//header file for registrar office simulation
#include <iostream>
#include <string>
using namespace std;
#include "OfficeWindow.h"
#include "OfficeQueue.h"

class OfficeSim{
  private:
    string filename; //file
    int currt; //current time
    int openwindows; //amount of open windows
    int sat; //student arrival time
    int nsa; //number of students who are arriving
    OfficeList<Student*> *s;
    OfficeQueue<Student*> *q;
    OfficeWindow *w;
  public:
    OfficeSim();
    OfficeSim(string f);
    ~OfficeSim();

    void fileInput();
    void runSim(); //starts the office simulation
    void stats(); //calculate the needed statistics
    bool windowsOpen(); //if all windows are open
    bool windowsClosed(); //if all windows are closed
};
