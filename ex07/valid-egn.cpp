#include <iostream>

using namespace std;

bool isLeapYear(long year) {
	return (year % 400 == 0)
	    || (year % 100 != 0 && year % 4 == 0);
}

int maxDaysInMonth(long month, long year) {
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: return 31;
		case 2: return 28 + isLeapYear(year);
		default: return 30;
	}
}


/*
	35 01 11 9256 / 10000 -> 350111 % 100 -> 11	
	35 01 11 9256 / 1000000 -> 3501 % 100 -> 01
	35 01 11 9256 / 100000000 -> 35
*/
long extractRawDay(long egn) {
	return (egn / 10000) % 100;
}

long extractRawMonth(long egn) {
	return (egn / 1000000) % 100;
}

long extractRawYear(long egn) {
	return (egn / 100000000);
}



// proxy
long extractDay(long egn) {
	return extractRawDay(egn);
}

long extractMonth(long egn) {
	long month = extractRawMonth(egn);

	if (month <= 12) {
		return month;
	}

	if (month <= 32) {
		return month - 20;
	}

	return month - 40;
}

long extractYear(long egn) {
	long month = extractRawMonth(egn);
	long year = extractRawYear(egn);

	if (month <= 12) {
		year += 1900;
		
	} else if (month <= 32) {
		year += 1800;
	} else {
		year += 2000;
	}

	return year;
}



bool validLength(long egn) {
	int lenght = ((int)log10(egn)) + 1;
	return lenght == 10;
}

bool validMonth(long egn) {
	long month = extractRawMonth(egn);
	
	return (1 <= month && month <= 12) // 1900-2000
		|| (21 <= month && month <= 32) // 1800-1900
		|| (41 <= month && month <= 52); // 2000-2100
}

bool validDay(long egn) {
	long day = extractDay(egn);
	long month = extractMonth(egn);
	long year = extractYear(egn);

	return 1 <= day && day <= maxDaysInMonth(month, year);
}

bool validChecksum(long egn) {
	return true;
}

bool isValidEGN(long egn) {
	return validLength(egn) 
		&& validMonth(egn) 
		&& validDay(egn) 
		&& validChecksum(egn);
}

int main() {
	cout << "true == " << isValidEGN(3501119256l) << endl; // ok
	cout << "true == " << isValidEGN(5809058594l) << endl; // ok
	cout << "true == " << isValidEGN(8512197012l) << endl; // ok
	cout << "true == " << isValidEGN(9107142141l) << endl; // ok
	cout << "true == " << isValidEGN(1044118570l) << endl; // ok
	cout << "true == " << isValidEGN(5021129212l) << endl; // ok
	cout << "false == " << isValidEGN(3501119l) << endl; // invalud lenght
	cout << "false == " << isValidEGN(58090585901l) << endl; // invalid lenght
	cout << "false == " << isValidEGN(8515197012l) << endl; // invalid month
	cout << "false == " << isValidEGN(9107502141l) << endl; // invalid day
	cout << "false == " << isValidEGN(5809058590l) << endl; // invalid checksum

	return 0;
}
