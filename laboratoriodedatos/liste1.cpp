#include <iostream>
using namespace std;

struct nodo{
  int dato;
  nodo *sig;
};

void insertar(nodo *&,int);

int main(){
  nodo *lista = NULL;
  int dato,cont=0;
  do{
  cout<<"inserte numero: ";
  cin>>dato;
  insertar(lista,dato);
  cont++;
  }while(cont<4);
  
}

void insertar(nodo *&lista, int n){
  nodo *nuevo = new nodo();
  nuevo->dato = n;

  nodo *aux1= lista;
  nodo *aux2;

  while((aux1 != NULL) && (aux1->dato < n)){
    aux2 = aux1;
    aux1 = aux1->sig;
  }
  if(lista==aux1){
    lista = nuevo;
  }
  else{
    aux2->sig = nuevo;
  }
  nuevo->sig = aux1;
  cout<<"\tel numero "<<n<<" insertado\n";
}

  
  

