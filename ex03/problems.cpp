#include <iostream>
#include <cmath>

using namespace std;

// Без IFs/Loops
// in: EGN
// out: how old is the person?
// today: hardcoded
// check: the lib for working with dates

int main() {
	// https://en.cppreference.com/w/cpp/numeric/math/sqrt
	// 1. a^2 + b^2 + square root(c) // float
	// in: 2.14 3.14 4.14
	
	float a, b, c;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	
	float result1 = a * a + b * b + sqrt(c);
	cout << "a^2 + b^2 + square root(c): "
		 << result1
		 << endl;
	

	// 2. x ^ y
	// https://en.cppreference.com/w/cpp/numeric/math/pow	
	double x, y;
	cout << "x: "; 
	cin >> x;
	cout << "y: "; 
	cin >> y;
	cout << pow(x, y) << endl;

	// 3. swap variables
	int v1, v2;
	cout << "v1: ";
	cin >> v1;
	cout << "v2: ";
	cin >> v2;
	
	// ## v1
	int temp = v1;
	v1 = v2;
	v2 = temp;

	// ## v2
	// v1 = v1 + v2;
	// v2 = v1 - v2;
	// v1 = v1 - v2;

	// ## v3
	// swap(v1, v2);

	// ## v4
	// binary operations
	// & (and):  0101 & 1100 = 0100
	// | (or) :  0101 | 1100 = 1101
	// << (shift left):  0101 << 1 = 01010
	// >> (shift right): 1010 >> 1 = 101
	// ^ (xor exclusive or): 0110 ^ 1010 = 1100
	// 0110 ^ 1010 = 1100
	// 1100 ^ 1010 = 0110
	// 1100 ^ 0110 = 1010
	
	// v1 = v1 ^ v2;
	// v2 = v1 ^ v2;
	// v1 = v1 ^ v2;

	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;

	// 4. Number of digits in a number
	int n;
	cout << "n: ";
	cin >> n;

	// v1
	cout << "Number of digits: "
		 << floor(log10(n)) + 1
		 << endl;

	cout << "Number of digits: "
		 << ((int) log10(n)) + 1
		 << endl;

	// v2
	cout << "Number of digits: "
		 << to_string(n).length()
		 << endl;

	return 0;
}