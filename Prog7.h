#pragma once
#include <iostream>
#include <string>
using namespace std; 

struct car {
	string name;
	string model;
	int plate;
	bool is_VIP;
};

class Node { 
public:
	Node() { next = NULL; }
	Node(struct car theData, Node* Link) { data = theData; next = Link; }
	struct car data; 
	Node* next; 
}; 

class Queue {
public:
	Queue(); 
	int size() const; 
	void push(string name, string model, int plate); 
	void VIPpush(string name, string model, int plate);
	void pop(); 
	bool is_empty() const; 
	void empty();
	void print();
private:
	Node *Head;
	Node *Tail;
	int count;
};

int menu();
int inmenu(string type);

