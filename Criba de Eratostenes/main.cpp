#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> criba;
  int n;
  cin>>n;
  criba.push_back(2);//Agrego el 2 a las criba por que es el unico numero para que tendrá
  for(int i=3;i<n+1;i+=2){//relleno la criba con todos los numeros hasta n evitando los pares ya que sabemos que no son primos
    criba.push_back(i);
  }
  int e=1;//inicio comprobando la divisibilidad desde el 3 ya que sabemos que no hay ningun multiplo de 2 en la criba
  while(criba[e]*criba[e]<n){//Nuestro while terminará cuando nuestro "e"^2 sea mayor que n
    for(int i=e+1;i<criba.size();i++){//Evalua si hay un numero multiplo de "e" en lo que resta de la criba
      if(criba[i]%criba[e]==0){
        criba.erase(criba.begin()+i);//Elimina a los multiplos de "e"
      }
    }
    e++;
  }
  for(int i=0;i<criba.size();i++){// imprime la criba
    cout<<criba[i]<<" ";
  }
}
