#include "Node.h"

/*******************************************************
* @Description Khoi tao mot Node moi co gia tri la Data
********************************************************/
template <class Datatype>
Node< Datatype>::Node(Datatype data)
{
	_data = data;
	_pNext = NULL;
}
/*******************************************************
* @Description Hien thi gia tri Node
********************************************************/
template <class Datatype>
void Node< Datatype>::display()
{
	cout << _data << endl;
}