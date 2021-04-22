#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Prog4.h"
#include <vector>
using namespace std;

Product::Product() {
	barcode = 0;
	price = 0;
	name = "";
	tax = 0;
	discount = 0;
}
Product::Product(int barcode, string name, double price, double tax, double discount) {
	if (barcode <= 0) {
		this->barcode = 0;
	}
	else {
		this->barcode = barcode;
		this->price = price;
		this->name = name;
		this->tax = tax;
		this->discount = discount;
	}
}
int Product::GetBarcode() {
	return barcode;
}
void Product::SetBarcode(int barcode) {
	this->barcode = barcode;
}
double Product::GetPrice() {
	return price;
}
void Product::SetPrice(double price) {
	this->price = price;
}
string Product::GetName() {
	return name;
}
void Product::SetName(string name) {
	this->name = name;
}
double Product::GetTax() {
	return tax;
}
void Product::SetTax(double price) {
	this->tax = price*.09;
}
double Product::GetDiscount(int numdays) {
	if (numdays < 10) {
		discount = 0;
	}
	else if (numdays > 10 && numdays < 14) {
		this->discount = 0.20;
	}
	else if (numdays > 15 && numdays < 29) {
		discount = .50;
	}
	else {
		discount = .80;
	}
	return discount;
}
void Product::SetDiscount(double tax) {
	this->discount = discount;
}
void Product::update(ofstream& output) {

}

Food::Food() {
	prodate = "";
	numdays = 0;
}

Food::Food(int barcode, string name, double price, double discount, string prodate, int numdays) {
	if (barcode <= 0) {
		this->barcode = 0;
	}
	else {
		this->barcode = barcode;
		this->price = price;
		this->name = name;
		this->tax = tax;
		this->discount = discount;
		this->prodate = prodate;
		this->numdays = numdays;
	}
}
string Food::GetDate() {
	return prodate;
}
void Food::SetDate(string prodate) {
	this->prodate = prodate;
}
int Food::GetDays() {
	return numdays;
}
void Food::SetDays(int numdays) {
	this->numdays = numdays;
}
bool Food::ReadData(ifstream& input, vector <Food>& Foods) {
	input.open("Food-1.txt");
	int barcode;
	string name;
	double price;
	double discount;
	string prodate;
	int numdays;
	ofstream output;
	try {
		while (!input.eof()) {
			input >> barcode >> name >> price >> prodate >> numdays;
			discount = GetDiscount(numdays);
			Food food(barcode, name, price, discount, prodate, numdays);
			Foods.push_back(food);
		}
		return true;
	}
	catch (...) {
		return false;
	}
}
void Food::update(ofstream& output) {
	
	output << name << " with Barcode: " << barcode << endl;
	output << "Its price = " << price << " and was produced on " << prodate << endl;
	if (discount == 0) {
		output << name << " not on sale" << endl;
	}
	else {
		output << name << " on clearance, final price is now " << price - (price * discount) << endl;
	}
	output << setfill('-') << setw(80) << '-' << endl;
}

Electronics::Electronics() {
	warranty = 0;
}
Electronics::Electronics(int barcode, string name, double price, double tax) {
	if (barcode <= 0) {
		this->barcode = 0;
	}
	else {
		this->barcode = barcode;
		this->price = price;
		this->name = name;
		this->tax = tax;
	}
}

bool Electronics::ReadData(ifstream& input2, vector <Electronics>& tech) {
	input2.open("Electronics-1.txt");
	int barcode;
	string name;
	double price;
	double tax;
	try {
		while (!input2.eof()) {
			input2 >> barcode >> name >> price;
			tax = price * .09;
			Electronics techno(barcode, name, price, tax);
			tech.push_back(techno);
		}
		return true;
	}
	catch (...) {
		return false;
	}
}

void Electronics::update(ofstream& output) {
	double total = price + tax;
	output << name << " with Barcode: " << barcode << " and price: " << price << endl;
	if (price < 200) {
		output << "Will have a 1 year warranty and price after taxes = " << total << endl;
		output << name << " has 1 option for payment" << endl << "1- Cash full price" << endl;
	}
	else if (price > 200 && price < 1000) {
		output << "Will have a 3 year warranty and price after taxes = " << total << endl;
		output << name << " has 2 options for payment" << endl << "1- Cash full price" << endl;
		output << "2- Pay over 12 months with 1% interest of the price," << endl;
		output << "so you will need to pay " << (total + (total * .01)) / 12 << endl;
	}
	else {
		output << "Will have a 5 year warranty and price after taxes = " << total << endl;
		output << name << " has 2 options for payment" << endl << "1- Cash full price" << endl;
		output << "2- Pay over 24 months with 1% interest of the price," << endl;
		output << "so you will need to pay " << (total + (total*.01) + (total*.01))/24 << endl;
	}
	output << setfill('-') << setw(80) << '-' << endl;
}