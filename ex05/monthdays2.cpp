#include <iostream>

using namespace std;

int main() {
	// input
	int month;
	int year;
	cout << "month, year: ";
	cin >> month >> year;


	// DRY = Don't Repeat Yourself

	// Refactoring:
	// code -->>> transform it -->>> different code with same functionality
	// google: Refactoring Techniques

	// magic

	bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

	int numberOfDaysInMonth = 31;
	if(month == 2)
	{
		numberOfDaysInMonth = isLeapYear ? 29 : 28;
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11)
	{
		numberOfDaysInMonth = 30;
	}

	// output
	cout << "Брой дни в месеца: " << numberOfDaysInMonth << endl;

	return 0;
}