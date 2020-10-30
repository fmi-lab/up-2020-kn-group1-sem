#include <iostream>

using namespace std;

int main() {

	int a, b, c;
	cout << "a, b, c: ";
	cin >> a >> b >> c;
	
	if (a > b) {
		if (a > c) {
			cout << "max is: " << a << endl;
		} else {
			cout << "max is: " << c << endl;
		}
	} else {
		if (b > c) {
			cout << "max is: " << b << endl;
		} else {
			cout << "max is: " << c << endl;
		}
	}

	int m = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
	cout << "max is: " << m << endl;

	// max(a, b, c) = max(max(a,b), c)
	// max(a, b, c) = max(a, max(b, c))
	int max = a > b ? a : b;
	max = max > c ? max : c;
	cout << "max is: " << m << endl;

	return 0;
}