#include "kasiski.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

kasiski::kasiski(){
}

void kasiski::cryptoanalisis(string mensaje){
  vector<int> distancias;
  for(int i=0;i<mensaje.length();i++){
    string prueba=prueba+mensaje[i]+mensaje[i+1]+mensaje[i+2];
    if(mensaje.find(prueba)!=-1){
      int x=mensaje.find(prueba)-i;
      distancias.push_back(x);
      cout<<x<<endl;
    }
  }
}
