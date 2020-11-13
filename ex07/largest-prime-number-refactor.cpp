#include <iostream>

using namespace std;

/*
 function? = named reusable code
 	- when we don't want to copy paste code
 	- better code clarity - naming, abstraction
*/

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	const int maxDivisor = sqrt(n);
	
	for (int divisor = 2; divisor <= maxDivisor; divisor++) {
		if (n % divisor == 0) {
			return false;
		}
	}

	return true;
}


/*
	Returns -1 if no such number exists
*/
int findTheLargestPrimeLessThan(int n) {
	for (int i = n - 1; i >= 2; i--) {
		if (isPrime(i)) {
			return i;
		}
	}

	return -1;
}

int readPositiveInt() {
	int n;
	do {
		cout << "n: ";
		cin >> n;
	} while (n <= 0);
	return n;
}

void outputLargestPrime(int largestPrime, int n) {
	if (largestPrime == -1) {
		cout << "No prime numbers smaller than " << n << endl;
	} else {
		cout << "The largest prime number is " << largestPrime << endl;
	}
}

void assertEqual(int expected, int actual) {
	cout << expected << " | " 
		 << actual << " ---- " 
		 << (expected == actual ? "OK" : "ERROR") << endl;
}

// unit testing
void test_findTheLargestPrimeLessThan() {
	assertEqual(47, findTheLargestPrimeLessThan(50));
	assertEqual(499, findTheLargestPrimeLessThan(500));
	assertEqual(3, findTheLargestPrimeLessThan(5));
	assertEqual(-1, findTheLargestPrimeLessThan(2));
	assertEqual(2, findTheLargestPrimeLessThan(3));
}

int main() {
	int n = readPositiveInt();
	int largestPrime = findTheLargestPrimeLessThan(n);
	outputLargestPrime(largestPrime, n);
	return 0;
}




