#include <iostream>
#include <math.h>
#include <ctype.h>
using namespace std;
int i,j,m,c=0,c1=0,c2=0,z,x,y,aux,h,c3=0,cont,f,g,b,op,d;
char a[100][100],a1[100][100],q;
main(){cout << "bienvenido al programa de calculo de matrices x" << endl;
cout << "introduzca el tamaño de la matriz "; cin >> m;
for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << "introduzca el caracter de la posicion (" << i << "," << j << ")=? "; cin >> a[i][j];}}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << a[i][j] << " ";} cout << endl;} for(i=1;i<=m;i++){for(j=1;j<=m;j++){z=a[i][j]; cout << "el codigo ASCII " << a[i][j]; cout << " es " << z << endl;}}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){c=c+a[i][j]; c1=c1+a[i][j];}cout << "la sumatoria de la fila " << i <<" en codigo ASCII es " << c << endl; c=0; cout << "la sumatoria total en codigo ASCII es " << c1 << endl;}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){if(a[i][j]%2==0){cout << "el caracter " << a[i][j] << " es par " << endl;}
if(a[i][j]%3==0){ cout << "el caracter " << a[i][j] << " es multiplo de 3" << endl;}if(a[i][j]%5==0){cout << "el caracter " << a[i][j] << " es multiplo de 5" << endl;}}}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){f=0;for(g=2;g<a[i][j];g++){b=a[i][j]%g;if(b==0){f=1;break;}}if(f==0){cout<<"el caracter " << a[i][j]<< " es primo" << endl;}}}
cout << "introduzca un caracter a buscar "; cin >> q;
for(i=1;i<=m;i++){for(j=1;j<=m;j++){if(a[i][j]==q){cout << "se halla el caracter " << q << " en la posicion " << i << "," << j << endl; c2=c2+1; cout << "se halla el caracter " << q << " un total de " << c2 << " veces" << endl;}
if(a[i][j]!=q){cout << "el caracter no existe en la matriz" << endl;break;}}}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){if(i=j){ cout << a[i][j] << " ";}}} for(i=1;i<=m;i++){for(j=1;j<=m;j++){if(i=j){c3=c3+a[i][j]; cout << "la sumatoria del codigo ACSII de la diagonal es " << c3 << endl;}}}
for(i=1;i<=m;i++){for(j=1;j<=m;j++){if(isdigit(a[i][j])){cout << "el caracter " << a[i][j] << " es un numero y se encuentra en la posicion " << i << "," << j << endl;}}}
cout << "desea acomodar la matriz?" << endl; cout << "1. DE MENOR A MAYOR" << endl; cout << "2. DE MAYOR A MENOR" << endl; cout << "3. NINGUNA DE LAS ANTERIORES" << endl;
cin >> op;
switch(op){case 1:{for(i=1;i<=m;i++){for(j=1;j<=m;j++){for(x=1;x<=m;x++){for(y=1;y<=m;y++){if(a[i][j]<a[x][y]){aux=a[i][j];a[i][j]=a[x][y];a[x][y]=aux;}}}}}
cout<<"Los Datos De La Matriz Fueron Ordenados de Menor a Mayor: "<<endl;for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << a[i][j]<<" ";}cout<<endl;};break;}
case 2:{for(i=1;i<=m;i++){for(j=1;j<=m;j++){for(x=1;x<=m;x++){for(y=1;y<=m;y++){if(a[i][j]>a[x][y]){aux=a[i][j];a[i][j]=a[x][y];a[x][y]=aux;}}}}}
cout<<"Los Datos De La Matriz Fueron Ordenados de Menor a Mayor: "<<endl;for(i=1;i<=m;i++){for(j=1;j<=m;j++){cout << a[i][j]<<" ";}cout<<endl;}break;}
case 3:{cout << "ha elegido no ordernar" << endl;}}
cout << "fin." << endl;}
