#include <iostream>
#include <fstream>
using namespace std;

#include "GrocerItem.h"

void GrocerItem::SetFoodCount() {	//Creating map with data from "GrocerInputFile.txt"
	ifstream inFS;
	string foodItem;

	inFS.open("GrocerInputFile.txt");
	while (!inFS.eof()) {

		inFS >> foodItem;	//read next line of input file

		if (!inFS.fail()) {
			if (grocerItems.count(foodItem) == 1) {  //returns 1 if the item is in the dictionary
				grocerItems[foodItem]++;				//increments the value associated with the item
			}
			else {
				grocerItems.emplace(foodItem, 1);		//adds the item in the dictionary if the above code returns 0
			}
		}
	}
	inFS.close();			//close input file
}

void GrocerItem::OutputCountToFile() {	//Writing data to backup file
	ofstream outFS;

	outFS.open("frequency.dat", fstream::app);  //Writes new data to file everytime
	outFS << "LATEST ENTRY" << endl;
	for (const auto& pair : grocerItems) {					//print each key value pair(grocery item with quantity)
		outFS << pair.first << ": " << pair.second << endl;
	}
	outFS << endl;
	outFS.close();				//close output file
}

void GrocerItem::Print() {
	cout << "List of all the items:" << endl;
	for (const auto& pair : grocerItems) {					//print each key value pair(grocery item with quantity)
		cout << pair.first << " " << pair.second << endl;
	}
	cout << endl;
}

void GrocerItem::PrintHisto() {
	cout << "List of all the items:" << endl;
	for (const auto& pair : grocerItems) {					//print each key value pair(grocery item with quantity)
		cout << pair.first << " " << string(pair.second, '*') << endl;
	}
	cout << endl;
}

void GrocerItem::PrintIndividualItem(string mapKey) {		//Prints the key and its value
	cout << mapKey << " " << grocerItems.at(mapKey) << endl;
	cout << endl;
}