#include <iostream>

using namespace std;

int fibonacciRecursion(int i){
	int rc = 1;
	if (i > 2){
		rc = fibonacciRecursion(i - 1) + fibonacciRecursion(i - 2);
	}
	return (i == 0) ? 0 : rc;
}

int main(){
	int rc = fibonacciRecursion(5);

	cout << "Fibonacci of 5: " << rc << endl;

	return 0;
}