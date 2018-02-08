#ifndef C_Q_H
#define C_Q_H

#include <stdlib.h>

/*
TODO 
Need to implement iterators
~Big 5~
*/

template <class T>
class CircularQueue
{
  public:

    /*
      took me forever to realize that my default ctor was originally just CircularQueue() = default; and when I make a new instance
      of the class it calls this ctor. Then when I do things like copy/move, or anything for that matter, my memory was not initied.
      So in my copy/move ctors there is a case where I try to free the memory when it was never intited.

      basically not sure how I want to do this default size...
    */

    CircularQueue(size_t s=10) :
      max_size(s),
      size(0),
      mem(new T[max_size]),
      front(mem),
      rear(mem)
    {}

    ~CircularQueue()
    {
      delete[] mem;
      front = nullptr;
      rear = nullptr;
    }

    /*
      copy ctor
      needs to COPY the contents from the RHS
      if there is a pointer, we need to do a deep copy
    */
    CircularQueue( CircularQueue const & rhs ) :
      mem(new T[rhs.max_size]),
      front( mem + ( rhs.front - rhs.mem ) ),
      rear( mem + ( rhs.rear - rhs.mem ) ),
      size(rhs.size),
      max_size(rhs.max_size)
    {
      for( int i = 0; i<size; i++)
      {
        mem[i] = rhs.mem[i];
      }

    }

    /*
      move ctor
      needs to take over the contents of the RHS

    */
    CircularQueue( CircularQueue && rhs ) :
      mem( rhs.mem ),
      front( rhs.front ),
      rear( rhs.rear ),
      size( rhs.size ),
      max_size( rhs.max_size)
    {
      rhs.mem = nullptr;
      rhs.front = nullptr;
      rhs.rear = nullptr;
      rhs.size = 0;
      rhs.max_size = 0;
    }

    //copy assign
    CircularQueue& operator=( CircularQueue const & rhs )
    {
      auto tmp = CircularQueue( rhs );
      *this = std::move( tmp );
      return *this;
    }

    //move assign
    CircularQueue& operator=( CircularQueue && rhs )
    {

      if( this == &rhs )
      {
        return *this;
      }

      delete[] mem;
      mem = rhs.mem;
      front = rhs.front;
      rear = rhs.rear;
      size = rhs.size;
      max_size = rhs.max_size;

      rhs.mem = nullptr;
      rhs.front = nullptr;
      rhs.rear = nullptr;
      rhs.size = 0;
      rhs.max_size = 0;

      return *this;
    }

    void enqueue(T val)
    {

      if(!full()){
        *rear = val;
        size++;
        increment(&rear);
      }
    }

    void dequeue()
    {

      if(!empty()){
        size--;
        increment(&front);
      }
    }

    T top() const
    {
      return *front;
    }

    bool const empty() const
    {
      return (size==0);
    }

    bool const full() const
    {
      return (size==max_size);
    }

    //for testing
    void display_queue()
    {
      auto cur = front;
      while(cur!=rear){
        std::cout << *cur << " ";
        increment(&cur);
      }
      std::cout << std::endl;
    }

  private:
    /*
      so for now I just increment the given pointer around the block of memory

    */
    void increment(T** p)
    {
        if(*p == mem+max_size-1){
          *p=mem;
        }else{
          ++*p;
        }
    }

    size_t max_size;
    size_t size;
    //a block of memory for the structure to use
    T* mem;
    T* front;
    T* rear;
};

#endif
