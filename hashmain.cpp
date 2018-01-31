#include "hash.h"


int main(){
  Hash<int> h = Hash<int>(5);
  h.insert(60, 1);
  h.insert(30, 2);
  h.insert(90, 2);
  h.insert(32, 9);
  h.insert(1, 9);
  h.insert(92, 92);
  h.insert(343, 75);
  h.insert(3323, 53);
  h.showHash();
  h.remove(3323);
  h.remove(343);
  h.showHash();
}
