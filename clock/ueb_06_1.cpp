#include <iostream>

using namespace std;

int gradM(int a){
	int r; // Rueckgabe Variable
	r = 6*a;
	return r;
}

float gradH(int a, int b){
	float r; // Rueckgabe Variable
	if (a > 12){
		a = a-12;
	}
	r = a*30;
	r += b*0.5;
	return r;
}

float berechner(int a, float b){ 
	float r; // Rueckgabe Variable
	if (a >= b){
		r = a-b;
	}else{
		r = b-a;
	}
	if (r > 180){
		r = 360-r;
	}
	return r;
}

int main(){
	int stunden = -1;
	int minuten = -1;
	while ((stunden > 23) || (stunden <0)){
		cout << "Bitte geben sie die Stundenzahl ein" << endl;
		cin >> stunden;
		cout << endl;	
	}
	while ((minuten > 59) || (minuten <0)){
		cout << "Bitte geben sie die Minutenzahl ein" << endl;
		cin >>minuten;
		cout << endl;	
	}
	cout << "Die Zeiger haben einen Winkel von " << berechner(gradM(minuten),gradH(stunden,minuten)) << " Grad";
	return 0;
}