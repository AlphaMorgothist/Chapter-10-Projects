#include "node.h"
#include <iostream>
using namespace std;

Node::Node(const string &data):
	m_Data(data), m_pNext(NULL)
{}

Node::Node(const int &data):
	m_intData(data), m_pNext(NULL)
{}


