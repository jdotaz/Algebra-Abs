#include <iostream>
#include <string>
#include "Cesar.cpp"

using namespace std;

int main (){

  string mensaje;
  int clave,opcion;
  bool fin=true;
  while (fin) {
    system("cls");
    cout<<"       Algoritmo Cesar"<<endl;
    cout<<"1. Cifrar."<<endl;
    cout<<"2. Descifrar."<<endl;
    cout<<"3. Salir."<<endl;
    cin>>opcion;
    switch (opcion) {
      case 1:{
        system("cls");
        cout<<"CIFRAR:"<<endl;
        cout<<"   Ingrese el menaje: ";
        cin>>mensaje;
        cout<<"   Ingrese la clave: ";
        cin>>clave;
        Cesar receptor(clave);
        string menDecCif=receptor.Cifrar(mensaje);
        cout<<menDecCif<<endl;
        system("pause");
        break;
      }
      case 2:{
        system("cls");
        cout<<"DESCIFRAR:"<<endl;
        cout<<"   Ingrese el menaje: ";
        cin>>mensaje;
        cout<<"   Ingrese la clave: ";
        cin>>clave;
        Cesar emisor(clave);
        string menCif=emisor.Descifrar(mensaje);
        cout<<menCif<<endl;
        system("pause");
        break;
      }
      case 3:{
        system("cls");
        cout<<"Adios"<<endl;
        fin=false;
        break;
      }
    }
  }
  return 0;
}
