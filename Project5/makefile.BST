# Honor Pledge:
#
# I pledge that I have neither given nor
# received any help on this assignment.
#
# iaustin and aschroeder 

BST.exe: driverBST.o Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o
	g++ driverBST.o Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o -o BST.exe
	
driverBST.o: driverBST.cpp
	g++ -c driverBST.cpp -o driverBST.o
	
Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o
	
TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o
	
BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o	

RedBlackTree.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RedBlackTree.o

clean:
	rm *.o BST.exe
	