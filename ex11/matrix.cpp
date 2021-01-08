#include <iostream>

using namespace std;

void print(int * a, int n, int m) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(a + i * m + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// a[2][3][4]
// #a[0] = 3 * 4
// a[1][0][0] = 1 * m * k
// a[1][2][0] = 1 * m * k + 2 * k
// a[1][2][3] = 1 * m * k + 2 * k + 3
// a[i][j][p] = i * m * k + j * k + p
void print(int * a, int n, int m, int k) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int p = 0; p < k; p++) {
				cout << *(a + i * m * k + j * k + p) << " ";	
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
	}
	cout << endl;
}

void print(int * a, int n) {
	if (n == 0) {
		cout << endl;
		return;
	}
	cout << a[0] << " ";
	print(a + 1, n - 1);
}

void print(int * a, int * n, int nn) {
	// Homework :)
}

void sum(int * a, int * b, int * result, int n, int m) {
	// a[i][j] === *(a + i * m + j)

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// maybe extract a function?
			// *onIndex(result, i, j, m) = onIndex(a, i, j, m) + *onIndex(b, i, j, m);
			// *(result + i * m + j) = getValue(a, i, j, m) + getValue(b, i, j, m);

			*(result + i * m + j) = *(a + i * m + j) + *(b + i * m + j);
		}
	}
}


// a[n][k] x b[k][m] --> c[n][m]
void product(int * a, int * b, int * c, int n, int k, int m) {
	// a[i][p]  === *(a + i * k + p)
	// b[p][j]  === *(b + p * m + j)
	// c[i][j]  === *(c + i * m + j)

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			int sum = 0;
			for (int p = 0; p < k; p++) {
				// sum += a[i][p] * b[p][j];
				sum += *(a + i * k + p) * *(b + p * m + j);
			}
			*(c + i * m + j) = sum;
		}
	}
}

void test_sum() {
	int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int b[3][3] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
	int c[3][3];

	print(&a[0][0], 3, 3);
	cout << "+" << endl;
	print(&b[0][0], 3, 3);
	cout << "=" << endl;

	sum(&a[0][0], &b[0][0], &c[0][0], 3, 3);
	print(&c[0][0], 3, 3);	
}

void test_product_all_same_size() {
	int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int b[3][3] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
	int c[3][3];

	print(&a[0][0], 3, 3);
	cout << "*" << endl;
	print(&b[0][0], 3, 3);
	cout << "=" << endl;
	
	product(&a[0][0], &b[0][0], &c[0][0], 3, 3, 3);
	print(&c[0][0], 3, 3);
}

void test_product_different_sizes() {
	int a[3][2] = { {1, 2}, {4, 5}, {7, 8}};
	int b[2][4] = { {10, 20, 30, 40},  {50, 60, 70, 80}};
	int c[3][4];
	
	print(&a[0][0], 3, 2);
	cout << "*" << endl;
	print(&b[0][0], 2, 4);
	cout << "=" << endl;
	
	product(&a[0][0], &b[0][0], &c[0][0], 3, 2, 4);
	print(&c[0][0], 3, 4);
}

void test_print_3d() {
	int a[2][3][4] = {
		{
			{10, 20, 30, 40},
			{50, 60, 70, 80},
			{90, 100, 110, 120},
		},
		{
			{-10, -20, -30, -40},
			{-50, -60, -70, -80},
			{-90, -100, -110, -120},
		}
	};
	print(&a[0][0][0], 2, 3, 4);
}





int main() {
	// test_sum();
	// test_product_all_same_size();
	// test_product_different_sizes();
	// test_print_3d();
	int a[5] = {50, 55, 60, 65, 70};
	print(a, 5);

	return 0;
}