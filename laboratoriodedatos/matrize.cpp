#include <iostream>
using namespace std;
int filas, cont, columnas,grande[10],grando, sum, matriz[100][100];

int main(){
  cout<<"inserte el numero de filas: "; cin>>filas;
  cout<<"inserte el numero de columnas: "; cin>>columnas;
  for(int i=1; i<filas+1; i++){
    for(int j=1; j<columnas+1; j++){
      cout<<"inserte los de votos para la ciudad "<<i<<" para el candidato "<<j<<"\n";
      cin>>matriz[i][j];
    }}
  for(int i=1; i<filas+1; i++){
    for(int j=1; j<columnas+1; j++){
      cout<<"la cantidad de votos en la ciudad "<<i<<" por el candidato "<<j<<" fueron de:"<<matriz[i][j]<<"\n";
    }}
  for(int i=1; i<columnas+1; i++){
    sum=0;
    for(int j=1; j<filas+1; j++){   //aqui hice cambio

      sum+=matriz[j][i];
    }
    grande[i]=sum;
    cout<<"la suma total de votos por el candidato "<<i<<" fueron de: "<<sum<<"\n";} //observar esto con cuidado posible tendria que cambiarse filas
  for(int i=1; i<filas+1; i++){                                                      //y columnas dentro de los for
    sum=0;
    for(int j=1; j<columnas+1; j++){
      sum+=matriz[i][j]; }
    cout<<"la suma total de votos en la ciudad "<<i<<" fueron de: "<<sum<<"\n";}
  grando = grande[1];
  for(int i=1; i<columnas+1;i++){ 
    if(grando<=grande[i]){
      grando=grande[i];cont=i;}}
    cout<<"gano el candidato "<<cont<<" con una cantidad de: "<<grando<<" votos! \n";std::cin.ignore();std::cin.get();}    
