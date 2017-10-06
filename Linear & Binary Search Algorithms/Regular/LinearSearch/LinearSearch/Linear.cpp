#include<iostream>

using namespace std;

int LinearSearch(int arry[], int size, int key){
	bool found = false;
	int rc = 0;
	for (int i = 0; i < size - 1 && !found; i++){
		if (arry[i] == key){
			found = true;
			rc = i;
		}
	}
	return rc;
}

int main(){
	int arry[5] = { 1, 2, 3, 4, 5 };

	int rc = LinearSearch(arry, 5, 4);

	cout << "The index in which the number 4 is located is: " << rc << endl;
	return 0;
}