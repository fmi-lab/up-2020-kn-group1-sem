#include <iostream>


using namespace std;


/*
We want to build a railway with a length of n kilometers.

Rails of 1, 2 and 3 km are available to build the railway.

You need to write a function, that given n, return the number of dictinct possible combinations to build this project.

We will consider that two rails of the same length are equivalent: this means that solutions a-b-c (1-1-3) et b-a-c (1-1-3) count as one solution;
i.e. in this example, the arail and the b rail are both 1km rails, they are "interchangeable".

In this other example: a-d-c (1-2-3) and a-c-d (1-3-2) count as 2 solutions.

Examples: 
For n = 4, the possible solutions being :
	=.=.=.=   (1-1-1-1)
	=.==.=    (1-2-1)
	=.=.==    (1-1-2)
	==.=.=    (2-1-1)
	==.==     (2-2)
	===.=     (3-1)
	=.===     (1-3)
The function should return 7.

For n = 5, the possible solutions being :
	=.=.=.=.=
	=.=.==.=
	=.=.=.==
	=.==.=.=
	=.==.==
	=.===.=
	=.=.===
	==.=.=.=
	==.=.==
	==.==.=
	==.===
	===.=.=
	===.==
The function should return 13.
*/

/*
	Solution
	n -> = . f(n-1)
	     == . f(n-2)
	     === . f(n-3)
*/
int railsCombinations(int lenght) {
	if (lenght == 0) {
		return 0;
	}
	if (lenght == 1) {
		return 1; // =
	}
	if (lenght == 2) {
		return 2; // == ; =.=
	}
	if (lenght == 3) {
		return 4; // === ; ==.=; =.==; =.=.=
	}

	return railsCombinations(lenght - 1)
	     + railsCombinations(lenght - 2)
	     + railsCombinations(lenght - 3);
}
/*
	railsCombinations(5) -> railsCombinations(4) -> railsCombinations(3)
												 -> railsCombinations(2)
												 -> railsCombinations(1)
						 -> railsCombinations(3) -> const
						 -> railsCombinations(2) -> const

	railsCombinations(6) -> railsCombinations(5) -> railsCombinations(4) -> railsCombinations(3)
												 						 -> railsCombinations(2)
												 						 -> railsCombinations(1)
						                         -> railsCombinations(3) -> const
						                         -> railsCombinations(2) -> const

						 -> railsCombinations(4) -> railsCombinations(3)
												 -> railsCombinations(2)
												 -> railsCombinations(1)
						 -> railsCombinations(3) -> const
*/

// Dynamic Programming
int railsCombinationsDynamic(int lenght, int n_1, int n_2, int n_3) {
	if (lenght == 0) {
		return n_1;
	}
	return railsCombinationsDynamic(lenght - 1, n_1 + n_2 + n_3,
												n_1,
										 		n_2);
}

int railsCombinationsDynamic(int lenght) {
	if (lenght == 0) {
		return 0;
	}
	if (lenght == 1) {
		return 1; // =
	}
	if (lenght == 2) {
		return 2; // == ; =.=
	}
	if (lenght == 3) {
		return 4; // === ; ==.=; =.==; =.=.=
	}
	return railsCombinationsDynamic(lenght - 3, 4, 2, 1);
}



void assertEqual(int expected, int actual) {
	if (expected == actual) {
		cout << "OK" << endl;
	} else {
		cout << "ERROR (expected: " << expected << ") (actual: " << actual << ")" << endl;
	}
}

int main() {
	assertEqual(1, railsCombinations(1));
	assertEqual(2, railsCombinations(2));
	assertEqual(4, railsCombinations(3));
	assertEqual(7, railsCombinations(4));
	assertEqual(13, railsCombinations(5));

	assertEqual(1, railsCombinationsDynamic(1));
	assertEqual(2, railsCombinationsDynamic(2));
	assertEqual(4, railsCombinationsDynamic(3));
	assertEqual(7, railsCombinationsDynamic(4));
	assertEqual(13, railsCombinationsDynamic(5));
	assertEqual(24, railsCombinationsDynamic(6));

	return 0;
}