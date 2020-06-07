#include "Afin.h"
#include "inversa/invMul.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

Afin::Afin(){
  generar_claves();
}
Afin::Afin(int _clave1,int _clave2){
  clave1=inversaMul(_clave1,alfabeto.size());
  clave2=_clave2;
}
void Afin::generar_claves(){
  srand (time(NULL));
  do {
    clave1=rand()%alfabeto.size();
  } while(mcd(clave1,alfabeto.size())!=1);
  clave2=rand()%alfabeto.size();
}
string Afin::Cifrar(string mensaje){
  string cifrado;
  for(int i=0;i<mensaje.size();i++){
    int x=alfabeto.find(mensaje[i]);
    x=modulo(clave1*x+clave2,alfabeto.size());
    cifrado+=alfabeto[x];
  }
  return cifrado;
}
string Afin::Descifrar(string mensaje){
  string descifrado;
  for(int i=0;i<mensaje.size();i++){
    int x=alfabeto.find(mensaje[i]);
    x=modulo(clave1*(x-clave2),alfabeto.size());
    descifrado+=alfabeto[x];
  }
  return descifrado;
}
int Afin::get_clave1(){
  return clave1;
}
int Afin::get_clave2(){
  return clave2;
}
