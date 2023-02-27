#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
  srand(time(NULL));
  stack<int> pila;
  int opcion;
  char respuesta;
  
  cout<<"Programa de pila, referente a 20 platos(cuales seran de 3 colores rojo, azul, amarillo), y se necesitara saber cuantos hay en la pila, cual esta de primero, y dira cuales entran o salen, empleando todo bajo el uso de srand. \n \n";
 pila.push(0);
  do{
    cout<<"Que desea hacer? \n 1. insertar plato. \n 2. remover plato. \n 3. ver plato que en el tope. \n 4. cuantos platos hay en la pila. \n 5. terminar programa. \n";
      cin>>opcion;
    switch(opcion){
    case 1:{ if(pila.size()!=21){pila.push(rand() % 3 + 1);
	cout<<"se ha insertado un plato de color: ";
	if (pila.top()==1){cout<<"rojo. \n";} 
	if (pila.top()==2){cout<<"azul. \n";}
	if (pila.top()==3){cout<<"amarillo. \n";}} else{ cout<<"pila llena!. \n";}
	break;}
    case 2:{
      if(pila.size()>1){
	    pila.pop();
	    cout<<"se ha removido el plato... \n";
	    if (pila.top()==1){cout<<"era rojo... \n";}
	    if (pila.top()==2){cout<<"era azul... \n";}
	    if (pila.top()==3){cout<<"era amarillo... \n";}}
      if (pila.size()==1){cout<<"no hay ningun plato en la pila, no puedes remover nada, volviendo al menu. \n";}break;}
      
    case 3:{ if(pila.size()>2){cout<<"el plato que actualmente esta en el tope es de color: ";
	    if (pila.top()==1){cout<<"rojo. \n";} 
	    if (pila.top()==2){cout<<"azul. \n";}
	    if (pila.top()==3){cout<<"amarillo. \n";}}else{ cout<<"no hay platos en la pila. \n";}
	    break;}

    case 4:{ cout<<"hay en total: ";
	if(pila.size()==1){ cout<<"0 platos en la pila, pila vacia!. \n";}
	if(pila.size()==21){ cout<<"20 platos en la pila, pila llena!. \n";}
	if(pila.size()!=1 && pila.size()!=21){
	  cout<< pila.size() << ". \n";}break;}
    case 5:{ cout<<"seguro que desea concluir?. s/n \n";
	cin>>respuesta; break;}
    default: { cout<<"opcion no valida, volviendo al menu... \n"; break;}}
  }while(respuesta!='s');
    cout<<"operacion terminada. \n";
}
