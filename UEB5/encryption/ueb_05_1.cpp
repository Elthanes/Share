#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, string key)
{
	string result;
	int i=0;
	int s=0;
	for(i=0; i<text.length();i++){
		result = result + char(int(text[i])-int(key[i-s]));
		if (i-s == key.length()-1){
			s += key.length();
		}
		}
	//Ihre Loesung

	return result;
}

string decrypt(string text, string key)
{
	string result;
	int i;
	int s=0;
	for(i=0; i<text.length();i++){
		result = result + char(int(text[i])+int(key[i-s]));
		if (i-s == key.length()-1){
			s += key.length();
		}
		}
	
	return result;
}

/** Hier beginnt das Hauptprogramm */
int main(int argc, char* argv[])
{
	string text = "Dies ist irgendein Text.";
	string key  =  "irgendein Passwort";
	cout << encrypt(text,key);
	cout << endl;
	cout << decrypt(encrypt(text,key),key); // zum Testen
	
	//Ihre Loesung
		
	return 0;
}
