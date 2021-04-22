#pragma once
#include <iostream>
using namespace std; 
//Function gets the number the user wants to use and will continue to ask until user enters valid input
long int get_num();
//Function will print the step by step procedure to get to 17 candies
int get_moves_print(long int num, int moves);
//This functions calculates the number of moves to get to 17 and stops once it reaches 20
int get_moves(long int num, int moves);

