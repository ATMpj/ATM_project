#pragma once
#include <iostream>
using namespace std;

template <class Datatype>
class Node
{
private:
	Datatype _data;
	Node* _pNext;
public:
	Node ( Datatype data);
	void display();
};

