#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> vectore;
  int opcion;
  int alguien;
  char respuesta;
  int contador=0;
  vectore.push_back(0);
  
  cout<<"El presente programa es sobre colas, referente a una cola de maximo de 20 personas con las condiciones de: usar arreglos/vectores y solamente 1 del escogido. el programa debera decir quien esta llegando, a quien se esta atendiendo, resultado(desplazar el primero fuera de la lista y mover a todos los demas un puesto adelante), total de personas atendidas. \n";

  do{
    cout<<"Que desea hacer? \n 1. alguien llega a la cola. \n 2. a quien estan atendiendo. \n 3. despachar. \n 4. personas atendidas. \n 5. terminar. \n";
    cin>>opcion;
    switch(opcion){
    case 1:{
      cout<<"ha llegado una nueva persona a la cola! \n y es:\n 1)un hombre \n 2)una mujer \n 3)algo\n (seleccione) \n";
      cin>>alguien;
      if(alguien==1){vectore.push_back(1); contador++;}
      if(alguien==2){vectore.push_back(2); contador++;}
      if(alguien==3){vectore.push_back(3); contador++;}
      if(alguien!=1 && alguien!=2 && alguien!=3){cout<<"opcion invalida intente de nuevo.\n";}
      ;break;}
    case 2:{
      if(vectore.size()==1){cout<<"no hay nadie en la cola. \n";}
      if(vectore[1]==1){cout<<"esta siendo atendido un hombre \n";}
      if(vectore[1]==2){cout<<"esta siendo atendido una mujer \n";}
      if(vectore[1]==3){cout<<"esta siendo atendido algo \n";}
      break;}
    case 3:{if(vectore.size()>1){vectore.erase(vectore.begin() +1);}
	if(vectore.size()==1){cout<<"no hay nadie en la cola. \n";}
	break;}
    case 4:{cout<<"se han atendido: " << contador << " personas! \n";break;}
    case 5:{cout<<"seguro que desea salir? s/n \n";
	cin>>respuesta; break;}
    default:{cout<<"la opcion no existe, volviendo al menu \n"; break;}
    };}while(respuesta!='s');}
