//office window class
#include <iostream>
using namespace std;
#include "Student.h"

class OfficeWindow{
  public:
    OfficeWindow();
    ~OfficeWindow();

    Student* currentstudent; //student currently at the window
    int idle; //how much time student has been idle
};

//default construction
OfficeWindow::OfficeWindow(){
  currentstudent = NULL;
  idle = 0;
}

//destructor
OfficeWindow::~OfficeWindow(){
  delete currentstudent;
}
