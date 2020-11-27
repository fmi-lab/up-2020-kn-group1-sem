#include <iostream>

using namespace std;
/*
+-----+-----+-----+-----+
|  0  |  1  |  2  |  3  |
+-----+-----+-----+-----+
|  4  |  x  |  6  |  7  |  x ?== 0 + 1 + 2 + 4 + 6 + 8 + 9 + 10 | 40
+-----+-----+-----+-----+  y ?== 9 + 10 + 11 + 13 + 15 | 58
|  8  |  9  | 10  | 11  |  z ?== 8 + 9 + 13 | 30
+-----+-----+-----+-----+
| z   | 13  |  y  | 15  |
+-----+-----+-----+-----+
*/
int sumOfNeighbours(int a[4][4], int i, int j) {
	int sum = 0;
	for (int deltaI = -1; deltaI <= 1; deltaI++) {
		if (!(0 <= i + deltaI && i + deltaI < 4)) {
			continue;
		}

		for (int deltaJ = -1; deltaJ <= 1; deltaJ++) {
			if (!(0 <= j + deltaJ && j + deltaJ < 4)) {
				continue;
			}

			sum += a[i + deltaI][j + deltaJ];
		}
	}
	return sum - a[i][j];
}


bool findElementEqualToSumOfNeighbours(int a[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == sumOfNeighbours(a, i, j)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int a[4][4] = {
		{0,  1,  2,  3},
		{4,  5,  6,  7},
		{8,  9, 10, 11},
		{12,13, 14, 15}
	};

	cout << findElementEqualToSumOfNeighbours(a) << endl;

	return 0;
}