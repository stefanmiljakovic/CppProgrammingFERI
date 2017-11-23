#include <iostream>
#include <string>

using namespace std;
short unsigned int iConstPathSize = 100;
short unsigned int iMaxArraySize = 5;


void clearCLS() {
	system("CLS");
}

void pause() {
	system("pause");
}

void endLine() {
	cout << endl << endl;
}

void inputError() {
	clearCLS();
	cout << "You have entered a wrong value!" << endl;
	pause();

	clearCLS();

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string sMakePath(short unsigned int iCompPct) {
	string sReturn = "";

	for (int i = 0; i < iConstPathSize; i++)
	{
		if (i < iCompPct)
			sReturn.append("*");
		else
			sReturn.append(".");
	}

	return sReturn;
}

string sMakeHeader(int iCompID, int iCompPct) {

	return "Competitor " + std::to_string(iCompID) + " (" + std::to_string(iCompPct) + "%)";

}

void drawPath(int iCompID, int iCompPct, int iPathRows) {

	string sPath = sMakePath(iCompPct);

	cout << sMakeHeader(iCompID, iCompPct) << endl;

	for (int i = 0; i < iPathRows; i++)
		cout << sPath << endl;
	cout << endl;
}

int calculatePct(int iCompSpeed, int iSharedTime, int iSharedDistance) {

	double pct;

	pct = 100 * iCompSpeed * iSharedTime / iSharedDistance;

	if (pct > 100)
		pct = 100;

	return round(pct);

}

int inputInt(string sMsg, int iMin, int iMax) {

	int iReturn;

	cout << sMsg << ": ";
	cin >> iReturn;

	if (cin.fail()) {
		inputError();
	}

	if (iReturn >= iMin && iReturn <= iMax)
		return iReturn;
	else {
		inputError();
	}

	return inputInt(sMsg, iMin, iMax);
}

int main()
{
	int iPathRows = inputInt("Enter number of rows (max 10)", 1, 10);
	clearCLS();
	int iNumCompetitors = inputInt("Enter number of competitors (max 5)", 1, iMaxArraySize);
	clearCLS();
	int iSharedTime = inputInt("Enter the duration of race (max 300s)", 1, 300);
	clearCLS();
	int iSharedDistance = inputInt("Enter the length of the route (max 9000m)", 1, 9000);
	clearCLS();

	cout << "Selected number of rows " << iPathRows << endl
		<< "Selected number of competitors " << iNumCompetitors << endl
		<< "Selected race duration " << iSharedTime << endl
		<< "Selected track distance " << iSharedDistance << endl << endl;

	pause();
	clearCLS();

	int *iCompPctArray = new int[iMaxArraySize];

	for (int iCompID = 0; iCompID < iNumCompetitors; iCompID++) {
		int iCompSpeed = inputInt("Enter speed of " + std::to_string(iCompID + 1) + ". competitor (max 30m/s)", 1, 30);

		iCompPctArray[iCompID] = calculatePct(iCompSpeed, iSharedTime, iSharedDistance);
	}

	endLine();

	for (int iCompID = 1; iCompID <= iNumCompetitors; iCompID++) {
		drawPath(iCompID, iCompPctArray[iCompID - 1], iPathRows);
	}

	endLine();

	pause();
	return 0;
}

