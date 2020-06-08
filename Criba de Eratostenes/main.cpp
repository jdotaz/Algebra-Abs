#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> criba;
  int z;
  cin>>z;
  for(int i=2;i<z+1;i++){
    criba.push_back(i);
  }
  int e=0;
  while(criba[e]*criba[e]<z){
    for(int i=0;i<criba.size();i++){
      if(criba[i]%criba[e]==0 and criba[i]!=criba[e]){
        criba.erase(criba.begin()+i);
      }
    }
    e++;
  }
  for(int i=0;i<criba.size();i++){
    cout<<criba[i]<<" ";
  }
}
