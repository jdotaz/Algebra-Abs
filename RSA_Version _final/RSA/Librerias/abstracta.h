#include <iostream>
#include <vector>
#include "Random.h"
#include <NTL/ZZ.h>
#include <sstream>
using namespace std;
using namespace NTL;

ZZ modulo(ZZ  a,ZZ b){
  ZZ r=a-(b*(a/b));
  if (r<0){
    return r+b;
  }
  return r;
}//Funcion modulo

ZZ mcd(ZZ a, ZZ b){
  while (true) {
    ZZ r=modulo(a,b);
    if(r==0){
      return b;
    }
    if(r>b/2){
      r=b-r;
    }
    a=b;
    b=r;
  }
}//Funcion mcd

struct extendido{
  ZZ a,b,x,y,d;
  extendido(ZZ _a,ZZ _b){
    ZZ q,r,r1,r2,s,s1,s2,t,t1,t2;
    r1=_a;
    s1=1;
    t1=0;
    r2=_b;
    s2=0;
    t2=1;
    while (r2>0) {
      q=r1/r2;
      r=r1-(q*r2);
      r1=r2;
      r2=r;
      s=s1-(q*s2);
      s1=s2;
      s2=s;
      t=t1-(q*t2);
      t1=t2;
      t2=t;
    }
    d=r1;
    a=_a;
    b=_b;
    x=s1;
    y=t1;
  }
  imprimirEcuacion(){
    cout<<a<<"("<<x<<")+"<<b<<"("<<y<<")="<<d<<endl;
  }
};//algoritmo extendido como un struct

ZZ inversaMul(ZZ e,ZZ N){
  if(mcd(e,N)==1){
    extendido inve(e,N);
    return modulo(inve.x,N);
  }
  return (ZZ)-1;//Significa que no tiene inversa
}//Inversa multiplicativa, usa el algoritmo xtendido de euclides

ZZ expoMod(ZZ a,ZZ x,ZZ n){
  ZZ r=(ZZ)1;
  while(x>0){
    if(modulo(x,(ZZ)2)==1){
      r=modulo((r*a),n);
    }
    a=modulo((a*a),n);
    x/=2;
  }
  return r;
}//Exponenciacion modular

ZZ RChino(vector<ZZ> &a,vector<ZZ> &p){
  vector<ZZ> c,q;
  ZZ mod=(ZZ)1;
  for(int i=0;i<p.size();i++){
    mod*=p[i];
  }
  for(int i=0;i<p.size();i++){
    c.push_back(mod/p[i]);
    q.push_back(inversaMul(c[i],p[i]));
  }
  ZZ res=(ZZ)0;
  for(int i=0;i<p.size();i++){
    res+=modulo(a[i]*c[i]*q[i],mod);
  }
  return modulo(res,mod);
}//Teorema del resto chino

ZZ random(int _bits){
  const int bits=_bits;
  int bin[bits];
  vector<int> num;
  int vueltas=(_bits/48);
  int n=0;
  for(int i=0;i<vueltas;i++){
    int K[48];
    gen(K,mod(n,16));
    num.insert(num.end(),K,K+48);
    n++;
  }
  int K[48];
  gen(K,mod(n,16));
  num.insert(num.end(),K,K+_bits-num.size());
  num[0]=1;//Para que siempre sea mayor que 2^n, quitar para no limitar
  num[_bits-1]=1;//Para que siempre sea impar, quitar para no limitar
  ZZ total=(ZZ)0;
  ZZ pot=(ZZ)1;
  for(int i=num.size()-1;i>=0;i--){
    if(num[i]){
      total+=pot;
    }
    pot*=2;
  }
  return total;
}//Funcion aleatorio usa RC4 y DES

bool primalidad(ZZ p){
  for(int a=2;a<10;a++){
    if(expoMod((ZZ)a,p-1,p)!=1){
      return false;
    }
  }
  return true;
}//Test de primalidad de Fermat

ZZ randPrim(int bits){
  ZZ num=random(bits);
  while(!primalidad(num)){
    num+=2;
  }
  return num;
}//Test de primalidad y random unidos

int digitos(ZZ num){
  if(num==0){
    return 1;
  }
  int size=0;
  while (num>0) {
    num=num/10;
    size++;
  }
  return size;
}//cuenta la cantidad de digitos en decimal de un numero
