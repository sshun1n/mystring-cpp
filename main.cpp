#include <iostream>
#include "String.h"

int main() {
	setlocale(LC_ALL, "RU");

	MyString string = "Привет ";
	MyString temp = "мир!";
	MyString result;

	result = string + temp;
	
	std::cout << result;

	return 0;
}