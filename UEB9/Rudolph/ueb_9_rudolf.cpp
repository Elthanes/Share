#include "ueb_9_rudolf.h"

/************************************************************************/
/* Klasse ListElem                                                      */
/************************************************************************/

ListElem::ListElem(string data)
{
	this->data = data;
	next = NULL;
	prev = NULL;
}

string ListElem::getData(void) const
{
	return data;
}

void ListElem::setNext(ListElem* elem)
{
	next = elem;
}

ListElem* ListElem::getNext() const
{
	return next;
}

void ListElem::setPrev(ListElem* elem)
{
	prev = elem;
}

ListElem* ListElem::getPrev() const
{
	return prev;
}

/************************************************************************/
/* Klasse List                                                          */
/************************************************************************/

List::List()
{
	first = NULL;
}

List::~List()
{
	while (!isEmpty()) 
	{
		removeFirst();
	}
}

//am Ende anhängen
void List::append(string data)
{
	ListElem *newElem = new ListElem(data);
	if(!isEmpty())
	{
		ListElem *curr = first;
		while(curr->getNext() != NULL)
		{
			curr = curr->getNext();
		}
		curr->setNext(newElem);
		newElem->setPrev(curr); //
	}
	else
	{
		first = newElem;
	}
}


// Löschen am Anfang
void List::removeFirst(void)
{
	if ( isEmpty() ) return;

	// Zu löschendes Element
	ListElem* delElem = first;

	first = first->getNext();
	if(first != NULL)
	{
		first->setPrev(NULL);
	}
	delete delElem;    // lösche Listenelement
	
	
}

//Element ans Ende schieben
void List::moveToEnd(ListElem* elemMove)
{
	if(!isEmpty())
	{
		if ( elemMove != NULL ) 
		{
			//Zwei neue Pointer: Der Vorgänger des zu verschiebenden...
			ListElem* elemPrev = elemMove->getPrev();
			//...und der Nachfolger
			ListElem* elemNext = elemMove->getNext();

			/************************************************************************/
			/* Beginn Aufgabenstellung a) (Teil moveToEnd)                          */
			/************************************************************************/
			if (elemNext != NULL){
				elemPrev->setNext(elemNext);
				elemNext->setPrev(elemPrev);
				ListElem *curr = elemNext;
				while(curr->getNext() != NULL){
					curr = curr->getNext();
				}
				curr->setNext(elemMove);
				elemMove->setNext(NULL);
			}
			//...

			/************************************************************************/
			/* Ende Aufgabenstellung a) (Teil moveToEnd)                            */
			/************************************************************************/

		}
	}
}


//Element an den Anfang schieben 
void List::moveToFront(ListElem* elemMove)
{
	//Wenn die Liste nicht leer ist...
	if (!isEmpty())
	{
		//Kann eigentlich nicht passieren, aber sicher ist sicher...
		if ( elemMove != NULL ) 
		{
			//Zwei neue Pointer: Der Vorgänger des zu verschiebenden...
			ListElem* elemPrev = elemMove->getPrev();
			//...und der Nachfolger
			ListElem* elemNext = elemMove->getNext();

			/************************************************************************/
			/* Beginn Aufgabenstellung  a) (Teil moveToFront)                       */
			/************************************************************************/
			if (elemPrev != NULL){
			elemPrev->setNext(elemNext);
			elemNext->setPrev(elemPrev);
			elemMove->setPrev(NULL);
			elemMove->setNext(first);
			elemMove->getNext()->setPrev(elemMove);
			first = elemMove;
			}
			//...

			/************************************************************************/
			/* Ende Aufgabenstellung  a) (Teil moveToFront)                         */
			/************************************************************************/
		}
	}
}


//Element an den Anfang schieben: Die Funktion wird in der main-Methode aufgerufen, 
//ihr wird ein string übergeben. Sie sucht in der Liste das Listenelement, welches
//den gesuchten String enthält. Wenn kein solches Listenelement vorhanden ist, 
//gibt sie dies aus. 
//Wurde das passende Element gefunden, wird moveToFront(ListElem* moveElem) aufgerufen. 
void List::moveToFront(const string& s)
{
	if (!isEmpty())
	{
		// Aktuelles Element 
		ListElem* e = find(s);
		if (e != NULL) {
			moveToFront(e);
		} else {
			cout << "Zu verschiebendes Element nicht gefunden!" << endl;
		}
	}
}

//Element ans Ende schieben: Die Funktion wird in der main-Methode aufgerufen, 
//ihr wird ein string übergeben. Sie sucht in der Liste das Listenelement, welches
//den gesuchten String enthält. Wenn kein solches Listenelement vorhanden ist, 
//gibt sie dies aus. 
//Wurde das passende Element gefunden, wird moveToEnd(ListElem* moveElem) aufgerufen. 

void List::moveToEnd(const string& s)
{
	if (!isEmpty())
	{
		ListElem* e = find(s);
		if (e != NULL) 
		{
			moveToEnd(e);
		}
		else 
		{
			cout << "Zu verschiebendes Element nicht gefunden!" << endl;
		}
	}
}


ListElem* List::find(const string &d)
{
	ListElem* result = first;
	while ( result != NULL && result->getData() != d ) 
	{
		result = result->getNext();
	}
	return result;
}

const ListElem* List::getFirst()
{ 
	return first; 
}

bool List::isEmpty(void) 
{ 
	return first == NULL; 
}

//Global deklarierte Funktionen zum Ausgeben der Liste (Von vorn nach hinten)
void printList(List &list)
{
	const ListElem* curr; // Zeiger auf das aktuelle Element
	curr = list.getFirst();// Beginne beim ersten Element
	cout << "Rentier --- ";
	while( curr != NULL ) 
	{
		// tu etwas mit dem Element (hier ausdrucken)
		cout << curr->getData() << " --- ";
		// gehe zum nächsten Listenelement
		curr = curr->getNext();
	}
	cout << endl;
}

//Global deklarierte Funktion zum Ausgeben der Liste (Von hinten nach vorn)
void printListBackwards(List &list)
{
	const ListElem* curr; // Zeiger auf das aktuelle Element
	curr = list.getFirst();// Beginne beim ersten Element
	while( curr->getNext() != NULL ) 
	{
		// gehe zum nächsten Listenelement
		curr = curr->getNext();
	}
	//jetzt sind wir ganz hinten, also gib die Daten aus und geh eins vorwärts
	while(curr->getPrev() != NULL)
	{
		cout << curr->getData() << " --- ";
		curr = curr->getPrev();
	}
	cout << curr->getData() << " ";
	cout << " --- Rentier";	
	cout << endl;
}

int main(void)
{
	List gespann; // Das Rentiergespann, noch ohne Schlitten...
	
	gespann.append("A");	//Schlitten für Dorf A
	gespann.append("B");	//Schlitten für Dorf B
	gespann.append("C");	//Schlitten für Dorf C
	gespann.append("D");	//Schlitten für Dorf D

	cout << "Rentiergespann zu Beginn der Ausfahrt...\n";
	printList(gespann);
	printListBackwards(gespann);
		
	/************************************************************************/
	/* AUFGABENTEIL b)                                                      */
	/************************************************************************/
	gespann.moveToFront("C");
	gespann.moveToEnd("B");
	
	cout << "Rentiergespann nach erfolgreichem Umsortieren der Schlitten...\n";
	printList(gespann);
	printListBackwards(gespann);

	return 0;

}
