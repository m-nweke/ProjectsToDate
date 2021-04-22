#include <iostream>
#include "Funcs.h"
using namespace std;

long int get_num() {
	long int num;
	bool valid = false;
	do {
		cout << "How many candies are you starting with?  ";
		cin >> num;
		if (num <= 0) {
			cout << "Number of candies must be grerater than zero and no less than 10,000" << endl;
		}
		else if (num > 10000) {
			cout << "Number of candies must be grerater than zero and no less than 10,000" << endl;
		}
		else {
			valid = true;
		}
	} while (!valid);
	return num;
}

int get_moves_print(long int num, int moves) {
	if (num == 17) {
		return moves;
	}
	else if (moves == 20) {
		moves += 1;
		return moves;
	}
	else if ((num + 23) % 17 == 0) {
		cout << "With " << num << " add 23 to get " << num+23 << "." << endl;
		num += 23;
		moves += 1;
		get_moves_print(num, moves);
	}
	else if (num % 2 == 0) {
		cout << "Reduce " << num << " by half to get " << num/2 << "." << endl;
		num = (num / 2);
		moves += 1;
		get_moves_print(num, moves);
	}
	else if (num % 3 == 0) {
		cout << "With " << num << " add 1/3 to get " << num+(num/3) << "." << endl;
		num += (num/3);
		moves += 1;
		get_moves_print(num, moves);
	}
	else {
		cout << "With " << num << " add 23 to get " << num + 23 << "." << endl;
		num += 23;
		moves += 1;
		get_moves_print(num, moves);
	}
}

int get_moves(long int num, int moves) {
	if (num == 17) {
		return moves;
	}
	else if (moves == 20) {
		moves += 1;
		return moves;
	}
	else if ((num + 23) % 17 == 0) {
		num += 23;
		moves += 1;
		get_moves(num, moves);
	}
	else if (num % 2 == 0) {
		num = (num / 2);
		moves += 1;
		get_moves(num, moves);
	}
	else if (num % 3 == 0) {
		num += (num / 3);
		moves += 1;
		get_moves(num, moves);
	}
	else {
		num += 23;
		moves += 1;
		get_moves(num, moves);
	}
}
