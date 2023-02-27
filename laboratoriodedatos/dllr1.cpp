#include <bits/stdc++.h>

using namespace std;

struct nodo{
  int clave;
  nodo* sig;
  nodo* ant;
};

void insertar(nodo** comienzo, int no){  //se inserta un valor al final de la lista
  // nodo* nuevo = new nodo;
  if(*comienzo == NULL){  //si la lista esta vacia
    nodo* nuevo = new nodo;
    nuevo->clave = no;
    nuevo->sig = nuevo->ant = nuevo;
    *comienzo = nuevo;
    return;
    }

  nodo *ultimo = (*comienzo)->ant;  //con esto busca el ultimo nodo

  nodo* nuevo = new nodo;  //se crea el nuevo nodo dinamicamente
  //cout<<"INSERTE CEDULA DEL EMPLEADO: ";
  nuevo->clave = no;

  nuevo->sig = *comienzo; //comienzo va a estar despues del nodo

  (*comienzo)->ant = nuevo; // hacer un nuevo nodo antes de comienzo

  nuevo->ant = ultimo; // hace a ultimo antes del nuevo nodo

  ultimo->sig = nuevo; //hace un nuevo nodo despues del antiguo  "ultimo"
}

void eliminar(nodo** comienzo, int llave){
  if(*comienzo == NULL){ //si la lista esta vacia
    return;
  }

  nodo *actual = *comienzo, *ant_1 = NULL; //busca el nodo requerido, empleando 2 nodos
  while(actual->clave != llave){
    if(actual->sig == *comienzo){
      cout<<"El valor <<"<<llave<<" no esta en la lista.\n";
      return;
    }

    ant_1 = actual;
    actual = actual->sig;
  }

  if(actual->sig == *comienzo && ant_1 == NULL){  //revisa si es el unico nodo en la lista
    (*comienzo) = NULL;
    free(actual);
    return;
  }

  if(actual == *comienzo){      //si la lista tiene mas de un nodo revisa si es el primero
    ant_1 = (*comienzo)->ant;        //mueve ant_1 al ultimo nodo
    *comienzo = (*comienzo)->sig;    //mueve comienzo al frente

    ant_1->sig = *comienzo;     //ajusta los punteros de ant_1 y comienza el nodo
    (*comienzo)->ant = ant_1;
    free(actual);
  }
  else if(actual->sig = *comienzo){
    ant_1->sig = *comienzo;
    (*comienzo)->ant = ant_1;
    free(actual);
  }else{
    nodo* aux = actual->sig;

    ant_1->sig = aux;
    aux->ant = ant_1;
    free(actual);
  }
}


       
void mostrar(nodo* comienzo){
  nodo *aux = comienzo;
  cout<<"\n Recorrido en dirección hacia adelante \n";
  while(aux->sig != comienzo){
    cout<<aux->clave;
    aux=aux->sig;
  }

  cout<<aux->clave<<"\n";
  
}


int main(){
  int cont=0,n;
  char res;
  nodo* comienzo = NULL;
  do{
    cout<<"inserte numero mijo\n";
    cin>>n;
    insertar(&comienzo, n);
    cont++;
  }while(cont<4);

  cout<<"se ha creado la lista";
  mostrar(comienzo);

  do{
    cout<<"eliminar numero mijo\n";
    cin>>n;
    eliminar(&comienzo, n);
    mostrar(comienzo);
    cout<<"listo?: ";
    cin>>res;
  }while(res!='y');

  //cout<<"inserte numero mijo\n";
  //cin>>n;
  //insertar(&comienzo);
  mostrar(comienzo);    
}
