#include<iostream>

using namespace std;


// replace(str, oldString, newString)
// 	- replace oldString with newString in str
// 	- use only strcpy, strlen



int main() {
	char mystring[100] = {0};
	const char * str = "Ala\0 bala"; // constant memory?, не мога да променям данните сочени от указателя
	// char * const str2 = "Ala bala"; // указателят е константен, не може да се променя
	// const char * const str3 = "Ala bala"; // указателят е константен, не може да се променя

	cout << str << endl;
	int n = 9; // strlen(str);
	for (int i = 0; i <= n; i++) {
		cout << str[i] << ": " << (int) str[i] << endl;
	}

	return 0;
}