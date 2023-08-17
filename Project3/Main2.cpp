#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include "GrocerItem.h"

using namespace std;

void MenuOptions() {
	cout << "Menu options:" << endl;
	cout << "1) Look up individual item" << endl;
	cout << "2) Print list with frequency of all items purchased" << endl;
	cout << "3) Print list with frequency of all items purchased in histogram format" << endl;
	cout << "4) Exit" << endl;
}

int main() {
	GrocerItem foodCount;
	char loop = 'c';
	int menuChoice;
	string userWord;
	

	
	foodCount.SetFoodCount();			//Reading in the file and storing its data in a map
	foodCount.OutputCountToFile();		//Writing data to backup file
	while (loop != 'q') {

		
		MenuOptions();				//Prints a menu
		cin >> menuChoice;
		cout << endl;
		if (menuChoice == 1) {
			try {
				cout << "Input the item you wish to look for. Ex= spinach" << endl;
				cin.clear();
				cin.ignore(123, '\n');
				getline(cin, userWord);
				userWord[0] = toupper(userWord[0]);				//Sets the first letter of user input to a capital letter
				foodCount.PrintIndividualItem(userWord);		//Prints individual item from list
			}
			catch (out_of_range& oor) {							//Catches input error and asks user to retry
				cerr << "Out of Range error: "  << endl;
				cout << "Enter a valid input" << endl;
				cout << "Press ENTER to continue" << endl;
				cin.clear();
				cin.ignore(123, '\n');				
			}
		}
		else if (menuChoice == 2) {								//Print list of items and their frequencies
			foodCount.Print();
		}
		else if (menuChoice == 3) {								//Print list of items and their frequencies in histogram format
			foodCount.PrintHisto();
		}
		else if (menuChoice == 4) {
			cout << "Exiting the program";
			break;
		}
		else {
			cout << "Invalid input" << endl;
		}

	}

	return 0;
}