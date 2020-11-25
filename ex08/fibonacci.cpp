#include <iostream>

using namespace std;

// recursive function
// 0! = 1
// n! = n * (n-1)!
long factorial(long n) {
	if (n == 0) { // base of recursion | дъно на рекурсията
		return 1;
	}
	return n * factorial(n - 1); // step | стъпка
}

// Fib(0) = 0
// Fib(1) = 1
// Fib(n) = Fib(n - 1) + Fib(n - 2)
long fib(long n) {
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	return fib(n - 1) + fib(n - 2);
}

// Can we do it with just 2 variables?
long fibLoop(long n) {
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	// fib(5)
	long f_1 = 1; // fib(1)
	long f_2 = 0; // fib(0)
	long f = f_1 + f_2; // fib(2)
/*
	f_2 = f_1;     // fib(1)
	f_1 = f;       // fib(2)
	f = f_1 + f_2; // fib(3)

	f_2 = f_1;     // fib(2)
	f_1 = f;       // fib(3)
	f = f_1 + f_2; // fib(4)

	f_2 = f_1;     // fib(3)
	f_1 = f;       // fib(4)
	f = f_1 + f_2; // fib(5)
*/
	for (int i = 2; i < n; i++) {
		f_2 = f_1;     // fib(1)
		f_1 = f;       // fib(2)
		f = f_1 + f_2; // fib(3)
	}

	return f;
}

long fibTail(long n, long f_1 = 1, long f_2 = 0) { // tail recursion
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	if (n == 2) {
		return f_1 + f_2;
	}

	return fibTail(n - 1, f_1 + f_2, f_1);
}

void print(int a = 1, int b = 20, int c = 30) {
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
}

int main() {
	/*
	print();
	cout << "======================" << endl;
	print(10);
	cout << "======================" << endl;
	print(100, 200);
	cout << "======================" << endl;
	print(100, 200, 300);
	cout << "======================" << endl;
	*/

	cout << " 0 == " << fib(0)  << " | " << fibLoop(0) <<  " | " << fibTail(0) << endl;
	cout << " 1 == " << fib(1)  << " | " << fibLoop(1) <<  " | " << fibTail(1) << endl;
	cout << " 1 == " << fib(2)  << " | " << fibLoop(2) <<  " | " << fibTail(2) << endl;
	cout << " 2 == " << fib(3)  << " | " << fibLoop(3) <<  " | " << fibTail(3) << endl;
	cout << " 3 == " << fib(4)  << " | " << fibLoop(4) <<  " | " << fibTail(4) << endl;
	cout << " 5 == " << fib(5)  << " | " << fibLoop(5) <<  " | " << fibTail(5) << endl;
	cout << " 8 == " << fib(6)  << " | " << fibLoop(6) <<  " | " << fibTail(6) << endl;
	cout << "13 == " << fib(7)  << " | " << fibLoop(7) <<  " | " << fibTail(7) << endl;
	cout << "21 == " << fib(8)  << " | " << fibLoop(8) <<  " | " << fibTail(8) << endl;
	cout << "34 == " << fib(9)  << " | " << fibLoop(9) <<  " | " << fibTail(9) << endl;
	cout << "55 == " << fib(10) << " | " << fibLoop(10) << " | " << fibTail(10) << endl;
	cout << "55 == " << fib(5)  << " | " << fibLoop(50) << " | " << fibTail(50) << endl;
	return 0;
}