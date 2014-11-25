#include <iostream>

int main(){
	int* p_pointer = new int(21);
	std::cout <<"Inhalt Zeigervariable: " << *p_pointer << std::endl;
	delete p_pointer;
	p_pointer = NULL;
	return 0;
}