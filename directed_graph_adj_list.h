#include <unordered_map>
#include <vector>
#include <algorithm>

/*
  Directed Graph using an Adjacency List as the underlying structure
  
  Performance with Adjaceney List (using hash table)

  add_edge : 
        O(1), since I use adjacency list, I find the vertex I want to connect this vertex to and add
        it to its adjacency list, so since lookup of a vertex is O(1) and adding a new value to a list (vector in my case)
        is also O(1) as I just do a push_back

  add_vertex :
        O(1) since there is random access (hash table) I just create a new key->value pair in the 
        hash table. Although hash tables only have constant lookup/insertion if there are no collisions

  test for adjacency:
        O(|V|) this is worst case, so worst case if you're testing that x is adjacent to y, if the adjacency list for x contains
        all |V|, then its O(|V|) to iterate through its list and find y. Average case is probably far better than O(|V|) depending
        on the application, but most vertices likely dont have an edge to every other vertex, especially in a directed graph.

  remove_edge(Vertex x, Vertex y):
        O(|V|) this is also worst case. If a vertex has an edge to every other vertex, then removing an edge requires you to scan through all of
        it's adjacent vertices. Although I believe if you used something with random access (O(1) lookup) to store the adjacent vertices, you should be able to get
        O(1) remove time. Not sure if thats necessary though.

  remove_vertex(Vertex v):
        O(|E|) need to go through all of the edges and remove any that have a link to Vertex v, then erase v. Average case it will be whatever
        the average number of edges between two vertices is.

*/

typedef int Vertex;
class GraphList{
  public:
    void add_vertex(Vertex v){
      if(graph.find(v)==graph.end()) 
        graph[v] = {};
    }

    void remove_vertex(Vertex v){
      auto it = graph.find(v);
      if(it!=graph.end()){
        for(auto n : graph){
          remove_edge(n.first, v);
        }
        graph.erase(v);
      }
    }

    void remove_edge(Vertex x, Vertex y){
      auto x_it = graph.find(x);
      if(x_it!=graph.end()){
        auto found = std::find(graph[x].begin(), graph[x].end(), y);
        if(found!=graph[x].end()){
          graph[x].erase(found);
        }
      }
    }

    void add_edge(Vertex x, Vertex y){
      auto x_it = graph.find(x);
      auto y_it = graph.find(y);
      if(x_it!= graph.end() && y_it!=graph.end()){
        if(!adjacent(y, x)){
          graph[x].push_back(y);
        }
      }
    }

    std::vector<Vertex> neighbors(Vertex x){
      auto it = graph.find(x);
      if(it!=graph.end()) return graph[x];
      return std::vector<Vertex>();
    }

    bool adjacent(Vertex x, Vertex y){
      auto it = graph.find(x);
      if(it!=graph.end()){
        return std::find(graph[x].begin(), graph[x].end(), y)!=graph[x].end();
      }
      return false;
    }

    int graph_nodes(){
      return graph.size();
    }

  private:
    std::unordered_map<Vertex, std::vector<Vertex>> graph;
    
};
