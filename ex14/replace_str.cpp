#include <iostream>
#include <cstring>

using namespace std;


// only when strlen(replaceWith) > strlen(replaceWhat);
// 2. the new size of result
// 		* памет за най-лошият случай? - всеки символ да го заменим - {strlen(replaceWith) * [1 + strlen(originalText) / strlen(replaceWhat)] + 1}
// 				+ Имаме формула да го сметнем
// 				- Потенциално ще използваме повече памет от нужната ни
// 		* динамично разширяване на низа - запълваме начално отделената памети и след това копираме в по-голяма памет ако имаме нужда
// 				+ Ще заемем по-малко памет от най-лошият случай
//				- Ще отделяме памет няколко пъти и ще имаме няколко копирания на текст
//      * преди да направя замяната, да преброя колко пъти се среща replaceWhat
//				+ Ще имаме точното количество памет, която ни трябва
//				- допълнителени стъпки strlen(originalText) * strlen(replaceWhat)
// ---> * най-лошият случай, и след това да прекопираме паметта в новоотделена памет, която има точният размер.
//				+ Ще имаме точното количество памет, която ни трябва
//				- ще отделяме памет 2 пъти и ще имаме едно копиране на текст
int estimatedNewStringSize(int originalTextLenght, int replaceWhatLenght, int replaceWithLenght) {
	if (replaceWhatLenght < replaceWithLenght) {
		// worst case new string length
		return (originalTextLenght / replaceWhatLenght + 1) * replaceWithLenght + 1;
	}

	return originalTextLenght + 1;
}

bool startsWith(const char * text, const char * textToFind) {
	for (int i = 0; textToFind[i] != '\0'; i++) {
		if (text[i] != textToFind[i]) {
			return false;
		}
	}
	return true;
}

// can be a char*
int find(const char * text, const char * textToFind, int startingPosition = 0) {
	int textLength = strlen(text);
	int textToFindLength = strlen(textToFind);
	int lastPossiblePosition = textLength - textToFindLength + 1;

	for (int i = startingPosition; i < lastPossiblePosition; i++) {
		if (startsWith(text + i, textToFind)) {
			return i;
		}
	}
	return -1;
}

void appendToText(char * result, int & k, const char * fromText, int fromPosition, int toPosition) {
	for (int i = fromPosition; i < toPosition; i++) {
		result[k++] = fromText[i];
	}
}


// 1. approach
//		- iterate char by char the originalText, and if the first letter of replaceWhat matches, try to do match & replace
// 		- write function find - index of the first replace what
//		- scan the array for all occurences of the first letter of replaceWhat
char * replaceStr(const char * originalText, 
				  const char * replaceWhat, 
				  const char * replaceWith) {
	int originalTextLenght = strlen(originalText);
	int replaceWhatLenght = strlen(replaceWhat);
	int replaceWithLenght = strlen(replaceWith);
	
	int newStringSize = estimatedNewStringSize(originalTextLenght, replaceWhatLenght, replaceWithLenght);
	char * result = new char[newStringSize];

	int k = 0;
	int i = 0;
	while (true) {
		int foundAtIndex = find(originalText, replaceWhat, i);
		if (foundAtIndex < 0) {
			appendToText(result, k, originalText, i, originalTextLenght);
			break;
		}

		appendToText(result, k, originalText, i, foundAtIndex);
		appendToText(result, k, replaceWith, 0, replaceWithLenght);
		i = foundAtIndex + replaceWhatLenght;
	}
	result[k] = '\0';
	return result;
}

void printExpectedVsActual(const char * expected, char * actual) {
	cout << expected << endl;
	cout << actual << endl;
	cout << endl;
	cout << endl;
	delete actual;
}

int main() {
	printExpectedVsActual("xxxbxxxnitsa   | ", replaceStr("alabalanitsa", "ala", "xxx"));
	printExpectedVsActual("XbXnitsa       | ", replaceStr("alabalanitsa", "ala", "X"));
	printExpectedVsActual("----b----nitsa | ", replaceStr("alabalanitsa", "ala", "----"));
	printExpectedVsActual("bnitsa         | ", replaceStr("alabalanitsa", "ala", ""));
	printExpectedVsActual("------------   | ", replaceStr("alaalaalaala", "ala", "---"));

	return 0;
}