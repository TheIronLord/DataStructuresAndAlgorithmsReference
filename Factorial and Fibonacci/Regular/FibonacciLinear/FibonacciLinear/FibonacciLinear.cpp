#include <iostream>

using namespace std;

int fibonacciLinear(int i){
	int nxtAns = 1;
	int prvAns = 0;
	int currAns = 0;

	if (i > 1)
	{

		for(int j = 1; j < i; j++){
			currAns = nxtAns + prvAns;
			prvAns = nxtAns;
			nxtAns = currAns;
		}
	}
	return (i == 1) ? 1 : currAns;
}

int main(){
	int rc = fibonacciLinear(5);

	cout << "Fibonacci of 5: " << rc << endl;

	return 0;
}