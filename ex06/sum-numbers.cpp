#include <iostream>

using namespace std;

int main() {
	{
		// 6. Потребител въвежда 10 числа. 
		// Да се намери сумата на тези от тях, които са в интервала [25, 75]
		// 10 20 30 60 80 101 23 2 3 50 == 140
		
		int sum = 0;
		cout << "numbers: ";
		for (int i = 0; i < 10; i++) {
			int x;
			cin >> x;
			if (25 <= x && x < 75) {
				sum += x;
			}
		}

		cout << "sum is " << sum << endl;
	}
	
	{
		// 7. Потребител въвежда числа. 
		// Да се намери сумата на първите 10 от тях, 
		// които са в интервала [25, 75]. 
		// 1 2 4 25 6134 25 23 25 79 25 590 25 988 25 123 50 23 50 50 50 90
		// 6 * 25 + 4 * 50		
		{ 	// with FOR
			int sum = 0;
			cout << "numbers: ";
			for (int i = 0; i < 10; ) {
				int x;
				cin >> x;
				if (25 <= x && x < 75) {
					sum += x;
					i++;
				}
			}

			cout << "sum is " << sum << endl;
		}

		{ 	// with WHILE
			int sum = 0;
			cout << "numbers: ";

			int numbersToRead = 10;
			while (numbersToRead > 0) {
				int x;
				cin >> x;
				if (25 <= x && x < 75) {
					sum += x;
					numbersToRead--;
				}
			}

			cout << "sum is " << sum << endl;
		}
	}
	
	return 0;
}