// Michael Nweke
// mnweke@mail.umkc.edu
// october 15, 2019
// Program4


#include <iostream>
#include <iomanip> 
#include <string>
#include <fstream>
#include "Prog4.h"
#include <vector>
using namespace std;


void main() {
	int choice = 0;
	vector <Food> Foods;
	vector <Electronics> tech;
	ofstream output("output.txt");
	ifstream input;
	ifstream input2;
	Food obj;
	Electronics obj2;
	int test = 0;
	int test2 = 0;
	char main;
	do {
		cout << "Welcome to our Supermarket" << endl;
		cout << "Which department do you want to check?" << endl;
		cout << "1- Food" << endl << "2- Electronics" << endl << "3- Both" << endl << "4- Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {

			test = obj.ReadData(input, Foods);
			if (test == 1) {
				cout << setfill('-') << setw(80) << "-" << endl;
				output << setfill(' ') << setw(40);
				output << "Food Inventory" << setfill(' ')
					<< endl;

				for (int i = 0; i < Foods.size()-1; i++) {
					Foods[i].update(output);
				}
			}
			else {
				cout << "Error reading Foods file" << endl;
			}
		}
		else if (choice == 2) {
			test2 = obj2.ReadData(input2, tech);
			if (test2 == 1) {
				cout << setfill('-') << setw(80) << "-" << endl;
				output << setfill(' ') << setw(40);
				output << "Electronics Inventory" << setfill(' ')
					<< endl;
				for (int i = 0; i < tech.size()-1; i++) {
					tech[i].update(output);
				}
			}
			else {
				cout << "Error reading Electronics file" << endl;
			}
		}
		else if (choice == 3) {
			test = obj.ReadData(input, Foods);
			if (test == 1) {
				output << setfill(' ') << setw(40);
				output << "Food Inventory" << setfill(' ')
					<< endl;
				for (int i = 0; i < Foods.size()-1; i++) {
					Foods[i].update(output);
				}
			}
			else {
				cout << "Error reading Foods file" << endl;
			}
			test2 = obj2.ReadData(input2, tech);
			if (test2 == 1) {
				cout << setfill('-') << setw(80) << "-" << endl;
				output << setfill(' ') << setw(40);
				output << "Electronics Inventory" << setfill(' ')
					<< endl;
				for (int i = 0; i < tech.size() - 1; i++) {
					tech[i].update(output);
				}
			}
			else {
				cout << "Error reading Electronics file" << endl;
			}
		}
		cout << "Back to main menu? [y: yes | n: no]: " << endl;
		cin >> main;
		main = tolower(main);
		if (main == 'y') {
			continue;
		}
		else if (main == 'n') {
			choice = 4;
		}
	} while (choice != 4);

}

