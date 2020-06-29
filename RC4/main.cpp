#include "RC4.h"

int main(){
  int bits;
  cin>>bits;
  const int sizeS=bits;
  int S[sizeS];
  RC4(bits,S);
  for(int i=0;i<bits;i++){
    cout<<S[i]<<endl;
  }
}
