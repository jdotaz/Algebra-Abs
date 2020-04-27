#include <iostream>
#include <stdlib.h>
#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <ctime>
#include "Euclides.h"
#include "EuclidesLimpio.h"

using namespace std;
using namespace NTL;


int main(){
  ZZ a,b,resultado;
  unsigned t0, t1;
  RR time;
  //EuclidesLimpio mcd; //Descomentar esta parte para ver el tiempo de ejecucion de los algoritmos sin interferencia de la comprobacion paso a paso
  Euclides mcd; //Descomentar esta parte para ver la comprobacion paso a paso
  cin>>a;
  cin>>b;

  t0=clock();
  cout<<"algoritmo 1:"<<endl;
  cout<<"a= "<<a<<endl<<"b= "<<b<<endl;
  resultado=mcd.mcd1(a,b);
  cout<<endl<<"mcd.mcd1("<<a<<","<<b<<")="<<resultado<<endl<<endl;
  t1=clock();
  time = (RR(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo de ejecucion: : " << time << endl;
  system("pause");
  system("cls");

  t0=clock();
  cout<<"algoritmo 2:"<<endl;
  cout<<"a= "<<a<<endl<<"b= "<<b<<endl;
  resultado=mcd.mcd2(a,b);
  cout<<endl<<"mcd.mcd2("<<a<<","<<b<<")="<<resultado<<endl<<endl;
  t1=clock();
  time = (RR(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo de ejecucion: : " << time << endl;
  system("pause");
  system("cls");

  t0=clock();
  cout<<"algoritmo 3:"<<endl;
  cout<<"a= "<<a<<endl<<"b= "<<b<<endl;
  resultado=mcd.mcd3(a,b);
  cout<<endl<<"mcd.mcd3("<<a<<","<<b<<")="<<resultado<<endl<<endl;
  t1=clock();
  time = (RR(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo de ejecucion: : " << time << endl;
  system("pause");
  system("cls");

  t0=clock();
  cout<<"algoritmo 4:"<<endl;
  cout<<"a= "<<a<<endl<<"b= "<<b<<endl;
  resultado=mcd.mcd4(a,b);
  cout<<endl<<"mcd.mcd4("<<a<<","<<b<<")="<<resultado<<endl<<endl;
  t1=clock();
  time = (RR(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo de ejecucion: : " << time << endl;
  system("pause");
  system("cls");

  t0=clock();
  cout<<"algoritmo 5:"<<endl;
  cout<<"a= "<<a<<endl<<"b= "<<b<<endl;
  resultado=mcd.mcd5(a,b);
  cout<<endl<<"mcd.mcd5("<<a<<","<<b<<")="<<resultado<<endl<<endl;
  t1=clock();
  time = (RR(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo de ejecucion: : " << time << endl;
  system("pause");
  system("cls");

  t0=clock();
  cout<<"algoritmo 6:"<<endl;
  cout<<"a= "<<a<<endl<<"b= "<<b<<endl;
  resultado=mcd.mcd6(a,b);
  cout<<endl<<"mcd.mcd6("<<a<<","<<b<<")="<<resultado<<endl<<endl;
  t1=clock();
  time = (RR(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo de ejecucion: : " << time << endl;
  system("pause");
  system("cls");

  t0=clock();
  cout<<"algoritmo 7:"<<endl;
  cout<<"a= "<<a<<endl<<"b= "<<b<<endl;
  resultado=mcd.mcd7(a,b);
  cout<<endl<<"mcd.mcd7("<<a<<","<<b<<")="<<resultado<<endl<<endl;
  t1=clock();
  time = (RR(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo de ejecucion: : " << time << endl;
  system("pause");
  system("cls");

  return 0;

}
