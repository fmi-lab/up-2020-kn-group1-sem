#include <iostream>

using namespace std;

// reference? --> псевдоним
// pass by value; swap(int a, int b)
// pass by reference: swap(int & a, int & b)
//	- return more than one value 
//  - if the paramters are taking a lot of memory
//  - modify the actual variable

void swap(int& a, int& b) { 
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 10;
	int b = 13;
	swap(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	return 0;
}
