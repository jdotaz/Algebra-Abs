#include <iostream>
#include <fstream>
#include <string.h>
#include<time.h>
#include "funciones.h"
#include "libro.h"

using namespace std;


int main (){
	int ejercicio;
	bool bucle=true;
	int h;
	while (bucle) {
		system("cls");
		cout << "Seleccione un ejercicio." << endl;
		cout << " 1.Ejercicio 1. " << endl;
		cout << " 2.Ejercicio 2. " << endl;
		cout << " 3.Ejercicio 3. " << endl;
		cout << " 4.Ejercicio 4. " << endl;
		cout << " 5.Ejercicio 5. " << endl;
		cout << " 6.Ejercicio 6. " << endl;
		cout << " 7.Ejercicio 7. " << endl;
		cout << " 8.Ejercicio 8. " << endl;
		cout << " 9.Ejercicio 9. " << endl;
		cout << " 10.Ejercicio 10. " << endl;
		cout << " 11.Ejercicio 11. " << endl;
		cout << " 12.Ejercicio 12. " << endl;
		cout << " 13.Ejercicio 13. " << endl;
		cout << " 14.Ejercicio 18.7. " << endl;
		cout << " 15.Ejercicio 18.11. " << endl;
		cout << " 16.Ejercicio 18.12. " << endl;
		cout << " 17.Ejercicio 18.19. " << endl;
		cout << " 18.Ejercicio 18.21. " << endl;
		cout << " 19.Ejercicio 18.22. " << endl;
		cout << " 20.Ejercicio 18.27. " << endl;
		cout << "Opcion: ";
		cin >> ejercicio;

		switch (ejercicio) {
		case 1: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 1: " << endl << endl;
			string x;
			getline(cin, x);
			char* c = StrToChar1(x);
			for (int i = 0; i < x.length(); i++) {
				cout << *(c + i);
			}
			cout << endl << CharToStr1(c, x.length()) << endl;
			system("Pause");
			break;

		}
		case 2: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 2: " << endl << endl;
			cout << "La funcion size devuelve la longitud de la cadena(el n�mero de elementos que 	posee), mientras que la funcion capacity devuelve el tama�o del espacio de 	almacenamiento asignado, este suele ser mayor o igual ya que se le asigna mas 	almacenamiento del necesario para facilitar su edici�n.  " << endl;
			system("Pause");
			break;
		}
		case 3: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 3: " << endl << endl;
			string x;
			getline(cin, x);
			cout << MinMay3(x) << endl;
			system("Pause");
			break;
		}
		case 4: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 4: " << endl << endl;
			int x, y;
			cin >> x;
			cin >> y;
			cout << concat4(x, y) << endl;
			cout << doble4(concat4(x, y)) << endl;
			system("Pause");
			break;
		}
		case 5: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 5: " << endl << endl;
			cout << caracteres5() << endl;
			system("Pause");
			break;
		}
		case 6: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 6: " << endl << endl;
			aprobar6();
			system("Pause");
			break;
		}
		case 7: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 7: " << endl << endl;
			string x, y;
			getline(cin, x);
			getline(cin, y);
			cout << "cantidad: " << busqueda7(x, y) << endl;
			system("Pause");
			break;
		}
		case 8: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 8: " << endl << endl;
			string x;
			getline(cin, x);
			imprimir8(x);
			system("Pause");
			break;
		}
		case 9: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 9: " << endl << endl;
			string x, y;
			getline(cin, x);
			getline(cin, y);
			cout << mitad9(x, y) << endl;
			system("Pause");
			break;
		}
		case 10: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 10: " << endl << endl;
			string x, y, z;
			getline(cin, x);
			getline(cin, y);
			getline(cin, z);
			cout << reemplazo10(x, y, z) << endl;
			system("Pause");
			break;
		}
		case 11: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 11: " << endl << endl;
			string x, y;
			getline(cin, x);
			getline(cin, y);
			cout << lexico11(x, y) << endl;
			system("Pause");
			break;
		}
		case 12: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 12: " << endl << endl;
			bool incorrecto=true;
			while (incorrecto) {
				cin >> h;
				if (h <= 10 and h >= 1) {
					incorrecto = false;
				}
				if (incorrecto) {
					cout << "Numero incorrecto, vuelvalo a escribir:";
				}
			}
			randomf12(h);
			system("Pause");
			break;
		}
		case 13: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 13: " << endl << endl;
			printtxt13();
			system("Pause");
			break;
		}
		case 14: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 18.7: " << endl << endl;
			string x;
			getline(cin, x);
			cout<<rot13(x)<<endl;
			string y;
			getline(cin, y);
			cout << unrot13(y) << endl;
			system("Pause");
			break;
		}
		case 15: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 18.11: " << endl << endl;
			string x,y;
			getline(cin, x);
			getline(cin, y);
			cout<<concatNombre(x, y)<<endl;
			system("Pause");
			break;
		}
		case 16: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 18.12: " << endl << endl;
			string x;
			getline(cin, x);
			ahorcado(x);
			system("Pause");
			break;
		}
		case 17: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 18.19: " << endl << endl;
			string x;
			getline(cin, x);
			cout<<alMedio(x)<<endl;
			system("Pause");
			break;
		}
		case 18: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 18.21: " << endl << endl;
			string x;
			getline(cin, x);
			char* y = StrToChar1(SinPuntuacion(x));
			tokens(y);
			system("Pause");
			break;
		}
		case 19: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 18.22: " << endl << endl;
			string x;
			getline(cin, x);
			cout << reves(x) << endl;
			system("Pause");
			break;
		}
		case 20: {
			system("cls");
			cin.ignore();
			cout << " Ejercicio 18.27: " << endl << endl;
			const int y = 5;
			string x[y];
			for (int i = 0; i < y; i++) {
				cin >> x[i];
			}
			seleccion(x, y);
			system("cls");
			for (int i = 0; i < y; i++) {
				cout<<x[i]<<endl;
			}
			system("Pause");
			break;
		}
		}
	}

	return 0;
}
