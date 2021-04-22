#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Product {
public:
	Product();
	Product(int barcode, string name, double price, double tax, double discount);
	int GetBarcode();
	void SetBarcode(int barcode);
	double GetPrice();
	void SetPrice(double price);
	string GetName();
	void SetName(string name);
	double GetTax();
	void SetTax(double price);
	double GetDiscount(int numdays);
	void SetDiscount(double discount);
	void update(ofstream& output);
	int barcode;
	double price;
	string name;
	double tax;
	double discount;
};

class Food :public Product {
public:
	Food();
	Food(int barcode, string name, double price, double discount, string prodate, int numdays);
	string GetDate();
	void SetDate(string prodate);
	int GetDays();
	void SetDays(int numdays);
	bool ReadData(ifstream& input, vector <Food>& Foods);
	void update(ofstream& output);
private:
	string prodate;
	int numdays;
};

class Electronics :public Product {
public:
	Electronics();
	Electronics(int barcode, string name, double price, double tax);
	bool ReadData(ifstream& input2, vector <Electronics>& tech);
	void update(ofstream& output);
private:
	int warranty;
};
