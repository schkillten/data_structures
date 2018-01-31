#include <vector>
#include <algorithm>
#include <iostream>

/*
  Analysis of Hash using Seperate Chaining to handle collision.

  Also, I didn't really make a very complicated hashing function, that was mostly a design descision, it only takes int keys
  and all it does is mod off the size of the array.

  I could always make a more complex hashing function that also allows for user defined hashing functions, and all of this code still works
  100% the same. Basically, the hash function has a huge impact on the chance of collisions, but the data structure works the same.

  Find/Lookup: 
    O(1) best case, if there are collisions you're looking at O(n) worst case lookup

  Insert: 
    Well since insert uses lookup, its virtually the same performance, best case O(1) is no collisions
    and O(n) worst case
          
  Delete/Remove: 
    Same thing, it looks for the key, if no collisions O(1), if collisions O(n) worst case

  I chose seperate chaining mostly because the data set I would be using is fairly random. Using a method like open addressing,
  depending on your array size, you increase the chance of collisions, if you have a larger array size, it wont play as big
  of a role. Open addressing removes the extra space complexity that seperate chaining introduces

*/

template <class T>
struct HashNode {
  T val;
  int key;
  HashNode(const int key, const T val) : val(val), key(key){}
  bool operator==(const HashNode& other) const {
    return other.key == this->key;
  }
  bool operator!=(const HashNode& other) const {
    return !(*this == other);
  }
};

template <class T> 
using HashTable = std::vector<std::vector<HashNode<T>>>;

template <class T>
class Hash{
  public:
    Hash(const int& size, const float& loadFactor=3.0f) : 
      hash_table(size), 
      hash_size(0),
      loadFactor(loadFactor)
    {}

    const int hash(const int& key) const{
      return key % hash_table.capacity();
    }

    void insert(const int& key, const T& val){
      int index = hash(key);
      auto& bucket = hash_table[index];
      auto b_it = std::find_if(bucket.begin(), bucket.end(), [&](const HashNode<T>& c){ return c.key == key;});
      if(b_it==bucket.end()) {
        if(bucket.empty()) {
          hash_size++;
        }
        bucket.emplace_back(HashNode<T>(key, val));
        if(overloaded()){
           resize();
        }
      }else{

        b_it->val = val;

      }
    }

    //this is an insert using an rvalue/std::move instead of doing a copy
    void insert(HashNode<T>&& n){
      int index = hash(n.key);
      auto& bucket = hash_table[index];
      auto b_it = std::find_if(bucket.begin(), bucket.end(), [&](const HashNode<T>& c){ return c.key == n.key;});
      if(b_it==bucket.end()) {
        if(bucket.empty()) {
          hash_size++;
        }
        bucket.emplace_back(n);
        if(overloaded()){
           resize();
        }
      }else{

        b_it->val = n.val;

      }

    }

    void remove(const int& key){
      int index = hash(key);
      auto& bucket = hash_table[index];
      auto b_it = std::find_if(bucket.begin(), bucket.end(), [&](const HashNode<T>& c){ return c.key == key;});

      if(b_it!=bucket.end()){
        bucket.erase(b_it);

        if(bucket.empty()) {
          hash_size--;
        }
      }
    }

    bool overloaded() const {
      float loadedFactor = (float)hash_table.capacity()/loadFactor;
      return hash_size > loadedFactor*2;
    }

    void resize(){
      //move the current hash_table into a tmp variable
      auto tmp(std::move(hash_table));
      //move a new HashTable with double the capacity into the member var
      hash_table = HashTable<T>(tmp.capacity()*2);
      //reset the hash_size as its now empty
      hash_size=0;
      //rehash the old table into the new one
      for(auto bucket : tmp){
        for(auto pair : bucket){
          //insert(HashNode<T>(std::move(pair)));
          insert(std::move(pair));
        }
      }
      //I could possible make a little optimization by just moving the HashNodes into new positions
      //rather than making new ones in the insert method
    }

    void showHash() const{
      for(int i=0;i<hash_table.size();i++){
        std::cout << "BUCKET:" << i << "> ";
        for(int j=0;j<hash_table[i].size();j++){
          std::cout << (hash_table[i][j]).val << " ";
        }
        std::cout << '\n';
      }
      std::cout << hash_size << '\n';
    }

  private:
    int hash_size;
    float loadFactor;
    HashTable<T> hash_table;
};
