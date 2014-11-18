#include <iostream>
#include <string>

using namespace std;

int querProdukt(int zahl)
{
	int qp=1;
	while ( zahl != 0){
		qp *= zahl % 10;
		zahl = zahl/10;
	}
	return qp;
	     //Hier muss Ihre Lösung hin!
}

int querSumme(int zahl)
{
	int qs=0;
	while ( zahl != 0){
		qs += zahl % 10;
		zahl = zahl/10;
	}
	return qs;
	
}

void produktGleichQuadratsumme(int start, int ende)
{
	for (int i=start; i<=ende; i++){
		if ((querSumme(i)*querSumme(i)) == querProdukt(i))
			cout << i << endl;
		}

}

/** Dies ist der Einstiegspunkt des Programms. */
int main(int argc, char* argv[]) {

	int myZahl=432;
	int qP=querProdukt(myZahl);
	int qS=querSumme(myZahl);
	
	cout <<" Querprodukt: " << qP << endl; //Für das Bsp. myZahl=432 müsste hier 24 rauskommen
	cout <<" Quersumme: " << qS << endl; //Ergebnis 9
	produktGleichQuadratsumme(100,9999);
	return 0;
}
