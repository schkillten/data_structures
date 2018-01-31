#include "heap.h"
#include <time.h>
#include <stdlib.h>

int main(){
  srand(time(NULL));
  int size = 30;
  std::vector<int> arr;
  for(int i=0;i<size;i++){
    arr.push_back(rand() % 100);
    //std::cout << rand() % 100 << '\n';
  }
  //std::vector<int> arr{12,5,3,4,8, 11, 15, 928, 32};
  Heap<int> h;
  for(auto x : arr){
    h.insert(x);
    h.display();
  }
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
  h.remove();
  h.display();
}
