#include <iostream>

using namespace std;

int factorialLinear(int i){
	int ans = i;
	i--;

	for (i; i > 0; i--){
		ans *= i;
	}

	return ans;
}

int main(){
	int ans = factorialLinear(5);

	cout << "Factorial of 5: " << ans << endl;

	return 0;
}