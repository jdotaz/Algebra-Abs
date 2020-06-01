#include "Polibio.h"
#include <iostream>
#include <string>

using namespace std;

Polibio::Polibio(){
}

int Polibio::modulo(int dividendo,int divisor){
  int residuo=dividendo-(divisor*(dividendo/divisor));
  if (residuo<0){
    residuo+=divisor;
  }
  return residuo;
}
string Polibio::Cifrar(string mensaje){
  string mensajeCifrado;
  for(int i=0;i<mensaje.size();i++){
    int x;
    if(mensaje[i]=='J'){
      x=8;
    }else{
      x=alfabeto.find(mensaje[i]);
    }
    string columna=to_string(modulo(x,5)+1);
    string fila=to_string((x/5)+1);
    mensajeCifrado+=fila;
    mensajeCifrado+=columna;
  }
  return mensajeCifrado;
}

string Polibio::Descifrar(string mensaje){
  string mensajeDescifrado;
  for(int i=0;i<mensaje.size();i+=2){
    int x=mensaje[i]-'0';
    int y=mensaje[i+1]-'0';
    int coor=(x-1)*5+(y-1);
    mensajeDescifrado+=alfabeto[coor];
  }
  return mensajeDescifrado;
}
