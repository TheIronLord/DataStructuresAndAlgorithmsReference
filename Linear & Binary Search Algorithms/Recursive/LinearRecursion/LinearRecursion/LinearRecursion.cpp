#include<iostream>

using namespace std;

int LinearSearchRecursion(int arry[], int size, int key){
	int rc;
	if (arry[size] == key){
		rc = size;
	}
	else if (size > 0){
		rc = LinearSearchRecursion(arry, size - 1, key);
	}
	return rc;
}

int main(){
	int arry[5] = { 1, 2, 3, 4, 5 };

	int rc = LinearSearchRecursion(arry, 4, 1);

	cout << "The index in which the number 1 is located is: " << rc << endl;
	return 0;
}