#include <iostream>
using namespace std;

struct numeros{
  
  int id, divisores[5];

} a[3]; //tener en cuenta que puedes poner arrays ahi donde esta a

int main(){
  cout<<"programa de numeros, donde se insertaran 20 (mayores a 50), donde se calcule y almacenen sus 5 primeros divisores solo usando el vector de estructura \n";
  for(int i=1;i<3;i++){
    do{
      cout<<"inserte el numero: ";
      
      cin>>a[i].id;
      
      if(a[i].id<=50){
	
	cout<<"\n numero invalido trate de nuevo. \n";}
      
    }while(a[i].id<=50);
    
    cout<<"el numero es: "<<a[i].id<<"\n";
    
  for(int j=1; j<=5;j++){
    
    for(int k=1; (k<=a[i].id);k++){

      if(j<=5){
	if(a[i].id%k==0){
      
	  a[i].divisores[j]=k;
 
	  cout<<"y su divores son: "<<a[i].divisores[j]<<"\n";j++;
	}
      }
 
    }
  }
  }
   for(int i=1;i<3;i++){

     cout<<"el numero es: "<<a[i].id<<"\n";
     
     for(int j=1;j<=5;j++){
       
       cout<<"y sus divisores son: "<<a[i].divisores[j]<<"\n";
     }
   }
}
