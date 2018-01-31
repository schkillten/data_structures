#include "Queue.h"
#include <cassert>

int main()
{
  Queue<int> q = Queue<int>();
  q.enqueue(32);
  q.enqueue(32);
  q.enqueue(32);
  q.enqueue(32);
  q.enqueue(9);
  assert(q.front()==32);
  assert(q.size()==5);
  assert(q.empty()==false);
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  assert(q.front()==9);
  std::cout << "ALL TESTS SUCCESSFUL" << std::endl;
}
