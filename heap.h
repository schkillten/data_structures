#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
/* MAX HEAP */

/*

  Analysis of this heap:

   Insert:
    
      worst case O(log n) best/average case O(1). Since the insertion is just added to the end of the heap

*/
template <class T>
class Heap{
  public:
    Heap(){}
    void insert(const T val){
      heap_array.push_back(val);
      heapMax(heap_array.size()-1);
    }

    void remove(){
      if(!heap_array.empty()){
        swap(heap_array[0], heap_array[heap_array.size()-1]);
        heap_array.pop_back();
        heapDown(0);
      }
    }
    
    //need to fix the indexing so that I only pick ones that are within the size of the array
    void heapDown(int index){
      int left_child = 2*index+1;
      int right_child = 2*index+2;
      int max = index;

      if(left_child < heap_array.size() && heap_array[max] < heap_array[left_child]){
        max = left_child;
      }

      if(right_child < heap_array.size() && heap_array[max] < heap_array[right_child]){
        max = right_child;
      }

      if(max!=index){
        std::cout << max << '\n';
        swap(heap_array[index], heap_array[max]);
        heapDown(max);
      }
    }

    void heapMax(int index){
      if(index > 0){
        int parent = (index-1)/2;
        if(heap_array[index] > heap_array[parent]){
          swap(heap_array[index], heap_array[parent]);
          heapMax(parent);
        }
      }
    }

    void swap(T& x, T& y){
      auto tmp(std::move(x));
      x = std::move(y);
      y = std::move(tmp);
    }

    void display(){
      for(int i=0;i<heap_array.size();i++){
        std::cout << heap_array[i] << ' ';
      }
      std::cout << '\n';
    }
  private:
    std::vector<T> heap_array;
};
