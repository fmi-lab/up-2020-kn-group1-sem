#include<iostream>

using namespace std;

int * sumViaReturn(int * a, int * b, int n, int m) {
	// a[i][j] ===> *(a + i * m + j)
	int * c = new int[n * m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(c + i * m + j) = *(a + i * m + j) + *(b + i * m + j);
		}
	}
	return c;
}


void sumViaOutParameter(int * a, int * b, int * c, int n, int m) {
	// a[i][j] ===> *(a + i * m + j)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(c + i * m + j) = *(a + i * m + j) + *(b + i * m + j);
		}
	}
}

void print(int * a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(a + i * m + j) << " ";
		}
		cout << endl;
	}
}


int main() {
	int a[2][2] = { 1, 2, 3, 4};
	int b[2][2] = { 10, 20, 30, 40};
	
	// option 1
	int * c = new int[2 * 2];
	sumViaOutParameter(&a[0][0], &b[0][0], c, 2, 2);
	print(c, 2, 2);
	delete[] c;

	// option 2
	int * d = sumViaReturn(&a[0][0], &b[0][0], 2, 2);
	int * e = d;
	print(d, 2, 2); // memory leak
	delete[] d;
	
	// smart pointers


	// delete vs delete[]
	// 	* delete is faster
	// 	* delete[] is safer and MUST be used with objects

	int ** cc = new int*[2];
	cc[0] = new int[2];
	cc[1] = new int[2];
	
	delete[] cc[0];
	delete[] cc[1];
	delete[] cc;


	return 0;
}