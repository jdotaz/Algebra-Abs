#include "RailFence.h"
#include <iostream>
#include <string>

using namespace std;

RailFence::RailFence(){
  clave=3;
}

RailFence::RailFence(int _clave){
  clave=_clave;
}

int RailFence::modulo(int dividendo,int divisor){
  int residuo=dividendo-(divisor*(dividendo/divisor));
  if (residuo<0){
    residuo+=divisor;
  }
  return residuo;
}

string RailFence::Cifrar(string mensaje){
  const int size=clave;
  string palabras[size];
  int j=0;
  bool crece=true;
  for(int i=0;i<mensaje.size();i++){
    palabras[j]+=mensaje[i];
    if(crece){
      j++;
    }else{
      j--;
    }
    if(j==0){
      crece=true;
    }
    if(j==clave-1){
      crece=false;
    }
  }
  string _mensaje;
  for(int i=0;i<clave;i++){
    _mensaje+=palabras[i];
  }
  return _mensaje;
}

string RailFence::Descifrar(string mensaje){
  int fragmentos=clave+clave-2;
  int sobra=modulo(mensaje.size(),fragmentos);
  int tam=mensaje.size()/fragmentos;
  const int size=clave;
  int tamArr[size];
  for(int i=0;i<size;i++){
    if (i==0 or i==clave-1){
      tamArr[i]=tam;
    }else{
      tamArr[i]=tam*2;
    }
  }
  int j=0;
  bool crece=true;
  for(int i=0;i<sobra;i++){
    tamArr[j]+=1;
    if(crece){
      j++;
    }else{
      j--;
    }
    if(j==0){
      crece=true;
    }
    if(j==clave-1){
      crece=false;
    }
  }
  string palabras[size];
  int k=0;
  for(int i=0;i<size;i++){
    palabras[i].append(mensaje,k,tamArr[i]);
    k+=tamArr[i];
  }
  string mensajeDecifrado;
  int g=0;
  for(int e=0;e<tam+1;e++){
    if(palabras[0][e]=='\0'){break;}
    mensajeDecifrado+=palabras[0][e];
    for(int f=1;f<clave-1;f++){
      if(palabras[f][g]=='\0'){break;}
      mensajeDecifrado+=palabras[f][g];
    }
    if(palabras[clave-1][e]=='\0'){break;}
    mensajeDecifrado+=palabras[clave-1][e];
    g++;
    for(int f=clave-2;f>0;f--){
      if(palabras[f][g]=='\0'){break;}
      mensajeDecifrado+=palabras[f][g];
    }
    g++;
  }

  return mensajeDecifrado;
}
