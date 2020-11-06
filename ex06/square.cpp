#include <iostream>

using namespace std;


/*
ASCII Art

xxxxx
xxxxx
xxxxx
xxxxx
xxxxx


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
	int side; // > 2 

	do {
		cout << "Side: ";
		cin >> side;
	} while (side < 2);

	{	//version 1
		// for now side = 5;
		// off by one error
		int lines = side;
		while (lines != 0) {

			int chars = side;
			while (chars != 0) {
				cout << "x";
				chars--;
			}
			cout << endl;

			lines--;
		}
	}
	cout << endl << endl;

	{	//version 2
		int lines2 = side;
		while (lines2--) {

			int chars = side;
			while (chars--) {
				cout << "x";
			}
			cout << endl;
		}
	}
	cout << endl << endl;

	{	// version 3
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++) {
				cout << "x";
			}
			cout << endl;
		}
	}

	return 0;
}