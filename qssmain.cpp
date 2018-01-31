#include "queue_from_stacks.h"
#include <iostream>

int main()
{
  QueueSS<int> qss;
  qss.enqueue( 5 );
  std::cout << qss.front() << '\n';
  qss.enqueue( 4 );
  std::cout << qss.front() << '\n';
  qss.enqueue( 3 );
  qss.enqueue( 2 );
  qss.enqueue( 1 );
  
  qss.dequeue();
  std::cout << qss.front() << '\n';
  qss.dequeue();
  std::cout << qss.front() << '\n';
  qss.dequeue();
  std::cout << qss.front() << '\n';

}
