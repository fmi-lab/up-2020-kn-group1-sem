#include <iostream>

using namespace std;

int main() {
	int x1, x2;
	double y1;
	char c;

	// cout << "x1 x2" << endl;
	// cin >> x1 >> c >> x2;
	// cout << "x1: " << x1 << endl;
	// cout << "x2: " << x2 << endl;
	// cout << "Successfull read? " << (cin) << endl;

	// // flush
	// cin.clear();
	// cin.ignore();

	// cout << "x1 x2" << endl;
	// cin >> x1 >> x2;
	// cout << "x1: " << x1 << endl;
	// cout << "x2: " << x2 << endl;
	// cout << "Successfull read? " << (cin) << endl;

	int month;
	cout << "Month: ";
	cin >> month;

	if (cin && 1 <= month && month <= 12) {
		cout << "Month is correct" << endl;
	} else {
		cout << "Wrong month...." << endl;
	}

	return 0;
}