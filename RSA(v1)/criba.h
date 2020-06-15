#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void criba(int fin,long long &p,long long &q){
  vector<int> criba;
  criba.push_back(2);
  for(int i=3;i<fin+1;i+=2){
    criba.push_back(i);
  }
  int e=1;
  while(criba[e]*criba[e]<fin){
    for(int i=e+1;i<criba.size();i++){
      if(criba[i]%criba[e]==0){
        criba.erase(criba.begin()+i);
      }
    }
    e++;
  }
  int f=rand()%(criba.size()/2)+(criba.size()/2);
  p=(long long) criba[f];
  f=rand()%(criba.size()/2)+(criba.size()/2);
  q=(long long) criba[f];
}
