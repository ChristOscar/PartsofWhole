// Test Average 

#include <iostream>
#include <iomanip>  //for output formatting

using namespace std;


int main()
{
	//declare variables needed
	double test1, test2, test3, test4, test5, avg;

	// user to enter input 
	cout << "Enter score for test 1: ";
	cin >> test1;

	cout << "Enter score for test 2: ";
	cin >> test2;

	cout << "Enter score for test 3: ";
	cin >> test3;

	cout << "Enter score for test 4: ";
	cin >> test4;

	cout << "Enter score for test 5: ";
	cin >> test5;

	// calculation for average
	avg = (test1 + test2 + test3 + test4 + test5) / 5.0;

	//output and display result
	cout << showpoint << setprecision(1) << fixed;
	cout << "\nAverage score for 5 tests is: " << avg << endl;

	cout << "Tanks you for using the program.";

	return 0;



}