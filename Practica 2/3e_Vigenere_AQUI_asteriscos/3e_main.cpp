#include <iostream>
#include <string>
#include "Vigenere.cpp"

using namespace std;

int main (){
  string mensaje,clave;
  int caso;
	bool bucle=true;
	while (bucle) {
		system("cls");
		cout << "1. Cifrar" << endl;
		cout << "2. Descifrar" << endl;
    cin>>caso;
    switch (caso) {
      case 1:{
        system("cls");
        cin.ignore();
        cout<<"Escribe el mensaje a cifrar: ";
        getline(cin,mensaje);
        cout<<"Escribe la clave: ";
        getline(cin,clave);
        Vigenere emisor(clave);
        system("cls");
        cout<<"Mensaje:"<<endl;
        cout<<emisor.Cifrar(mensaje)<<endl;
        system("Pause");
  			break;
      }
      case 2:{
        system("cls");
        cin.ignore();
        cout<<"Escribe el mensaje a descifrar: ";
        getline(cin,mensaje);
        cout<<"Escribe la clave: ";
        getline(cin,clave);
        Vigenere receptor(clave);
        system("cls");
        cout<<"Mensaje:"<<endl;
        cout<<receptor.Descifrar(mensaje)<<endl;
        system("Pause");
  			break;
      }
    }
  }
  return 0;
}
