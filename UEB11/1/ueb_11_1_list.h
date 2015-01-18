#include <string>

#ifndef UEB_11_1_LIST_HPP
#define UEB_11_1_LIST_HPP

/** This is a simple type containing 
    only one member variable. */
class DataElem
{
public:

	/** Constructor */
	DataElem(int i, std::string s);
	
	/** Some value... */
	int key;
	
	/** A string */
	std::string value;
};

/** This class implements the list element 
    data structure. */
class ListElem 
{
public:

	/** Constructor */
	ListElem(DataElem* d);
	
	/** This function returns a pointer to the data 
	    element. */
	DataElem* getData();
	
	/** This function sets the data element. */
	void setData(DataElem* data_elem);
	
	/** This function sets the pointer to the next 
	    list element. */
	void setNext(ListElem* n);
	
	/** This function returns a pointer to the next 
	    list element */
	ListElem* getNext();

	/** This function sets the pointer to the previous 
	    list element. */
	void setPrev(ListElem* n);
	
	/** This function returns a pointer to the previous 
	    list element */
	ListElem* getPrev();
	
private:

	/** Pointer to the data element */
	DataElem* m_data;
	
	/** Pointer to the next list element */
	ListElem* m_next;
	
	/** Pointer to the previous list element */
	ListElem* m_prev;
};

/** This class implements the list 
    data structure. */
class List
{
public:

	/** Constructor */
	List();

	/** Destructor */
	~List();

	/** This function initializes an empty list. */
	void init(DataElem* data_elem);

	/** This function returns the first element. */
	ListElem* getFirst();

	/** This function returns the last element. */
	ListElem* getLast();

	/** This function adds one element at the beginning. */
	void prepend(DataElem* data_elem);
	
	/** This function adds one element at the end. */
	void append(DataElem* data_elem);

	/** This function inserts one element after list_elem. */
	void insert(DataElem* data_elem, ListElem* list_elem);

	/** This function removes the first element. */
	void removeFirst();

	/** This function removes the last element. */
	void removeLast();

	/** This function removes element list_elem. */
	void remove(ListElem* list_elem);

private:

	/** Pointer to the first list element */
	ListElem* m_first;
	
	/** Pointer to the last list element */
	ListElem* m_last;	
};

#endif
