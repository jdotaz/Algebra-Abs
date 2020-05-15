#include <iostream>

using namespace std;

void division(int a,int b,int &residuo,int &cociente){
  cociente=a/b;
  residuo=a-(b*cociente);
  if (residuo<0){
    cociente--;
    residuo+=b;
  }
}

int main(){
int a,n,r,q;
cout<<"ingrese el a: ";
cin>>a;
cout<<"ingrese el b: ";
cin>>n;
division(a,n,r,q);
cout<<a<<"=("<<q<<"*"<<n<<")+"<<r<<endl;
}
