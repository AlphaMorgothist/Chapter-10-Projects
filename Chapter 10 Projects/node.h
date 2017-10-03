#pragma once 
#include <string>
using namespace std;



#define NODE_H
#include <string>
using namespace std;

class Node {
	friend class List;
	friend class Stack;
public:
	Node(const string &data);
	Node(const int &data);
private: 
	string m_Data;
	int m_intData;
	Node* m_pNext;
};


