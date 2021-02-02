#include"Node.h"
Node::Node(string d, Node* p, Node* n) {
	data = d;
	next = n;
	prev = p;
}