#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <windows.h>
#define MB 1048576

using namespace std;
using namespace NTL;

int mod(int dividendo,int divisor){
  int residuo=dividendo-(divisor*(dividendo/divisor));
  if (residuo<0){
    residuo+=divisor;
  }
  return residuo;
}

void swap(int S[],int i,int f){
  int aux=S[i];
  S[i]=S[f];
  S[f]=aux;
}

void seeds(vector<int> &semillas){
  MEMORYSTATUSEX memStat;
  memStat.dwLength = sizeof (memStat);
  GlobalMemoryStatusEx(&memStat);
  SYSTEMTIME sysTime;
  GetSystemTime(&sysTime);
  int a=memStat.dwMemoryLoad;
  int b=mod(memStat.ullTotalPhys/MB,256);
  int c=mod(memStat.ullAvailPhys/MB,256);
  int d=mod(memStat.ullAvailPageFile/MB,256);
  int e=mod(sysTime.wMilliseconds,256);
  semillas.push_back(a);//porcentaje memoria física en uso
  semillas.push_back(c);// memoria física disponible
  semillas.push_back(d);//máxima de memoria usable
  semillas.push_back(e);//Milisegundos del sistema
  semillas.push_back(mod(b-c,256));//memoria física en uso
}

void RC4(vector<int> &seedDes){
  //Relleno mi vector S con numeros en orden
  int S[256];
  for(int i=0;i<256;i++){
    S[i]=i;
  }
  //Creo mi vector de semillas
  vector<int> k;
  seeds(k);
  //Desordeno mi vector S
  int f=0;
  for(int i=0;i<256;i++){
    f=(f+S[i]+k[mod(i,k.size())])%256;
    swap(S,i,f);
  }
  //Generación de secuencia cifrante
  f=0;
  int i=0,t;
  while (seedDes.size()<64) {
    i=mod(i+1,256);
    f=mod(f+S[i],256);
    swap(S,i,f);
    t=mod(S[i]+S[f],256);
    int bin[8];
    for(int i=0,x=S[t];i<8;i++,x/=2){
      bin[i]=mod(x,2);
    }
    for(int i=7;i>=0;i--){
      seedDes.push_back(bin[i]);
    }
  }
}

void izq(int V[]){
  int x=V[0];
  for(int i=0;i<28;i++){
    V[i]=V[i+1];
  }
  V[27]=x;
}

void der(int V[]){
  int x=V[27];
  for(int i=27;i>0;i--){
    V[i]=V[i-1];
  }
  V[0]=x;
}

void DES(vector<int> &seedDes,int K[],int n){
  int PC1[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
  int PC2[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
  int Kn[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
  int C[28];
  int D[28];
  for(int i=0;i<28;i++){
    C[i]=seedDes[PC1[i]-1];
    D[i]=seedDes[PC1[i+28]-1];
  }
  for(int i=0;i<Kn[n];i++){
    izq(C);
    der(D);
  }

  int CD[56];
  for(int i=0;i<28;i++){
    CD[i]=C[i];
    CD[i+28]=D[i];
  }

  for(int i=0;i<48;i++){
    K[i]=CD[PC2[i]-1];
  }
}

void gen(int K[],int n){
  vector<int> seedDes;
  RC4(seedDes);
  DES(seedDes,K,n);
}

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
}
