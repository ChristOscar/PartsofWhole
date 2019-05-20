//contents of main.cpp

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//function prototypes
void sortArray(double *, string *, int);
double getAverage(double *, int);

int main()
{
	//variable to store user input
	//for number of tests
	int numTests;

	//prompt user to enter input then read
	cout << "Please enter number of test scores ";
	cout << "that will be stored:\n";
	cin >> numTests;

	//dynamically allocate array large enough
	//for scores and student names
	double *testScores = new double[numTests];
	string *studentNames = new string[numTests];

	//read values into array using for loop
	for (int counter = 0; counter < numTests; counter++) {
		cout << "Student " << counter + 1 << " name: ";
		//use pointer notation, don't forget
		//to dereference first
		cin >> *(studentNames + counter);

		cout << "Test score: ";
		cin >> *(testScores + counter);

		//validate input
		while (*(testScores + counter) < 0) {
			//print error message then prompt and read
			cout << "ERROR! Negative values not allowed!";
			cout << " Enter again!\n";
			cin >> *(testScores + counter);
		}
	}

	//sort arrays
	sortArray(testScores, studentNames, numTests);

	//format output
	cout << fixed << setprecision(1);

	//display contents of array along with names
	cout << endl;
	cout << "Sorted test scores are: \n";
	cout << "Name\t\tScore\n";
	for (int counter = 0; counter < numTests; counter++) {
		cout << *(studentNames + counter) << "\t\t";
		cout << *(testScores + counter) << endl;
	}

	//print message for average
	cout << "\n\nAverage of " << numTests << " tests is: ";
	cout << getAverage(testScores, numTests);

	//return 0 to mark successful termination
	return 0;
}

//function to sort arrays
void sortArray(double *ptr, string *namesPtr, int arraySize) {
	//temporary variable to help in swapping
	double temp;
	string tempName;

	//boolean variable that will control when
	//array is done sorting
	bool swapped = true;

	while (swapped) {
		swapped = false;

		//loop on all elements
		for (int counter = 0; counter < arraySize - 1; counter++) {
			//check if following element is greater
			//than current element
			if (*(ptr + counter) > *(ptr + counter + 1)) {
				//if so, perform swap
				temp = *(ptr + counter + 1);
				tempName = *(namesPtr + counter + 1);

				*(ptr + counter + 1) = *(ptr + counter);
				*(namesPtr + counter + 1) = *(namesPtr + counter);

				*(ptr + counter) = temp;
				*(namesPtr + counter) = tempName;

				//and update boolean variable
				swapped = true;

			}   //if ends here
		}   //for loop ends here
	}   //while loop ends here
}

//function to get average
double getAverage(double *ptr, int arraySize) {
	//accumulator variable
	double total = 0.0;

	//loop on all values of array, except from
	//first one (the lowest score which will be dropped)
	for (int counter = 0; counter < arraySize; counter++) {
		total += *(ptr + counter);
	}

	//use typecast to double to
	//prevent integer division
	return (double)total / arraySize;
}