#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>

/*
  TODO implement iterators and use them for traversing internally
  TODO store the back node to make removal from the back easier (for queues)
*/

template <class T>
struct Node {
  T value;
  Node<T>* next;
  Node(T val) : value(val) {}
};

template <class T>
class LinkedList {
  public:
    LinkedList() : start_node(nullptr), _size(0) {}
    T& get(int index)
    {
      if(empty() || index < 0 || index > size()-1)
      {
        throw -1;
      }else{
        Node<T>* current = start_node;
        int cur_index = 0;
        while(current->next && cur_index != index)
        {
          current = current->next;
          cur_index++;
        }
        return current->value;
      }
    }

    bool empty()
    {
      return (size() > 0) ? false : true;
    }

    int size()
    {
      return _size;
    }

    void insert(int index, const T& elem)
    {
      if(index < 0 || index > size() || (empty() && index != 0))
      {
        throw -1;
      }
      if(index == 0){
        if(empty())
        {
          start_node = new Node<T>(elem);
        }
        else
        {
          Node<T>* tmp = start_node;
          start_node = new Node<T>(elem);
          start_node->next = tmp;
        }
        _size++;
      }else{
        Node<T>* current = start_node;
        int cur_index = 0;
        while(current->next && cur_index != index-1)
        {
          current = current->next;
          cur_index++;
        }
        Node<T>* tmp = current->next;
        current->next = new Node<T>(elem);
        current->next->next = tmp;
        _size++;
      }
    }

    void erase(int index)
    {
      if(empty() || index > size()-1 || index < 0)
      {
        throw -1;
      }else{
        if(index == 0)
        {
          start_node = start_node->next;
        }else{
          Node<T>* current = start_node;
          int cur_index = 0;
          while(current->next && cur_index != index-1)
          {
            current = current->next;
            cur_index++;
          }
          if(current->next)
          {
            current->next = current->next->next;
          }else{
            current->next = NULL;
          }
        }
        _size--;
      }
    }

    void insert_back(const T& elem)
    {
      if(!empty()){
        auto current = start_node;
        while(current->next){
          current = current->next;
        }
        current->next = new Node<T>(elem);
      }else{
        start_node = new Node<T>(elem);
      }
      _size++;
    }

    void insert_front(const T& elem)
    {
      if(!empty())
      {
        Node<T>* tmp = start_node;
        start_node = new Node<T>(elem);
        start_node->next = tmp;
      }else{
        start_node = new Node<T>(elem);
      }
      _size++;
    }

    void erase_front()
    {
      if(!empty())
      {
        erase(0);
      }else{
        throw -1;
      }
    }

    T& getBack()
    {
      if(!empty())
      {
        auto current = start_node;
        while(current->next)
        {
          current = current->next;
        }
        return current->value;
      }else{
        throw -1;
      }
    }

    T& getFront()
    {
      if(!empty()){
        return start_node->value;
      }else{
        throw -1;
      }
    }
    void reverse()
    {
      Node<T>* prev = nullptr;
      Node<T>* cur = start_node;
      Node<T>* next;
      while(cur!=nullptr){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
      }
      start_node = prev;
    }

    void printList(){
      Node<T>* current = start_node;
      while(current){
        std::cout << current->value << '\n';
        current = current->next;
      }
    }
  private:
    Node<T>* start_node;
    int _size;
};

#endif
