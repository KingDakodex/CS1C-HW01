#include "header.h"


/*
Author:     Dakota Gall
Class:      CS1c TTH 4:30
Assignment: HW01
*/


// variables

// cont is used in the while statement to check if the user wants to execute the loop again
int cont = 1;
// temps store the digits for the random number
int tempOne = 0;
int tempTwo = 0;
int tempThree = 0;
// maths hold the results for performing arithmatic temporarily
// mathZero is a catch incase mathOne overflows into double digits
int mathZero = 0;
int mathOne = 0;
int mathTwo = 0;
int mathThree = 0;
// option is used to navigate the menus
int option = 0;
// sets the size for the array
const int ARR_SIZE = 10;
// array for random numbers
int ranArr[ARR_SIZE] = {rand()%10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10};

int readArr[ARR_SIZE];
// variables used to help sort ranArr, using bubble sort
int sortOne = 0;
int sortTwo = 0;
int sortTemp = 0;
// index is used walking through the for loops
int index = 0;

ofstream fout;

str welcomeWagon = "Welcome to The Random Number Generator \n";



int main()
{
	cout << welcomeWagon;

	// generate rand numbers
	// *unsolved ERROR*: tempOne is always 1, tempTwo is always 7, tempThree is always 4
	// * ERROR note: when run on a different day it produced different consistent random numbers, maybe isue with rand()?
	tempOne = rand() % 10;
	tempTwo = rand() % 10;
	tempThree = rand() % 10;

	// starts user interface program
	while (cont != 0)
	{
		PrintMenu(tempOne, tempTwo, tempThree);
		// *note: as I am not clearing the terminal input (forgot correct term) both cont and option are collecting the same data
		cin >> option;
		
		
		if (option == Sum) // sums all three digits and outputs to terminal
		{
			mathOne = tempOne + tempTwo + tempThree;
			cout << "The Sum of the Digits is: " << mathOne << "!\n";
		}
		else if (option == Tripple) // tripples each digit, if tempOne overflows its tent place is removed and added to tempZero
		{
			mathZero = 0;
			mathOne = tempOne * 3;
			mathTwo = tempTwo * 3;
			mathThree = tempThree * 3;

			while (mathThree > 9)
			{
				mathThree = mathThree - 10;
				mathTwo++;
			}
			while (mathTwo > 9)
			{
				mathTwo = mathTwo - 10;
				mathOne++;
			}
			while (mathOne > 9)
			{
				mathOne = mathOne - 10;
				mathZero++;
			}
			if (mathZero > 0)
			{
				cout << "The Trippled Number is: " << mathZero << mathOne << mathTwo << mathThree << "!\n";
			}
			else
			{
				cout << "The Trippled Number is: " << mathOne << mathTwo << mathThree << "!\n";
			}

		}
		else if (option == Reverse) // reverses the digits by swapping tempOne and tempThree
		{
			// *note: could have just swapped oreder in output, did not occur until notation
			mathOne = 0;
			mathTwo = 0;
			mathThree = 0;

			mathOne = tempThree;
			mathTwo = tempTwo;
			mathThree = tempOne;

			cout << "The Reversed digits are: " << mathOne << mathTwo << mathThree << "!\n";
		}
		else
		{
			cout << "That is not a valid option, please enter a number between 1 and 3\n";
		}

		// updates loop parametter
		// *note: as I am not clearing the terminal input (forgot correct term) both cont and option are collecting the same data
		cout << "Would You Like To Continue? Enter 0 To Exit.";
		cin >> cont;
	}

	// sorts ranArr
	// *note: attempted to use the sort() function but was unable to get it to work
	for (sortOne = 0; sortOne < ARR_SIZE; sortOne++)
	{
		for (sortTwo = sortOne + 1; sortTwo < ARR_SIZE; sortTwo++)
		{
			if (ranArr[sortTwo] < ranArr[sortOne])
			{
				sortTemp = ranArr[sortOne];
				ranArr[sortOne] = ranArr[sortTwo];
				ranArr[sortTwo] = sortTemp;
			}
		}
	}


	fout.open("Array.txt");

	for (index = 0; index < ARR_SIZE; index++)
	{
		fout << ranArr[index] << " ";
		cout << ranArr[index] << " ";
	}

	cout << "\n";

	fout.close();

	PrintArray(readArr, ARR_SIZE);

	return 0;
}

