// System header files
#include <iostream>
#include <string>

// Local header files
#include "ueb_11_1_list.h"

// Namespaces used in this file
using namespace std;

// Implementation of the DataElem class
// --------------------------

DataElem::DataElem(int i, string s)
{
	key = i;
	value = s;
}

// Implementation of the ListElem class
// --------------------------

ListElem::ListElem(DataElem* d) 
{
	m_next = NULL;
	m_prev = NULL;
	m_data = d;
}

DataElem* ListElem::getData() 
{ 
	return m_data; 
}

void ListElem::setData(DataElem* data_elem)
{
	m_data = data_elem;
}
	
void ListElem::setNext(ListElem* n) 
{ 
	m_next = n; 
}

ListElem* ListElem::getNext() 
{ 
	return m_next; 
}

void ListElem::setPrev(ListElem* n) 
{ 
	m_prev = n; 
}


ListElem* ListElem::getPrev() 
{ 
	return m_prev; 
}

// Implementation of the List class
// --------------------------

List::List()
{
	m_first = NULL;
	m_last = NULL;
}

List::~List()
{
	ListElem* e = m_first;
	while (e != NULL)
	{
		ListElem* next = e->getNext();
		delete e;
		e = next;
	}
}

void List::init(DataElem* data_elem)
{
	m_first = m_last = new ListElem(data_elem);
	return;
}

ListElem* List::getFirst()
{
	return m_first;
}

ListElem* List::getLast()
{
	return m_last;
}

void List::prepend(DataElem* data_elem)
{
	if (m_first == NULL)
	{
		init(data_elem);
		return;
	}

	ListElem* first = m_first;
	m_first = new ListElem(data_elem);
	m_first->setNext(first);
	first->setPrev(m_first);
}

void List::append(DataElem* data_elem)
{
	if (m_first == NULL)
	{
		init(data_elem);
		return;
	}

	ListElem* last = m_last;
	m_last = new ListElem(data_elem);
	last->setNext(m_last);
	m_last->setPrev(last);
}

void List::insert(DataElem* data_elem, ListElem* list_elem)
{
	if (list_elem == m_last)
	{
		append(data_elem);
		return;
	}

	ListElem* new_elem = new ListElem(data_elem);
	new_elem->setPrev(list_elem);
	new_elem->setNext(list_elem->getNext());
	(list_elem->getNext())->setPrev(new_elem);
	list_elem->setNext(new_elem);
}

void List::removeFirst()
{
	if (m_first == NULL)
		return;

	ListElem* first = m_first;
	m_first = m_first->getNext();
	m_first->setPrev(NULL);
	delete first;
}

void List::removeLast()
{
	if (m_last == NULL)
		return;

	ListElem* last = m_last;
	m_last = m_last->getPrev();
	m_last->setNext(NULL);
	delete last;
}

void List::remove(ListElem* list_elem)
{
	if (list_elem == m_first)
	{
		removeFirst();
		return;
	}
	else if (list_elem == m_last)
	{
		removeLast();
		return;
	}
	
	(list_elem->getPrev())->setNext(list_elem->getNext());	
	(list_elem->getNext())->setPrev(list_elem->getPrev());
	delete list_elem;
}
