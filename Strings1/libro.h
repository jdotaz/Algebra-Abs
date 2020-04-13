#include <iostream>
#include <fstream>
#include <string.h>
#include<time.h>

using namespace std;

string rot13(string x,int clave = 13) {
	int y;
	for (int i = 0; i < x.length(); i++) {
		if (x[i] >= 65 and x[i] <= 90) {
			y = x[i] + clave;
			if(y>90){
				y -= 26;
			}
			x[i] = static_cast<char>(y);
		}
		if (x[i] >= 97 and x[i] <= 122) {
			y = x[i] + clave;
			if (y > 122) {
				y -= 26;
			}
			x[i] = static_cast<char>(y);
		}
	}
	return x;
}

string unrot13(string x,int clave=13) {
	int y;
	for (int i = 0; i < x.length(); i++) {
		if (x[i] >= 65 and x[i] <= 90) {
			y = x[i] - clave;
			if (y < 65) {
				y += 26;
			}
			x[i] = static_cast<char>(y);
		}
		if (x[i] >= 97 and x[i] <= 122) {
			y = x[i] - clave;
			if (y < 97) {
				y += 26;
			}
			x[i] = static_cast<char>(y);
		}
	}
	return x;
}

string concatNombre(string nombre, string apellido) {
	return nombre + " " + apellido;
}

void imprimirMuneco(int _errores) {
	if (_errores == 1) {
		cout << "  0  " << endl;
	}
	if (_errores == 2) {
		cout << "  0  " << endl;
		cout << "  |  " << endl;
	}
	if (_errores == 3) {
		cout << "  0  " << endl;
		cout << " /|  " << endl;
	}
	if (_errores == 4) {
		cout << "  0  " << endl;
		cout << " /|/ " << endl;
	}
	if (_errores == 5) {
		cout << "  0  " << endl;
		cout << " /|/ " << endl;
		cout << " /   " << endl;
	}
	if (_errores == 6) {
		cout << "  0  " << endl;
		cout << " /|/ " << endl;
		cout << " / / " << endl;
	}
}

void ahorcado(string x) {
	string palabra(x.length(), '*');
	string intento;
	string rmpl=x;
	int errores=0;
	int i = 7;
	bool ganar = false;
	while(i > 0) {
		system("cls");
		imprimirMuneco(errores);
		cout << palabra << endl << "Tienes " << i << " intentos: ";
		cin >> intento;
		if (x.find(intento) == -1) {
			errores++;
		}
		else {
			while (x.find(intento) != -1 and rmpl.find(intento) != -1) {
				palabra.replace(rmpl.find(intento), 1, intento);
				rmpl.replace(rmpl.find(intento), 1, "*");
			}
			i++;
		}
		i--;
		if (palabra == x) {
			i = 0;
			ganar = true;
		}
	}
	if (ganar) {
		cout << "Ganaste!!" << endl;
	}
	else {
		cout << "Perdiste :(" << endl;

	}
}

string alMedio(string x) {
	x.insert(x.length() / 2, "******");
	return x;
}

string SinPuntuacion(string x) {
	string exep[] = { ".",",",";",":","-","_","�","?","�","!","{","}","(",")","[","]","''","*","/" };//isalph
	for (int i = 0; i < 19; i++) {
		while (x.find(exep[i]) != string::npos) {
			x.replace(x.find(exep[i]), 1, " ");
		}
	}
	return x;
}

void tokens(char*c) {
	char* pch;
	pch = strtok(c, " ");
	while (pch != NULL) {
		cout << pch << endl;
		pch = strtok(NULL, " ");
	}
}

string reves(string x) {
	string str;
	string::const_iterator iterador1 = x.end()-1;
	while (iterador1 != x.begin()) {
		str.push_back(*iterador1);
		iterador1--;
	}
	str.push_back(*x.begin());
	return str;
}

void swapx(string arr[], int x, int y){
	string c = arr[x];
	arr[x] = arr[y];
	arr[y] = c;
}

void seleccion(string arr[], int tam) {
	for (int i = 0; i < tam-1; i++) {
		int guar = i;
		for (int j = i + 1; j < tam; j++) {
			if (arr[guar] < arr[j]) {
				guar = j;
			}
			swapx(arr, guar, i);
		}
	}
}
