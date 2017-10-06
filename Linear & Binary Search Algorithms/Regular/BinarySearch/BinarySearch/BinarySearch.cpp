#include<iostream>
using namespace std;

int BinarySearch(int arry[], int size, int key){
	int rc = -1;
	int high = size - 1;
	int low = 0;
	int mid = 0;

	while (low <= high && rc == -1){
		mid = (low + high) / 2;

		if (arry[mid] > key){
			high = mid - 1;
		}
		else if (arry[mid] < key){
			low = mid + 1;
		}
		else{
			rc = mid;
		}
	}
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