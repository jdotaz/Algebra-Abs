#include <iostream>
#include <string>
#include "MonoBino.cpp"

using namespace std;

int main(){
  string mensaje,clave0;
  int clave1,clave2,opcion;
  bool fin=true;
  while (fin) {
    system("cls");
    cout<<"       Algoritmo Monomio-Binomio"<<endl;
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
        cout<<"   Ingrese la palabra memotecnia: ";
        getline(cin,clave0);
        cout<<"   Ingrese la clave 1: ";
        cin>>clave1;
        cout<<"   Ingrese la clave 2: ";
        cin>>clave2;
        MonoBino emisor(clave0,clave1,clave2);
        string menCif=emisor.Cifrar(mensaje);
        cout<<menCif<<endl;
        system("pause");
        break;
      }
      case 2:{
        system("cls");
        cout<<"DESCIFRAR:"<<endl;
        cout<<"   Ingrese el mensaje: ";
        cin.ignore();
        getline(cin,mensaje);
        cout<<"   Ingrese la palabra memotecnia: ";
        getline(cin,clave0);
        cout<<"   Ingrese la clave 1: ";
        cin>>clave1;
        cout<<"   Ingrese la clave 2: ";
        cin>>clave2;
        MonoBino receptor(clave0,clave1,clave2);
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
