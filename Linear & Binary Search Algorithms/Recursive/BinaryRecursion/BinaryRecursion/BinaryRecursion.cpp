#include<iostream>
using namespace std;

int BinarySearchRecursion(int arry[], int high, int low, int key){
	int mid = (low + high) / 2;
	int rc = -1;
	if (low <= high){
		if (arry[mid] > key){
			high = mid - 1;
		} else if (arry[mid] < key){
			low = mid + 1;
		} else{
			rc = mid;
		}
		
		if(rc == -1){
			rc = BinarySearchRecursion(arry, high, low, key);
		}
	}
	return rc;
}

int BinarySearch(int arry[], int size, int key){
	int rc = -1;
	int high = size - 1;
	int low = 0;

	rc = BinarySearchRecursion(arry, high, low, key);

	return rc;
}

int main(){
	int arry[5] = { 1, 2, 3, 4, 5 };

	//Only works when array is sorted
	int rc = BinarySearch(arry, 5, 2);

	if (rc != -1){
		cout << "The index in which the number 2 is located is: " << rc << endl;
	}
	else{
		cout << "Two is not in the array" << endl;
	}

	return 0;
}