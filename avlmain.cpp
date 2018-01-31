#include "avltree.h"

int main(){
  AVLTree<int> avl;
  avl.insert(5);
  avl.inOrder();
  avl.insert(8);
  avl.inOrder();
  avl.insert(7);
  avl.inOrder();
  avl.insert(92);
  avl.inOrder();
  avl.insert(15);
  avl.inOrder();
  avl.insert(43);
  avl.inOrder();
  avl.insert(28);
  avl.inOrder();
  avl.insert(48);
  avl.inOrder();
  avl.insert(1);
  avl.inOrder();
  avl.insert(9);
  avl.inOrder();
}
