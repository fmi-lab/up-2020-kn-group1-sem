#include <iostream>
using namespace std;

int main() {
	int year1, month1, day1;
	int year2, month2, day2;

	cout << "Date 1: (yyyy mm dd)";
	cin >> year1 >> month1 >> day1;

	cout << "Date 2: (yyyy mm dd)";
	cin >> year2 >> month2 >> day2;
	/*
		1 ... 31
		32 = 2^5 = 5bits
		1..12
		16 = 2^4 = 4 bits
	*/
	int date = (year1 << 9) | (month1 << 5) | day1;

	long date1 = year1 * 10000 + month1 * 100 + day1;
	long date2 = year2 * 10000 + month2 * 100 + day2;
	
	if (date1 < date2) {
		cout << "Date 1 < Date 2";
	} else if (date1 > date2) {
		cout << "Date 1 > Date 2";
	} else {
		cout << "Date 1 = Date 2";
	}

	int result = 0;
	if (year1 < year2) {
		result = -1;
	} else if (year2 > year1) {
		result = 1;
	} else if (month1 < month2) {
		result = -1;
	} else if (month2 > month1) {
		result = 1;
	} else if (day1 < day2) {
		result = -1;
	} else if (day2 > day1) {
		result = 1;
	} else { // day1 == day2
		result = 0;
	}

	if (result < 0) {
		cout << "Date 1 < Date 2";
	} else if (result > 0) {
		cout << "Date 1 > Date 2";
	} else {
		cout << "Date 1 = Date 2";
	}


	// out
	cout << "Date 1 < Date 2";
	cout << "Date 1 > Date 2";
	cout << "Date 1 = Date 2";

	return 0;
}