#include <bits/stdc++.h>
using namespace std;

struct nodo{
  int ci;
  string nb;
  int sueldo;
  nodo* sig;
  nodo* ant;
};

void insertar(nodo** comienzo, int valor, string nombre, int dinero){

  if(comienzo == NULL){
    nodo* nuevo = new nodo;
    nuevo->ci = valor;
    nuevo->nb = nombre;
    nuevo->sueldo = dinero;
    nuevo->sig = nuevo->ant = nuevo;
    *comienzo = nuevo;
    return;
  }

  nodo* ultimo = (*comienzo)->ant;

  nodo* nuevo = new nodo;

  nuevo->ci = valor;
  nuevo->nb = nombre;
  nuevo->sueldo = dinero;
  
  nuevo->sig = *comienzo;

  (*comienzo)->ant = nuevo;

  nuevo->ant = ultimo;

  ultimo->sig = nuevo;
}

void eliminar(nodo** comienzo,  int clave){
  if(*comienzo == NULL){
    return;
  }

  nodo *actual = *comienzo, *ant_1 = NULL;

  while(actual->ci != clave){
    
    if(actual->sig == *comienzo){
      
      cout<<"la cedula "<<clave<<" no existe.\n";
      return;
    }

    ant_1 = actual;
    actual = actual->sig;
  }

  if(actual->sig == *comienzo && ant_1 == NULL){
    (*comienzo) = NULL;
    free(actual);
    return;
  }

  if(actual == *comienzo){
    ant_1 = (*comienzo)->ant;

    *comienzo = (*comienzo)->sig;

    ant_1->sig = *comienzo;

    (*comienzo)->ant = ant_1;
    free(actual);
  }

  else if(actual->sig == *comienzo){
    ant_1->sig = *comienzo;
    (*comienzo)->ant = ant_1;
    free(actual);
  }
  else{
    nodo* aux = actual->sig;

    ant_1->sig = aux;
    aux->ant = ant_1;
    free(actual);
  }
}

void mostrar(nodo* comienzo){
  nodo *aux = comienzo;
  
  while(aux->sig != comienzo){
    cout<<aux->ci<<" ";
    cout<<aux->nb<<" ";
    cout<<aux->sueldo<<" \n";
    aux=aux->sig;
  }
  cout<<aux->ci<<" ";
  cout<<aux->nb<<" ";
  cout<<aux->sueldo<<" \n";
}

int main(){
  nodo* comienzo= NULL;
  int id,stu,cont=0;
  string meme;
  
  do{
  cout<<"ci: \n";
  cin>>id;
  cout<<"nombre: \n";
  cin.ignore();
  getline(cin,meme,'\n');
  cout<<"sueldo: \n";
  cin>>stu;
  insertar(&comienzo,id,meme,stu);
  cont++;
  }while(cont!=2);
  mostrar(comienzo);
  cout<<"borre \n";
  cin>>id;
  eliminar(&comienzo,id);
  mostrar(comienzo);
};
