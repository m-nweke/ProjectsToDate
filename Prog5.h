#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
public:
	Date();//Default constructor
	Date(int month, int day, int year);//Overloaded constructor
	bool isValid();//Test if class has a valid date
	bool isLeap(int year);//Checks if the year is a leap year or not
	int daysInMonth(int month);//Returns the number of days in the month
	int findTotalDays(); //Returns number of days from Jan 1, 1900
	string daysOfweek();//Gets the day of the week
	Date& operator++(); // overload pre - increment to increment a day
	Date& operator--(); //overload pre - decrement to decrement a day
	Date operator++(int); //overload post - increment to increment a day
	Date operator--(int); //overload post - decrement to decrement a day
	Date& operator+=(int days);  //add days to the given date
	Date& operator-=(int days); //subtract days from the given date.
	bool operator==(Date& right); //checks if two date objects are the same
	bool operator!=(Date& right); //checks if two date objects are not the same.
	Date& operator=(const Date& right); //assign right to LHS
	friend int operator-(Date& date1, Date& date2); //returns the difference between date1 and date 2(number of days)
	friend ostream& operator<<(ostream& output, Date& date); //outputs the day of the week, month of the year, day, and year of date.e.g : “Tue Oct 22 2019”
	void plusReset(Date& date); //will be used to adjust the new date if necessary.
	void minusReset(Date& date); //will be used to adjust the new date if necessary.
	string monthsOfyear();//Returns the month based on the number
	static int startWeekday;
	static int startYear;
private:
	int month;
	int day;
	int year;
};
