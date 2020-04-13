#include <iostream>
#include <fstream>
#include <string>
#include<time.h>

using namespace std;

char* StrToChar1(string str) {
	int longitud = str.length();
	char* cstr = new char[longitud + 1];
	str.copy(cstr, longitud);
	cstr[longitud] = '\0';
	return cstr;
}

string CharToStr1(char* _cstr, int longitud) {
	string str;
	str.assign(_cstr, longitud);
	return str;
}

string MinMay3(string x) {
	for (int i = 0; i < x.length(); i++) {
		if (x[i] >= 65 and x[i] <= 90) {
			x[i] = tolower(x[i]);
		}
		else if (x[i] >= 97 and x[i] <= 122) {
			x[i] = toupper(x[i]);
		}
	}
	return x;
}

string stringToInt(int x) {
	string str = (to_string(x));
	return str;
}
long IntToString(string x) {
	long n = atoi(x.c_str());
	return n;
}

string concat4(int x, int y) {
	return stringToInt(x) + stringToInt(y);
}
string doble4(string x) {
	long n = IntToString(x) * 2;
	return stringToInt(n);
}

string caracteres5() {
	string obj(1000, 'a');
	return obj;
}

void aprobar6() {
	string x("Yo desaprobe el curso de Algebra Abstracta");
	cout << x << endl;
	x.replace(3, 9, "aprobe");
	cout << x << endl;
}

int busqueda7(string x, string y) {
	int conteo = 0;
	while (x.find(y) != -1) {
		conteo += 1;
		x.erase(x.find(y), y.length());
	}
	return conteo;
}

void imprimir8(string x) {
	string::const_iterator iterador1 = x.begin();
	while (iterador1 != x.end()) {
		cout << *iterador1<< endl;

		iterador1++;
	}

}

string mitad9(string x, string y) {
	x.insert(x.length() / 2, y);
	return x;
}

string reemplazo10(string x, string y, string z) {
	while (x.find(y) != -1) {
		x.replace(x.find(y), y.length(), z);
	}
	return x;
}

string lexico11(string x, string y) {
	if (x > y) {
		return x;
	}
	return y;
}

void randomf12(int n) {
	srand(time(NULL));
	
	fstream nuevo("numeros.txt");
	for (int i = 0; i < n; i++) {
		nuevo << (1 + rand() % 1001) << endl;
	}
}

void printtxt13(int n) {
	ifstream nuevo("numeros.txt");
	int total = 0;
	int numero;
	for(int i=0;i<n;i++){
		nuevo >> numero;
		total += numero;
	}
	cout << total<<endl;
}
