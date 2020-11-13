#include <iostream>

using namespace std;

int main() {
	int n;
	cout << "n: ";
	cin >> n;

	int largestPrime = -1;

	for (int i = n - 1; i >= 2; i--) {
		bool isPrime = true;

		const int maxDivisor = sqrt(i);
		for (int divisor = 2; divisor <= maxDivisor; divisor++) {
			if (i % divisor == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			largestPrime = i;
			break;
		}
	}


	if (largestPrime == -1) {
		cout << "No prime numbers smaller than " << n << endl;
	} else {
		cout << "The largest prime number is " << largestPrime << endl;
	}
	
	return 0;
}