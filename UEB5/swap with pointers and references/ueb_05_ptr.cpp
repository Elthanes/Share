#include <iostream>

using namespace std;

void swapIt(int* p_x, int* p_y)
{
	int temp;
	temp = *p_x;
	*p_x = *p_y;
	*p_y = temp;
}

int main()
{
	int x=5;
	int y=10;
	int* p_x = &x;
	int* p_y = &y;
	cout << "Vorher: x= "<< x << " y = " << y << endl;
	swapIt (p_x,p_y);
	cout << "Nachher: x= "<< x << " y = " << y << endl;

	return 0;
}
