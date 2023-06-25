#include <iostream>
#include <fstream>
#include <map>

using namespace std;

//Create a class to Find items
class ItemFinder {
private:
	map<string, int> frequencyMap;

public:
	ItemFinder() {
	}

	//Method for reading the iinput of a file
	void readInputFile(string filename) {
		ifstream inputFile(filename);
		string item;
		while (inputFile >> item) {
			frequencyMap[item]++;
		}
		inputFile.close();
	}
	//Method for ouputting an item with its frequency
	//Example: Apples 4
	void printItemFrequency(string item) {
		if (frequencyMap.count(item) > 0) {
			cout << item << " " << frequencyMap[item] << endl;
		}
		else {
			cout << "Item does not exist." << endl;
		}
	}
	//Method for ouputting all items from the list
	void printAllFrequencies() {
		for (auto i = frequencyMap.begin(); i != frequencyMap.end(); ++i) {
			cout << i->first << " " << i->second << endl;
		}
	}
	//Method for outputting items in histogram form
	void printHistogram() {
		for (auto i = frequencyMap.begin(); i != frequencyMap.end(); ++i) {
			cout << i->first << " ";
			for (int j = 0; j < i->second; ++j) {
				cout << "*";
			}
			cout << endl; 
		}
	}
	//Method for creating and writing a .dat backup file for item frequency
	void writeFrequencyFile(string fileName) {
		ofstream frequencyFile(fileName);
		for (auto i = frequencyMap.begin(); i != frequencyMap.end(); ++i) {
			frequencyFile << i->first << " " << i->second << endl;
		}
		frequencyFile.close();
	}
};

int main() {
	ItemFinder finder;
	//Call for reading the inpuit file
	finder.readInputFile("CS210_Project_Three_Input_File.txt");

	//Declare user choice variable
	int userChoice;
	//Do-while loop to output a menu and get input from user
	do {
		//Print menu selection and requests user input
		cout << "" << endl;
		cout << "======================================" << endl;
		cout << "|                Menu                |" << endl;
		cout << "======================================" << endl;
		cout << "| 1. Input word or item to look for  |" << endl;
		cout << "| 2. Print frequency of all items    |" << endl;
		cout << "| 3. Print histogram of all items    |" << endl;
		cout << "| 4. Exit program                    |" << endl;
		cout << "======================================" << endl;
		cout << "\nEnter your choice as a number (1-4): ";
		cin >> userChoice;

		switch (userChoice) {
		//Outputs a single item with frequency if user inputs 1 for menu choice 
		case 1:
		{
			string item;
			cout << "\nEnter item or word to search for: ";
			cin >> item;
			finder.printItemFrequency(item);
			break;
		}
		//Outputs all items with their frequencies if user inputs 2 for menu choice
		case 2:
		{
			finder.printAllFrequencies();
			break;
		}
		//Outputs item histogram if user inputs 3 for menu choice
		case 3:
		{
			finder.printHistogram();
			break;
		}
		//Exits progrem and writes .dat file if user inputs 4 for menu choice
		case 4:
		{
			finder.writeFrequencyFile("frequency.dat");
			cout << "\nExiting Program. Thank you." << endl;
			break;
		}
		//Default is invlaid choice if user does not input a number between 1 and 4
		default:
		{
			cout << "\nInvlaid choice. Please enter a number between 1 and 4." << endl;
			break;
		}
		}
	} 
	//Do-while loop closes when user input is 4
	while (userChoice != 4);

	return 0;
}