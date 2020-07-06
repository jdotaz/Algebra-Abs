#include "Random.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main(){
  for(int i=0;i<10;i++){
    auto start = system_clock::now();
    ZZ x=random(1024);
    auto end = system_clock::now();
    duration<double,milli>duration=end-start;
    cout<<x<<endl<<"Tiempo: "<<duration.count()/100<<endl<<endl;
  }

}
