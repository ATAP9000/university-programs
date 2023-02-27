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
cout<<"Los Datos De La Matriz Fueron Ordenados de Menor a Mayor: "<<endl;for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << a[i][j]<<" ";}cout<<endl;}break;}}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){if(islower(a[i=(2,4,6,8,10)][j]&&a[i][j=(2,4,6,8,10)]){ cout << "basado en la matriz original solo se muestan los caracteres minusculas en la cruz " << endl;
cout << a[i][j] << " " << endl;}}}}
