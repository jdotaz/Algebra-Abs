#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> criba;
  int n;
  cin>>n;//Pedimos n para saber hasta que número será la criba
  criba.push_back(2);//Agrego el 2 a las criba porque sera el único número par que tendrá
  for(int i=3;i<n+1;i+=2){
    criba.push_back(i);
  }//relleno la criba con todos los números hasta n evitando los pares ya que sabemos que no son primos
  int e=1;//inicio comprobando la divisibilidad desde el indice 1 ya que sabemos que no hay ningún múltiplo de 2(indice 0) en la criba
  while(criba[e]*criba[e]<n){//Nuestro while terminará cuando nuestro [e]^2 sea mayor que n
    for(int i=e+1;i<criba.size();i++){//Evaluá si hay un número múltiplo de [e] en lo que resta de la criba
      if(criba[i]%criba[e]==0){
        criba.erase(criba.begin()+i);//Elimina a los múltiplos de [e]
      }
    }
    e++;
  }
  for(int i=0;i<criba.size();i++){
    cout<<criba[i]<<" ";
  }// imprime la criba
}
