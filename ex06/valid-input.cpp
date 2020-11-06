#include <iostream>

using namespace std;

int main() {
	int month; // 1 - 12

	// option 1
	do {
		cout << "Type value for month: ";
		cin >> month;

		if (month <= 0 || month >= 13) {
			cout << "Invalid month. Month should be between (1..12)!" << endl;
		} else {
			break;
		}
	} while (true);


	// option 2
	while (true) {
		cout << "Type value for month: ";
		cin >> month;

		if (0 <= month && month <= 12) {
			break;
		}

		cout << "Invalid month. Month should be between (1..12)!" << endl;
	}

	// option 3
	do {
		cout << "Type value for month: ";
		cin >> month;

		if (month <= 0 || month >= 13) {
			cout << "Invalid month. Month should be between (1..12)!" << endl;
		}		
	} while (month <= 0 || month >= 13);

	// option 4
	bool isMonthValid = false;
	do {
		cout << "Type value for month: ";
		cin >> month;

		isMonthValid = (1 <= month && month <= 12);
		if (!isMonthValid) {
			cout << "Invalid month. Month should be between (1..12)!" << endl;
		}		
	} while (!isMonthValid);


	cout << "Valid value for month: " << month << endl;
	return 0;
}