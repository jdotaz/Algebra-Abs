#include <iostream>

using namespace std;

void division(int dividendo,int divisor,int &residuo,int &cociente){
  cociente=dividendo/divisor;
  residuo=dividendo%divisor;
  if (residuo<0){
    cociente--;
    residuo=dividendo-(cociente*divisor);
  }
}

int main(){
int a,n,r,q;
cout<<"ingrese el dividendo: ";
cin>>a;
cout<<"ingrese el divisor: ";
cin>>n;
division(a,n,r,q);
cout<<a<<"=("<<q<<"*"<<n<<")+"<<r<<endl;
}
