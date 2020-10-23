#include <iostream>
using namespace std;

/*
	Problems
	1. What's my age?
		-> today's date (2nd step)

	2. Is Leap Year?
		- Ако се дели на 400
		- Не е високосна ако се дели на 100
		- Ако се дели на 4

	3. Compare two dates. Which one is earlier?

	4. 

	Talking about time zones:
	https://www.youtube.com/watch?v=-5wpm-gesOY
*/

int main() {
	int yearToday = 2020;
	int monthToday = 10;
	int dayToday = 23;

	int yearOfBirth;
	int monthOfBirth;
	int dayOfBirth;
	// 1 1 2000    = 20
	// 24 11 2000  = 19
	// 25 10 2000  = 19
	// 21 10 2000  = 20
	// 23 10 2000  = 20 + "Horayyyyy"

	cout << "What's your birth date? (day month year): ";
	cin >> dayOfBirth >> monthOfBirth >> yearOfBirth;

	int age = yearToday - yearOfBirth;
	
	if (monthToday < monthOfBirth) {
		age--;
	} else if (monthToday == monthOfBirth) { 

		if (dayToday < dayOfBirth) {
			age--;
		} else if (dayToday == dayOfBirth) {
			cout << "Happy Birthday!" << endl;
		}
	}

	// if (monthToday < monthOfBirth) {
	// 	age--;
	// } else if (monthToday == monthOfBirth && dayToday < dayOfBirth) { 
	// 	age--;
	// } else if (monthToday == monthOfBirth && dayToday == dayOfBirth) { 
	// 	cout << "Happy Birthday!" << endl;
	// }

	cout << "So you're: " << age << endl;

	

	return 0;
}