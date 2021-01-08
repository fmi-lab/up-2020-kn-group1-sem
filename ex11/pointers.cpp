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

int main() {
	int x = 5;
	int * px = &x;
	int & rx = x;
	
	cout << "&x: " << (&x) << endl;
	cout << "px: " << (px) << endl;
	cout << "dereference of px:" << (*px) << endl; // dereference 
	
	(*px) += 10;
	cout << "x: " << x << endl;  

	rx += 10;
	cout << "x: " << x << endl;  

	// pointer arithmentics

	cout << "px    : " << px << endl;
	cout << "px + 1: " << (px + 1) << endl;

	long y = 10;
	long * py = &y;

	cout << "py    : " << py << endl;
	cout << "py + 1: " << (py + 1) << endl;

	int a[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
	cout << "&a[i]" << endl;
	cout << &a[0] << endl;
	cout << &a[1] << endl;
	cout << &a[2] << endl;

	int * pa = a;
	for (int i = 0; i < 10; i++) {
		cout << *(pa + i) << endl;	
	}

	int b[3][3] = {
		{100, 200, 300}, {400, 500, 600}, {700, 800, 900}
  	  // 0,0   0,1  0,2    1,0  1,1  1,2    2,0  2,1  2,2
  	  //   0    1     2      3    4    5      6    7    8
  	  //   					-3              -6
  	  //   					0    1    2      0    1    2
	};

	print(&b[0][0], 3, 3);
	print(b[0], 3, 3);

	int c[10][5];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			c[i][j] = i * i + j;
		}
	}
	print(&c[0][0], 10, 5);

	return 0;
}