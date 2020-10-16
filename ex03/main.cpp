#include <iostream>

using namespace std;

int main() {
	int x = 501231231;
	float y = 5.1234123;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	cout << "x / 2: " << x / 2 << endl;
	cout << "y / 2: " << y / 2 << endl;

	cout << "x / 3: " << x / 3 << endl;
	cout << "y / 3: " << y / 3 << endl;

	// cast - смяна на типа
	long lx = x; // implicit cast
	double ly = y; // implicit cast
	lx = lx + 10000000000;
	ly = lx + 10000000000;

	cout << "lx: " << lx << endl;
	cout << "ly: " << ly << endl;


	int smallX = lx;
	float smallY = ly;
	cout << "smallX: " << smallX << endl;
	cout << "smallY: " << smallY << endl;

	// explicit 
	int a = (int) y; // float y;
	float b = (float) x;
	cout << "a: " << a << " / " << y << endl;
	cout << "b: " << b << " / " << x << endl;


	// trying [using pointers]
	// след няколко упражнения :) 
	int xx = 5;
	float yy = 5.5;

	int * xp = (int*)&yy;
	float * yp = (float*)&xx;

	cout << "xp: " << (*xp) << " / " << yy << endl;
	cout << "yp: " << (*yp) << " / " << xx << endl;

	// multiline editing
	// Text Editor
	// IDE

	int i;
	cout << "i: ";
	cin >> i; 

	cout << "i^2: " << (i * i) << endl;

	return 0;
}
