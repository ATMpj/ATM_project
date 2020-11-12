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

	void addHead(Datatype);
	void addTail(Datatype);
	void addAfter(Node <Datatype>*, Datatype);
	Node <Datatype>* search(Datatype);
	Node <Datatype>* searchPre(Datatype);

	void removeHead();
	void removeTail();
	void removeAfter(Node <Datatype>*);
	void remove(Datatype);
	void clear();

	void display();
};

