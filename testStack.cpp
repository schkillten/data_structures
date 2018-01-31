#include "Stack.h"
#include <cassert>

int main(){
  Stack<int> s = Stack<int>();
  s.push(3);
  s.push(9);
  s.push(10);
  assert(s.size()==3);
  assert(s.top()==10);
  assert(s.empty()==false);
  s.pop();
  s.pop();
  s.pop();
  assert(s.size()==0);
  assert(s.empty()==true);
  try{
    s.top();
  }catch(int e){
    std::cout << "Successfully handled access to out of bounds" << '\n';
  }
  try{
    s.pop();
  }catch(int e){
    std::cout << "Successfull handled pop to empty stack" << '\n';
  }
  std::cout << "ALL TESTS SUCCESSFUL" << std::endl;
}
