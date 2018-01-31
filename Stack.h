#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

template <class T>
class Stack {
  public:
    bool empty(){
      return stack.empty();
    }
    int size(){
      return stack.size();
    }
    void push(const T& elem){
      stack.insert_front(elem);
    }
    void pop(){
      stack.erase(0);
    }
    T& top(){
      return stack.getFront();
    }
  private:
    LinkedList<T> stack;
};

#endif
