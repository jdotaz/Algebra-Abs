#include "RSA/RSA.cpp"
int main(){
  int bits,opcion;
  bool bucle=true;
  ZZ N,e;
  cout<<"                Protocolo RSA"<<endl;
  cout<<"Bloque de bits a trabajar: "<<endl;
  cin>>bits;
  RSA usuario(bits);
  cout<<"Claves del locutor: "<<endl;
  cout<<"N: ";
  cin>>N;
  cout<<"e: ";
  cin>>e;
  usuario.locutor(N,e);
  cout<<"Continuar..."<<endl;
  system("pause");
  while (bucle) {
    system("cls");
    cout<<"                Protocolo RSA"<<endl;
    cout<<"1.Cifrar."<<endl;
    cout<<"2.Descifrar."<<endl;
    cout<<"3.Cambiar claves."<<endl;
    cout<<"4.Cambiar publicas."<<endl;
    cout<<"5.Imprimir Claves."<<endl;
    cout<<"6.Salir."<<endl;
    cout<<"Opcion: ";
    cin>>opcion;
    switch (opcion) {
      case 1:{
        system("cls");
        cout<<"                Protocolo RSA - Cifrado"<<endl;
        cout<<"Ingrese el mensaje: ";
        string mensaje;
        cin.ignore();
        getline(cin,mensaje);
        cout<<"Mensaje cifrado: "<<endl<<usuario.Cifrar(mensaje)<<endl;
        system("pause");
        break;
      }
      case 2:{
        system("cls");
        cout<<"                Protocolo RSA - Descifrado"<<endl;
        cout<<"Ingrese el mensaje cifrado: ";
        string mensaje;
        cin.ignore();
        getline(cin,mensaje);
        cout<<"Mensaje: "<<endl<<usuario.Descifrar(mensaje)<<endl;
        system("pause");
        break;
      }
      case 3:{
        system("cls");
        cout<<"                Protocolo RSA - Cambiar claves"<<endl;
        ZZ p,q,e;
        cout<<"Ingrese p: ";
        cin>>p;
        cout<<"Ingrese q: ";
        cin>>q;
        cout<<"Ingrese e: ";
        cin>>e;
        usuario.Cambio(p,q,e);
        cout<<"Cambio realizado."<<endl;
        system("pause");
        break;
      }
      case 4:{
        system("cls");
        cout<<"                Protocolo RSA - Cambiar publicas"<<endl;
        ZZ N,e;
        cout<<"Ingrese N: ";
        cin>>N;
        cout<<"Ingrese e: ";
        cin>>e;
        usuario.locutor(N,e);
        cout<<"Cambio realizado."<<endl;
        system("pause");
        break;
      }
      case 5:{
        system("cls");
        cout<<"                Protocolo RSA - Imprimir claves"<<endl;
        usuario.Print();
        system("pause");
        break;
      }
      case 6:{
        system("cls");
        bucle=false;
        cout<<"Hasta luego :D"<<endl;
        system("pause");
        break;
      }
    }
  }
}
