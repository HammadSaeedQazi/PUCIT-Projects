#include"EditorList.h"
EditorList::EditorList() {
	head = new Node("");
	tail = new Node("");
	head->next = tail;
	tail->prev = head;
	count = 0;
	fileName = "";
}

void EditorList::insertAtPos(int p, string d) {
	Node* curr = head;
	for (int i = 0; i < p; i++)
		curr = curr->next;
	Node* t = new Node(d, curr->prev, curr);
	curr->prev->next = t;
	curr->prev = t;
	count++;
	return;
}

void EditorList::stoi(string s, int &n1, int &n2) {
	int i = 0;
	int l = s.length();
	if (l == 1)
		return;
	while (i<l && s[i] != ' ') { i++; }
	if (i<l-1 && s[i + 1] >= '0' && s[i + 1] <= '9') {
		//int l = s.length();
		int j = 0;
		int temp;
		string s1 = "";
		string s2 = "";
		i++;
		while (i<l && s[i] != ' ') {
			s1 = s1 + s[i];
			i++;
		}
		i++;
		while (i<l && s[i] != ' ') {
			s2 = s2 + s[i];
			i++;
		}
		int l1 = s1.length();
		int l2 = s2.length();
		for (int i = l1 - 1; i >= 0; i--) {
			temp = s1[i] - 48;
			n1 = n1 + int(pow(10, j)*temp);
			j++;
		}
		j = 0;
		for (int i = l2 - 1; i >= 0; i--) {
			temp = s2[i] - 48;
			n2 = n2 + int(pow(10, j)*temp);
			j++;
		}
	}
}

void EditorList::start() {
	cout << "Note : \n       There is a one space gap between a command and its parameters (if any)\n\n";
	string temp;
	getInput(temp);
}

void EditorList::getInput(string &temp) {
	getline(cin, temp);
	for (int i = 5; i < temp.length(); i++)
		fileName = fileName + temp[i];
	fileName = fileName + "`";
	if ((temp[0] == 'e' || temp[0] == 'E') && (temp[1] == 'd' || temp[1] == 'D') && (temp[2] == 'i' || temp[2] == 'I') && (temp[3] == 't' || temp[3] == 'T'))
		edit();
	else return;
}

bool EditorList::checkWhichFunction(string &temp, int n1, int n2, int &iterator) {
	bool isExist = false;
	if (temp[0] == 'i' || temp[0] == 'I') {
		if (temp.length()==1) {
			funcI(temp, n1, n2, iterator);
			return true;
		}
		else {
			for (int i = 1; i<temp.length(); i++) {
				if (temp[i] == ' ' || (temp[i] >= '0' && temp[i] <= '9'))
					isExist = true;
				else {
					isExist = false;
					break;
				}
			}
			if (isExist == true) {
				funcI(temp, n1, n2, iterator);
				return true;
			}
		}
	}
	else if (temp[0] == 'd'|| temp[0] == 'D') {
		if (temp.length() == 1) {
			funcD(n1, n2, iterator);
			return true;
		}
		else {
			for (int i = 1; i<temp.length(); i++) {
				if (temp[i] == ' ' || (temp[i] >= '0' && temp[i] <= '9'))
					isExist = true;
				else {
					isExist = false;
					break;
				}
			}
			if (isExist == true) {
				funcD(n1, n2, iterator);
				return true;
			}
		}
	}
	else if (temp[0] == 'l' || temp[0] == 'L') {
		if (temp.length() == 1) {
			funcL(n1, n2, iterator);
			return true;
		}
		else {
			for (int i = 1; i<temp.length(); i++) {
				if (temp[i] == ' ' || (temp[i] >= '0' && temp[i] <= '9'))
					isExist = true;
				else {
					isExist = false;
					break;
				}
			}
			if (isExist == true) {
				funcL(n1, n2, iterator);
				return true;
			}
		}
	}
	else if (temp == "a" || temp == "A") {
		funcA(iterator);
		return true;
	}
	else if (temp == "e" || temp == "E") {
		funcE();
		return true;
	}
	return false;
}

void EditorList::funcI(string &temp, int n1, int n2, int &iterator) {
	bool isFunction = false;
	if (n1 == 0) {
		iterator = iterator - 1;
		cout << '\n' << iterator << "> ";
		getInput(temp);
		isFunction=checkWhichFunction(temp, n1, n2, iterator);
		if (isFunction == false)
			insertAtPos(iterator, temp);
	}
	else {
		Node* curr = head;
		iterator = 0;
		for (int i = 0; i < n1; i++) {
			iterator++;
		}
		cout << '\n' << iterator << "> ";
		getInput(temp);
		isFunction=checkWhichFunction(temp, n1, n2, iterator);
		if (isFunction == false)
			insertAtPos(iterator, temp);
	}
	count++;
	return;
}

void EditorList::funcD(int n1, int n2, int &iterator) {
	Node* curr = head;
	if (n1 == 0 && n2 == 0) {
		for (int i = 0; i < iterator - 1; i++)
			curr = curr->next;
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete curr;
		iterator = iterator - 2;
		count--;
	}
	else if (n2 == 0) {
		for (int i = 0; i < n1; i++)
			curr = curr->next;
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete curr;
		iterator = iterator - 2;
		count--;
	}
	else {
		Node* nxt = NULL;
		for (int i = 0; i < n1; i++)
			curr = curr->next;
		for (int i = n1; i <= n2 && curr!=NULL; i++) {
			nxt = curr->next;
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
			curr = nxt;
			count--;
		}
		iterator = iterator - (n2 - n1 + 2);
	}
	return;
}

void EditorList::funcL(int n1, int n2, int &iterator) {
	Node* curr = head;
	if (n1 == 0 && n2 == 0) {
		int i = 1;
		curr = head->next;
		while (curr != tail) {
			cout << '\n' << i << "> " << curr->data << '\n';
			curr = curr->next;
			i++;
		}
		iterator--;
	}
	else if (n2 == 0) {
		int i;
		for (i = 0; i < n1; i++)
			curr = curr->next;
		cout << '\n' << i << "> " << curr->data << '\n';
		iterator--;
	}
	else {
		int i;
		for (i = 0; i < n1; i++)
			curr = curr->next;
		for (int i = n1; i <= n2; i++) {
			cout << '\n' << i << "> " << curr->data << '\n';
			curr = curr->next;
		}
		iterator--;
	}
	return;
}

void EditorList::funcA(int &iterator) {
	Node* curr = head;
	for (int i = 0; i < iterator; i++)
		curr = curr->next;
	string s;
	cout << '\n' << iterator << "> ";
	getInput(s);
	if (head->next == tail) {
		insertAtPos(1 , s);
		return;
	}
	curr->data = curr->data + s;
	return;
}

void EditorList::funcE() {
	ofstream fname;
	string extra=fileName;
	fileName = "";
	int i = 0;
	while (i<extra.length() && extra[i] != '`') {
		fileName = fileName + extra[i];
		i++;
	}
	i = 1;
	fileName = fileName + ".txt";
	fname.open(fileName);
	Node* curr = head->next;
	fname << "Total Count : " << count<<'\n';
	while (curr != tail) {
		fname << '\n' << i << "> " << curr->data << '\n';
		curr = curr->next;
		i++;
	}
}

void EditorList::edit() {
	int iterator = 1;
	int n1, n2;
	bool isFunction = false;
	string temp;
	do {
		n1 = 0;
		n2 = 0;
		cout << '\n' << iterator << "> ";
		getInput(temp);
		stoi(temp, n1, n2);
		isFunction=checkWhichFunction(temp,n1,n2,iterator);
		if (isFunction == false)
			insertAtPos(iterator, temp);
		iterator++;
	} while (temp != "e" && temp != "E");
	return;
}

EditorList::~EditorList() {
	Node* curr = head;
	Node* nxt = NULL;
	while (curr != NULL) {
		nxt = curr->next;
		delete curr;
		curr = nxt;
	}
	head = NULL;
	tail = NULL;
}