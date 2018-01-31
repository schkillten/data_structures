#include <iostream>
#include "directed_graph_adj_list.h"

void printV(std::vector<int> v){
  for(auto x : v){
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

int main(){
  GraphList g = GraphList();
  g.add_vertex(5);
  g.add_vertex(9);
  g.add_vertex(2);
  g.add_vertex(8);
  g.add_vertex(32);
  g.add_edge(5,9);
  g.add_edge(5,32);
  g.add_edge(5,8);
  g.add_edge(5,99); //trying to add edge between 5 -> 99, 99 doesnt exist, handles it fine
  g.add_edge(9,5); //trying to add edge between 9 -> 5, but edge exists between 5 -> 9 already (directed graph)
  //A) Tries to see if 9 has an adjacent node 5 after we try to make them adjacent, since 5 -> 9 exists it fails successfully
  if(g.adjacent(9,5)) std::cout << "ADJACENT\n";
  if(!g.adjacent(9,5)) std::cout << "NOT ADJACENT\n";
  //A)
  printV(g.neighbors(5));
  g.remove_edge(5,8);
  printV(g.neighbors(5));
  g.remove_vertex(9);
  printV(g.neighbors(5));
}
