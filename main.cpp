/******************************************************************************

Seat Selection on airplane

Author: Rocco Marino
Due Date 9/25/2024

*******************************************************************************/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void seatSelection(); //Select seat
void display(); //displaying Vectors
vector<string> v1{"1", "0", "0", "0", "0"};  //making vectors global variables
vector<string> v2{"2", "0", "0", "0", "0"};
vector<string> v3{"3", "0", "0", "0", "0"};
vector<string> v4{"4", "0", "0", "0", "0"};
vector<string> v5{"5", "0", "0", "0", "0"};
int main()
{
	display(); //displaying the vecor
	seatSelection(); //calling the seat selection
	return 0;
}

void display()
{
	cout << "  A B C D"; //Printing The letters of the columns
	cout << endl;

	for (string i: v1)
	{
		cout << i << " ";
	}
	cout << endl;

	for (string i: v2)
	{
		cout << i << " ";
	}
	cout << endl;

	for (string i: v3)
	{
		cout << i << " ";
	}
	cout << endl;

	for (string i: v4)
	{
		cout << i << " ";
	}
	cout << endl;

	for (string i: v5)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "O:Available X:Unavailable" << endl;  //printing what variables mean
}

void seatSelection()
{
	string selection;
	cout << "Enter seat (e.g., B3): ";    //asking user for Seat number with row number
	cin >> selection;
	int seat;

	try
	{
		if (selection[0] == 'A') //Assigning interger values to the string for future use
		{
			seat = 1;
		}
		else if (selection[0] == 'B')
		{
			seat = 2;
		}
		else if (selection[0] == 'C')
		{
			seat = 3;
		}
		else if (selection[0] == 'D')
		{
			seat = 4;
		}
		else
		{
			throw runtime_error("Seat does not exist"); //Exception
		}
	}
	catch (runtime_error& ex)
	{
		cout << "Seat " << selection << " does not exist please ";
		seatSelection();
	}
	try
	{
		if (selection.length() != 2) //Making sure the sting length is 2
		{
			throw runtime_error("Invalid seat number");
		}
		else if (selection[1] == '1') //Getting the seat number for the row
		{
			if (v1.at(seat) == "0") //Making sure seat is Available
			{
				v1[seat] = "X"; //replaceing value with X
			}
			else
			{
				throw runtime_error("Seat is taken"); //Exception
			}
		}
		else if (selection[1] == '2')
		{
			if (v2.at(seat) == "0") //Making sure seat is Available
			{
				v2[seat] = "X"; //replaceing value with X
			}
			else
			{
				throw runtime_error("Seat is taken");
			}
		}
		else if (selection[1] == '3')
		{
			if (v3.at(seat) == "0") //Making sure seat is Available
			{
				v3[seat] = "X"; //replaceing value with X
			}
			else
			{
				throw runtime_error("Seat is taken");
			}
		}
		else if (selection[1] == '4')
		{
			if (v4.at(seat) == "0") //Making sure seat is Available
			{
				v4[seat] = "X"; //replaceing value with X
			}
			else
			{
				throw runtime_error("Seat is taken");
			}
		}
		else if (selection[1] == '5')
		{
			if (v5.at(seat) == "0") //Making sure seat is Available
			{
				v5[seat] = "X"; //replaceing value with X
			}
			else
			{
				throw runtime_error("Seat is taken");
			}
		}
		else
		{
			throw runtime_error("Invalid Seat Number");
		}
		display(); //display new seating arrangment
		cout << "Seat " << selection << " Selected " << endl; //Display what seat you selected
	}
	catch (runtime_error& ex)
	{
		cout << "Seat "<< selection << " is taken or the seat number is invalid please ";
	}
	seatSelection(); //calling the seat selection
}