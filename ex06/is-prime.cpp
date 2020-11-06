#include <iostream>

using namespace std;

int main() {
	int n; // [2, sqrt(n)]
	// n = n1 * n2
	// n1 in [2, sqrt(n)]
	// n2 in [sqrt(n), n]
	
	cout << "n=";
	cin >> n;

	{	// version 1 - counting while
		bool isPrime = true;
		
		int maxDivisor = sqrt(n);
		int currentDivisor = 2;
		// [2 .. maxDivisor] --> for ();

		while (currentDivisor <= maxDivisor) {
			if (n % currentDivisor == 0) {
				isPrime = false;
				break;
			}
			currentDivisor++;
		}

		if (isPrime) {
			cout << n << " is prime" << endl;
		} else {
			cout << n << " is NOT prime" << endl;
		}
	}

	{	// version 2 - proper while
		bool isPrime = true;
		
		int maxDivisor = sqrt(n);
		while (maxDivisor >= 2) {
			if (n % maxDivisor == 0) {
				isPrime = false;
				break;
			}
			maxDivisor--;
		}

		if (isPrime) {
			cout << n << " is prime" << endl;
		} else {
			cout << n << " is NOT prime" << endl;
		}
	}

	{	// version 3 - for loop
		bool isPrime = true;
				
		// for (init var (1); condition (2); modify var(4)) {
		// 		code ... (3)
		// }
		// (1) -> (2) -> (3) -> (4) -> [(2) -> (3) -> (4)] -> [(2) -> (3) -> (4)]
		
		int maxDivisor = sqrt(n);
		for (int divisor = 2; divisor <= maxDivisor; divisor++) {
			if (n % divisor == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			cout << n << " is prime" << endl;
		} else {
			cout << n << " is NOT prime" << endl;
		}
	}
	
	
	return 0;
}