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
		case 1: 
		case 3: 
		case 5: 
		case 7: 
		case 8: 
		case 10: 
		case 12: numberOfDays = 31; break;

		case 2: numberOfDays = 28 + isLeapYear; break;
		
		case 4:
		case 6:
		case 9:
		case 11: numberOfDays = 30; break;
		default: numberOfDays = -1;
	}

	// if month has correct values
	switch (month) {
		case 2: numberOfDays = 28 + isLeapYear; break;
		
		case 4:
		case 6:
		case 9:
		case 11: numberOfDays = 30; break;
		default: numberOfDays = 31;
	}


	// date output
	cout << "Number of days: " << numberOfDays << endl;
	return 0;
}