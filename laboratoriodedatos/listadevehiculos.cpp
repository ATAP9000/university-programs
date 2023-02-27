#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string> //string.h me cagaba todo

using namespace std;

struct vehiculo
{
  string placa;         /* las placas tienes letras por eso usa string */
  string nbpropietario; /* nombre del propietario */
  string nbmodelo;      /* nombre del modelo del vehiculo*/
  string marca;         /* nombre de la marca */
  string fechacompra;   /* fecha de compra del vehiculo (dia/mes/anno) */

  /* Punteros para los vehiculos */
  vehiculo *ant;
  vehiculo *sig;
};



//funcion para insertar un vehiculo a la lista
void insertar(vehiculo** comienzo)
{
  /* si la lista esta vacia, se crea un nodo */
  if(*comienzo == NULL)
    {
      vehiculo* nuevo = new vehiculo;
 
    /*las placas pueden tener letras y numeros, pero no simbolos */
    cout<<"\n INSERTE NUMERO DE PLACA: ";
    //cin.ignore();
    getline(cin,nuevo->placa,'\n');

    /* los nombres solo pueden tener letras */
    cout<<"\n INSERTE NOMBRE DEL PROPIETARIO: ";
    //cin.ignore();
    getline(cin,nuevo->nbpropietario,'\n');

    /* los modelos solo pueden tener numeros y letras */
    cout<<"\n INSERTE NOMBRE DEL MODELO: ";
    //cin.ignore();
    getline(cin,nuevo->nbmodelo,'\n');

    /* las marcas pueden ser llamadas como sea */
    cout<<"\n INSERTE NOMBRE DE LA MARCA: ";
    //cin.ignore();
    getline(cin,nuevo->marca,'\n');

    /*ver como resolver esta situacion de como presentar fecha*/
    cout<<"\n fecha de compra: ";
    //cin.ignore();
    getline(cin,nuevo->fechacompra,'\n');

    nuevo->sig = nuevo->ant = nuevo;
    *comienzo = nuevo;
    return;
    }

  // si la lista no esta vacia
  
  /* encuentra el ultimo nodo */
  vehiculo* ultimo = (*comienzo)->ant;

  /* crea un nodo dinamicamente */
  vehiculo* nuevo = new vehiculo;

  cout<<"\n INSERTE NUMERO DE PLACA: ";
  //cin.ignore();
  getline(cin,nuevo->placa,'\n');
  
  cout<<"\n INSERTE NOMBRE DEL PROPIETARIO: ";
  //cin.ignore();
  getline(cin,nuevo->nbpropietario,'\n');
  
  cout<<"\n INSERTE NOMBRE DEL MODELO: ";
  //cin.ignore();
  getline(cin,nuevo->nbmodelo,'\n');

  cout<<"\n INSERTE NOMBRE DE LA MARCA: ";
  //cin.ignore();
  getline(cin,nuevo->marca,'\n');
  
  cout<<"\n fecha de compra: ";
  //cin.ignore();
  getline(cin,nuevo->fechacompra,'\n');


  /* comienzo sera el siguiente de nuevo nodo */
  nuevo->sig = *comienzo;

  /*  hace un nuevo nodo del comienzo previo */
  (*comienzo)->ant = nuevo;

  /* hace el ultimo previo del nuevo nodo */
  nuevo->ant = ultimo;

  /* hace un nuevo nodo proximo de el viejo ultimo */ 
  ultimo->sig = nuevo;
}



//funcion para mostrar toda la lista
void mostrar(vehiculo* comienzo)
{
  vehiculo* aux = comienzo;

  while(aux->sig != comienzo)
    {
      cout<<aux->placa<<" ||| "<<aux->nbpropietario<<" || |"<<aux->nbmodelo<<" ||| "<<aux->marca<<" ||| "<<aux->fechacompra<<"\n";
      aux = aux->sig;
    }
  cout<<aux->placa<<" ||| "<<aux->nbpropietario<<" ||| "<<aux->nbmodelo<<" ||| "<<aux->marca<<" ||| "<<aux->fechacompra<<"\n";
}



//funcion para borra elementos
void borrar(vehiculo** comienzo)
{
  string comprobar;
  
  if(*comienzo == NULL)
    {
      return;
    }

  vehiculo *act = *comienzo, *ant_1 = NULL;

  cout<<"inserte la placa a borrar: ";
  getline(cin,comprobar,'\n');
  
  while(act->placa != comprobar)
    {
      if(act->sig == *comienzo)
	{
	  cout<<"\n La placa "<<comprobar<<" no existe en la lista.\n";
	  return;
	}
      ant_1 = act;
      act = act->sig;
    }

  if(act->sig == *comienzo && ant_1 == NULL)
    {
      (*comienzo) = NULL;
      free(act);
      return;
    }

  if(act == *comienzo)
    {
      ant_1 = (*comienzo)->ant;

      *comienzo = (*comienzo)->sig;

      ant_1->sig = *comienzo;
      (*comienzo)->ant = ant_1;
      free(act);
    }

  else if(act->sig == *comienzo)
    {
      ant_1->sig = *comienzo;
      (*comienzo)->ant = ant_1;
      free(act);
    }
  else
    {
      vehiculo* aux = act->sig;

      ant_1->sig = aux;
      aux->ant = ant_1;
      free(act);
    }
}

int buscar(vehiculo* comienzo)
{
  vehiculo *aux = comienzo;

  int cont=0,bandera=0;
  string busqueda;

  cout<<"INSERTE EL VALOR A BUSCAR: ";
  getline(cin,busqueda,'\n');
  
  if(aux == NULL)
    {
      return -1;
    }
  else
    {
      while(aux->sig != comienzo)
	{
	  cont++;

	  if(aux->placa == busqueda)
	    {
	      bandera=1;
	      cont--;
	      break;
	    }
	  aux = aux->sig;
	}

      if(aux->placa == busqueda)
	{
	  cont++;
	  bandera = 1;
	}

      if(bandera == 1)
	{
	  cout<<"\n la placa "<<busqueda<<" se consiguio en la posicion "<<cont<<endl;
	}
      else
	{
	  cout<<"\n la placa "<<busqueda<<" no encontrada.\n";
	}
    }
  return 0;
}

int main() 
{ 
  // Start with the empty list 
  vehiculo* comienzo = NULL; 

  insertar(&comienzo);
  insertar(&comienzo);
  insertar(&comienzo);
  //insertar(&comienzo);
  mostrar(comienzo);
  borrar(&comienzo);
  mostrar(comienzo);
  buscar(comienzo);
  return 0;
}
