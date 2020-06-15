#include <iostream>

using namespace std;

long long expoMod(long long a,long long x,long long n){
  long long r=1;
  do {
    if(x%2==1){
      r=(r*a)%n;
    }
    a=((a%n)*(a%n))%n;
    x/=2;
  } while(x>0);
  return r;
}
