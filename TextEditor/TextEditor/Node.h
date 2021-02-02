#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
class EditorList;
using namespace std;
class Node {
	friend EditorList;
	string data;
	Node* next;
	Node* prev;
public:
	Node(string d = " ", Node* p = NULL, Node* n = NULL);
};