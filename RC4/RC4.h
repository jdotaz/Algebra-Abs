#include <iostream>
#include <vector>
#include <windows.h>
#define MB 1048576

using namespace std;

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

void seeds(vector<int> &semillas,int bits){
  MEMORYSTATUSEX memStat;
  memStat.dwLength = sizeof (memStat);
  GlobalMemoryStatusEx(&memStat);
  SYSTEMTIME sysTime;
  GetSystemTime(&sysTime);
  int a=memStat.dwMemoryLoad;
  int b=mod(memStat.ullTotalPhys/MB,bits);
  int c=mod(memStat.ullAvailPhys/MB,bits);
  int d=mod(memStat.ullAvailPageFile/MB,bits);
  int e=mod(sysTime.wMilliseconds,bits);
  semillas.push_back(a);
  semillas.push_back(c);
  semillas.push_back(d);
  semillas.push_back(e);
  semillas.push_back(mod(b-c,bits));
  semillas.push_back(mod(a*b,bits));
  semillas.push_back(mod(b*d,bits));
  semillas.push_back(mod(e*a,bits));
  semillas.push_back(mod(e+c,bits));
}

void RC4(int bits, int S[]){
  //Relleno mi vector S con numeros en orden
  for(int i=0;i<bits;i++){
    S[i]=i;
  }
  //Creo mi vector de semillas con los que rellenaré K
  vector<int> semillas;
  seeds(semillas,bits);
  //Creo mi vector K del porte de S y lo relleno con las semillas
  const int sizeK=bits;
  int K[sizeK];
  for(int i=0,j=0;i<bits;i++,j++){
    if(j==semillas.size())
      j=0;
    K[i]=semillas[j];
  }
  //Desordeno mi vector S
  int f=0;
  for(int i=0;i<bits;i++){
    f=(f+S[i]+K[i])%bits;
    swap(S,i,f);
  }
}
