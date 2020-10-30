#include <iostream>

using namespace std;

int main() {
	// input
	int year;
	int month;
	int day;
	cout << "year month day: ";
	cin >> year >> month >> day;

	// is CIN is valid?
	// is year is valid? - always true
	// is month is valid? 1 .. 12
	// is day is valid? 1 .. 28/29/30/31

	// magic
	bool isDateValid = false;
	if (cin && 1 <= month && month <= 12) {

		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		
		int numberOfDaysInMonth = 31;
		switch (month) {
			case 2: numberOfDaysInMonth = 28 + isLeapYear; break;
			
			case 4:
			case 6:
			case 9:
			case 11: numberOfDaysInMonth = 30; break;
			default: numberOfDaysInMonth = 31;
		}

		if (1 <= day && day <= numberOfDaysInMonth) {
			isDateValid = true;
		}
	}

	// output
	if (isDateValid) {
		cout << "Датата е валидна" << endl;
	} else {
		cout << "Датата не е валидна" << endl;
	}

	return 0;
}