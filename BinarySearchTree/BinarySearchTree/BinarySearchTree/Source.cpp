#include<iostream>

#include "BST.h"

using namespace std;

int main(){
	BST bst;

	bst.insert(20);
	bst.insert(30);
	bst.insert(15);
	bst.insert(18);
	bst.insert(40);
	bst.insert(25);
	bst.insert(35);
	bst.insert(80);

	/*bst2.insert(20);
	bst2.insert(30);
	bst2.insert(15);
	bst2.insert(18);
	bst2.insert(40);
	bst2.insert(25);
	bst2.insert(35);
	bst2.insert(80);

	*/
	//bst.removeMain(30);
	BST bst2(bst);
	bool compare = bst == bst2;
	int ans = bst.find(40);
	ans = bst.find(1);

	//bst.printBetween(10, 30);

	int count = bst.numOfNodesInTree();
	return 0;
}