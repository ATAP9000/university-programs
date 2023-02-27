#include <iostream>
#include <string>
#include <cctype>  //falta annadir restricciones para que la cedula no pueda ser 0, igual que los salarios
#include <algorithm>

using namespace std;

struct empleado{
  int ci;
  string nombre;
  double salario;
} e[10];

int opcion,cedula,cont;
bool loop=true,error=true;

int main(){
  cout<<"programa de registro de una lista de empleados, cuales tendran ci, nombre(incluido apellido), y su salario. El programa deberia poder: 1)agregar empleados, borrar empleados(segun la id que se provea), mostrar un empleado, y mostrar la lista completa.\n";

  while(loop==true){
    do{
      cout<<"MENU:\n 1.AGREGAR EMPLEADO\n 2.BORRAR EMPLEADO\n 3.MOSTRAR EMPLEADO\n 4.MOSTRAR LISTA DE EMPLEADOS\n 5.SALIR\n";
      cin>>opcion;
      if(cin.fail()){
      cin.clear();cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}
    }while(!opcion);
      
       switch(opcion){

       case 1:{
	 
     	for(int i=0;i<4;i++){

	  if(cont<4){
	    
     	     if(e[i].ci==0){
	       
	       do{
		 
		 cout<<"INSERTE CEDULA DEL EMPLEADO: ";
		 
		 cin>>e[i].ci;
		 
		 if(cin.fail()){

		   cout<<"dato invalido\n";
		   
		   cin.clear();cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		   
		 }
		 
	       }while(!e[i].ci);
	       
	       do{
	       
		 cout<<"\nINSERTE NOMBRE: "; //solucionar para que lea esto como string, ve si no tienes que usar los arrays y NO USES MAS WHILES

		 cin.ignore();
		 
		 getline(cin,e[i].nombre,'\n');

		 for(int row = 0; row < e[i].nombre.size(); row++){

		   if(isalpha(e[i].nombre[row]) ||isspace(e[i].nombre[row]) ){     //este ciclo for es para chequear si el string es un nombre valido(los nombres no pueden tener numeros, pero el isspace me permite dejar los espacios en blancos)
		     
		     error=false;
		   
		   }else{   //curiosamente no devolvera el mensaje si se pone solo un caracter
		     cout<<"Nombre invalido los nombres no pueden tener numeros o caracteres\n";
		     
		     error=true;
		     
		     break;
		     
		   }

		 }
		 
	       }while(error==true);

		 do{
		   cout<<"\nINSERTE SALARIO: ";
		   
		   cin>>e[i].salario;

		   if(cin.fail()){

		   cout<<"dato invalido\n";
		   
		   cin.clear();cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		   
		   }else{

		     cout<<"\n se ha insertado exitosamente el trabajador.\n";

		     cont++;

		   }
		 
	       }while(!e[i].salario);       

		 break;  //este break permite salir del for, si se pone en otro lado terminaria nunca volviendo entrar al for (la opcion nunca se realizaria).
	     }
	  }
	}
	 
	if(cont==4){
	  cout<<"lista llena!\n";
	}
	break;
       }
	
       case 2:{error=true;
	 cout<<"INSERTE LA CEDULA DEL EMPLEADO: ";
	  cin>>cedula;
	  for(int i=0; i<4;i++){
	    if(cedula==e[i].ci){
	      e[i].ci=0;                        //revisar esto luego por si falta annadir alguna restriccion (caracteres)
	      e[i].nombre.erase(e[i].nombre.begin(),e[i].nombre.begin());
	      e[i].salario=0;
	      cout<<"SE HA BORRADO EL EMPLEADO.\n"; cont--;
	      error=false;}}
	    if(error==true){
	      cout<<"EMPLEADO NO ESTA REGISTRADO.\n"; error=false;}
	  break;}
	
       case 3:{error=true;
	 cout<<"INSERTE LA CEDULA DEL EMPLEADO: ";
	  cin>>cedula;
	  for(int i=0; i<10;i++){
	    if(cedula==e[i].ci){
	      cout<<e[i].ci<<"    "<<e[i].nombre<<"     "<<e[i].salario<<"\n";
	      error=false;}}
	    if(error==true){
	      cout<<"EMPLEADO NO ESTA REGISTRADO.\n"; error=false;}
	  break;}
	
      case 4:{

	cout<<"CEDULA     NOMBRE     SALARIO\n";

	for(int i=0;i<10;i++){

	  if(e[i].ci!=0){

	    cout<<e[i].ci<<"          "<<e[i].nombre<<"          "<<e[i].salario<<endl;

	  }

	}
	
	break;

      }

       case 5:{

	 loop=0;

	 cout<<"fin";

	 break;

       }

       default:{

	 cout<<"opcion no valida\n";

	 break;

       }

       }

  }

}
	  
