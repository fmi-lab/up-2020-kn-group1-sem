#include <iostream>

using namespace std;

int main() {

	int a, b;
	cout << "a, b: ";
	cin >> a >> b;

	
	if (a < b) {
		cout << "max is: " << b << endl;
	} else {
		cout << "max is: " << a << endl;
	}

	int m;
	if (a < b) {
		m = b;
	} else {
		m = a;
	}
	cout << "max is: " << m << endl;

	// (predicate) ? (if true) : (if false);
	int M = (a < b) ? b * 1000 : a * 100;
	cout << "max is: " << M << endl;


	(a > b) ? (cout << "max is: " << a << endl) 
			: (cout << "max is: " << b << endl);

	cout << "max is: " << (a > b ? a : b) << endl;


	return 0;
}