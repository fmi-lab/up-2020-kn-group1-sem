#include <iostream>


using namespace std;


/*
С помощта само на рекурсия (без използване на цикли или масиви),
да се реализира програма, която проверява дали при 
дадени две числа може да се задраскат цифри от едното или от другото, 
така че да се получат едни и същи числа. 
Не може да задраскваме цифри и от двете числа едновременно.
*/

long crossoutDigit(long source, int position) {
	return source % (long) pow(10, position) +
		   source / (long) pow(10, position + 1) * (long) pow(10, position);
}

int numberLenght(long n) {
	return (int)log10(n) + 1;
}

bool canReduceToSameNormalized(long, long);
bool tryToCrossoutEach(long, long, int);
bool tryToCrossoutEach_v1(long, long, int, int);


/*
	for (int position = 0; position < sourceLength; position++) {
		if (canReduceToSameNormalized(target, crossoutDigit(source, position))) {
			return true;
		}
	}
	return false;
*/
bool tryToCrossoutEach_v1(long target, long source, int position, int sourceLength) {
	if (position >= sourceLength) {
		return false;
	}
	
	if (canReduceToSameNormalized(target, crossoutDigit(source, position))) {
		return true;
	}

	return tryToCrossoutEach_v1(target, source, position + 1, sourceLength);
}

bool tryToCrossoutEach(long target, long source, int position) {
	if (position < 0) {
		return false;
	}
	
	if (canReduceToSameNormalized(target, crossoutDigit(source, position))) {
		return true;
	}

	return tryToCrossoutEach(target, source, position - 1);
}

						 // stays the same, from where we crossout
bool canReduceToSameNormalized(long target, long source) {
	// дъно
	// при успех
	if (target == source) {
		return true;
	}
	
	// при неуспех за изпълнение на работата
	if (target > source) {
		return false;
	}

	// стъпка
	int sourceLength = numberLenght(source);
	return tryToCrossoutEach(target, source, sourceLength - 1);

	// return tryToCrossoutEach_v1(target, source, 0, sourceLength);
}

// not recursive
// proxy function
bool canReduceToSame(long n1, long n2) {
	if (n1 < n2) {
		return canReduceToSameNormalized(n1, n2);
	} else {
		return canReduceToSameNormalized(n2, n1);
	}
}

// Решение от Димитър Ангелов
bool eraseDigits(long long m,long long n) {
    if(m < n) {
    	swap(m,n);
	}

    if(m == n) {
    	return true;
	}

    int lastdigM,lastdigN;
    lastdigM = m % 10;
    lastdigN = n % 10;

    if(lastdigM == lastdigN) {
    	m = m / 10;
    	n = n / 10;
	}
    if(lastdigM != lastdigN) {
    	m = m / 10;
	}

    if(n > m) {
    	return false;
	}

    return eraseDigits(m,n);
}

void assertEqual(bool expected, bool actual) {
	if (expected == actual) {
		cout << "OK" << endl;
	} else {
		cout << "ERROR" << endl;
	}
} 

int main() {
	assertEqual(true, canReduceToSame(1025, 125));
	assertEqual(true, canReduceToSame(125, 1025));
	assertEqual(true, canReduceToSame(125, 1251));
	assertEqual(true, canReduceToSame(125, 9125));
	assertEqual(false, canReduceToSame(125, 2025));

	assertEqual(true, eraseDigits(1025, 125));
	assertEqual(true, eraseDigits(125, 1025));
	assertEqual(true, eraseDigits(125, 1251));
	assertEqual(true, eraseDigits(125, 9125));
	assertEqual(false, eraseDigits(125, 2025));

	return 0;
}

