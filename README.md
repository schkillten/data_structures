Data Structures

  To compile and run them just use the `make` command (hopefully it works for you)
  and you can run them each individually. The programs are just me using all the operations
  and testing the output.
  
[Circular Buffer/Queue](circurlar_buffer.h)
  Basically just a rotating queue, fun data structure to make since it required you wrapping around memory, couple of solutions
  to this too.
  
[Queue Using two Stacks](queue_from_stacks.h)
  This was more of a programming problem I was doing, but its still a data structure eh. Using two stacks to implement a queue
  one acts as an input stack, and the other is an output, just have to make sure you only dump the input into the output when
  the output is empty.

[AVL Tree](avltree.h)

  An AVL tree is a balancing binary tree. It uses a balancing factor to ensure that all
  nodes are of a certain height, when you insert, if you break the balancing factor 
  then a balance is triggered.

  As with most trees, most operations are O(log n) since you're traversing a path in
  the tree which is a log n operation. After ever modifying operation you confirm that
  every node in the inserted path does not break the balance factor, if it does you 
  rebalance by either doing a single swap or a double swap.


[Graph](directed_graph_adj_list.h) (with adjacency list implementation)

  |V| = all vertices
  |E| = all edges

  The graph I implemented is a directed graph using an adjacency list to store it's
  adjacent nodes. Since a vertex is stored in a hash table, inserting a vertex is O(1)
  and finding one is also O(1). Once you add a vertex you must add an edge from it to
  anther vertex which is also an O(1) operation because I use an adjacency list, all 
  I have to do is add it to the adjacency list which is O(1).

  Testing if Vertex x is adjacent to Vertex y is O(|V|), I have to scan all of the
  edges in the x adjacency list which has the potential to have a link to all other
  nodes. This is basically the same for removing an edge, you have to scan all the 
  edges for a specified node.

  Removing a vertex x is O(|E|), since you have to look through all of the edges and
  remove any that point to x.

[Hash table](hash.h)

  A hash table is a chunk of contiguous memory, it has to be a structure that allows
  for random indexing otherwise you lose out on the O(1) insertion. Removal is also
  O(1).

  The idea is you you have a key => value pair. When you do an insertion you pass 
  the key with the value. Then you pass the key to a hash function and it returns an
  index into the array and thats where you store the value. When you want to retrieve 
  this information you just pass the same key and your hash function will return the
  same index as it was stored in.

  One of the biggest challenges is creating an evenly distributed hash function.
  Perfect hash functions are almost impossible without knowing something about your
  input. 

  Another challenge is collision. Since it's so hard to have a perfect hash function,
  you need to expect some keys will hash to the same value. There are many solutions 
  to this problem. A popular solution is separate chaining, where you have buckets
  for each index of your array. When your key hashes to a specific value, it is then
    thrown into the bucket for that index, when you want to find the value, all you do
    is look at the bucket in the hashed index and scan for it. This isn't O(1) but is
    still much better than full scans. Another solution is open addressing, this
    solution is far better for space, as you dont use any extra space, but you end up
    rehashing more often and colliding more often.

[Heap](heap.h)

  A heap is a tree structure but usually stored in an array (a contiguous structure).
  The heap is stored as an array but operated on as a binary tree.
  The concept is that an array is max heapified or min heapified. In a max heap, if 
  you have parent p with the child l and the child r then p > l and p > r. This
  doesn't mean that l < r or l > r, that part doesn't matter, this is not a binary
  search tree, just a binary tree.

  Insertion O(logn) worst case, this is because when you insert, all you do is add
  the value to the very back of the array then sift up, in a max heap you check if
  the current nodes parent is less than it, swap if so, and repeat, so we get O(logn)
  however it's O(1) average case if the value inserted is less than its parent.

  Removal is similar to a stack, where you cant just remove any element, you can only
  remove from the top. So you guarantee that you're removing the largest element in 
  the tree (or smallest in a min heap). So the common strategy is to swap the top
  with the back, delete the back (O(1) to delete back since no shifting) then sift
  the top down which is O(logn).

  Heaps are very commonly used for priority queues where you pass in some comparator 
  and that function is used to compare values, so you can define what the highest
  priority value in the heap is or the lowest, and can be any type of data as long
  as you define the comparator.

[Linked List](LinkedList.h)

  A linked list a non contiguous memory data structure. You have a node that stores 
  its data and a pointer to the next element in the structure.

  With a singly linked list you have a choice, you can either have O(1) insertion
  and O(n) deletion or vise versa. This is because you have to traverse the entire
  structure in order to get to the end, or the front, depending on how you orient it.

  Linked lists are the base data structure for several other data structures, including
  queues and stacks, but they can be implemented with many other structures.

[Skip List](skip_list.h)

  A skip list is a linked list, but instead of storing a pointer to just the next node
  it stores pointers to several other nodes. What happens is you use a distributed 
  probability function that uses the size and a max height as a way to determine how
  many other nodes a newly inserted node will point to. Each node points to a different
  number of nodes based off of the result of this probability function. The max height
  is generally based off of the max size.

  Since you have nodes pointing to a varying number of other nodes, you get a similar
  traversal pattern as a binary search tree. You start with the first node of max 
  height which can point to other nodes of the same height, allowing you to skip 
  through all of the nodes between them.

  Because of this you get insertion, delete, and search time of O(log n)

[Queue](Queue.h)

  A queue is a FIFO data structure, first in first out, meaning the first element you
  insert into the queue, will be the first one removed upon deletion, so if you insert
  1,2,3,4,5 then do a delete, you'll delete 1. Depending on your implementation you
  can have very fast insertion and deletion times. My implementation uses a singly 
  linked list so I have O(1) insertion and O(n) deletion.

[Stack](Stack.h)

  A stack is a LIFO or last in first out data structure, so if you insert 1 2 3 4 5, 
  the first thing you can delete is the 5. My implementation uses my linked list and
  since insertion and deletion operate on the same node, both operations are O(1).

