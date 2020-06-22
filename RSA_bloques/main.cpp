#include <iostream>
#include <NTL/ZZ.h>
#include <stdlib.h>
#include "generador.h"
#include "RSA.cpp"

using namespace std;
using namespace NTL;

int main(){
  system ("color 0F");
  int opcion;
  while (true) {
    system("cls");
    cout<<"         RSA"<<endl;
    cout<<"1.Generador de claves"<<endl;
    cout<<"2.Cifrar un mensaje"<<endl;
    cout<<"3.Descifrar un mensaje"<<endl;
    cout<<"4.Salir"<<endl;
    cout<<"Opcion: ";
    cin>>opcion;
    switch (opcion) {
      case 1:{
        system("cls");
        cout<<"     Generador de claves"<<endl;
        imprimirClaves();
        system("pause");
        break;
      }
      case 2:{
        system("cls");
        cout<<"     Cifrar mensaje"<<endl;
        ZZ clavePublica,Zn;
        cout<<"Ingrese el Zn: ";
        cin>>Zn;
        cout<<"Ingrese la clave Publica: ";
        cin>>clavePublica;
        RSA emisor(Zn,clavePublica);
        cout<<"Ingrese el mensaje: ";
        string mensaje;
        cin.ignore();
        getline(cin,mensaje);
        cout<<"Mensaje cifrado: "<<emisor.Cifrar(mensaje)<<endl;
        system("pause");
        break;
      }
      case 3:{
        system("cls");
        cout<<"     Descifrar mensaje"<<endl;
        ZZ clavePrivada,Zn;
        cout<<"Ingrese el Zn: ";
        cin>>Zn;
        cout<<"Ingrese la clave Privada: ";
        cin>>clavePrivada;
        RSA receptor(Zn,clavePrivada);
        cout<<"Ingrese el mensaje: ";
        string mensaje;
        cin.ignore();
        getline(cin,mensaje);
        cout<<"Mensaje descifrado: "<<receptor.Descifrar(mensaje)<<endl;

        system("pause");
        break;
      }
    }
  }
}
