//Michael Nweke
//Program 3
//Student ID 16278575

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
//Function displays gameboard, showing where each AI is at the time
void board(int score1, int score2) {
	int i;
	int count = 0;
	int tick = 0;
//Formatting uses two for loops because the first 10 weren't lined up
	for (i = 1; i < 10; i++) {
		cout << setfill('*') << setw(70);
		if (i == score1) {
			cout << right << setw(6) << "| " << "AI1" << "|";
			count += 1;
		}
		else if (i == score2) {
			cout << right << setw(6) << "| " << "AI2" << "|";
			count += 1;
		}
		else if (i == score1 && i == score2) {
			cout << right << setw(6) << "| " << "Both" << "|";;
		}
		else {
			cout << right << setw(6) << "| " << i << "|";
			count += 1;
		}
		//The tick will break out of the loop and end the formatting when the board is all printed
		if (count == 10) {
			tick += 1;
			if (tick == 10) {
				cout << endl;
				break;
			}
			cout << endl;
			cout << setfill('*') << setw(60) << endl;
			count = 0;

		}

	}
	for (i = 10; i < 101; i++) {
		cout << setfill('*') << setw(60);
		if (i == score1) {
			cout << right << setw(5) << "| " << "AI1" << "|";
			count += 1;
		}
		else if (i == score2) {
			cout << right << setw(5) << "| " << "AI2" << "|";
			count += 1;
		}
		else if (i == score1 && i == score2) {
			cout << right << setw(5);
		}
		else {
			cout << right << setw(5) << "| " << i << "|";
			count += 1;
		}
		if (count == 10) {
			tick += 1;
			if (tick == 10) {
				cout << endl;
				break;
			}
			cout << endl;
			cout << setfill('*') << setw(60) << endl;
			count = 0;

		}

	}
}
//Function returns a random number between 1 and 6
int rand_dice()
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL));
		first = false;
	}
	return 1 + rand() % ((7) - 1);
}
//Function handles the chute rules which decreases the score if landing on a certain number and returns that score
int roll_chutes(int score) {
	if (score == 14) {
		return 2;
	}
	else if (score == 99) {
		return 50;
	}
	//If not on a ladder spot, it'll still return the score 
	return score;
}
//Function handles the ladder rules which increases the score if landing on a certain number and returns that score
int roll_ladder(int score) {
	if (score == 8) {
		return 34;
	}
	else if (score == 20) {
		return 90;
	}
	//If not on a ladder spot, it'll still return the score 
	return score;
}
//Function rolls the dice, displays each roll and changes the score accordingly
int players(int score) {
	int dice1 = rand_dice();
	int dice2 = rand_dice();
	int total = 0;
	int old = score;
	total += dice1 + dice2;
	score += total;
	cout << "Roling the dice" << endl;
	cout << "You got dice1: " << dice1 << ", dice2: " << dice2 << endl;
	//The user will be notified if they landed on a chute or ladder
	if (score == 14 || score == 99) {
		cout << "Sorry, you landed on a chute" << endl;
		score = roll_chutes(score);
	}
	else if (score == 8 || score == 20) {
		cout << "Congrats, you landed on a ladder" << endl;
		score = roll_ladder(score);
	}
	//Also tells how much the player moved that turn
	cout << "Total moves " << score-old << endl;
	cout << "Player moved from " << old << " to " << score << endl;
	//Returns adjusted score after the turn
	return score;
}
//Function that loops the program and will run until someone gets 100 or more
void play(int& round, int& score1, int& score2) {
	do {
		cout << "Round: " << round << endl;
		cout << "Player 1 turn: " << endl;
		//Calls the players function which shows the player turn for the round 
		score1 = players(score1);
		cout << "Player 2 turn: " << endl;
		//Players function called for each player
		score2 = players(score2);
		//Keeps track of what round the game is on, displayed at the beginning
		round += 1;
		//Output the playing board after each turn
		board(score1, score2);
	} while (score1 < 100 && score2 < 100);
	//If player1 reaches 100 first then they're declared as winner
	if (score1 >= 100) {
		cout << "Player 1 is the winner" << endl;
	}
	//If player2 reaches 100 first 2 then they're declared as winner
	else if (score2 >= 100) {
		cout << "Player 2 is the winner" << endl;
	}
}


void main() {
	//Initialize score and round number in the main function
	int score1 = 0;
	int score2 = 0;
	int round = 1;
	int player1 = 1;
	int player2 = 2;
	int winner = 0;
	//Displays welcome message to the user
	cout << "Welcome to Chutes and Ladders" << endl
		<< "We have two players, both are AI players" << endl <<
		"First to reach 100 or above is the winner" << endl <<
		"Let's play: " << endl;
	play(round, score1, score2);
}