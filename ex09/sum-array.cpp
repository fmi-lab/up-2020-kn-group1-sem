#include <iostream>

using namespace std;

double sum(double a[5][5]) {
	double currentSum = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			currentSum += a[i][j];
		}
	}
	return currentSum;
}

void test_sum() {
	double a[5][5] = {
		{1.1, 1.2, 1.3, 1.4, 1.5},
		{2.1, 2.2, 2.3, 2.4, 2.5},
		{3.1, 3.2, 3.3, 3.4, 3.5},
		{4.1, 4.2, 4.3, 4.4, 4.5},
		{5.1, 5.2, 5.3, 5.4, 5.5}
	};

	cout << "Sum is " << sum(a) << endl;
}

void print(double a[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void print(double a[4][2]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void sum(double a[4][4], double b[4][4], double result[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result[i][j] = a[i][j] + b[i][j];
		}
	}
}

void test_sum_matrix() {
		double a[4][4] = {
		{1.1, 1.2, 1.3, 1.4},
		{2.1, 2.2, 2.3, 2.4},
		{3.1, 3.2, 3.3, 3.4},
		{4.1, 4.2, 4.3, 4.4}
	};

	double b[4][4] = {
		{10.01, 10.02, 10.03, 10.04},
		{20.01, 20.02, 20.03, 20.04},
		{30.01, 30.02, 30.03, 30.04},
		{40.01, 40.02, 40.03, 40.04}
	};

	double result[4][4];
	sum(a, b, result);
	print(result);
}


void product(double a[4][3], double b[3][2], double result[4][2]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			double sum = 0;
			for (int k = 0; k < 3; k++) {
				sum += a[i][k] * b[k][j];
			}
			result[i][j] = sum;
		}
	}
}


int main() {
	double a[4][3] = {
		{1.1, 1.2, 1.3},
		{2.1, 2.2, 2.3},
		{3.1, 3.2, 3.3},
		{4.1, 4.2, 4.3}
	};

	double b[3][2] = {
		{10, 100},
		{20, 200},
		{30, 300}
	};

	double result[4][2];
	// [(1.1, 1.2, 1.3) * (10, 20, 30)] [(1.1, 1.2, 1.3) * (100, 200, 300)] 
	// [(2.1, 2.2, 2.3) * (10, 20, 30)] [(2.1, 2.2, 2.3) * (100, 200, 300)] 
	// [(3.1, 3.2, 3.3) * (10, 20, 30)] [(3.1, 3.2, 3.3) * (100, 200, 300)] 
	// [(4.1, 4.2, 4.3) * (10, 20, 30)] [(4.1, 4.2, 4.3) * (100, 200, 300)]
	product(a, b, result);
	print(result);
	
	return 0;
}
