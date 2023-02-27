#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

/*estructura del empleado (cada uno es un nodo)*/
struct empleado
{
  int ci; /* cedula de identidad */
  string nb; /* nombre */
  int sal; /* salario */

  /* punteros para los empleados que esten antes y despues */
  empleado *ant;
  empleado *sig;
};

void insertar(empleado** comienzo){
  if(*comienzo == NULL){
    empleado* nuevo = new empleado;
    cout<<"\n INSERTE CEDULa: ";
    cin>>nuevo->ci;
    cout<<"\n INSERTE NOMBRE: ";
    cin.ignore();
    getline(cin,nuevo->nb,'\n');
    //cin>>nuevo->nb;
    cout<<"\n INSERTE salario: ";
    cin>>nuevo->sal;
    nuevo->sig = nuevo->ant = nuevo;
    *comienzo = nuevo;
    return;
  }

  empleado* ultimo = (*comienzo)->ant;

  empleado* nuevo = new empleado;
  cout<<"\n INSERTE CEDULa: ";
  cin>>nuevo->ci;
  cout<<"\n INSERTE NOMBRE: ";
  cin>>nuevo->nb;
  cout<<"\n INSERTE salario: ";
  cin>>nuevo->sal;
  /*pensar si emplear repercusion aqui solo por los kekes*/
  
  nuevo->sig = *comienzo;
  (*comienzo)->ant = nuevo;
  nuevo->ant = ultimo;
  ultimo->sig = nuevo;
}

void mostrar(empleado* comienzo)
{
  empleado* aux = comienzo;

  while(aux->sig != comienzo)
    {
      cout<<aux->ci<<" "<<aux->nb<<" "<<aux->sal<<"\n";
      aux = aux->sig;
    };
  cout<<aux->ci<<" "<<aux->nb<<" "<<aux->sal<<"\n";
}

void borrar(empleado** comienzo)
{
  int cedula;
  
  if(*comienzo == NULL)
    {
      return;
    }
  
  empleado *act = *comienzo, *ant_1 = NULL;
  
  cout<<"inserte el empleado a eliminar (cedula): ";
  cin>>cedula;
  while(act->ci != cedula)
    {
      if(act->sig == *comienzo)
	{
	  cout<<"\n el empleado "<<cedula<<"  no existe.\n";
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
      empleado* aux = act->sig;
      ant_1->sig = aux;
      aux->ant = ant_1;
      free(act);
    }
  /* pensar en incluir repercusion por los kekes */
}

//int buscar(empleadooar(comienzo);
// mostrar(comienzo);
//}
  
