#include<iostream>

using namespace std;

void test_heap() {
	// 4 bytes * 1024 = 4096 bytes = 4KB -> 4MB;	
	long size = 1024l * 1024l * 1024l * 5l;
	int * x = new int[size]; // 20 GB
	cout << x << endl;
	for (long i = 0; i < size; i++) {
		x[i] = i;
	}
}

void stackOverflow(int x) {
	stackOverflow(x + 1);
}


int main() {
	return 0;
}