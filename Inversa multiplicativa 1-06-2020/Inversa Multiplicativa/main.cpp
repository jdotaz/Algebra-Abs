#include <iostream>
#include "invMul.h"
using namespace std;

int main(){
  while (true) {
    system("cls");
    cout<<"         Inversa Multiplicativa"<<endl;
    int a,b;
    cout<<"Ingrese el numero: ";
    cin>>a;
    cout<<"Ingrese el Zn: ";
    cin>>b;
    int inv=inversaMul(a,b);
    if (inv==-1){
      cout<<a<<" no tiene inversa multiplicativa en Z"<<b<<endl;
    }else{
      cout<<"La inversa multiplicativa de "<<a<<" en Z"<<b<<" es "<<inv<<endl;
    }

    system("pause");
  }
}
