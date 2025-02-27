#include <iostream>
using namespace std;

#define DEPORTURES_LEN 3

/* STRUCTURES DECLARATIONS */
struct Date {
	int day;
	int month;
	int year;
};

struct Time {
	int hours;
	int minutes;
};

struct AEROFLOT {
	string destination;
	Date dateDeporture;
	Time timeDeporture;
};
/* STRUCTURES DECLARATIONS END*/


/* FUNCTIONS DECLARATIONS */
void printDeportureDateTimes(Date date, Time time) {
	cout << "date: " << date.day << "." << date.month << "." << date.year << endl;
	cout << "time: " << time.hours << ":" << time.minutes << endl << endl;
}

void printLine(int length = 10) {
	cout << endl;
	for (int i = 0; i < length; i++) cout << i;
	cout << endl;
}

void printDeporturesByName(AEROFLOT deportures[], string dest_name) {
	bool findedMoreZero = false;

	for (int i = 0; i < DEPORTURES_LEN; i++)
	{
		if (deportures[i].destination == dest_name) {
			if (!findedMoreZero) {
				findedMoreZero = true;
				cout << endl << "*** " << "FOUNDED DEPORTURES BY QUERY '" << dest_name << "' ***: " << endl << endl;
			} 

			printDeportureDateTimes(deportures[i].dateDeporture, deportures[i].timeDeporture);
		}
	}

	if (!findedMoreZero) cout << "BY QUERY '" << dest_name << "' NOTHING WAS FOUND.";
}

AEROFLOT enterDeporture() {
	AEROFLOT deportureResult;

	cout << "Enter name: "; cin >> deportureResult.destination;
	cout << "Enter day"; cin >> deportureResult.dateDeporture.day;
	cout << "Enter month (number) "; cin >> deportureResult.dateDeporture.month;
	cout << "Enter (year) "; cin >> deportureResult.dateDeporture.year;
	cout << "Enter hours "; cin >> deportureResult.timeDeporture.hours;
	cout << "Enter minutes (number) "; cin >> deportureResult.timeDeporture.minutes; cout << endl;

	return deportureResult;
}
/* FUNCTIONS DECLARATIONS END */


int main() {

	cout << "**** WELCOME DEPORTURES MANAGER BY TIKHOMIROV ****" << endl << endl;
	cout << "YOU SHOULD TO FILL DATA FOR " << DEPORTURES_LEN << " DEPORTURES" << endl << endl;
	AEROFLOT deportures[DEPORTURES_LEN];

	for (int i = 0; i < DEPORTURES_LEN; i++)
	{
		cout << "ENTER DATA FOR" << i + 1 << " DEPORTURE:" << endl << endl;
		
		deportures[i] = enterDeporture();
	}

	string queryName;
	cout << "SEARCHING MODE. PLEASE ENTER DESTINATION NAME: "; cin >> queryName;

	printDeporturesByName(deportures, queryName);

	return 0;
}
