//simulation implementation
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
#include "OfficeSim.h"

// default constructor
OfficeSim::OfficeSim(){
  currt = 0;
  openwindows = 0;
  sat = 0;
  nsa = 0;
  filename = "";
  s = new OfficeList<Student*>();
  q = new OfficeQueue<Student*>();
}

//overloaded constructor
OfficeSim::OfficeSim(string f){
  currt = 0;
  openwindows = 0;
  sat = 0;
  nsa = 0;
  filename = f;
  q = new OfficeQueue<Student*>();
}

//destructor
OfficeSim::~OfficeSim(){
  delete q;
  delete s;
  delete []w;
}

//fileInput() function
void OfficeSim::fileInput(){
  string line = "";
  ifstream file(filename); //open file
  if(file){
    getline(file, line);
    openwindows = stoi(line);
    w = new OfficeWindow[openwindows]; //array of size of amount of open windows
    for (int i = 0; i < openwindows; ++i){
      w[i] = *new OfficeWindow();
    }
    while(getline(file, line)){
      sat = stoi(line);
      getline(file, line);
      nsa = stoi(line);
      for (int i = 0; i < nsa; ++i){
        getline(file, line);
        Student* s = new Student(stoi(line), sat);
        q->enqueue(s); //add student to queue
      }
    }
    file.close();
  }
  else{
    cout << "Failed to open file." << endl;
  }
}

//runSim() function
void OfficeSim::runSim(){
  currt = 0;
  while(!q->isEmpty() || !windowsOpen()){ //while queue is not empty and all windows are not open
    if (currt == 0){ //avoid more idle time
      while (!q->isEmpty() && q->front()->arrivaltime == currt && !windowsClosed()){ //while there are students arriving at time 0 and there are still open windows
        for (int i = 0; i < openwindows; ++i){
          if (w[i].currentstudent == NULL){ //if window open
              w[i].currentstudent = q->dequeue();
          }
        }
      }
    }
    else{
      for (int i = 0; i < openwindows; ++i){
        if (w[i].currentstudent == NULL){ //if no student at window
            ++w[i].idle;
        }
        else{ //if there is a student atwindow
          w[i].currentstudent->helptime--;
          if (w[i].currentstudent->helptime == 0){ //when student is finished at window
            Student* temp = w[i].currentstudent;
            s->insertBack(temp); //add the student to finished student list
            w[i].currentstudent = NULL;
          }
        }
      }
      while (!q->isEmpty() && q->front()->arrivaltime <= currt && !windowsClosed()){//when student is in queue and theres open window
        for (int i = 0; i < openwindows; ++i){
          if (w[i].currentstudent == NULL && !q->isEmpty()){ //if window open
            w[i].currentstudent = q->dequeue();
            w[i].currentstudent->waittime = currt - w[i].currentstudent->arrivaltime; //amount of time waited -> current time
          }
        }
      }
    }
    currt++;
  }
}

//stats() function
void OfficeSim::stats(){
  double awt; //average wait time
  int nStudents = s->getSize();
  int sWait[nStudents];
  int tenmin = 0; //number of students waiting for more than 10 mins
  int i = 0;
  while (!s->isEmpty()){
    sWait[i] = s->removeFront()->data->waittime;
    if (sWait[i] >= 10){
      ++tenmin;
      awt += sWait[i];
      ++i;
    }
    awt = awt/nStudents; //finds the average

    double ait; //average idle time
    int wIdle[openwindows]; // array of window idle time integers
    int li; //longest idle time
    int max = 0; //max value in window array
    int fivemin = 0; //number of windows idle for over 5 minutes
    for(int j = 0; j < openwindows; ++j){
      ait += w[j].idle;
      wIdle[j] = w[j].idle; // creates new array of idle time integers
      if(wIdle[j] > max){
        li = max;
      }
      if(w[j].idle >= 5){
        fivemin++;
      }
    }
    ait = ait/openwindows; //finds the average

    int medwait; //median wait time for students
    sort(sWait, sWait + nStudents);
    int mid = nStudents/2;
    if(nStudents % 2){ //if the size is even
      medwait = (sWait[mid] + sWait[mid+1])/2;
    }
    else{ //if the size is odd
      medwait = sWait[mid]; //get middle number of array
    }
    int lw = sWait[nStudents-1]; // longest student wait time

    cout << "The mean student wait time: " << awt << endl;
    cout << "The median student wait time: " << medwait << endl;
    cout << "The longest student wait time: " << lw << endl;
    cout << "The number of students waiting over 10 min: " << tenmin << endl;
    cout << "The mean window idle time: " << ait << endl;
    cout << "The longest window idle time: " << li << endl;
    cout << "Number of windows idle for over 5 min: " << fivemin << endl;
  }
}

//windowsOpen() function
bool OfficeSim::windowsOpen(){
  for (int i = 0; i < openwindows; ++i){
    if (w[i].currentstudent != NULL){ //if a student is at the window
      return false;
  }
  return true;
}

//windowsClosed() function
bool OfficeSim::windowsClosed(){
  for (int i = 0; i < openwindows; ++i){
    if (w[i].currentstudent == NULL) // if someone is at the window
      return false;
    }
  }
  return true;
}
