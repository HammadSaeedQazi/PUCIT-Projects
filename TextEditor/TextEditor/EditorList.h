#pragma once
#include"Node.h"
class EditorList {
	Node* head;
	Node* tail;
	int count;
	string fileName;
public:
	EditorList();
	void insertAtPos(int p, string d);
	void start();			//just to reduce lines of code in main
	void getInput(string &temp);
	void edit();
	void stoi(string s, int &n1, int &n2);
	bool checkWhichFunction(string &temp, int n1, int n2, int & iterator);
	void funcI(string &temp, int n1, int n2, int &iterator);
	void funcD(int n1, int n2, int &iterator);
	void funcL(int n1, int n2, int &iterator);
	void funcA(int &iterator);
	void funcE();
	~EditorList();
};