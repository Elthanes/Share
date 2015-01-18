// System header files
#include <iostream>
#include <string>

// Eine Listenstruktur
#include "ueb_11_1_list.h"

using namespace std;
int anz=0;
/** Die Klasse bildet eine Struktur, die integer-Schlüssel auf string-Objekte abbildet und
Kollisionen durch verkettete Listen behandelt. */
class HashMap
{
public:

	/** Der Konstruktor 
	n ist die Größe des Arrays, das von der Hashfunktion benutzt wird. */
	HashMap(int n)
	{
		m_array = new List[n];
		m_size = n;
	}
	
	/** Der Destruktor */
	~HashMap()
	{
		for (int i = 0; i < m_size; i++)
			for (ListElem* e = m_array[i].getFirst(); e != NULL; e = e->getNext())
				delete e->getData();
		delete [] m_array;
	}
		
	/** Gibt die HashMap aus. */
	void print()
	{
		for (int i = 0; i < m_size; i++)
		{
			cout << "[" << i << "] ";
			for (ListElem* e = m_array[i].getFirst(); e != NULL; e = e->getNext())
				cout << "-> (" << e->getData()->key << ", "
				     << e->getData()->value << ") ";
			cout << "\n";
		}
	}

	/** Liefert den Wert zum angegebenen Key zurück */
	string get(int key)
	{
		/************************************************************************/
		/* Aufgabenteil a)                                                      */
		for (ListElem* e = m_array[key%m_size].getFirst(); e!=NULL; e = e->getNext())
		{
				if ((e->getData()->key) == key)
					return e->getData()->value;
		}
		/************************************************************************/
		return "?!";				
	}

	/** Fügt den Schlüssel key mit der Zeichenkette value zur HashMap hinzu */
	void put(int key, string value)
	{
		/************************************************************************/
		/* Aufgabenteil a)														 */
		m_array[key%m_size].append(new DataElem(key,value));
		/************************************************************************/
	}

private:

	/** 
		Ein Array, welches Listen von DataElems speichert. Siehe ueb_13_1_list.hpp */
	List* m_array;

	/** Die Größe des Arrays. */
	int m_size;
};


//Enumeration zur Unterscheidung zwischen den Sondierungsverfahren
enum Method {LINEAR, QUADRATIC, DOUBLE};

/** Die Klasse bildet eine Struktur, die integer-Schlüssel auf string-Objekte abbildet und
dazu verschiedene Sondierungsverfahren benutzt. */
class NewHashMap
{
public:

	/** Der Konstruktor 
	n ist die Größe des Arrays, das von der Hashfunktion benutzt wird. 
	method ist das Sondierungsverfahren. */
	NewHashMap(int n, Method method)
	{
		/**************************************************************************/
		/* Aufgabenteil b)                                                        */
		m_array = new DataElem*[n];
		m_size = n;
		m_method = method;
		for (int i=0; i<n;i++)
			m_array[i]=NULL;
		/**************************************************************************/
		//Membervariablen initialisieren
		//Speicherplatz allokieren etc.
		//...		
	}

	/** Der Destruktor */
	~NewHashMap()
	{
		/**************************************************************************/
		/* Aufgabenteil b)                                                        */
		for (int i = 0; i < m_size; i++){
			delete m_array[i];
		}	
		delete [] m_array;
		/**************************************************************************/
		//Speicherplatz freigeben etc.
		//...	
	}

	/** Gibt die HashMap aus. */
	void print()
	{
		for (int i = 0; i < m_size; i++)
			if (m_array[i] != NULL)
				cout << "(" << m_array[i]->key << ", "
				<< m_array[i]->value << ")\n";
			else
				cout << "(-, -)\n";
	}

	/** Liefert den Wert zum angegebenen Key zurück */
	string get(int key)
	{
		/**************************************************************************/
		/* Aufgabenteil b)          			*/
		for (int i=0;i<100;i++){
			if (m_method == LINEAR){
				if (m_array[(key+i)%m_size] != NULL){
					return m_array[(key+i)%m_size]->value;
				}
			}
			if (m_method == QUADRATIC){
				if (m_array[(key+(i*i))%m_size] != NULL){
					return m_array[(key+(i*i))%m_size]->value;
				}
			}
			if (m_method == DOUBLE){
				if (m_array[(key+(key*i))%m_size] == NULL){
					return m_array[(key+(key*i))%m_size]->value;
				}
			}
		}
		/**************************************************************************/
		//Element suchen
		//solange nicht gefunden, je nach Sondierungsmethode weitersuchen.
		//...	
		return "Value?!"; //Muss geändert werden.			
	}

	/** Fügt den Schlüssel key mit der Zeichenkette value zur HashMap hinzu */
	void put(int key, string value)
	{
		/**************************************************************************/
		/* Aufgabenteil b)          		*/
		
		for (int i=0; i < 100 ;i++){
			if (key == 4)
				anz++;
			if (m_method == LINEAR){
				if (m_array[(key+i)%m_size] == NULL){
					m_array[(key+i)%m_size] = new DataElem(key,value);
					return;
				}
			}
			if (m_method == QUADRATIC){
				if (m_array[(key+(i*i))%m_size] == NULL){
					m_array[(key+(i*i))%m_size] = new DataElem(key,value);
					return;
				}
			}
			if (m_method == DOUBLE){
				if (m_array[(key+(key*i))%m_size] == NULL){
					m_array[(key+(key*i))%m_size] = new DataElem(key,value);
					return;
				}
			}
		}
		/**************************************************************************/
		//Index berechnen
		//Wenn Kollision, dann je nach Sondierungsmethode weiter springen.
		//Wenn freier Platz gefunden: Einordnen.
		
	}

private:

	/** Array, welches DataElems speichert */
	DataElem** m_array;

	/** Die Größe des Arrays */
	int m_size;

	/** Die gewählte Sondierungsmethode */
	Method m_method;
};



int main(int argc, char* argv[])
{
	// Anzahl der Elemente, die gespeichert werden sollen
	const int n = 16;

	// Array mit irgendwelchen keys...
	int keys[n]      = {17,     8,      23,       3,        2, 
	                    128,    256,      16,       9,        10, 
	                    4,      0,       99,     5,      7,    1};
											
	// Array mit irgendwelchen Wörtern...
	string values[n] = {"Baum", "Hase", "Wurzel", "Schnee", "Flasche", 
	                    "Gold", "Beamer", "Papier", "Schere", "Kreide", 
	                    "Buch", "Apfel", "Zahl", "Heft", "CD", "Kabel"};
	
	/************************************************************************/
	/* Aufruf Aufgabenteil a)                                               */
	/************************************************************************/
	// Das HashMap Objekt
	HashMap map(8);                       

	/************************************************************************/
	/* Aufruf Aufgabenteil b)                                               */
	/************************************************************************/
	NewHashMap mapH(25, QUADRATIC);         
	
	// Hier werden die Elemente in die HashMap gesteckt (key/value - Paare).
	for (int i = 0; i < n; i++){
		map.put(keys[i], values[i]);	
		mapH.put(keys[i], values[i]);	
	}
	// Print array to terminal;
	cout << "Map content: \n";
	map.print();
	cout << endl;
	cout << "Map content: \n";
	mapH.print();
	cout << anz;
	return 0;
}
