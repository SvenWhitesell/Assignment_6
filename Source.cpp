#include <iostream>
#include <stdio.h>
#include <memory>
using namespace std;
/*
Title: Assignment-1

Author: Sven Whitesell
		101006983

Objective: 

	Create a program that asks a user to enter in an array size, then asks them to enter in the values for the array. Double the 
array size if they choose to enter in more numbers. Print a list of all numbers in the array if asked, print the max or min value if asked.


Algorithm: 
	
	Create an array size variable for the user to set. Create dynamic array. Create variables for 'choice' to navigate the menu loop,
variable for 'purchase' which adds the price of purchase to array, variable for 'count' which counts the purchases. Enter menu loop, ask 
user to enter choice for menu.

	If choice is option 1, ask user to enter in a price, put that number into the array. If 'count' is greater than the array size, double
	the array size and keep data.
	If choice is option 2, print a list of all numbers in the array.
	If choice is option 3, print the most expensive purchase.
	If choice is option 4, print the least expensive purchase.
	If choice is option 5, end the program.
*/

int* PurchaseRecord() {
	
	int ArraySize; //Creating the array size variable
	cout << "Enter number of purchases: \n"; //asking user to enter in array size
	cin >> ArraySize; //takes the array size

	int* Purchases = (int*)malloc(ArraySize * sizeof(int)); //creates an array using that size
	
	int choice = 0; //Variable to guide the user through the options
	int purchase; //Variable for the price of each purchase
	int count = 0; //The count of purchases

	while (true) { //Menu Loop

		 //All the options
			cout << "Choices: \n" << "1) -Enter a new purchase\n" << "2) -See full list of entered purchases\n" << "3) -Show the value of the most expensive purchase\n" << "4) -Show the value of the least expensive purchase\n" << "5) -End program\n";
			cin >> choice;
		//Choices
		if (choice == 1) { //add numbers to the array
			cout << "Enter in a price: "; 
			cin >> Purchases[count]; //puts numbers into the array
			count++;

			if (count > ArraySize) { 
				ArraySize *= 2; //Doubles the array size if the user wants to enter more than the originally stated array size.
				int* data = (int*)malloc(ArraySize * sizeof(data)); //creates more memory.
				
			}
			
		}
		
		if (choice == 2) { //Shows a full list of the numbers in the array
			for (int i = 0; i < count; i++)
			{
				cout << "--> " << Purchases[i] << "\n"; //Prints all the numbers in the array.
			}
		}
		
		if (choice == 3) { //Shows the Most expensive purchase
			int max = Purchases[0];
			for (int i = 0; i < count; i++)
			{
				if (max < Purchases[i]) //if the maximum number is less than the newest number entered..
					max = Purchases[i]; //..it sets the new max number to be that entered number.
			}
			cout << "Most expensive purshase is: " << max << "\n"; //Prints the most expensive price
		}
		
		if (choice == 4) { //Shows the Least expensive purchase
			int min = Purchases[0]; //sets the minimum to be 0 so that it has something to reference
			for (int i = 0; i < count; i++)
			{
				if (min > Purchases[i]) //if the minimum number is greater than the newest number entered..
					min = Purchases[i]; //..it sets the new min number to be that entered number.
			}
			cout << "Least expensive purshase is: " << min << "\n"; //Prints the least expensive price
		}
		if (choice == 5) { //Ends the program
			break;
		}
		
		//Give error message
		if (choice > 5) { //Gives an error message to user if they enter in an invalid number
			cout << "Command invalid! Enter in a valid number!\n";
		}
		if (choice < 1) { //Gives an error message to user if they enter in an invalid number
			cout << "Command invalid! Enter in a valid number!\n";
		}
	}

	return Purchases;
}

void main() {
	free(PurchaseRecord());
}