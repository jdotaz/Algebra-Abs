#include <iostream>

using namespace std;

int expoMod(int a,int x, int n){
  int r=1;
  do {
    if(x%2==1){
      r=(r*a)%n;
    }
    a=((a%n)*(a%n))%n;
    x/=2;
  } while(x>0);
  return r;
}
