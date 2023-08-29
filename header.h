#ifndef HEADER_FILE
#define HEADER_FILE

// input output
#include <iostream>
// basic functions
#include <iomanip>
// string variable and string functions
#include <string>
// random num function
#include <cstdlib>
// for external file handling
#include <fstream>
using namespace std;

// Type Definers
typedef string str;

// Enum Types
enum Options
{
	Sum = 1,
	Tripple = 2,
	Reverse = 3
};

// functions
void PrintMenu(int numOne, int numTwo, int numThree)
{

	cout << "Your Number is: " << numOne << numTwo << numThree << " \n\n";
	cout << "Functions: \n";
	cout << "1 --- Sum Digits\n";
	cout << "2 --- Triple Number\n";
	cout << "3 --- Reverse Digits\n";
	cout << "What would you like to do?\n";


}

void PrintArray(int *array, int size)
{
	ifstream file;

	file.open("Array.txt");

	for (int index = 0; index < size; index++)
	{
		file >> array[index];
		cout << array[index] << " ";
	}

	file.close();
}

#endif