#include <iostream>
#include <sstream>
#include <string>
#include "Vigenere.cpp"

using namespace std;

int main (){

  string mensaje,clave;
  int caso,tipo;
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
        cout<<"Escribe el tipo de alfabeto: "<<endl;
        cout<<"1. Numerico"<<endl;
        cout<<"2. ASCII"<<endl;
        cout<<"3. HEX(error)"<<endl;
        cin>>tipo;
        system("cls");
        cout<<"Mensaje:"<<endl;
        cout<<emisor.Cifrar(mensaje,tipo)<<endl;
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
        cout<<"Escribe el tipo de alfabeto: "<<endl;
        cout<<"1. Numerico"<<endl;
        cout<<"2. ASCII"<<endl;
        cout<<"3. HEX(error)"<<endl;
        cin>>tipo;
        system("cls");
        cout<<"Mensaje:"<<endl;
        cout<<receptor.Descifrar(mensaje,tipo)<<endl;
        system("Pause");
  			break;
      }
    }
  }
  return 0;
}
