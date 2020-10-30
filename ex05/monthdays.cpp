#include <iostream>

using namespace std;

int main() {
	// data input 
	int month;
	int year;
	cout << "month, year: ";
	cin >> month >> year;


	bool isLeapYear = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
	// true / false
	// 1 / 0

	// the magic !!!
	int numberOfDays;
	switch (month) {
		case 1: numberOfDays = 31; break;
		case 2: numberOfDays = 28 + isLeapYear; break;
		case 3: numberOfDays = 31; break;
		case 4: numberOfDays = 30; break;
		case 5: numberOfDays = 31; break;
		case 6: numberOfDays = 30; break;
		case 7: numberOfDays = 31; break;
		case 8: numberOfDays = 31; break;
		case 9: numberOfDays = 30; break;
		case 10: numberOfDays = 31; break;
		case 11: numberOfDays = 30; break;
		case 12: numberOfDays = 31; break;
	}

	// date output
	cout << "Number of days: " << numberOfDays << endl;
	return 0;
}