#include <iostream>

// This enables us to use all std definitions directly.
using namespace std;

// g_numDiscs is the number of discs. The prefix "g_" is a naming 
// convention for naming global variables.
// "const" means that the variable cannot be changed during the runtime of 
// a program. Such variables (--> constants ;) ) should always be qualified 
// as "const" for safety reasons. 
const int g_numDiscs = 3;

// Variable declarations
// ------------------

// We define a disc array for each pile. Each array 
// element specifies the radius of the corresponding 
// disc. Radius 0 means that no disc is located at 
// the indexed position.
// So each of the three piles can take g_numDiscs discs.
int g_pile_1[g_numDiscs];
int g_pile_2[g_numDiscs];
int g_pile_3[g_numDiscs];

// The g_pile_array contains all three piles
int* g_pile_array[3] = {g_pile_1, g_pile_2, g_pile_3};

//This is what it could look like: 
/**
	g_pile_1: {5, 4, 0, 0, 0}
	g_pile_2: {3, 2, 1, 0, 0}
	g_pile_3: {0, 0, 0, 0, 0}	
	g_pile_array: {{5, 4, 0, 0, 0}, 
	               {3, 2, 1, 0, 0}, 
	               {0, 0, 0, 0, 0}}	
	corresponds to:
	     |            |            |       
	     |            |            |       
	     |           <|>           |       
	 <<<<|>>>>      <<|>>          |       
	<<<<<|>>>>>    <<<|>>>         |       
	-------------------------------------
*/

// Function declarations
// ------------------

/** This is the entry point of the program. */
int main(int argc, char* argv[]);

/** This function should do one recursion step. */
void hanoi(int discs, int from, int to, int aux);

/** This function moves the first disc. */
void move(int from, int to);

/** This function draws the Hanoi system to the terminal. */
void draw();

// Function implementation
// -------------

int main(int argc, char* argv[])
{
	// Fill the first pile:
	for (int i = 0; i < g_numDiscs; i++)
	{
		g_pile_array[0][i] = g_numDiscs-i;
		g_pile_array[1][i] = 0;
		g_pile_array[2][i] = 0;
	}

	//This is what it looks like in the beginning:
	/**     	        
		   <|>           |            |       
	      <<|>>          |            |       
         <<<|>>>         |            |       
       -------------------------------------
	**/

	// This draws the three piles to the terminal
	draw();

	// Now move g_numDiscs from pile0 to pile1, and use the auxiliary pile2
	hanoi(g_numDiscs, 0, 1, 2);
	draw();
	//getchar();
	return 0;
}

void hanoi(int discs, int from, int to, int aux)
{
	// Here, something is missing...
	if(discs >0){
		hanoi(discs-1,from,aux,to);
		move(from,to);
		draw();
		hanoi(discs-1,aux,to,from);	
	}	
	// Use recursion to move "discs" discs from pile 
	// "from" to pile "to", using third pile "aux".
}

void move(int from, int to)
{
	// Here, something is missing...
	int r=0;
	int a=0;
	for (int i=2; i >=0 && a==0; i--){
		if (g_pile_array[from][i] != 0) {
			r = g_pile_array[from][i];
			g_pile_array[from][i] = 0;
			a = 1;
		}
	}
	a=0;
	for (int i=0; i<=2 && a==0; i++){
		if (g_pile_array[to][i] == 0){
			g_pile_array[to][i] = r;
			r = 0;
			a=1;
		}
	}
	// 1) Find the highest disc on pile "from"
	// 2) Remove it and remember radius r
	// 3) Find the lowest free space on pile "to"
	// 4) Add disc with radius r
}


void draw()
{
	for (int i = 0; i < g_numDiscs; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int discs = g_pile_array[j][g_numDiscs-1-i];
			for (int k = g_numDiscs-1; k >= 0; k--) 
				if (k >= discs) cout << " ";
				else cout << "<";
			cout << "|";
			for (int k = 0; k < g_numDiscs; k++) 
				if (k >= discs) cout << " ";
				else cout << ">";
			cout << "  ";
		}
		cout << "\n";
	}
	for (int i = 0; i < g_numDiscs*3*2+(3-1)*2+3; i++) 
		cout << "-";
	cout << "\n\n";
}
