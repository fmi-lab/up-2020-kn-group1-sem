#include <iostream>
using namespace std;

/*
	if (__условие / predicate ___) { // искам ли да влезна в стая X?
		// какво ще направя в тази стая ...
	}

	==, !=, <, >, <=, >=
	&&, ||, !
*/



/*
	Избор на правилен стил на коментарите


	// проверяваме дали месецът е м/у 1 и 12
	// implementation detail
	// bool isMonthValid = (1 <= month && month <= 12);

	vs 
	// дали месецът е валиден
	// bool isMonthValid = (1 <= month && month <= 12);

	// проверяваме дали месецът е м/у 1 и 12
		// по-дискриптивен
		// по-добре 20 сек повече в четене на спек вместо 2 часа в debugging
		// ами ако месецът е м/у 0 и 11
		// ако ако имаме низове с имената на месеците
	// дали месецът е валиден
		// не е ясно какво означава да е валиден един месец
		// по-бързо се чете
		// ясно е, че е м/у 1 и 12

	// X some sort of magic

	// Какво и как? проверяваме дали месецът е м/у 1 и 12
	// Какво? дали месецът е валиден
	// Какво?  <----- second best
	// * Защо? <---- искаме такива коментири	
*/

/*
	// DRY
	// Don't Repeat Yourself

	// Book Recommendation: The Pragmatic Programmer
	// https://www.amazon.com/Pragmatic-Programmer-Journeyman-Master/dp/020161622X
*/

int main() {

	int month; // 1..12
	cout << "What's your birth month: ";
	cin >> month;

	/*
		if (month < 0) {
			cout << "Uhhhh ... yeah" << endl;
		}

		if (month > 11) {
			cout << "Big boy yeah" << endl;
		}

		bool isMonthValid = (0 <= month && month <= 11);
		if (isMonthValid) {
			cout << "OK, OK" << endl;	
		}
	*/

	bool isMonthValid = (1 <= month && month <= 12);
	if (isMonthValid) {
		cout << "OK, OK" << endl;	
	} else if (month < 1) {
		cout << "Hello Little Pinokio" << endl;
	} else {
		cout << "Big Pinokio..." << endl;
	}

	if (isMonthValid) {
		cout << "OK, OK" << endl;	
	} else if (month < 1) {
		cout << "Hello Little Pinokio" << endl;
	} else if (month > 12) {
		cout << "Big Pinokio..." << endl;
	}

	// if (predicate) {
	// 	code
	// }

	// if (predicate) {
	// 	code
	// } else {
	// 	code if predicate is false
	// }

	// if (predicate) {
	// 	code
	// } else if (predicate 2) {
	//	code
	// } else {
	// 	code if predicate is false
	// }

	// if (predicate) {
	// 	code
	// } else if (predicate 2) {
	//	code
	// }
	

	return 0;
}