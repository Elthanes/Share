#include <iostream>
#include <string>

using namespace std;

/** Vervollständigen Sie die Methode berechnePotenz mit Hilfe von Rekursionen */
int berechnePotenz(int a, int n)
{  
	if (n > 0){
		a*=berechnePotenz(a,n-1);
	}else{
		a=1;
	}
	return a;
}   

/** Dies ist der Einstiegspunkt des Programms. Hier soll nichts verändert werden! */
int main(int argc, char* argv[]) {

    int a=0;
    int n=0;
    int ergebnis=0;

    cout << "Geben Sie einen Wert >0 fuer a ein: ";
    cin >> a;

    cout << "Geben Sie einen Wert >0 fuer n ein: ";
    cin >> n;

    ergebnis=berechnePotenz(a,n);
    cout << "Ergebnis: " << ergebnis << endl;

return 0;


}
