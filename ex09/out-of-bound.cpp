#include <iostream>

using namespace std;

void printOutOfBound(int a[]) {
	cout << a[5] << endl;
}

int main() {
	int a[5] = {0, 1, 2, 3, 4 };
	printOutOfBound(a);

	return 0;
}