#include <iostream>
#include <stdlib.h>
#include <string> 
#include <algorithm>
#include <cctype>

using namespace std;

struct agenda_telefonica{    /* Registro de agenda telefonica */
  
  string numerotelf;         /* los numeros de telefonos */
  string nombre;             /* nombre del propietario */
  string marca;              /* nombre de la marca */
  string diacumple;          /* dia de cumple de la persona */
  string mescumple;          /* mes de cumple de la persona */
  string annocumple;         /* anno de cumple de la persona */
             
  agenda_telefonica *sig;    /* Puntero para los vehiculos */

} *cabeza = NULL;


void mostrar(){

  if(!cabeza)
    {
      cout<<"lista vacia!\n";
    }
  else
    {
      agenda_telefonica* aux = cabeza;
      
      cout<<"NUMERO      ||| NOMBRE     ||| MARCA    |||FECHA CUMPLEANNOS|\n";
      while (aux != NULL)
	{
	  cout<<aux->numerotelf<<" ||| "<<aux->nombre<<" ||| "<<aux->marca<<" ||| "<<aux->diacumple<<"/"<<aux->mescumple<<"/"<<aux->annocumple<<"\n";
	  aux = aux -> sig;

	}
    }
}

void insertar(){
  cin.ignore();
  int a;
  char res;
  agenda_telefonica *nuevo = new agenda_telefonica;   //Crea espacio para el nuevo nodo
  
  do
    {
      a=0;
      cout<<"\nINSERTE NUMERO DE TELEFONO (11 digitos): ";
      getline(cin,nuevo->numerotelf,'\n');

      cout<<"cantidad provista para el numero:"<<nuevo->numerotelf.length()<<endl;
      
      if(nuevo->numerotelf.length() < 11 || nuevo->numerotelf.length() > 11)
	{
	  a=1;
	  cout<<"la cantidad ingresada no es la adecuada para un numero de telefono, tienen que ser 11 digitos. intente de nuevo\n";
	} 
      else
	{
	  for (int i = 0; i < 11; ++i) {
	    if (std::isalpha(nuevo->numerotelf[i]))
	      {
		a=1;
		cout<<"no se permite usar letras para un numero de telefono.\n";
		break;
	      }
	  }
	}
      
    }while(a==1);
  
  do
    {
      a=0;
      cout<<"\n INSERTE NOMBRE: ";
      getline(cin,nuevo->nombre,'\n');
      
      for(int row = 0; row < nuevo->nombre.size(); row++)
	{
	
	  if(isdigit(nuevo->nombre[row])) // este ciclo es para chequear si el string tiene un nombre valido(no debe tener numeros) 
	    {     
	      a=1;
	      cout<<"Nombre invalido los nombres no pueden tener numeros\n";	  
	    }
	}
    }while(a==1);
  
  /* las marcas telefonicas pueden ser llamadas como sea */
  cout<<"\n INSERTE NOMBRE DE LA MARCA: ";
  getline(cin,nuevo->marca,'\n');
 
  do
    {
      /* el dia puede ser llamado como sea, se da la libertad al usuario de eso*/
      cout<<"\n DIA DE CUMPLEANNOS: ";
      getline(cin,nuevo->diacumple,'\n');                   
      /* el dia puede ser llamado como sea, se da la libertad al usuario de eso*/
      cout<<"\n MES DE CUMPLEANNOS: ";
      getline(cin,nuevo->mescumple,'\n');
      /* el dia puede ser llamado como sea, se da la libertad al usuario de eso*/
      cout<<"\n ANNO DE CUMPLEANNOS: ";
      getline(cin,nuevo->annocumple,'\n');

      cout<<"esta fecha es correcta? s/n \n";
      cin>>res;
      cin.ignore();
    }while(res!='s');
   
  if(!cabeza || nuevo->numerotelf <= cabeza->numerotelf)   //Insertando en el frente
    {
      if(cabeza) nuevo->sig = NULL;
      else nuevo->sig = cabeza;
      cabeza = nuevo;
    }
      else
	{/*
	  agenda_telefonica *aux = cabeza, *ant = NULL;
	  while(aux && nuevo->numerotelf > aux->numerotelf)
	    {
	      ant = aux;
	      aux = aux ->sig; //va pasando por la lista
	    }
	  nuevo->sig = aux; //Inserta en medio o por atras
	  ant->sig = nuevo;
	 */
	  cout<<"numero smol nose puede\n";
	}
}

void borrarduplicados()   //funcion de chequeo que revisa la lista, si encuentra un duplicado lo sobre escribe con el nuevo 
{ 
    agenda_telefonica *ptr1, *ptr2, *dup; 
    ptr1 = cabeza; 
  
    while (ptr1 != NULL && ptr1->sig != NULL)  //Selecciona los elementos uno por uno 
    { 
        ptr2 = ptr1; 
  
        while (ptr2->sig != NULL) //comparacion del elemento seleccionado con el resto de los elementos)
        { 
           
	  if (ptr1->numerotelf == ptr2->sig->numerotelf)  // si es duplicado lo borra
            { 
                dup = ptr2->sig; 
                ptr2->sig = ptr2->sig->sig; 
                delete(dup); 
            } 
	  else
	    {
                ptr2 = ptr2->sig; 
	    }
	} 
        ptr1 = ptr1->sig; 
    } 
} 

void borrar()
{
  cin.ignore();
  string a;
  agenda_telefonica* aux = cabeza, *ant = NULL;
  if(aux==NULL){
    cout<<"lista vacia no puedes borrar!\n";
  }
  else{
    cout<<"inserte el numero a borrar: ";
    getline(cin,a,'\n');
    while(aux)  //pasa por la lista hasta que encuentre lo que se pide
      {
	if(aux->numerotelf == a)
	  {
	    break;
	  }
	ant = aux;
	aux = aux->sig;
      }
    if(!aux)
      {
	cout<<"\n Numero no encontrado.\n";
      }
    else{
      agenda_telefonica *referencia = aux;  //referencia es el nodo a ser borrado
      if(referencia == cabeza)
	{
	  cabeza = cabeza->sig;    //borrando por el frente 
	}
      else
	{
	  ant->sig = referencia->sig;
	}                          //borrando por el medio/final
      free(referencia);
    }
  }
}

void buscar()
{
  cin.ignore();
  int indice=0;
  string valor;
  agenda_telefonica *act;
  act = cabeza;

  cout<<"dato a buscar: ";
  getline(cin,valor,'\n');
  
  while(act != NULL && act->numerotelf != valor)
    {
      indice++;
      act = act->sig;
    }

  if(indice >= 0 && act != NULL)
    {
      cout<<valor<<" encontrado en la posicion: "<<indice+1<<"\n y le pertenece a: "<<act->numerotelf<<" ||| "<<act->nombre<<" ||| "<<act->marca<<" ||| "<<act->diacumple<<"/"<<act->mescumple<<"/"<<act->annocumple<<"\n";
    }
  else
    {
      cout<<valor<<" no se encuentra en la lista.\n";
    }
}

int main(){
  int opcion;

  cout<<"programa de lista usando un registro llamado agenda telefonica, cual tendra numero de telefono, nombre, marca, y fecha de cumpleannos (dia/mes/anno). El programa deberia poder: 1)agregar numeros de telefonos de forma ordenada, 2)buscar los numeros de telefono.\n";

  while(1){

    do{

      cout<<"MENU:\n 1.AGREGAR NUMERO\n 2.BORRAR NUMERO\n 3.MOSTRAR LISTA\n 4.BUSCAR 5.SALIR\n";

      cin>>opcion;

      if(cin.fail()){
	
	cin.clear();cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}   //esto es por si se llegase a colocar un caracter o algo
      
    }while(!opcion);

    switch(opcion){

    case 1:

      insertar();
      borrarduplicados();
      break;

    case 2:

      //if(cabeza){

      borrar();

      //}

      break;

    case 3:

      mostrar();

      break;

    case 4:

      buscar();

      break;

    case 5:

      cout<<"\nFin del programa.\n";

      return 0;

    default:

      cout<<"\nOpcion invalida intente de nuevo.\n";

      break;

    }

  }
  
}
