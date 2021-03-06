// Assignment_5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const static int DIV_LOWER_RANGE = 300;
const static int DIV_HIGHER_RANGE = 2000;
const static int DIVISOR = 7;


int leastCommonMultiplier(int a, int b) {

	for (int i = 1;; i++) {
		if ((a*i) % b == 0) 
			return a*i;
	}

	return 0;
}

int firstDivisor() {

	for (int i = DIV_LOWER_RANGE; i <= DIV_HIGHER_RANGE; i++) {
		if (i % DIVISOR == 0)
			return i;
	}

	return 0;
}

int f1(int a, int b) {
	return 2 * leastCommonMultiplier(a, b);

}

int f2() {

	return (DIV_HIGHER_RANGE - firstDivisor()) / DIVISOR + 1; // to prevent for looping; count will increase by integer part, decimal will be ignored;		
																	// add + 1 , cause i % divisor = 0
}

int f3(int arrayA [], int size) {

	int first = firstDivisor();

	for (int i = 0; i < size; i++) {
		arrayA[i] = first + 7 * i;
	}


	return arrayA[size / 2];
}

void f4(int arrayA[], int size) {

	for (int i = 0; i < size; i += 2) {
		cout << arrayA[i] << ", ";
	}

	cout << "\b\b" << "." << endl << endl;
}

void f5(int arrayA[], int size) {

	size--; // make size last index; size - 1

	if (size % 2 == 0) // if last index isn't odd, subtract 1;
		size--;

	for (int i = size; i > 0; i -= 2) {
		cout << arrayA[i] << ", ";
	}

	cout << "\b\b" << "." << endl << endl;

}

int main()
{
	int a, b;

	cout << "Enter number a: ";
	cin >> a;
	cout << "\nEnter number b: ";
	cin >> b;

	int size = f2();

	cout << endl << "Least common multiplier * 2 for number " << a << " and number " << b << " is " << f1(a, b) << endl << endl;
	cout << "Number of digits divisible by " << DIVISOR << " between " << DIV_LOWER_RANGE << " and " <<
		DIV_HIGHER_RANGE << " is: " << size << endl << endl;

	int arrayA[1 + (DIV_HIGHER_RANGE - DIV_LOWER_RANGE) / DIVISOR] = {}; // in theory size shouldn't be higher than this;

	f3(arrayA, size);
	f4(arrayA, size);
	f5(arrayA, size);

	system("pause");
    return 0;
}

