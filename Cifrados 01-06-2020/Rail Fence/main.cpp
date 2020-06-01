#include <iostream>
#include <string>
#include "RailFence.cpp"

using namespace std;

int main(){
  string mensaje;
  int clave,opcion;
  bool fin=true;
  while (fin) {
    system("cls");
    cout<<"       Algoritmo Rail Fence"<<endl;
    cout<<"1. Cifrar."<<endl;
    cout<<"2. Descifrar."<<endl;
    cout<<"3. Salir."<<endl;
    cin>>opcion;
    switch (opcion) {
      case 1:{
        system("cls");
        cout<<"CIFRAR:"<<endl;
        cout<<"   Ingrese el mensaje: ";
        cin.ignore();
        getline(cin,mensaje);
        cout<<"   Ingrese la clave: ";
        cin>>clave;
        RailFence emisor(clave);
        string menCif=emisor.Cifrar(mensaje);
        cout<<"Mensaje: "<<menCif<<endl;
        system("pause");
        break;
      }
      case 2:{
        system("cls");
        cout<<"DESCIFRAR:"<<endl;
        cout<<"   Ingrese el mensaje: ";
        cin.ignore();
        getline(cin,mensaje);
        cout<<"   Ingrese la clave: ";
        cin>>clave;
        RailFence receptor(clave);
        string menDes=receptor.Descifrar(mensaje);
        cout<<"Mensaje: "<<menDes<<endl;
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
