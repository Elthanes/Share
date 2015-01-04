#ifndef UEB_10_1_SOL_H
#define UEB_10_1_SOL_H

#include <iostream>
#include <string>

using namespace std;

class ListElem
{
public:
	ListElem(string s);

	string    getData(void) const;
	ListElem* getNext(void) const;
	ListElem* getPrev()     const;

	void setNext(ListElem* elem);
	void setPrev(ListElem* elem);

private:
	string data;
	ListElem *next;
	ListElem *prev;
};

class List
{
public:
	List();
	~List();

	// Einfügen am Anfang
	void append(string data);
	
	// Löschen
	void removeFirst(void);
	
	// Verschieben
	void moveToEnd(const string& s);   
	void moveToFront(const string& s);

	// Abfragen
	bool isEmpty(void); 

	// Zugriff auf Listenelemente
	const ListElem *getFirst();

// PRIVATE MEMBERFUNKTIONEN
private:
	void moveToEnd(ListElem* e);
	void moveToFront(ListElem* e);
	ListElem* find(const string &d);

// PRIVATE MEMBERVARIABLEN
private:
	ListElem* first;
	
};

#endif 