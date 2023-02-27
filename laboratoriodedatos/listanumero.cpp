#include <iostream>
#include <algorithm>
using namespace std;

struct lista{
  
  int numero;
  lista *sig;

} *cabeza =NULL;

void insertar(int n){
  lista *nuevo = new lista;
  nuevo->numero = n;
  if(!cabeza || cabeza->numero < nuevo->numero )
    {
      if(cabeza) nuevo->sig = cabeza; //cabeza->sig = NULL;  //resolver como hacer que se inserte al frente
      else nuevo->sig = NULL;
      cabeza = nuevo; 
    }
  else
    {
      cout<<"numero muy pequenno intente de nuevo.\n";
    }
}

void display(lista* cabeza){
	if(cabeza){
	  display(cabeza->sig);
	  cout<<cabeza->numero<<" ";
	}
}

void mostrar()
{
  if(!cabeza)
    {
      cout<<"lista vacia!\n";
    }
  else
    {
      lista *aux = cabeza;
      while(aux != NULL)
	{
	  cout<<aux->numero<<endl;
	  aux = aux->sig;
	}
    }
}

int main(){
  int n, bandera;
  do{
    do{
      cout<<"inserte numero: \n";
      cin>>n;
      if(cin.fail())
	{
	  cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  cout<<"dato invalido\n";
	}
      else if(n<=0){
	cout<<" dato invalido\n";
      }

    }while(!n || n<=0);
    
    if(n!=999)
      {
	insertar(n);
      }
    else
      {
	bandera=1;
	display(cabeza);
      }
  }while(bandera!=1);
}


/*
int main(){
  int n,bandera;
  lista *aux = cabeza, *ant = NULL;
 
  do{
    do
      {
	cout<<"programa de lista, inserte numero naturales (solo se puede insertar con valores mayores que el anterior):\n";
      cin>>n;
      if(cin.fail())
	{
	  cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  cout<<"no es dato valido\n";
	  cin.clear();
	  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
      else if(n < 0)
	{
	  cout<<"dato invalido\n";
	}
      }while(!n || n < 0);

    lista *nuevo = new lista;
    
    if(n!=999){
      nuevo->numero = n;
      if(!cabeza)
	{
	    if(cabeza) nuevo->sig = cabeza; //cabeza->sig = NULL;  //resolver como hacer que se inserte al frente
	    else nuevo->sig = NULL;
	    nuevo->sig = NULL;
	    cabeza = nuevo; 
	}
      else
	{
	 while(aux && nuevo->numero > aux->numero)
	    {
	      ant = aux;
	      aux = aux ->sig; //va pasando por la lista
	    }
	  nuevo->sig = aux; //Inserta en medio o por atras
	  ant->sig = nuevo;
	}
      
    }
    else
      {
	cout<<"Fin del programa, lista final. (esta expuesta desde el final al comienzo)\n";
	bandera=1;
	nuevo = cabeza;
	if(!cabeza)
	  {
	    cout<<"lista vacia!\n";
	  }
	else
	  {
	    
	    while( cabeza != NULL)
	      {
		cout<<cabeza->numero<<endl;;
		
		cabeza = cabeza->sig;
		
	      }
	  }
      }
  }while(bandera!=1);
}
*/
