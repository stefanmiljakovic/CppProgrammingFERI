#include <iostream>
#include <string>

using namespace std;

const int numDays = 5;

void printLine(int iMin, int iMax, int i)
{
	string sNote = "";

	if (iMin > 12 && iMax < 35)
	{
		sNote = "no note";
	}
	
	if (iMin < 12)
	{
		sNote += "\n# (Minimum temeperature was lower than 12 degrees)";
	}

	if (iMin > 35)
	{
		sNote += "\n? (Max temperature was higher than 35 degrees)";
	}

	cout << "Minimum temperature for " << abs(i - 5) << " days before today was " << iMin << " and maximum was " << iMax << ".\nNotes: " << sNote << endl << endl;
}

int main()
{
	int iTempMin[numDays] = { 7, 10, 6, 11, 4};
	int iTempMax[numDays] = { 18, 22, 14, 17, 17 };

	for (int i = 0; i < numDays; i++)
	{
		printLine(iTempMin[i], iTempMax[i], i);
	}


	system("pause");

    return 0;
}

