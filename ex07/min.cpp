#include <iostream>

using namespace std;

float myMin(float a, float b) {
	return a < b ? a : b;
}

double myMin(double a, double b) {
	return a < b ? a : b;
}

int myMin(int a, int b) {
	cout << "int min" << endl;
	return a < b ? a : b;
}

long myMin(long a, long b) {
	cout << "long min" << endl;
	return a < b ? a : b;
}

// overload
int myMin(int a, int b, int c) {
	return myMin(a, myMin(b, c));
}

int main() {
	cout << myMin(10l, 13l) << endl;
	cout << myMin(12312, 513) << endl;
	cout << myMin(50, 50) << endl;
	cout << myMin(50, 4, 123) << endl;


	return 0;
}
