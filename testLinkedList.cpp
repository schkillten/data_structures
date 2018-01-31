#include "LinkedList.h"
#include <cassert>

int main()
{
  LinkedList<int> l = LinkedList<int>();
  l.insert(0,2);
  assert(l.get(0)==2);
  std::cout << "(TEST ONE) #INSERT# index <0> #GET# index <0>: SUCCESSFUL" << '\n';
  l.insert(0,9);
  assert(l.get(0)==9);
  std::cout << "(TEST TWO) #INSERT# index <0> #GET# index <0>: SUCCESSFUL" << '\n';
  l.erase(0);
  assert(l.get(0)==2);
  std::cout << "(TEST THREE) #ERASE# index <0> #GET# index <0>: SUCCESSFUL" << '\n';
  l.insert_front(42);
  assert(l.get(0)==42);
  std::cout << "(TEST FOUR) #INSERT_FRONT# index <0> #GET# index <0>: SUCCESSFUL" << '\n';
  l.insert_back(92);
  assert(l.get(2)==92);
  std::cout << "(TEST FIVE) #INSERT_BACK# index <2> #GET# index <2>: SUCCESSFUL" << '\n';
  assert(l.size()==3);
  std::cout << "(TEST SIX) #SIZE#: SUCCESSFUL" << '\n';
  assert(l.getBack()==92);
  std::cout << "(TEST SEVEN) #GET_BACK#: SUCCESSFUL" << '\n';
  assert(l.getFront()==42);
  std::cout << "(TEST EIGHT) #GET_FRONT#: SUCCESSFUL" << '\n';
  l.insert_back(23);
  l.insert_back(42);
  l.insert_back(332);
  l.insert_back(2211);
  assert(l.size()==7);
  std::cout << "(TEST NINE) #SIZE# = 7: SUCCESSFUL" << '\n';
  l.erase(0);
  l.erase(0);
  l.erase(0);
  l.erase(3);
  assert(l.size()==3);
  std::cout << "(TEST TEN) #SIZE# = 3: SUCCESSFUL" << '\n';
  assert(l.getBack()==332);
  std::cout << "(TEST ELEVEN) #GET_BACK# = 332: SUCCESSFUL" << '\n';
  assert(l.getFront()==23);
  std::cout << "(TEST TWELVE) #GET_FRONT# = 23: SUCCESSFUL" << '\n';
  std::cout << "ALL TESTS SUCCESSFUL" << std::endl;
  l.insert_back(3);
  l.insert_back(48);
  l.insert_back(18);
  l.insert_back(91);
  l.insert_back(114);
  l.printList();
  std::cout << '\n';
  l.reverse();
  l.printList();
}
