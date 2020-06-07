#include <iostream>
#include <string>
#include "Afin.cpp"

using namespace std;

int main (){

  string mensaje;
  int clave1,clave2,opcion;
  bool fin=true;
  while (fin) {
    system("cls");
    cout<<"       Algoritmo Afin"<<endl;
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
        Afin emisor;
        string menCif=emisor.Cifrar(mensaje);
        clave1=emisor.get_clave1();
        clave2=emisor.get_clave2();
        cout<<"Clave 1: "<<clave1<<endl;
        cout<<"Clave 2: "<<clave2<<endl;
        cout<<"Mensaje:"<<endl<<menCif<<endl;
        system("pause");
        break;
      }
      case 2:{
        system("cls");
        cout<<"DESCIFRAR:"<<endl;
        cout<<"   Ingrese el mensaje: ";
        cin.ignore();
        getline(cin,mensaje);
        cout<<"   Ingrese la clave 1: ";
        cin>>clave1;
        cout<<"   Ingrese el clave 2: ";
        cin>>clave2;
        Afin receptor(clave1,clave2);
        string menDes=receptor.Descifrar(mensaje);
        cout<<menDes<<endl;
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
