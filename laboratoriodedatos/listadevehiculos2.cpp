#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string> //string.h me cagaba todo
#include <algorithm>
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
vehiculo* comienzo = NULL;

//funcion para insertar un vehiculo a la lista
void insertar(vehiculo** comienzo)
{
  /**/
 
  int e=0;
  /* si la lista esta vacia, se crea un nodo */
 vehiculo* act = *comienzo;
   
 vehiculo* nuevo = new vehiculo;
 
 /*las placas pueden tener letras y numeros, pero no simbolos */
 cout<<"\n INSERTE NUMERO DE PLACA: ";
 cin.ignore();
 getline(cin,nuevo->placa,'\n');

 
 /* los nombres solo pueden tener letras */
 do{
   cout<<"\n INSERTE NOMBRE DEL PROPIETARIO: ";
   //cin.ignore();
   getline(cin,nuevo->nbpropietario,'\n');
 
   for(int row = 0; row < nuevo->nbpropietario.size(); row++)
     {
       if(isalpha(nuevo->nbpropietario[row]) || isspace(nuevo->nbpropietario[row]))
	 {
	   e=0;
	 }
	 else
	   {
	     cout<<"nombre invalido, nombre no puede tener numeros o caracteres.\n";
	     e=1;
	   }
     }
 }while(e=0);
	 
 
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
      
 // Case 1 of the above algo  
 if (act == NULL)  
   {
     nuevo->sig = nuevo;
     *comienzo = nuevo;
    }  
 
 // Case 2 of the above algo  
 else if (act->placa >= nuevo->placa)  
   {  
     /* si el valor es mas pequenno que el valor del comienzo entonces
        necesitamos cambiar el sig del ultimo nodo */
     while(act->sig != *comienzo)  
       act = act->sig;  
     act->sig = nuevo;  
     nuevo->sig = *comienzo;  
     *comienzo = nuevo;
      
   }  
 
 // Case 3 of the above algo  
 else
   {  
     /* Locate the node before the point of insertion */
     while (act->sig!= *comienzo && act->sig->placa < nuevo->placa)  
       {
	 act = act->sig;  
       }
     
     nuevo->sig = act->sig;  
     act->sig = nuevo;
   }
 
}  

//funcion para mostrar toda la listav
void mostrar(vehiculo* comienzo)
{
  vehiculo* aux = comienzo;
  if(aux == NULL){
    cout<<"lista vacia\n";
  }
  else{
    
  while(aux->sig != comienzo) 
    {
      cout<<aux->placa<<" ||| "<<aux->nbpropietario<<" ||| "<<aux->nbmodelo<<" ||| "<<aux->marca<<" ||| "<<aux->fechacompra<<"\n";
      aux = aux->sig;
    }
    cout<<aux->placa<<" ||| "<<aux->nbpropietario<<" ||| "<<aux->nbmodelo<<" ||| "<<aux->marca<<" ||| "<<aux->fechacompra<<"\n";
  }

}


//funcion para borra elementos
void borrar(vehiculo** comienzo)
{
  vehiculo* aux;
  string comprobar;
  
  if(*comienzo == NULL)
    {
      return;
      }

  vehiculo *act_1 = *comienzo, *ant_1 = NULL;

  cout<<"inserte la placa a borrar: ";
  cin.ignore();
  getline(cin,comprobar,'\n');
  
  while(act_1->placa != comprobar)
    {
      if(act_1->sig == *comienzo)
	{
	  cout<<"\n La placa "<<comprobar<<" no existe en la lista.\n";
	  return;
	}
      ant_1 = act_1;
      act_1 = act_1->sig;
    }

  if(act_1->sig == *comienzo && ant_1 == NULL)
    {
      (*comienzo) = NULL;
      free(act_1);
      return;
    }

  if(act_1 == *comienzo)
    {
      ant_1 = (*comienzo)->ant; //esto parece ser el error parece ser que hay mas

      *comienzo = (*comienzo)->sig;   //esto me permite borrar

      ant_1->sig = *comienzo;
      (*comienzo)->ant = ant_1; //puse sig en vez de ant
      free(act_1);
    }
  
  else if(act_1->sig == *comienzo)
    {
      ant_1->sig = *comienzo;
      (*comienzo)->ant = ant_1;  //igual aqui
      free(act_1);
    }
  else
    {
      if(act_1->ant == NULL){  //parece ser que esto es el cuasante de todo
	cout<<"error de memoria.\n";
      }
      else
	{
     /* vehiculo* */aux = act_1->sig;

      ant_1->sig = aux;
      aux->ant = ant_1;
      free(act_1);
	}
    }
}

int buscar(vehiculo* comienzo)
{
  vehiculo *aux = comienzo;

  int cont=0,bandera=0;
  string busqueda;

  cout<<"INSERTE EL VALOR A BUSCAR: ";
  cin.ignore();
  getline(cin,busqueda,'\n');
  
  if(aux == NULL)
    {
      cout<<"no hay lista\n";
      return 0;
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

int main()  //programa funciona pero tiene un error de que solo si es el ultimo o mayor (debido al sorting) puede borrarse
  
{
  // Start with the empty list 
  vehiculo* comienzo = NULL; 
  int opcion;
  bool loop=true,error=true;

cout<<"programa de lista usando registro de una lista de vehiculos, cuales tendran placa, nombre de propietario, modelo del vehiculo, marca, y fecha de compra. El programa deberia poder: 1)agregar vehiculos, 2)borrar vehiculos(segun la placa que se provea), 3)buscar el vehiculo y decir en que posicion, y 4)mostrar la lista completa.\n";

  while(loop==true){
    do{
      cout<<"MENU:\n 1.AGREGAR VEHICULO\n 2.BORRAR VEHICULO\n 3.BUSCAR VEHICULO\n 4.MOSTRAR LISTA\n 5.SALIR\n";
      cin>>opcion;
      if(cin.fail()){
      cin.clear();cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}
    }while(!opcion);
      
       switch(opcion){

       case 1:
	 {
	   insertar(& comienzo);
	   break;
	 }
	
       case 2:
	 {
	   borrar(&comienzo);
	   break;
	 }
	
       case 3:
	 {
	   buscar(comienzo);
	   break;
	 }
	
      case 4:
	{
	  mostrar(comienzo);
	  break;
	}

       case 5:
	 {
	 loop=0;
	 cout<<"fin del programa\n";
	 break;
       }

       default:
	 {
	 cout<<"opcion no valida\n";
	 break;
	 }
	 
       }

  }
}

