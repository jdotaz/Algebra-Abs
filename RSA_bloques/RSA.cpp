#include "RSA.h"
#include <iostream>
#include <NTL/ZZ.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <sstream>

using namespace std;
using namespace NTL;

RSA::RSA(){
  Zn=0;
  clave=0;
}
RSA::RSA(ZZ _Zn,ZZ _clave){
  Zn=_Zn;
  clave=_clave;
}

ZZ RSA::expoMod(ZZ a,ZZ x){
  ZZ r=(ZZ)1;
  do {
    if(x%2==1){
      r=(r*a)%Zn;
    }
    a=(a*a)%Zn;
    x/=2;
  } while(x>0);
  return r;
}

int RSA::Digitos(ZZ num){
  int size=1;
  while (num>0) {
    num/=(ZZ)10;
    size++;
  }
  return size;
}

string RSA::Cifrar(string mensaje){
  string alfa,cifrado;
  for(int i=0;i<mensaje.size();i++){
    int x=alfabeto.find(mensaje[i]);
    int ceros=Digitos((ZZ)alfabeto.size()-1)-Digitos((ZZ)x);
    for(int i=0;i<ceros;i++){
      alfa+="0";
    }
    alfa+=to_string(x);
  }
  int e=0;
  while (e<alfa.size()) {
    string temp;
    int tope=e;
    for(int j=e;j<tope+Digitos(Zn-1)-2;j++){
      if(j>alfa.size()-1){
        temp+="5";
        j++;
        if(j<tope+Digitos(Zn-1)-2){
          temp+="4";
        }
      }else{
        temp+=alfa[e];
      }
      e++;
    }
    ZZ toInt(  INIT_VAL, temp.c_str());
    stringstream cif;
    ZZ caracter=expoMod(toInt,clave);
    cif<<caracter;
    int ceros=Digitos(Zn-(ZZ)1)-Digitos(caracter);
    for(int i=0;i<ceros;i++){
      cifrado+="0";
    }
    cifrado+=cif.str();
  }
  return cifrado;
}

string RSA::Descifrar(string mensaje){
  string descifrado;
  vector<string> vectorMensaje;
  string letra, unido;
  int j=0;
  for(int i=0;i<mensaje.size();i++){
    if(j<Digitos(Zn-1)-1){
      letra+=mensaje[i];
      j++;
    }else{
      vectorMensaje.push_back(letra);
      j=0;
      letra="";
      i--;
    }
  }
  vectorMensaje.push_back(letra);

  for(int i=0;i<vectorMensaje.size();i++){
    string str=vectorMensaje[i];
    ZZ toInt(  INIT_VAL, str.c_str());
    ZZ bloque=expoMod(toInt,clave);
    stringstream bloqueStr;
    bloqueStr<<bloque;
    int ceros=Digitos(Zn-(ZZ)1)-Digitos(bloque)-1;
    for(int i=0;i<ceros;i++){
      unido+="0";
    }
    unido+=bloqueStr.str();
  }
  for(int i=0;i<unido.size();i+=2){
    string carac;
    carac.append(unido,i,2);
    stringstream convertir(carac);
    int pos=0;
    convertir>>pos;
    descifrado+=alfabeto[pos];
  }

  return descifrado;
}
