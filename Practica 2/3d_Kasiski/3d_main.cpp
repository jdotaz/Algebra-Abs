#include <iostream>
#include <string>
#include <vector>
#include "kasiski.cpp"


using namespace std;

int main (){
  kasiski kas;
  string mensaje;
  getline(cin,mensaje);
  cout<<kas.cryptoanalisis(mensaje);
}
