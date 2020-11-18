//doubly linked list implementation
#include <iostream>
using namespace std;
#include "OfficeListNode.h"

template <typename type> //any type
class OfficeList{
  private:
    unsigned int size;
    OfficeListNode<type> *front;
    OfficeListNode<type> *back;
  public:
    OfficeList();
    ~OfficeList();
    void insertFront(type data);
    void insertBack(type data);
    OfficeListNode<type> *removeFront();

    OfficeListNode<type> *peek();
    OfficeListNode<type> *remove(type d); // remove node containing d
    OfficeListNode<type> *removeBack();

    void printList();
    bool isEmpty();
    unsigned int getSize();
};

//default constructor
template <typename type>
OfficeList<type>::OfficeList(){
  front = NULL;
  back = NULL;
  size = 0;
}

//destructor
template <typename type>
OfficeList<type>::~OfficeList(){
  for(int i = 0; i < size; i++){
    OfficeListNode<type> *node = front;
    front = front->next;
    delete node;
  }
}

//insertFront() function
template <typename type>
void OfficeList<type>::insertFront(type d){
  OfficeListNode<type> *node = new OfficeListNode<type>(d);
  if(isEmpty()){ //if the list is empty
    back = node;
  }
  else{ //if list is not empty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

//insertBack() function
template <typename type>
void OfficeList<type>::insertBack(type d){
  OfficeListNode<type> *node = new OfficeListNode<type>(d);
  if(isEmpty()){
    front = node;
  }
  else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

//removeFront() function
template <typename type>
OfficeListNode<type> *OfficeList<type>::removeFront(){
  OfficeListNode<type> *tempfront = front;
  if(front = back){ //if one node
    back = NULL;
  }
  else{ //if more than one node
    front->next->prev = NULL;
  }
  front = front->next;
  tempfront->next = NULL;
  size--;
  return tempfront;
}

//peek() function
template <typename type>
OfficeListNode<type> *OfficeList<type>::peek(){
  if(!isEmpty()){
    return front;
  }
  else{
    cout << "EMPTY LINKED LIST" << endl;
    return NULL;
  }
}

//remove() function
template <typename type>
OfficeListNode<type> *OfficeList<type>::remove(type d){
  OfficeListNode<type> *curr = front;
  while(curr->data != d){
    curr = curr->next;
    if(curr == NULL){
      return NULL;
    }
  }
  if(curr == front){
    front = curr->next;
  }
  else{
    curr->prev->next = curr->next;
  }
  if(curr == back){
    back = curr->prev;
  }
  else{
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  size--;
  return curr;
}

//removeBack() function
template <typename type>
OfficeListNode<type> *OfficeList<type>::removeBack(){
  OfficeListNode<type> *tempback = back;
  if(front = back){
    front = NULL;
  }
  else{
    back->prev->next == NULL;
  }
  back = back->prev;
  tempback->prev = NULL;
  size--;
  return tempback;
}

//printList() function
template <typename type>
void OfficeList<type>::printList(){
  OfficeListNode<type> *current = front;
  while (current != NULL){
    cout << current->data << endl;
    current = current->next;
  }
}

//isEmpty() function
template <typename type>
bool OfficeList<type>::isEmpty(){
    return (front == NULL);
}

//getSize() function
template<typename type>
unsigned int OfficeList<type>::getSize(){
  return size;
}
