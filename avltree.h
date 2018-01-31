#include <iostream>
#include <algorithm>


template <class T>
struct AVLNode {

  T val;
  AVLNode<T>* left;
  AVLNode<T>* right;
  int height;

  AVLNode(T val) :
    val(val),
    left(nullptr),
    right(nullptr),
    height(0)
  {}

  AVLNode(T val, AVLNode<T>* l, AVLNode<T>* r, int height=0) :
    val(val),
    left(l),
    right(r),
    height(height)
  {}
};

template <class T>
class AVLTree {
  public:

    AVLTree() : 
      root(nullptr),
      imbalance(1)
    {}

    ~AVLTree()
    {
      avlDelete(root);
    }

    void insert(T val){
      avlInsert(root, val);
    }

    void inOrder(){
      inOrderTrav(root);
      std::cout << '\n';
    }

  private:

    void avlDelete(AVLNode<T>* node){
      if(node!=nullptr){
        avlDelete(node->left);
        avlDelete(node->right);
        delete node;
      }
    }

    void inOrderTrav(const AVLNode<T>* cur) const {
      if(cur!=nullptr){
        inOrderTrav(cur->left);
        std::cout << "PARENT: " << cur->val << ' ';
        if(cur->left!=nullptr) std::cout << "LEFT: " << cur->left->val << ' ';
        if(cur->right!=nullptr) std::cout << "RIGHT: " << cur->right->val << ' ';
        std::cout << '\n';
        inOrderTrav(cur->right);
      }
    }

    void avlInsert(AVLNode<T>*& node, T& val){

      if(node == nullptr){
        node = new AVLNode<T>(val, nullptr, nullptr);

      }else if(node->val > val){
        avlInsert(node->left, val);

      }else if(node->val < val){
        avlInsert(node->right, val);
      }
      balance(node);

    }

    void balance(AVLNode<T>*& node){
      /*
        need to determine if the left side is unbalanced
        or the right side is unbalanced
        if one of the sides is unbalanced, then we figure out if we need to do a double rotate, or a single rotate
      */
      if(height(node->left) - height(node->right) > imbalance){
        //left side is heavy
        //need to see if its a double rotate or a single rotate
        if(height(node->left->left) >= height(node->left->right)){
          //single left
          singleLeft(node);
        }else{
          doubleLeft(node);
          //double left right
        }
      }else if(height(node->right) - height(node->left) > imbalance){
        //right heavy
        if(height(node->right->right) >= height(node->right->left)){
          singleRight(node);
          //single right
        }else{
          doubleRight(node);
          //double right left
        }
      }
      node->height = std::max(height(node->left), height(node->right))+1;
    }

    void singleRight(AVLNode<T>*& node){
      auto tmp = std::move(node->right);
      node->right = std::move(tmp->left);
      tmp->left = std::move(node);
      node->height = std::max(height(node->left), height(node->right))+1;
      tmp->height = std::max(height(tmp->left), height(tmp->right))+1;
      node = std::move(tmp);
    }

    void singleLeft(AVLNode<T>*& node){
      auto tmp = std::move(node->left);
      node->left = std::move(tmp->right);
      tmp->right = std::move(node);
      node->height = std::max(height(node->left), height(node->right))+1;
      tmp->height = std::max(height(tmp->left), height(tmp->right))+1;
      node = std::move(tmp);
    }

    void doubleRight(AVLNode<T>*& node){
      singleLeft(node->right);
      singleRight(node);
    }

    void doubleLeft(AVLNode<T>*& node){
      singleRight(node->left);
      singleLeft(node);
    }

    int height(AVLNode<T>*& node) const {
      return (node==nullptr) ? -1 : node->height;
    }

    AVLNode<T>* root;
    int imbalance;
};
