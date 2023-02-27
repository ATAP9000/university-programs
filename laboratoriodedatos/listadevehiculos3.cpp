#include <iostream>
#include <stdlib.h>
#include <string> 
#include <algorithm>
using namespace std;

struct vehiculo{
  string placa;         /* las placas tienes letras por eso usa string */
  string nbpropietario; /* nombre del propietario */
  string nbmodelo;      /* nombre del modelo del vehiculo*/
  string marca;         /* nombre de la marca */
  string fechacompra;   /* fecha de compra del vehiculo (dia/mes/anno) */
  
  /* Puntero para los vehiculos */
  vehiculo *sig;
} *cabeza = NULL;

void display(){
  if(!cabeza)
    {
      cout<<"lista vacia!\n";
    }
  else
    {
      vehiculo* aux = cabeza;
      
      while (aux != NULL)
	{
	  cout<<aux->placa<<" ||| "<<aux->nbpropietario<<" ||| "<<aux->nbmodelo<<" ||| "<<aux->marca<<" ||| "<<aux->fechacompra<<endl;
	 aux = aux -> sig;
        }
    }
}

void insertar(){
  cin.ignore();
  char res;
  string diacompra,mescompra,annocompra;
  string a;
  vehiculo *nuevo = new vehiculo;   //Crea espcio pr el nuevo nodo
  
  cout<<"\n INSERTE NUMERO DE PLACA: ";
  getline(cin,a,'\n');
  nuevo->placa = a;
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
  
  do                                                                                //la razon del porque deje esto como string es para dejar en el
    {                                                                               //registro solo fecha de cumpleannos, realmente no se si podia
      /* el dia puede ser llamado como sea, se da la libertad al usuario de eso*/   //separalo o no, asi que opte por este metodo usando strings
      cout<<"\n DIA DE CUMPLEANNOS: ";                                              //y termina uniendo todo para obtener la fecha al final
      getline(cin,diacompra,'\n');                                                  //donde el usuario confirma si esta bien o no.
      /* el dia puede ser llamado como sea, se da la libertad al usuario de eso*/   //tampoco sabia si deberia usar la funcion to_string debido a
      cout<<"\n MES DE CUMPLEANNOS: ";                                              //que es c++11 y preferi evitarme algun inconveniente por eso
      getline(cin,mescompra,'\n');
      /* el dia puede ser llamado como sea, se da la libertad al usuario de eso*/
      cout<<"\n ANNO DE CUMPLEANNOS: ";
      getline(cin,annocompra,'\n');
      
      nuevo->fechacompra=diacompra+"/"+mescompra+"/"+annocompra;
      cout<<"esta fecha "<<nuevo->fechacompra<<" es correcta? s/n \n";
      cin>>res;
      cin.ignore();
    }while(res!='s');
  
  if(!cabeza || a <= cabeza->placa)   //Insertando en el frente
    {
      if(cabeza) nuevo->sig = cabeza;
      else nuevo->sig = NULL;
        cabeza = nuevo;
    }
  else
    {
      vehiculo *aux = cabeza, *ant = NULL;
      while(aux && a > aux->placa)
	{
	  ant = aux;
	  aux = aux ->sig; //va pasando por la lista
	}
      nuevo->sig = aux; //Inserta en medio o por atras
      ant->sig = nuevo;
    }
}



void borrar()
{
  cin.ignore();
  string a;
  vehiculo* aux = cabeza, *ant = NULL;
  if(aux==NULL){
    cout<<"lista vacia no puedes borrar!\n";
  }
  else{
    cout<<"inserte la placa a borrar: ";
    getline(cin,a,'\n');
    while(aux)  //pasa por la lista hasta que encuentre lo que se pide
      {
	if(aux->placa == a)
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
      vehiculo *referencia = aux;  //referencia es el nodo a ser borrado
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
  vehiculo *act;
  act = cabeza;

  cout<<"dato a buscar: ";
  getline(cin,valor,'\n');

  while(act != NULL && act->placa != valor)
    {
      indice++;
      act = act->sig;
    }

  if(indice >= 0 && act != NULL)
    {
      cout<<valor<<" encontrado en la posicion: "<<indice+1<<"\n y le pertenece a: "<<act->nbpropietario<<" ||| "<<act->nbmodelo<<" ||| "<<act->marca<<" ||| "<<act->fechacompra<<endl;
    }
  else
    {
      cout<<valor<<" no se encuentra en la lista.\n";
    }
}

int main(){
    int opcion;
    cout<<"programa de lista usando registro de una lista de vehiculos, cuales tendran placa, nombre de propietario, modelo del vehiculo, marca, y fecha de compra. El programa deberia poder: 1)agregar vehiculos, 2)borrar vehiculos(segun la placa que se provea), 3)mostrar la lista completa.\n";
    while(1){
      do{
	cout<<"MENU:\n 1.AGREGAR VEHICULO\n 2.BORRAR VEHICULO\n 3.MOSTRAR LISTA\n 4.SALIR\n";
	cin>>opcion;
	if(cin.fail()){
	  cin.clear();cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}
      }while(!opcion);
      switch(opcion){
      case 1:
	insertar();
	break;
      case 2:
	//if(cabeza){
	  borrar();
	  //}
	break;
      case 3:
	display();
	break;
      default:
	printf("\nOpcion invalida intente de nuevo.\n");
	break;
      case 4:
	printf("\nFin del programa.\n");
	return 0;
      case 5:
	buscar();
	break;
      }
    }
}
