#include <iostream>
#include "Extendido.cpp"

using namespace std;

int main(){
  while (true) {
    system("cls");
    cout<<"         Algoritmo extendido de Euclides"<<endl;
    int a,b;
    cout<<"Ingrese a: ";
    cin>>a;
    cout<<"Ingrese b: ";
    cin>>b;
    Extendido res(a,b);
    res.imprimirEcuacion();
    system("pause");
  }
}
