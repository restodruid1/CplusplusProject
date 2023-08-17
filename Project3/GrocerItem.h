#pragma once
#ifndef GROCERITEM_H
#define GROCERITEM_H
#include <map>
#include <string>
using namespace std;

class GrocerItem {
	public:
		void SetFoodCount();
		void OutputCountToFile();
		void Print();
		void PrintHisto();
		void PrintIndividualItem(string mapKey);
	private:
		map<string, int> grocerItems;
		
};
#endif