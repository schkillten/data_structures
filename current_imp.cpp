#include <stdlib.h>
#include <time.h>
#include "skip_list.h"
#include <iostream>

/*
[9->4->3->7->1]
[<-9<-4<-3<-7<-1

cur = root


*/

int main(){
  srand(time(NULL));
  skip_list<int> sl = skip_list<int>(50,0.5);
  sl.insert(32);
  sl.insert(19);
  sl.printList();
}
