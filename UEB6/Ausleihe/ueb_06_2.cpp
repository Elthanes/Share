#include <iostream>
#include <string>

using namespace std;

class Book
{
	string m_title;
	string m_author;
	string m_isbn;

public:
	void setTitle(string title){
	m_title = title;
	}
	
	void setISBN(string isbn){
	m_isbn = isbn;
	}
	
	void setAuthor(string author){
	m_author = author;
	}
	
	Book(string title,
	     string author,
	     string isbn)
	{
		setTitle(title);
		setISBN(isbn);
		setAuthor(author);
	}

	string getTitle(){
	return m_title;
	}
	
	string getISBN(){
	return m_isbn;
	}
	
	string getAuthor(){
	return m_author;
	}
	// ...
};

class Student
{
	// array der geliehenen Buecher
	Book* m_book[8];
	
public:
	Student()
	{
		for(int i=0; i<8; i++){
		m_book[i] = NULL;
		}
	}
	
	~Student()
	{
		for(int i=0; i<8; i++){
		delete m_book[i];
		}
		// ...
	}
	
	void addBook(Book& book)
	{
		int a=0; //Check
		for (int i=0;i<8 && a<1;i++){
			if (m_book[i] == NULL){
				m_book[i] = new Book(book);
				a =1; //Check
			}
		}
		// ...
	}

	void removeBook(Book& book)
	{
		int a=0; //Check
		for (int i=0; i<8 and a<1;i++){
			if (m_book[i] != NULL){
				if((m_book[i] -> getISBN()) == (book.getISBN())){
					delete  m_book[i];
					m_book[i] = NULL;
					a=1; //Check
					}
			}
			
			
		}
	}	

	void printBooks()
	{
		for (int i=0;i<8;i++){
			if (m_book[i] != NULL){
			cout << m_book[i] -> getTitle() << endl;
		}
		}
		// ...	
	} 
};

/** This is the entry point of the program. */
int main(int argc, char* argv[])
{
	cout << "----------------\n";;

	Book book_1("Introduction to Algorithms",
	            "Th. Cormen, Ch. Leiserson, R. Rivest", 
	            "0262531968");

	Book book_2("The C++ Programming Language",
	            "Bjarne Stroustrup", 
	            "0201700735");

	Book book_3("Grundkurs Informatik",
	            "H. Ernst", 
	            "3528257172");

	Student student;
	student.addBook(book_1);
	student.addBook(book_2);
	student.addBook(book_3);
	student.printBooks();
	
	cout << "----------------\n";;
	
	student.removeBook(book_2);
	student.printBooks();
	
	cout << "----------------\n";;
	
	return 0;
}
