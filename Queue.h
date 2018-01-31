#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"

template <class T>
class Queue {
  public:
    bool empty()
    {
      return queue.empty();
    }
    int size()
    {
      return queue.size();
    }
    void enqueue(const T& elem)
    {
      queue.insert_back(elem);
    }
    void dequeue()
    {
      queue.erase_front();
    }
    T& front()
    {
      return queue.getFront();
    }
  private:
    LinkedList<T> queue;
};

#endif
