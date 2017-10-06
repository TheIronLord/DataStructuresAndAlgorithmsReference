#include <iostream>

using namespace std;

int factorialRecursion(int i){
	int rc = 1;
	if (i > 1){
		rc = i * factorialRecursion(i - 1);
	}
	return rc;
}

int main(){
	int ans = factorialRecursion(5);

	cout << "Factorial of 5: " << ans << endl;

	return 0;
}