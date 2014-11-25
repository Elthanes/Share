#include <iostream>

using namespace std;

void swapIt(int& r_x, int& r_y)
{
	int temp;
	temp = r_x;
	r_x = r_y;
	r_y = temp;
}

int main()
{
	int x=5;
	int y=10;
	int& r_x = x;
	int& r_y = y;
	cout << "Vorher: x= "<< x << " y = " << y << endl;
	swapIt (r_x,r_y);
	cout << "Nachher: x= "<< x << " y = " << y << endl;

	return 0;
}
