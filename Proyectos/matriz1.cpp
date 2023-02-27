#include <iostream>      //completado//
#include <math.h>
using namespace std;

int a[100][100],a1[100][100],i,j,m,c=0,c1=0,q,c2=0,z,f,t,mayor;
main(){cout << "introduzca la cantidad de la matriz "; cin >> m;
for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << "introduzca el numero de la posicion (" << i << "," << j << ")=? "; cin >> a[i][j];}}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << a[i][j] << " ";} cout << endl;} for(i=1;i<=m;i++){for(j=1;j<=m;j++){c=c+a[i][j]; c1=c1+a[i][j];}cout << "la sumatoria de la fila " << i <<
" es " << c << endl; c=0; cout << "la sumatoria total es " << c1 << endl;} for(i=1;i<=m;i++){for(j=1;j<=m;j++){if(a[i][j]%2==0){cout << "el numero " << a[i][j] << " es par " << endl;}
if(a[i][j]%3==0){ cout << "el numero " << a[i][j] << " es multiplo de 3" << endl;}if(a[i][j]%5==0){cout << "el numero " << a[i][j] << " es multiplo de 5" << endl;}}}
cout << "introduzca un numero a buscar "; cin >> q;
for(i=1;i<=m;i++){for(j=1;j<=m;j++){if(a[i][j]==q){cout << "se halla el numero " << q << " en la posicion " << i << "," << j << endl; c2=c2+1; cout << "se halla el numero " << q << " un total de " << c2 << " veces" << endl;}}}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){if(i=j){ cout << a[i][j] << endl;}}}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){for(f=1;f<=m;f++){for(t=1;t<=m;t++){if(a[i][j]>a[f][t]){mayor=a[i][j];a[i][j]=a[f][t];a[f][t]=mayor;}}}}}
cout<<"Los Datos De La Matriz Fueron Ordenados de Mayor a Menor"<<endl;for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << a[i][j] << " ";}}}


}//
#include <iostream>
#include <math.h>
#include <ctype.h>
#include <iomanip>
using namespace std;
int i,j,m,op,x,y,z,aux;
char a[100][100];
main(){cout << "programa de matriz" << endl;
cout << "introduzca el tamaño de la matriz "; cin >> m;
for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << "introduzca el caracter de la posicion (" << i << "," << j << ")=? "; cin >> a[i][j];}}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << a[i][j] << " ";} cout << endl;} for(i=1;i<=m;i++){for(j=1;j<=m;j++){z=a[i][j]; cout << "el codigo ASCII " << a[i][j]; cout << " es " << z << endl;}}
cout << "¿como desea acomodar la matriz?" << endl; cout << "1. DE MENOR A MAYOR" << endl; cout << "2. DE MAYOR A MENOR" << endl;
cin >> op;
switch(op){case 1:{for(i=1;i<=m;i++){for(j=1;j<=m;j++){for(x=1;x<=m;x++){for(y=1;y<=m;y++){if(a[i][j]<a[x][y]){aux=a[i][j];a[i][j]=a[x][y];a[x][y]=aux;}}}}}
cout<<"Los Datos De La Matriz Fueron Ordenados de Menor a Mayor: "<<endl;for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << a[i][j]<<" ";}cout<<endl;};break;}
case 2:{for(i=1;i<=m;i++){for(j=1;j<=m;j++){for(x=1;x<=m;x++){for(y=1;y<=m;y++){if(a[i][j]>a[x][y]){aux=a[i][j];a[i][j]=a[x][y];a[x][y]=aux;}}}}}
cout<<"Los Datos De La Matriz Fueron Ordenados de Menor a Mayor: "<<endl;for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << a[i][j]<<" ";}cout<<endl;}break;}
}}
//
