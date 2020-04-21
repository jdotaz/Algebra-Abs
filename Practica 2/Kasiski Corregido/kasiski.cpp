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
      j+=_mcd;
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
    cout<<alfabeto[i]<<": "<<tabla[i]<<endl;
  }
  return AnalisisFrecuencias(tabla);
}

string kasiski::AnalisisFrecuencias(int _tabla[]){
  int tablaResultado[alfabeto.length()];
  for(int i=0;i<alfabeto.length();i++){
    tablaResultado[i]=_tabla[i]+_tabla[(i+4)%alfabeto.length()]+_tabla[(i+14)%alfabeto.length()]+_tabla[(i+18)%alfabeto.length()];
    cout<<alfabeto[i]<<tablaResultado[i]<<endl;
  }
  int indice=0;
  for(int i=1;i<alfabeto.length();i++){
    if(tablaResultado[indice]<tablaResultado[i]){
      indice=i;
    }
  }
  string mayor;
  mayor+=alfabeto[indice];
  return mayor;
}

string kasiski::cryptoanalisis(string mensaje){
  tamDeLaClave(mensaje);
  int mcd=euclidesVector();
  cout<<endl<<"El porte de la clave es:"<<mcd<<endl;
  string subcadenas[mcd];
  dividirSubCadenas(mensaje,subcadenas,mcd);
  string calveResultado;
  for(int i=0;i<mcd;i++){
    calveResultado+=contarTabla(subcadenas[i]);
  }
  return calveResultado;
}
