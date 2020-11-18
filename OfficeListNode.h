//node class for doubly linked list
#include <iostream>
using namespace std;

template <typename type> //any type
class OfficeListNode{
  public:
    OfficeListNode();
    OfficeListNode(type d);
    ~OfficeListNode();

    OfficeListNode<type> *next;
    OfficeListNode<type> *prev;
    type data;
};

//default constructor
template <typename type>
OfficeListNode<type>::OfficeListNode(){
  data = NULL;
  next = NULL;
  prev = NULL;
}

//overloaded constructor
template <typename type>
OfficeListNode<type>::OfficeListNode(type d){
  data = d;
  next = NULL;
  prev = NULL;
}

//destructor
template <typename type>
OfficeListNode<type>::~OfficeListNode(){
  next = NULL;
  prev = NULL;
  delete data;
}
