#include <iostream>
using namespace std;

int main() {
	int year; 
	cout << "Year: ";
	cin >> year;

	bool isLeap = (year % 400 == 0) || 
				  (year % 100 != 0 && year % 4 == 0);
				  
	if (isLeap) {
		cout << "The year is leap" << endl;
	} else {
		cout << "The year is NOT leap" << endl;
	}

	return 0;
}