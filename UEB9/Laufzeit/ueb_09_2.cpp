#include <iostream>

// This enables us to use all std definitions directly.
using namespace std;

/** This function returns a Fibonacci number. */
int fib(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	else return fib(n-1)+fib(n-2);
}

int lfib(int n){
	int y,x,aux;
	y=0;
	x=1;
	for(int i=0;i<n;i++){
		aux = y;
		y = x;
		x +=  aux;
	}
	return y;
}

int ifib(int n){
	int f[n+1];
	int i;
	f[0] = 0;
	if (n>0)
	f[1] = 1;
 	for (i = 2; i <= n; i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
   return f[n];
}
/** This is the entry point of the program. */
int main(int argc, char* argv[])
{
	int i = 42;
	cout << "Please wait...\n";
	cout << "fib[" << i << "] = " << ifib(i) << "\n";
	cout << "Please wait...\n";
	cout << "fib[" << i << "] = " << lfib(i) << "\n";
}
