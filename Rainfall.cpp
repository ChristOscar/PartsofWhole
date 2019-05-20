//contents of main.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//declare array of doubles of 12 values
	double rainFall[12];

	//prompt user to enter rainfall data then
	//read using for loop
	cout << "Please enter rainfall data for 12 Months:\n";
	for (int counter = 0; counter < 12; counter++) {
		cout << "Month " << counter + 1 << ": ";
		cin >> rainFall[counter];
		//validate input using while loop
		while (rainFall[counter] < 0) {
			//print error message then prompt to enter again
			cout << "ERROR! Negative values not accepted ";
			cout << "for rainfall! Enter again!\n";
			cout << "Month " << counter + 1 << ": ";
			cin >> rainFall[counter];
		}
		cout << endl;
	}

	//variables to store total rainfall and
	//average monthly rainfall
	double total = 0.0, average;

	//variables to store indexes of highest
	//and lowest rainfall months
	//and initialize them both to 0
	int lowest = 0, highest = 0;

	//loop on all elements to get necessary data
	for (int counter = 0; counter < 12; counter++) {
		//update lowest index
		if (rainFall[counter] < rainFall[lowest])
			lowest = counter;
		//update highest index
		if (rainFall[counter] > rainFall[highest])
			highest = counter;

		//add current value to accumulator
		//variable total
		total += rainFall[counter];
	}

	//use typecasting to prevent integer division
	average = (double)total / 12;

	//format output
	cout << fixed << setprecision(2);
	cout << "\nThe total yearly rainfall: " << total << endl;
	cout << "The average monthly rainfall: " << average << endl;
	cout << "The lowest rainfall was in month " << lowest + 1;
	cout << " with " << rainFall[lowest] << endl;
	cout << "The highest rainfall was in month " << highest + 1;
	cout << " with " << rainFall[highest] << endl;

	//return 0 to mark successful termination
	return 0;
}