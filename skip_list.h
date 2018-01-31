#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


/*
  skipNode([int size [, int value ]])
  returns a skipNode that points up to `size` other nodes with the internal value of `value`
*/
template <class T>
struct skipNode {
  T value;
  skipNode<T>* next;
  skipNode(){}
  skipNode(int size){next = new skipNode<T>[size];}
  skipNode(int size, int value) : value(value), next(new skipNode<T>[size]) {}
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
      header = new skipNode<T>[max_level];
    }

    int level() const
    {
      int lev = 1;
      while(rand() <= cutOff) lev++;
      return (lev <= max_level) ? lev : max_level;
    }

    int size() const
    {
      return sSize;
    }

    bool empty() const
    {
      return (size() > 0) ? false : true;
    }

    void printList() const
    {
      auto current = header;
      while(x < 2)
      {
        x++;
        current = current[0];
        std::cout << current->value;
      }
    }

    void insert(T value)
    {
      int new_level = level();
      skipNode<T> new_node = skipNode<T>(new_level, value);

      if(!empty())
      {
        printf("%d\n", value);
      }else{
        printf("%d\n", value);
        for(int i=0;i<new_level;i++)
        {
          header[i] = new_node;
        }
      }
      sSize++;
    }


};
