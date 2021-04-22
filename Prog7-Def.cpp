#include "Def.h"
//default constructor


Queue::Queue() {
	Head = NULL;
	Tail = NULL;
	count = 0;
}

int Queue::size() const {return count;}

void Queue::push(string name, string model, int plate) {
	Node* node = new Node;
	node->data.name = name;
	node->data.model = model;
	node->data.plate = plate;
	node->data.is_VIP = false;
	if (count == 0) {
		Head = node;
		Tail = node;
	}
	else {
		Tail->next = node;
		Tail = node;
	}
	cout << "Adding car: " << name << " " << model << " " << plate << endl;
	count += 1;
}

void Queue::VIPpush(string name, string model, int plate) {
	Node* node = new Node;
	node->data.name = name;
	node->data.model = model;
	node->data.plate = plate;
	if (count == 0) {
		Head = node;
		Tail = node;
	}
	else {
		int i;
		Node* temp = new Node;
		Node* temp1 = new Node;
		temp = Head;
		//temp pointer will be used to navigate the queue and get past all the VIPs
		for (i = 0; i < count; i++) {
			if (temp->data.is_VIP) {
				temp1 = temp;
				temp = temp->next;
			}
			else {
				temp1 = temp;
				//Once a VIP is found, it will insert the new data after it
				temp1->next->data.name = name;
				temp1->next->data.model = model;
				temp1->next->data.plate = plate;
				temp1 = temp1->next;
				temp1->next = temp;
			}
		}
		cout << "Adding VIP car: " << name << " " << model << " " << plate << endl;
		count += 1;
	}
}

void Queue::pop() {
	if (count != 0) {
		Node* temp = new Node;
		temp = Head;
		Head = Head->next;
		cout << "Taking car to auction: " << temp->data.name << " " << temp->data.model << " " << temp->data.plate << endl;
		delete temp;
		count -= 1;
	}
	else {
		cout << "Empty queue" << endl;
	}
}
bool Queue::is_empty() const {
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}
void Queue::empty() {
	while (!is_empty()) {
		pop();
	}
}
void Queue::print() {
	int i; 
	Node* temp = new Node; 
	temp = Head; 
	for (i = 0; i < count; i++) {
		cout << temp->data.model << " " << temp->data.name << " " << temp->data.plate << endl;
		temp = temp->next; 
	}
	if (is_empty()) {
		cout << "Queue is empty" << endl;
	} 
}

int menu() {
	int choice;
	cout << "Welcome to BMW Auctions" << endl;
	cout << "1. New Cars" << endl;
	cout << "2. Old and Historical Cars" << endl;
	cout << "3. Luxury Cars" << endl;
	cout << "4. Exit" << endl;
	cout << "Please enter your choice" << endl;
	cin >> choice;
	return choice;
}

int inmenu(string type) {
	int choice = 0;
	cout << "Welcome to Exhibition " << type << endl;
	cout << "1. Add car" << endl;
	cout << "2. Add VIP car" << endl;
	cout << "3. Take car to auction" << endl;
	cout << "4. Cancel Car" << endl;
	cout << "5. List all currently queued cars" << endl;
	cout << "6. Exit back to main menu" << endl;
	cout << "Please enter your choice" << endl;
	cin >> choice;
	return choice;
}

