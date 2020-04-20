#include "kasiski.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

kasiski::kasiski(){
}

int kasiski::euclides(int a,int b){
  int r=a%b;
  if(r==0){
    return(b);
  }
  return euclides(b,r);
}

int kasiski::euclidesVector(){
  int mcd=euclides(distancias[0],distancias[2]);;
  for(int i=3;i<distancias.size();i++){
    mcd=euclides(mcd,distancias[i]);
  }
  return mcd;
}

void kasiski::tamDeLaClave(string mensaje){
  string prueba;
  for(int i=0;i<mensaje.length()-2;i++){
    prueba.append(mensaje,i,5);
    size_t found=mensaje.find(prueba,i+1);
    if (found!=std::string::npos){
      int x=mensaje.find(prueba,i+1);
      x-=i;
      distancias.push_back(x);
    }
    prueba="";
  }
}

void kasiski::dividirSubCadenas(string _mensaje,string _subcadenas[], int _mcd){
  for(int i=0;i<_mcd;i++){
    int j=i;
    while(j<_mensaje.length()){
      _subcadenas[i]+=_mensaje[j];
      j+=4;
    }
  }
}

string kasiski::contarTabla(string cadena){
  int tabla[alfabeto.length()];
  for(int i=0;i<alfabeto.length();i++){
    tabla[i]=0;
    for(int j=0;j<cadena.length();j++){
      if(cadena[j]==alfabeto[i]){
        tabla[i]++;
      }
    }
  }
  int encontrado=tabla[0];
  int indice=0;
  for(int i=0;i<alfabeto.length()-1;i++){
    if(encontrado<tabla[i]){
      encontrado=tabla[i];
      indice=i;
    }
  }
  indice-=26;
  if (indice<0){
    indice+=alfabeto.length();
  }
  string letra;
  letra+=alfabeto[indice];
  return letra;
}

string kasiski::cryptoanalisis(string mensaje){
  tamDeLaClave(mensaje);
  int mcd=euclidesVector();
  string subcadenas[mcd];
  dividirSubCadenas(mensaje,subcadenas,mcd);
  string calveResultado;
  for(int i=0;i<mcd;i++){
    calveResultado+=contarTabla(subcadenas[i]);
  }
  return calveResultado;
}
