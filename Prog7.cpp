#include "Def.h"
using namespace std;

void main() {
	Queue NewCars;
	Queue OldCars;
	Queue LuxCars;
	int choice = 0;
	choice = menu();
	do {
		if (choice == 1) {
			int func;
			do {
				func = inmenu("New Cars");
				if (func == 1) {
					string name;
					string model;
					int plate;
					cout << "Enter name of car" << endl;
					cin >> name;
					cout << "Enter model of car" << endl;
					cin >> model;
					cout << "Enter plate number of car" << endl;
					cin >> plate;
					NewCars.push(name, model, plate);
				}
				else if (func == 2) {
					string name;
					string model;
					int plate;
					cout << "Enter name of car" << endl;
					cin >> name;
					cout << "Enter model of car" << endl;
					cin >> model;
					cout << "Enter plate number of car" << endl;
					cin >> plate;
					NewCars.VIPpush(name, model, plate);
				}
				else if (func == 3) {
					NewCars.pop();
				}
				else if (func == 4) {

				}
				else if (func == 5) {
					NewCars.print();
				}
				else if (func == 6) {
					choice = menu();
				}
				else {
					cout << "Please enter a valid choice" << endl;
				}
			} while (func < 0 || func >6);
		}
		else if (choice == 2) {
			int func1;
			func1 = inmenu("Old and Historical Cars");
			if (func1 == 1) {
				string name;
				string model;
				int plate;
				cout << "Enter name of car" << endl;
				cin >> name;
				cout << "Enter model of car" << endl;
				cin >> model;
				cout << "Enter plate number of car" << endl;
				cin >> plate;
				OldCars.push(name, model, plate);
			}
			else if (func1 == 2) {
				string name;
				string model;
				int plate;
				cout << "Enter name of car" << endl;
				cin >> name;
				cout << "Enter model of car" << endl;
				cin >> model;
				cout << "Enter plate number of car" << endl;
				cin >> plate;
				OldCars.VIPpush(name, model, plate);
			}
			else if (func1 == 3) {
				OldCars.pop();
			}
			else if (func1 == 4) {

			}
			else if (func1 == 5) {
				OldCars.print();
			}
			else if (func1==6){
				choice = menu();
			}
			else {
				cout << "Please enter a valid choice" << endl;
			}
		}
		else if (choice == 3) {
			int func2;
			func2 = inmenu("Luxury Cars");
			if (func2 == 1) {
				string name;
				string model;
				int plate;
				cout << "Enter name of car" << endl;
				cin >> name;
				cout << "Enter model of car" << endl;
				cin >> model;
				cout << "Enter plate number of car" << endl;
				cin >> plate;
				LuxCars.push(name, model, plate);
			}
			else if (func2 == 2) {
				string name;
				string model;
				int plate;
				cout << "Enter name of car" << endl;
				cin >> name;
				cout << "Enter model of car" << endl;
				cin >> model;
				cout << "Enter plate number of car" << endl;
				cin >> plate;
				LuxCars.VIPpush(name, model, plate);
			}
			else if (func2 == 3) {
				LuxCars.pop();
			}
			else if (func2 == 4) {

			}
			else if (func2 == 5) {
				LuxCars.print();
			}
			else if (func2==6){
				choice = menu();
			}
			else {
				cout << "Please enter a valid choice" << endl;
			}
		}
		else if (choice==4){
			break;
		}
		else {
			cout << "Please input a valid choice" << endl;
		}
		choice = menu();
	}while (choice != 4);
}
