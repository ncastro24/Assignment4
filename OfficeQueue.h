//queue class
#include <iostream>
using namespace std;
#include "OfficeList.h"

template <typename type>
class OfficeQueue{
  public:
    OfficeQueue();
    ~OfficeQueue();

    type front();
    void enqueue(type t);
    type dequeue();
    int size();
    bool isEmpty();
  private:
    OfficeList<type> OL; //the doubly linked list
    int n; //elements in the list
};

//default constructor
template <typename type>
OfficeQueue<type>::OfficeQueue(){
  n = 0;
  OL = OfficeList<type>();
}

//destructor
template <typename type>
OfficeQueue<type>::~OfficeQueue(){
}

//front() function
template <typename type>
type OfficeQueue<type>::front(){
  if(!isEmpty()){
    return OL.peek()->data;
  }
  else{
    cout << "EMPTY QUEUE" << endl;
  }
}

//enqueue() function
template <typename type>
void OfficeQueue<type>::enqueue(type t){
  OL.insertBack(t);
  n++;
}

//dequeue() function
template <typename type>
type OfficeQueue<type>::dequeue(){
  if(!isEmpty()){
    n--;
    return OL.removeFront()->data;
  }
  else{
    cout << "EMPTY QUEUE" << endl;
  }
}

//size() function
template <typename type>
int OfficeQueue<type>::size(){
  return n;
}

//isEmpty() function
template <typename type>
bool OfficeQueue<type>::isEmpty(){
  return(n == 0);
}
