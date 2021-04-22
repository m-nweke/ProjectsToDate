#include "Funcs.h"

void main() {
	long int num;
	int moves = 0;
	char choice;
	//Do while loop to run until the user decides to quit by pressing "n"
	do {
		num = get_num();
		cout << "Searching for a solution within 20 moves...." << endl;
		cout << endl;
		moves = get_moves(num, moves);
		//If there is a solution, the user will be told how many moves were remaining
		//Then the print function will be called that will print out the step by step procedure to get to 17
		if (moves <= 20) {
			cout << "Found solution, I have exactly 17 candies, with " << 20 - moves << " moves left."<< endl;
			get_moves_print(num, moves);
			cout << endl;
		}
		//If the moves exceed 20, the user will be told
		else if (moves > 20) {
			cout << "No solution found within 20 moves. Sorry." << endl;
		}
		//Moves reset to zero and the user is asked if the want to continue
		moves = 0;
		cout << endl << "Would you like to try again [Y/N]? ";
		cin >> choice;
		choice = toupper(choice);
		//Loop used to get valid input from the user
		do {
			if (choice != 'Y' && choice != 'N') {
				cout << "Please enter one of the options [Y/N] ";
				cin >> choice;
				choice = toupper(choice);
			}
		} while (choice != 'N' && choice != 'Y');
	} while (choice != 'N');
}