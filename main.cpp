#include <iostream>
#include "skip_list.h"
void blah(skipNode<int>* n);

int main()
{
  skipNode<int>* nodes = new skipNode<int>[3];
  auto double_nodes = nodes;
  blah(nodes);
  auto tmp = nodes[0].next[1];
  std::cout << nodes[0].next[1].value << '\n';
  auto new_node = skipNode<int>(2, 25);
  new_node.next[1] = tmp;
  nodes[0].next[1] = new_node;
  std::cout << nodes[0].next[1].value << '\n';
  std::cout << nodes[0].next[1].next[1].value << '\n';
  nodes = nullptr;
  delete nodes;
  std::cout << double_nodes[0].next[1].next[1].value << '\n';
}

void blah(skipNode<int>* n){

  skipNode<int> one = skipNode<int>(3);
  one.value = 1;
  skipNode<int> two = skipNode<int>(3);
  two.value = 2;
  skipNode<int> three = skipNode<int>(3);
  three.value = 3;
  skipNode<int> four = skipNode<int>(3);
  four.value = 4;
  one.next[0] = two;
  one.next[1] = three;
  one.next[2] = four;
  n[0] = one;
}
