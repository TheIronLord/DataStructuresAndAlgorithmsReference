#include "LinkedList.h"

int main(){
	List linkedlist;

	//push values in
	linkedlist.push_back(5);
	linkedlist.push_front(6);
	linkedlist.push_back(4);
	linkedlist.push_front(7);
	linkedlist.push_back(3);
	linkedlist.push_front(8);
	linkedlist.push_back(2);
	linkedlist.push_front(9);
	linkedlist.push_back(1);
	linkedlist.push_front(10);
	linkedlist.push_back(0);

	//Delete from the front
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();
	linkedlist.pop_front();

	//Print out values
	linkedlist.print();

	//Re-push again
	linkedlist.push_back(5);
	linkedlist.push_front(6);
	linkedlist.push_back(4);
	linkedlist.push_front(7);
	linkedlist.push_back(3);
	linkedlist.push_front(8);
	linkedlist.push_back(2);
	linkedlist.push_front(9);
	linkedlist.push_back(1);
	linkedlist.push_front(10);
	linkedlist.push_back(0);


	//Delete from the back
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();
	linkedlist.pop_back();

	//Print out values
	linkedlist.print();

	//Push it in again for a third time
	linkedlist.push_back(5);
	linkedlist.push_front(6);
	linkedlist.push_back(4);
	linkedlist.push_front(7);
	linkedlist.push_back(3);
	linkedlist.push_front(8);
	linkedlist.push_back(2);
	linkedlist.push_front(9);
	linkedlist.push_back(1);
	linkedlist.push_front(10);
	linkedlist.push_back(0);

	//Print out values
	linkedlist.print();

	return 0;
}