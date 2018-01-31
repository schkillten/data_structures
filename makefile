CC = g++
COMPILER_FLAGS = -g -std=c++11 
BINS = queueTest stackTest linkedListTest directed_graph hashmap heap avl
CUR_BIN = current_imp

tests: queue stack linked_list graph hash heap avl

queue:
	$(CC) testQueue.cpp -o queueTest $(COMPILER_FLAGS)

stack:
	$(CC) testStack.cpp -o stackTest $(COMPILER_FLAGS)

linked_list:
	$(CC) testLinkedList.cpp -o linkedListTest $(COMPILER_FLAGS)

graph:
	$(CC) directed_graph_main.cpp -o directed_graph $(COMPILER_FLAGS)

hash:
	$(CC) hashmain.cpp -o hashmap $(COMPILER_FLAGS)


heap:
	$(CC) heapmain.cpp -o heap $(COMPILER_FLAGS)

avl:
	$(CC) avlmain.cpp -o avl $(COMPILER_FLAGS)

current_imp:
	$(CC) current_imp.cpp -o current_imp $(COMPILER_FLAGS)

clean_cur:
	rm $(CUR_BIN)

clean:
	rm $(BINS)
