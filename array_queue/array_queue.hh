//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#ifndef ARRAY_QUEUE_HH
#define ARRAY_QUEUE_HH

#include <cstdlib>
#include <iostream>


using namespace std;

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

const int MAX_QUEUE_SIZE = 100;

template<typename T>
class MyQueue
{
public:
  
  MyQueue();          // make an empty queue

  void enqueue(T);    // put item on the queue
  T dequeue();        // take item off

  bool empty();       // is the queue empty?
  bool full();        // is the queue full (aka max capacity reached)?
  int size();         // how many items are in the queue?
  void error(string); // print and exit

private:

  T *A;
  int maxnum;
  int curnum;
  int back;
  int front;

};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

template<typename T>
MyQueue<T>::MyQueue() 
{ 
  maxnum = MAX_QUEUE_SIZE; 
  curnum = 0; 
  A = new T[maxnum];   // make an empty queue
  front = -1;
  back = -1;
}    

//----------------------------------------------------------------------------

template<typename T>
bool MyQueue<T>::empty() 
{ 
  return curnum == 0; 
}
  
//----------------------------------------------------------------------------

template<typename T>
void MyQueue<T>::enqueue(T theData)
{
  if(full()){
    error("tried to enqueue full queue");
  }
  if (front == -1) {
    front = 0;
    back = 0;
    curnum = curnum + 1;
  } else {
    if (back == MAX_QUEUE_SIZE - 1){
      back = 0;
    }else{
      back = back + 1;
      curnum = curnum + 1;
}
}
  A[back] = theData;
}
 

//----------------------------------------------------------------------------

// return item currently at FRONT of queue (aka which is index curnum - 1)

template<typename T>
T MyQueue<T>::dequeue(){
 if(empty()){
   error("tried to dequeue an empty queue");
 } 
 if(front == back){
    front = -1;
    back = -1;
    curnum = curnum - 1;
    return A[curnum];
}else if(front == MAX_QUEUE_SIZE - 1){
   int temp = front;
   front = 0;
   back = back + 1;
   curnum = curnum - 1;
   return A[temp]; 
}else{
   front = front + 1;
   curnum = curnum - 1;
   back = back + 1;
   return A[front-1];
}
}
//----------------------------------------------------------------------------

template<typename T>
bool MyQueue<T>::full() 
{ 
  return curnum == maxnum; 
}
  
//----------------------------------------------------------------------------

template<typename T>
int MyQueue<T>::size() 
{ 
  return curnum; 
}  

//----------------------------------------------------------------------------

template<typename T>
void MyQueue<T>::error(string s) 
{ 
  cout << "Error: " << s << endl; 
  exit(1); 
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif
