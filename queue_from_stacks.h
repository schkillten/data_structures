#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H

#include <vector>
#include <iostream>

/*
Queue Using two stacks (problem)
Basically use two stacks to manage a queue
*/

template <class T>
class Stack
{
  public:
    Stack() = default;
    Stack( int size ) : stack(size) {}

    void push( T const& value )
    {
      stack.push_back( value );
    }
    void pop()
    {
      stack.pop_back();
    }

    T const& top() const
    {
      return stack.back();
    }

    bool empty() const
    {
      return stack.empty();
    }

    int size() const
    {
      return stack.size();
    }

  private:
    std::vector<T> stack;
};

template <class T>
class QueueSS
{
  public:
    QueueSS() = default;
    QueueSS( int size ) :
      input(size),
      output(size),
      max_size(size)
    {}
    ~QueueSS(){}

    void enqueue( T value )
    {
      doubleStackPush( value );
    }

    void dequeue()
    {
      doubleStackRemove();
    }

    T front()
    {
      return doubleStackFront();
    }

  private:

    void doubleStackPush( T value )
    {
      //need to think about how I should determine if its full, guess I can check the size of both stacks
      if( (input.size() + output.size()) < max_size )
        input.push( value );
    }

    void doubleStackRemove()
    {
      if( !input.empty() ){
        if( output.empty() )
          inputDump();

        output.pop();
      }
    }

    T doubleStackFront()
    {
      if( !input.empty() ){
        if( output.empty() )
          inputDump();

        return output.top();
      }
    }

    void inputDump()
    {
      while( !input.empty() )
      {
        output.push( input.top() );
        input.pop();
      }
    }

    Stack<T> input;
    Stack<T> output;
    int max_size;
};

#endif
