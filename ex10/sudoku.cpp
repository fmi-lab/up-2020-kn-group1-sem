#include <iostream>

using namespace std;

/* 9 x 9   [ 1..9 ]                                  [ 1..9 ]

(0,0) - (2,2)         (0,3) - (2,5)        (0,6) - (2,8)
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  | [1 .. 9]
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+

(3,0) - (5,2)         (3,3) - (5,5)        (3,6) - (5,8)
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+

(6,0) - (8,2)         (6,3) - (8,5)        (6,6) - (8,8)
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
|  1  |  2  |  3  |     4  |  5  |  6  |     7  |  8  |  9  |
+-----+-----+-----+   -----+-----+-----+   -----+-----+-----+
*/
// DRY - Don't Repeat Yourself
bool isComponentValid(int board[9][9], int componentPositions[9][2], int errorPosition[2]) {
	int occurrences[9] = {0};

	for (int i = 0; i < 9; i++) {
		int x = componentPositions[i][0];
		int y = componentPositions[i][1];
		int number = board[x][y];
		
		if (number == 0) {
			continue;
		}
		
		occurrences[number - 1]++;
		if (occurrences[number - 1] > 1) {
			errorPosition[0] = componentPositions[i][0];
			errorPosition[1] = componentPositions[i][1];
			return false;
		}
	}
	return true;
}


bool isRowValid(int board[9][9], int row, int errorPosition[2]) {
	int positions[9][2];
	for (int i = 0; i < 9; i++) {
		positions[i][0] = row;
		positions[i][1] = i;
	}
	return isComponentValid(board, positions, errorPosition);
}

bool isColumnValid(int board[9][9], int column, int errorPosition[2]) {
	int positions[9][2];
	for (int i = 0; i < 9; i++) {
		positions[i][0] = i;
		positions[i][1] = column;
	}
	return isComponentValid(board, positions, errorPosition);
}

bool isSquareValidGenerated(int board[9][9], int startI, int startJ, int errorPosition[2]) {
	int positions[9][2];
	int k = 0;
	for (int i = startI; i < startI + 3; i++) {
		for (int j = startJ; j < startJ + 3; j++) {
			positions[k][0] = i;
			positions[k][1] = j;
			k++;
		}
	}
	return isComponentValid(board, positions, errorPosition);
}

bool isSquareValid(int board[9][9], int i, int j, int errorPosition[2]) {
	int positions[9][2] = {
		{i,   j}, {i,   j+1}, {i,   j+2},
		{i+1, j}, {i+1, j+1}, {i+1, j+2},
		{i+2, j}, {i+2, j+1}, {i+2, j+2},
	};
	return isComponentValid(board, positions, errorPosition);
}

bool allRowsAreValid(int board[9][9], int errorPosition[2]) {
	for (int i = 0; i < 9; i++) {
		if (!isRowValid(board, i, errorPosition)) {
			return false;
		}
	}
	return true;
}

bool allColumnsAreValid(int board[9][9], int errorPosition[2]) {
	for (int i = 0; i < 9; i++) {
		if (!isColumnValid(board, i, errorPosition)) {
			return false;
		}
	}
	return true;
}

bool allSquaresAreValid(int board[9][9], int errorPosition[2]) {
	for (int startI = 0; startI < 9; startI += 3) {
		for (int startJ = 0; startJ < 9; startJ += 3) {
			if (!isSquareValid(board, startI, startJ, errorPosition)) {
				return false;
			}

		}
	}
	return true;
}

const int ERROR_IN_ROW = 0;
const int ERROR_IN_COLUMN = 1;
const int ERROR_IN_SQUARE = 2;

bool isValidSolution(int board[9][9], int error[3]) {
	int errorPosition[2];

	if (!allRowsAreValid(board, errorPosition)) {
		error[0] = ERROR_IN_ROW;
		error[1] = errorPosition[0];
		error[2] = errorPosition[1];
		return false;
	}

	if (!allColumnsAreValid(board, errorPosition)) {
		error[0] = ERROR_IN_COLUMN;
		error[1] = errorPosition[0];
		error[2] = errorPosition[1];
		return false;
	}

	if (!allSquaresAreValid(board, errorPosition)) {
		error[0] = ERROR_IN_SQUARE;
		error[1] = errorPosition[0];
		error[2] = errorPosition[1];
		return false;
	}

	return true;
}

void test_invalidBoard() {
	int board[9][9] = {
		{1,2,3, 4,5,6, 7,8,9},
		{9,1,2, 3,4,5, 6,7,8},
		{8,9,1, 2,3,4, 5,6,7},

		{7,8,9, 1,2,3, 4,5,6},
		{6,7,8, 9,1,2, 3,4,5},
		{5,6,7, 8,9,1, 2,3,4},

		{4,5,6, 7,8,9, 1,2,3},
		{3,4,5, 6,7,8, 9,1,2},
		{2,3,4, 5,6,7, 8,9,1}
	};

	int error[3];
	if (isValidSolution(board, error)) {
		cout << "The board is valid" << endl;
	} else {
		cout << "The was problem with the board! " << endl;
		switch (error[0]) {
			case ERROR_IN_ROW: cout << "Duplicate in row."; break;
			case ERROR_IN_COLUMN: cout << "Duplicate in column."; break;
			case ERROR_IN_SQUARE: cout << "Duplicate in square."; break;
			default: cout << "Unknown error " << error[0] << ".";
		}
		cout << " Position: (" << error[1] << "," << error[2] << ")" << endl;
	}
}

void test_validBoard() {
	int board[9][9] = {
		{5,3,4, 6,7,8, 9,1,2},
		{6,7,2, 1,9,5, 3,4,8},
		{1,9,8, 3,4,2, 5,6,7},

		{8,5,9, 7,6,1, 4,2,3},
		{4,2,6, 8,5,3, 7,9,1},
		{7,1,3, 9,2,4, 8,5,6},

		{9,6,1, 5,3,7, 2,8,4},
		{2,8,7, 4,1,9, 6,3,5},
		{3,4,5, 2,8,6, 1,7,9}
	};

	int error[3];
	cout << "Is valid: " << (true == isValidSolution(board, error)) << endl;
}

void print(int board[9][9]) {
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) {
			cout << endl;
		}
		for (int j = 0; j < 9; j++) {
			if (j % 3 == 0) {
				cout << " ";
			}
			cout << board[i][j];
		}
		cout << endl;
	}
}

/*
	Brute Force == try all combinations

	BackTracking
*/
bool solve(int board[9][9], int i, int j) {
	if (i == 9) {
		int error[3];
		return isValidSolution(board, error);
	}

	if (board[i][j] != 0) {
		return solve(board, i + (j + 1) / 9, (j + 1) % 9);
	}

	int error[3];
	for (int k = 1; k <= 9; k++) {
		board[i][j] = k;
		if (isValidSolution(board, error)) {
			if (solve(board, i + (j + 1) / 9, (j + 1) % 9)) {
				return true;
			}	
		}
	}
	board[i][j] = 0;
	return false;
}

void solve(int board[9][9]) {
	solve(board, 0, 0);
}


void test_solve() {
	int board[9][9] = {
		{5,3,4, 6,7,8, 9,1,2},
		{6,7,2, 1,9,5, 3,4,8},
		{1,9,8, 3,4,2, 5,6,7},

		{8,5,9, 7,6,1, 4,2,3},
		{4,2,6, 8,5,3, 7,9,1},
		{7,1,3, 9,2,4, 8,5,6},

		{9,6,1, 5,3,7, 2,8,4},
		{2,8,7, 4,1,9, 6,3,5},
		{0,0,0, 0,8,0, 0,7,9}
	};

	/*
		{5,3,0, 0,7,0, 0,0,0},
		{6,0,0, 1,9,5, 0,0,0},
		{0,9,8, 0,0,0, 0,6,0},

		{8,0,0, 0,6,0, 0,0,3},
		{4,0,0, 8,0,3, 0,0,1},
		{7,0,0, 0,2,0, 0,0,6},

		{0,6,0, 0,0,0, 2,8,0},
		{0,0,0, 4,1,9, 0,0,5},
		{0,0,0, 0,8,0, 0,7,9}
	*/

	solve(board);
	print(board);
}

/*
	return row, column or square which has wrong numbers
	option 1: error code
		bool -> int
		// 0 == valid (!isRowInvalid())
		// 1..9 == error on row ... 
		1   100  -> error by row
		101 200 -> error by column
		201 300 -> error by square

	option 2: out parameters for the error
		allRowsAreValid(int board[9][9])
		-> allRowsAreValid(int board[9][9], int errorPosition[2])

		bool isValidSolution(int board[9][9])
		-> bool isValidSolution(int board[9][9], int errorPosition[3]
			{
				0: type of check (0 = row, 1 = column, 2 = square)
				1: row
				2: column
			}

*/


int main() {
	test_solve();
	return 0;
}













