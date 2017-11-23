#include <iostream>
#include <string>

using namespace std;


double inValue(string msg)
{
	system("CLS");
	double inValue;

	cout << "Enter the value for " << msg << ": ";

	cin >> inValue;
	
	return inValue;

}

string cutZeros(string a)
{
	a = a.erase(a.find_last_not_of('0') + 1, string::npos);

	if (*a.rbegin() == '.')
		a.erase(1, string::npos);

	return a;
}

string returnMessage(double velocity, double timeSpent, double routeLength)
{
	double remainingPath = routeLength - velocity * timeSpent;

	if (remainingPath == 0)
		return "Route has been completed. Cyclist has just crossed the line!";
	else if (remainingPath > 0)
		return "Cyclist hasn't finished the route yet, he has " + cutZeros(to_string(remainingPath)) + "m left.";
	else
		return "Cyclist has completed the route and he's been cycling even after the finish, " + cutZeros(to_string(-remainingPath)) + "m so far.";

}

int main()
{
	cout << "Cyclist is going on a route, enter his velocity, time spent and route length." << endl << endl;
	system("pause");

	double velocity, timeSpent, routeLength;

	velocity = inValue("speed");
	timeSpent = inValue("time spent");
	routeLength = inValue("route length");

	cout << "Entered values are: "
		<< "\nVelocity: " << cutZeros(to_string(velocity)) << "m/s"
		<< "\nTime spent: " << cutZeros(to_string(timeSpent)) << "s"
		<< "\nRoute length: " << cutZeros(to_string(routeLength)) << "m" << endl << endl;
		
	system("pause");

	system("CLS");
	string printMsg = returnMessage(velocity, timeSpent, routeLength);

	cout << printMsg << endl << endl;

	system("pause");


	return 0;
}