#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <class Datatype>
class LinkedList
{
	Node <Datatype>* _pHead;
	Node <Datatype>* _pTail;
	int _iSize;
public:
	LinkedList();
	~LinkedList();

	void addHead(Datatype data);
	void addTail(Datatype data);
	void addAfter(Node <Datatype>* node, Datatype data);
	Node <Datatype>* search(Datatype data);
	Node <Datatype>* searchPre(Datatype data);

	void removeHead();
	void removeTail();
	void removeAfter(Node <Datatype>* node);
	void remove(Datatype data);
	void clear();

	void display();
};

