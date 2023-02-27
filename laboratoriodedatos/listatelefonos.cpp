//alumno: angelo tarazona programa de listas
//todo lo que esta hecho aqui fue compilado con el compilador g++

#include <iostream>       //libreria in/out estandard de c++
#include <stdlib.h>       //uso esta libreria para emplear el null
#include <string>         //uso la libreria de string de c++ 
#include <algorithm>      //uso la libreria de algoritmo solo para una funcion de seleccion en el menu
#include <cctype>         //uso cctype para hacer chequeos en los strings

using namespace std;

struct agenda_telefonica{    /* Registro de agenda telefonica */
  
  string numerotelf;         /* los numeros de telefonos */           //la razon de porque es string es para tener mas facil manejo de datos
  string nombre;             /* nombre del propietario */             //los strings permiten organizar los valores normalmente y permiten incluir el 0
  string marca;              /* nombre de la marca */                 //al principio si el numero asi lo pide "tipo 0412 o parecidos" 

  string fechacumple;        /* fecha de cumpleannos de la persona */ //vease la insersion para explicacion del por que es string 
             
  agenda_telefonica *sig;    /* Puntero para la agenda */

} *cabeza = NULL;            // esto me permite tener la lista (por defecto vacia) 

//funcion para mostrar toda la lista
void mostrar(){

  if(!cabeza)   //si cabeza esta null lo considera como lista vacia
    {
      cout<<"lista vacia!\n";
    }
  else
    {
      agenda_telefonica* aux = cabeza;
      
      cout<<"NUMERO      ||| NOMBRE     ||| MARCA    |||FECHA CUMPLEANNOS\n";         //informacion del orden de los datos
      while (aux != NULL)
	{
	  cout<<aux->numerotelf<<" ||| "<<aux->nombre<<" ||| "<<aux->marca<<" ||| "<<aux->fechacumple<<"\n"; //datos a devolver
	  aux = aux -> sig;

	}
    }
}


//funcion para insertar 
void insertar(){
  cin.ignore();
  int a;                                             //se usa para chequear el numero de telefono
  char res;                                          //se usa para chequear la seleccion de fecha
  string diacumple,mescumple,annocumple;             //los strings para las fechas
  
  agenda_telefonica *nuevo = new agenda_telefonica;   //Crea espacio para el nuevo nodo
  
  do
    {
      a=0;
      /* los numero de telefono solo pueden tener digitos */
      cout<<"\nINSERTE NUMERO DE TELEFONO (11 digitos): ";     //deje que solo pudiera insertar strings que tengan solo 11 digitos
      getline(cin,nuevo->numerotelf,'\n');                     //ejemplo de un numero seria 04121234578 

      cout<<"cantidad provista para el numero:"<<nuevo->numerotelf.length()<<endl;
      
      if(nuevo->numerotelf.length() < 11 || nuevo->numerotelf.length() > 11)   //chequeo de que si el valor no es 11
	{                                                                      //no emplee != porque no me terminaba dando el resultado esperado
	  a=1;
	  cout<<"la cantidad ingresada no es la adecuada para un numero de telefono, tienen que ser 11 digitos. intente de nuevo\n";
	} 
      else
	{
	  for (int i = 0; i < 11; ++i) {
	    if (std::isalpha(nuevo->numerotelf[i]))     //chequea si tiene letras en el numero provisto, si tiene devuelve para introducir de nuevo
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
      /* los nombres no pueden tener digitos */
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
  
  /* las marcas pueden tener cualquier nombre */
  cout<<"\n INSERTE NOMBRE DE LA MARCA: ";
  getline(cin,nuevo->marca,'\n');
 
  do                                                                                //la razon del porque deje esto como string es para dejar en el
    {                                                                               //registro solo fecha de cumpleannos, realmente no se si podia
      /* el dia puede ser llamado como sea, se da la libertad al usuario de eso*/   //separalo o no, asi que opte por este metodo usando strings
      cout<<"\n DIA DE CUMPLEANNOS: ";                                              //y termina uniendo todo para obtener la fecha al final
      getline(cin,diacumple,'\n');                                                  //donde el usuario confirma si esta bien o no.
      /* el dia puede ser llamado como sea, se da la libertad al usuario de eso*/   //tampoco sabia si deberia usar la funcion to_string debido a
      cout<<"\n MES DE CUMPLEANNOS: ";                                              //que es c++11 y preferi evitarme algun inconveniente por eso
      getline(cin,mescumple,'\n');
      /* el dia puede ser llamado como sea, se da la libertad al usuario de eso*/
      cout<<"\n ANNO DE CUMPLEANNOS: ";
      getline(cin,annocumple,'\n');
      
      nuevo->fechacumple=diacumple+"/"+mescumple+"/"+annocumple;
      cout<<"esta fecha "<<nuevo->fechacumple<<" es correcta? s/n \n";
      cin>>res;
      cin.ignore();
    }while(res!='s');
   
  if(!cabeza || nuevo->numerotelf <= cabeza->numerotelf)   //aqui inserta el valor al frente
    {
      if(cabeza)
	{
	  nuevo->sig = cabeza;
	}
      else
	{
	nuevo->sig = NULL;
	}
      cabeza = nuevo;
    }
      else
	{
	  agenda_telefonica *aux = cabeza, *ant = NULL;
	  while(aux && nuevo->numerotelf > aux->numerotelf)
	    {
	      ant = aux;
	      aux = aux ->sig;                               //va pasando por la lista
	    }
	  nuevo->sig = aux;                                  //Inserta en el medio/atras
	  ant->sig = nuevo;
	  
	}
}

void borrarduplicados()   //funcion de chequeo que revisa la lista, si encuentra un duplicado, sobreescribe el original 
{ 
    agenda_telefonica *pun1, *pun2, *dup; 
    pun1 = cabeza; 
  
    while (pun1 != NULL && pun1->sig != NULL)  //Selecciona los elementos uno por uno 
    { 
        pun2 = pun1; 
  
        while (pun2->sig != NULL) //comparacion del elemento seleccionado con el resto de los elementos)
        { 
           
	  if (pun1->numerotelf == pun2->sig->numerotelf)  // si es duplicado lo borra
            { 
                dup = pun2->sig; 
                pun2->sig = pun2->sig->sig; 
                delete(dup); 
            } 
	  else
	    {
	      pun2 = pun2->sig;    //busca en la proxima posicion
	    }
	} 
        pun1 = pun1->sig; 
    } 
} 

//funcion de borrado
void borrar()                                                           //deje esta funcion como un adicional al programa
{
  cin.ignore();
  string a;
  agenda_telefonica* aux = cabeza, *ant = NULL;

  if(aux==NULL){
    cout<<"lista vacia no puedes borrar!\n";     
  }
  else{
    cout<<"inserte el numero a borrar: ";
    getline(cin,a,'\n');                                                   //esto es otra razon del por que uso string, evita que se tenga 
    while(aux)  //pasa por la lista hasta que encuentre lo que se pide     //que implementar alguna funcion de chequeo de errores
      {                                                                    //y si llegase a poner una letra o algo que no es un numero
	if(aux->numerotelf == a)                                           //no devolveria nada
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
	}               //borrando por el medio/final
      cout<<"se ha borrado el numero "<<a<<endl;
      free(referencia);
    }
  }
}


//funcion de busqueda
void buscar()
{
  cin.ignore();
  int indice=0;
  string valor;
  agenda_telefonica *act;
  act = cabeza;

  cout<<"dato a buscar: ";                                //el mismo caso que lo dicho en la funcion de borrar, permite mejor manejo
  getline(cin,valor,'\n');
  
  while(act != NULL && act->numerotelf != valor)
    {
      indice++;
      act = act->sig;
    }

  if(indice >= 0 && act != NULL)  //devuelve el valor y la posicion en que se encuentra de la lista
    {
      cout<<"el numero "<<valor<<" se encontra en la posicion: "<<indice+1<<"\n y contiene a: "<<act->nombre<<" ||| "<<act->marca<<" ||| "<<act->fechacumple<<"\n";
    }
  else
    {
      cout<<valor<<" no se encuentra en la lista.\n";
    }
}



//programa principal
int main(){
  int opcion;

  cout<<"programa de lista usando un registro llamado agenda telefonica, cual tendra numero de telefono, nombre, marca, y fecha de cumpleannos (dia/mes/anno). El programa deberia poder: 1)agregar numeros de telefonos de forma ordenada, 2)buscar los numeros de telefono.\n";

  while(1){

    do{

      cout<<"MENU:\n 1.AGREGAR NUMERO\n 2.BORRAR NUMERO\n 3.BUSCAR \n 4.VER LISTA\n 5.SALIR\n";     //he dejado la funcion borrar como adicional
                                                                                                    //disculpe si no queria esa funcion 
      cin>>opcion;                                                                                  //en este codigo

      if(cin.fail()){
	
	cin.clear();cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}   //esto es por si se llegase a colocar un caracter o algo
                                                                                      //y es el motivo de la libreria algoritmo
    }while(!opcion);

    switch(opcion){

    case 1:

      insertar();
      borrarduplicados();
      break;

    case 2:

      borrar();
      break;

    case 3:

      buscar();
      break;

    case 4:

      mostrar();
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
