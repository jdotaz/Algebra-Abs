#include <iostream>
#include <vector>
#include "invMul.h"
using namespace std;

int RChino(vector<int> &a,vector<int> &p){
  vector<int> c,q;
  int mod=1;
  for(int i=0;i<p.size();i++){
    mod*=p[i];
  }
  for(int i=0;i<p.size();i++){
    c.push_back(mod/p[i]);
    q.push_back(inversaMul(c[i],p[i]));
  }
  int res=0;
  for(int i=0;i<p.size();i++){
    res+=modulo(a[i]*c[i]*q[i],mod);
  }
  return modulo(res,mod);
}

int main(){
  //EJEMPLO
  vector<int> a={2,3,2};
  vector<int> p={3,5,7};
  cout<<RChino(a,p);
}
