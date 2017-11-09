#include <iostream>
#include <string>

using namespace std;

const int INITIAL_CALL = 0;

const string GLOBAL_OPTION_INTRO = "This program is used for testing and calculating prime numbers, choose one of the following:";
const string GLOBAL_OPTION_INTRO_1 = "1. Test if number A is a prime.";
const string GLOBAL_OPTION_INTRO_2 = "2. Check how many prime numbers from A to B.";
const string GLOBAL_OPTION_INTRO_3 = "3. Find 20 closest primes equal or greater than number A.";

const string CIN_FAIL_LIMIT = "You've entered number outside of bounds.";
const string CIN_FAIL_FORMAT = "You've entered a wrong input format.";

void chooseOption(int id);

// Helper functions
void pauseApp(){
	cout << endl << endl;
	system("pause");
}

void clearLog(){
	system("cls");
}


// Input related functions
void inputError(string msg){

	clearLog();
	cout << msg;
	pauseApp();

	clearLog();

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int inputNum(int min, int max, bool clear){

	if (clear)
	clearLog();

	cout << "Enter a number between " << to_string(min)
		<< " and " << to_string(max) << ": ";

	int input;
	cin >> input;

	if (cin.fail())
		inputError(CIN_FAIL_FORMAT);
	else if (input >= min && input <= max)
		return input;
	else
		inputError(CIN_FAIL_LIMIT);

	return inputNum(min, max, true);
}



// Function 1, check prime
bool isPrime(int iNum){
	
	bool bPrime = true;

	for (int i = 2; i <= sqrt(iNum); i++){
		if (iNum % i == 0){
			bPrime = false;
			break;
		}
	}

	return bPrime;
}

// Function 2, count primes
int countPrimes(int min, int max){
	int num = 0;

	if (min < 2)
		min = 2;

	for (; min <= max; min++){
		if (isPrime(min))
			num++;
	}

	return num;
}


// Function 3, table of closest primest

void makeTable(int num, int * table){

	int i = 0;

	if (num < 2)
		num = 2;

	for (; num <= INT_MAX; num++){
		if (isPrime(num) && i < 20 ){
			* table = num;
			table++; i++;
		}
		if (i == 20)
			break;
	}

}

// User input

void chooseOption_1(){
	clearLog();
	cout << GLOBAL_OPTION_INTRO_1 << endl << endl;

	bool bIsPrime = isPrime(inputNum(2, INT_MAX, false));

	if (bIsPrime)
		cout << endl << endl << "Number A is a prime.";
	else
		cout << endl << endl << "Number A isn't a prime.";

	pauseApp();

	chooseOption(INITIAL_CALL);
}

void chooseOption_2(){
	clearLog();
	cout << GLOBAL_OPTION_INTRO_2 << endl << endl;
	int iMin = inputNum(INT_MIN, INT_MAX, false);
	int iMax = inputNum(iMin, INT_MAX, false);

	int iNumOfPrimes = countPrimes(iMin, iMax);


	cout << endl << endl << "Number of primes from "
		<< to_string(iMin) << " to "
		<< to_string(iMax) << " equals to: "
		<< iNumOfPrimes;

	pauseApp();

	chooseOption(INITIAL_CALL);
}

void chooseOption_3(){
	clearLog();
	cout << GLOBAL_OPTION_INTRO_3 << endl << endl;
	
	// INT_MAX / 2 to avoid null pointer
	int iNum = inputNum(INT_MIN, INT_MAX/2, false);

	int iTable[20];

	makeTable(iNum, iTable);

	for (int i = 0; i < sizeof(iTable)/sizeof(iTable[0]); i++){
		cout << endl << "A[" << to_string(i + 1) << "] = " << to_string(iTable[i]);
	}

	pauseApp();
	chooseOption(INITIAL_CALL);
}

void chooseOption(int id){
	clearLog();

	switch (id){
	case 1: chooseOption_1();
		return;
	case 2: chooseOption_2();
		return;
	case 3: chooseOption_3();
		return;
	default: break;
	}

	cout << GLOBAL_OPTION_INTRO << endl
		<< GLOBAL_OPTION_INTRO_1 << endl
		<< GLOBAL_OPTION_INTRO_2 << endl
		<< GLOBAL_OPTION_INTRO_3 << endl << endl;

	chooseOption(inputNum(1, 3, false));
}


int _tmain(int argc, _TCHAR* argv[])
{
	chooseOption(INITIAL_CALL);


	return 0;
}

