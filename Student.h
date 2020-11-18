//student class file
#include <iostream>
using namespace std;

class Student{
  public:
    Student();
    Student(int h, int a);

    int helptime;
    int waittime;
    int arrivaltime;
};

//default constructor
Student::Student(){
  helptime = 0;
  waittime = 0;
  arrivaltime = 0;
}

//overloaded constructor
Student::Student(int h, int a){
  helptime = h;
  waittime = 0;
  arrivaltime = a;
}
