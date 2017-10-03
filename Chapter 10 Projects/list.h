#pragma once
#include <string>
#include <Windows.h>
using namespace std;

class Node;

class List {
public: 
	//def constructor
	List();

	//copy constructor
	List(List &other);

	//destructor
	~List();

	//overloaded operator
	void operator + (List &other) {
		Sleep(200);
		List temp;
		temp.m_pHead = m_pHead;
		m_pHead = other.m_pHead;
		other.m_pHead = temp.m_pHead;
		temp.m_pHead = NULL;
	}

	bool Contains(const string &data) const;
	int Count() const;
	void Display() const;
	void Add(const string &data);
	bool Remove(const string &data);
	void Clear();
private:
	//List member node pointer
	Node* m_pHead;
	Node* m_pTail;
};