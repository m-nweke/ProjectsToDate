#include "Date.h"

Date::Date() {
	this->month = 1;
	this->day = 1;
	this->year = 1900;
}

Date::Date(int month, int day, int year) {
	this->month = month;
	this->day = day;
	this->year = year;
}

bool Date::isValid() {
	if (month >= 1 && month <= 12) {
		if (day >= 1 && day <= daysInMonth(month)) {
			if (year >= 1900) {
				return true;
			}
		}
	}
	else {
		return false;
	}
}

bool Date::isLeap(int year) {
	if (year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int Date::daysInMonth(int month) {
	if (month == 9 ||month==4 ||month==6 ||month==11 ) {
		return 30;
	}
	else if (month == 2) {
		if (this->year%4==0) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else {
		return 31;
	}
}

int Date::findTotalDays() {
	int Ytemp = year - 1900;
	int result = Ytemp * 365;
	for (int i = 1; i < month; i++) {
		result += daysInMonth(i);
	}
	result += day;
	for (int i = 1; i < Ytemp; i++) {
		if (isLeap(i)) {
			result += 1;
		}
	}
	return result;
}
string Date::daysOfweek() {
	string week;
	int dayoweek = 0;
	int Ytemp = year - 1900;
	int result = Ytemp * 365;
	for (int i = 1; i < month; i++) {
		result += daysInMonth(i);
	}
	result += day;
	for (int i = 1; i < Ytemp; i++) {
		if (isLeap(i)) {
			result += 1;
		}
	}
	for (int i = 1; i <= result; i++) {
		dayoweek += 1;
		if (dayoweek > 7) {
			dayoweek = 1;
		}
	}
	if (dayoweek == 1) {
		week = "Mon";
	}
	else if (dayoweek == 2) {
		week = "Tue";
	}
	else if (dayoweek == 3) {
		week = "Wed";
	}
	else if (dayoweek == 4) {
		week = "Thr";
	}
	else if (dayoweek == 5) {
		week = "Fri";
	}
	else if (dayoweek == 6) {
		week = "Sat";
	}
	else if (dayoweek == 7) {
		week = "Sun";
	}
	return week;
}

string Date::monthsOfyear() {
	string months;
	if (month == 1) {
		months = "Jan";
	}
	else if (month == 2) {
		months = "Feb";
	}
	else if (month == 3) {
		months = "Mar";
	}
	else if (month == 4) {
		months = "Apr";
	}
	else if (month == 5) {
		months = "May";
	}
	else if (month == 6) {
		months = "Jun";
	}
	else if (month == 7) {
		months = "Jul";
	}
	else if (month == 8) {
		months = "Aug";
	}
	else if (month == 9) {
		months = "Sept";
	}
	else if (month == 10) {
		months = "Oct";
	}
	else if (month == 11) {
		months = "Nov";
	}
	else if (month == 12) {
		months = "Dec";
	}
	return months;
}

Date& Date::operator++() {
	day++;
	Date temp(month, day, year);
	return temp;
}

Date& Date::operator--() {
	day--;
	Date temp(month, day, year);
	return temp;
}

Date Date::operator++(int) {
	int temp=day;
	day++;
	Date result(month, temp, year);
	return result;
}

Date Date::operator--(int) {
	int temp = day;
	day--;
	Date result(month, temp, year);
	return result;
}

Date& Date::operator+=(int days) {
	day += days;
	Date result(month, day, year);
	return result;
}

Date& Date::operator-=(int days) {
	day -= days;
	Date result(month, day, year);
	return result;
}

bool Date::operator==(Date& right){
	int comp = findTotalDays();
	int test = right.findTotalDays();
	if (comp == test) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator!=(Date& right) {
	int comp = findTotalDays();
	int test = right.findTotalDays();
	if (comp != test) {
		return true;
	}
	else {
		return false;
	}
}

Date& Date::operator=(const Date& right) {
	month = right.month;
	day = right.day;
	year = right.year;
	Date result(month, day, year);
	return result;
}

int operator-(Date& date1, Date& date2) {
	int num1 = date1.findTotalDays();
	int num2 = date2.findTotalDays();
	return num1 - num2;
}

ostream& operator<<(ostream& output, Date& date) {
	output << date.daysOfweek() << " " << date.monthsOfyear() << " " << date.day << " " << date.year << endl;
	return output;
}

void Date::plusReset(Date& date) {
	do {
		if (day > daysInMonth(month)) {
			date.day = day - daysInMonth(month);
			date.month = month + 1;
		}
		if (month > 12) {
			date.month = 1;
			date.year = year + 1;
		}
		else {
			break;
		}
	} while (date.day > daysInMonth(month));
	
}

void Date::minusReset(Date& date) {
	do {
		if (date.day < 1) {
			date.day += daysInMonth(date.month);
			date.month -= 1;
		}
		if (date.month < 1) {
			date.month = 12;
			date.year -= 1;
		}
		
	} while (date.day < 1);
	
}