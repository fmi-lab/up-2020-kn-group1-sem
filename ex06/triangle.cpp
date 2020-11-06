#include <iostream>

using namespace std;


/*
ASCII Art

side = 5
x
xx
xxx
xxxx
xxxxx

    x
   xx
  xxx
 xxxx
xxxxx
*/


int main() {
	int side;

	do {
		cout << "Side: ";
		cin >> side;
	} while (side < 2);

	// for now side = 5;
	// x----
	// xx---
	// xxx--
	// xxxx-
	// xxxxx

	{	// version 1
		int lines = side;
		while (lines != 0) {
			// (lines - 1)        => 4, 3, 2, 1, 0
			// side - (lines - 1) => 1, 2, 3, 4, 5

			int chars = side - (lines - 1);
			while (chars != 0) {
				cout << "x";
				chars--;
			}
			cout << endl;

			lines--;
		}
	}
	cout << endl << endl;

	{	// version 2
		for (int row = 0; row < side; row++) {
			for (int col = 0; col < row + 1; col++) {
				cout << "x";
			}
			cout << endl;
		}
	}
	cout << endl << endl;

	// ----x // position = 5, 4, 3, 2, 1
	// ---xx // position = [5, 4, 3], 2, 1
	// --xxx
	// -xxxx
	// xxxxx
	{
		int lines = side;
		while (lines != 0) {

			int whiteSpaces = lines - 1;
			while (whiteSpaces != 0) {
				cout << " ";
				whiteSpaces--;
			}

			int chars = side - (lines - 1);
			while (chars != 0) {
				cout << "x";
				chars--;
			}
			cout << endl;

			lines--;
		}
	}
	cout << endl;

	{
		int lines = side;
		while (lines != 0) {
			int position = side;
			while (position != 0) {
				if (position > side - (lines - 1)) {
					cout << " ";
				} else {
					cout << "x";
				}
				position--;
			}
			cout << endl;
			lines--;
		}
	}

	return 0;
}