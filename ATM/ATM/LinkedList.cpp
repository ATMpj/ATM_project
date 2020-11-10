#include "LinkedList.h"

/*******************************************************
* @Description Ham khoi tao mot LinkedList rong
********************************************************/
template <class Datatype>
LinkedList <Datatype>::LinkedList()
{
	_pHead = NULL;
	_pTail = NULL;
	_iSize = 0;
}

/*******************************************************
* @Description Ham huy
********************************************************/
template <class Datatype>
LinkedList <Datatype>::~LinkedList(){}

/*******************************************************
* @Description Them mot phan tu vao dau LinkedList
* @parameter Gia tri phan tu can them
********************************************************/
template <class Datatype>
void LinkedList <Datatype>::addHead(Datatype data)
{
	Node <Datatype>* pAdd = new Node <Datatype>(data);
	if (_pHead = NULL)
	{
		_pHead = _pTail = pAdd;
	}
	else
	{
		pAdd->_pNext = _pHead;
		_pHead = pAdd;
	}
	_iSize++;
}
/*******************************************************
* @Description Them mot phan tu vao cuoi LinkedList
* @parameter Gia tri phan tu can them
********************************************************/
template <class Datatype>
void LinkedList <Datatype>::addTail(Datatype data)
{
	Node <Datatype>* pAdd = new Node <Datatype>(data);
	if (_pHead = NULL)
	{
		_pHead = _pTail = pAdd;
	}
	else
	{
		_pTail->_pNext = pAdd;
		_pTail = pAdd;
	}
	_iSize++;
}
/************************************************************************
* @Description Them mot phan tu vao sau phan tu Node trong LinkedList
* @parameter Phan tu Node va gia tri phan tu can them
*************************************************************************/
template <class Datatype>
void LinkedList <Datatype>::addAfter(Node <Datatype>* node, Datatype data)
{
	Node <Datatype>* pAdd = new Node <Datatype>(data);
	if (Node != NULL)
	{
		pAdd->_pNext = node->_pNext;
		node->_pNext = pAdd;
		if (node == _pTail)
			_pTail == pAdd;
	}
	else
	{
		addHead(pAdd);
	}
	_iSize++;
}
/************************************************************************
* @Description Tim mot phan tu trong LinkedList Khi biet khoa
* @parameter Gia tri khoa cua phan tu can tim
* @return Tra ve phan tu tim thay, NULL neu khong tim duoc
*************************************************************************/
template <class Datatype>
Node <Datatype>* LinkedList <Datatype>:: search(Datatype data)
{
	Node <Datatype>* p = _pHead;
	while ((p != NULL) && (p->_data != data))
	{
		p = p->_pNext;
	}
	return p;
}
/************************************************************************
* @Description Tim mot phan tu dung truoc node trong LinkedList
* @parameter Phan tu dung truoc phan tu can tim
* @return Tra ve phan tu tim thay, NULL neu khong tim duoc
*************************************************************************/
template <class Datatype>
Node <Datatype>* LinkedList <Datatype>::searchPre(Datatype data)
{
	Node <Datatype>* p = _pHead;
	if (p == node)
		return NULL;
	while ((p != NULL) && (p->_pNext != Node))
	{
		p = p->_pNext;
	}
	return p;
}


template <class Datatype>
void removeHead();
template <class Datatype>
void removeTail();
template <class Datatype>
void removeAfter(Node <Datatype>* data);
template <class Datatype>
void remove(Datatype data);
template <class Datatype>
void clear();


/*******************************************************
* @Description Xuat toan bo du lieu cua LinkedList
********************************************************/
template <class Datatype>
void LinkedList <Datatype>::display()
{
	Node <Datatype>* pWalker = _pHead;
	while (pWalker != NULL)
	{
		pWalker->display();
		pWalker = pWalker->_pNext;
	}
}