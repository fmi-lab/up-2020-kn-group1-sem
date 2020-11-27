#include <iostream>

using namespace std;

/* 9 x 9   [ 1..9 ]                                  [ 1..9 ]
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  | [1 .. 9]
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+

|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+

|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
*/

bool isRowValid(int board[9][9], int row) {
	int occurrences[9] = {0};
	for (int i = 0; i < 9; i++) {
		int number = board[row][i];
		occurrences[number - 1]++;
		if (occurrences[number - 1] > 1) {
			return false;
		}
	}
	return true;
}

bool allRowsAreValid(int board[9][9]) {
	for (int i = 0; i < 9; i++) {
		if (!isRowValid(board, i)) {
			return false;
		}
	}
	return true;
}

bool isValidSolution(int board[9][9]) {
	return allRowsAreValid(board) 
	    && allColumnsAreValid(board) 
	    && allSquaresAreValid(board);
}


int main() {
	int board[9][9] = {0};
	cout << isValidSolution(board) << endl;
	

	return 0;
}