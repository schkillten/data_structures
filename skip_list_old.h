#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/*
skip list...

Nodes are assigned a level.

A node of level i points to at most 1 node of each level.

when inserting, you must keep track of the last visited node of each level
  for each of the last visited nodes, you must update their ith level next to the newly insert node
  
  then for the newly created node, for each of its levels, update its next to the last visited node of the same level



*/

template <class T>
struct skipNode {
  T value;
  skipNode<T>** next;
  skipNode(){}
  skipNode(int size) {next = new skipNode<T>*[size];}
  ~skipNode(){delete[] next;}
};


template <class T>
class skip_list {
  public:
    skipNode<T>* header;
    int max_size;
    float cutOff;
    int max_level;
    float prob;
    int sSize;

    skip_list(int max_size, float prob) 
      : max_size(max_size),
        sSize(0),
        prob(prob)
    {
      cutOff = prob * RAND_MAX;
      max_level = (int) ceil(logf((float) max_size) / logf(1/prob)) - 1;
      header = new skipNode<T>(max_size+1);
    }

    ~skip_list()
    {
      delete_node(header);
    }

    int level() const
    {
      int lev = 0;
      while(rand() <= cutOff) lev++;
      return (lev <= max_level) ? lev : max_level;
    }

    skipNode<T>* find(T value)
    {
      if(header->next[0]){
        auto current = header;
        for(int i = max_level;i>=0;i--){
          while(current->next[i] && current->next[i]->value < value){
            current = current->next[i];
          }
        }
        if(current->next[0] && current->next[0]->value == value){
          return current->next[0];
        }
      }
      return NULL;
    }

    void erase(T value){
      /*
        if its not empty,
          search for the element
          if you find it
            delete it
            reassign pointers
      */
      skipNode<T>** last_seen = new skipNode<T>*[max_level+1];
      if(header->next[0])
      {
        auto current = header;
        for(int i=max_level;i>=0;i--)
        {
          while(current->next[i] && current->next[i]->value < value)
          {
            current = current->next[i];
          }
          last_seen[i] = current;
        }
        if(current->next[0] && current->next[0]->value == value){
          auto to_delete = current->next[0];
          int i=0;
          while(to_delete->next[i]){
            last_seen[i]->next[i] = to_delete->next[i];
            i++;          
          }
          delete to_delete;
          sSize--;
        }
      }
      delete last_seen;
    }

    void insert(T value)
    {
      skipNode<T>** last_seen = new skipNode<T>*[max_level+1];
      if(header->next[0]){
        auto current = header;
        for(int i = max_level;i>=0;i--){
          while(current->next[i] && current->next[i]->value < value){
            current = current->next[i];
          }
          last_seen[i] = current;
        }
        int new_level = level();
        auto new_node = new skipNode<T>(new_level+1);
        new_node->value = value;
        for(int i=0;i<=new_level;i++){
          auto tmp = last_seen[i]->next[i];
          new_node->next[i] = tmp;
          last_seen[i]->next[i] = new_node;
        }
      }else{
        int new_level = level();
        auto new_node = new skipNode<T>(new_level+1);
        new_node->value = value;
        for(int i=0;i<=new_level;i++){
          header->next[i] = new_node;
        }
      }
      delete last_seen;
      sSize++;
    }

    int size()
    {
      return sSize;
    }
  private:

    void delete_node(skipNode<T>* n){
      if(n->next[0]){
        delete_node(n->next[0]);
      }
      printf("%d\n", n->value);
      delete n;
    }

};
