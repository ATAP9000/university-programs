#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int n,i,z,cont=0,c=0,c1=0,l,f,g,b,c2,opc;
char a[100],q;
bool continuar,continuar1,continuar2;

main(){do{ cout << "programa de vectores de caracteres." << endl;
    do{ continuar=false;
         cin.clear(); if(cont>0) cin.ignore(1024, '\n');
        cout << "longitud del vertice" << endl;cin >> n;
         cont++;
         if(cin.fail()&&cin.rdstate()){
            cout << "ha ingresado un caracter invalido" << endl;
            continuar=true;
         }}while(continuar);
for(i=1;i<=n;i++){cout << "introduzca algun caracter/letra/valor para la posicion " << n << " del vector." << endl; cin>> a[i];}
for(i=1;i<=n;i++){cout << a[i]<< " " << endl;} for(i=1;i<=n;i++){z=a[i]; cout << "el codigo ASCII " << a[i]; cout << " es " << z << endl;}
for(i=1;i<=n;i++){c=c+a[i]; c1=c1+a[i];cout << "la sumatoria de la fila " << i <<" en codigo ASCII es " << c << endl; c=0; cout << "la sumatoria total en codigo ASCII es " << c1 << endl;}
for(i=1;i<=n;i++){if(a[i]%2==0){cout << "el caracter " << a[i] << " es par " << endl;}if(a[i]%3==0){ cout << "el caracter " << a[i] << " es multiplo de 3" << endl;}if(a[i]%5==0){cout << "el caracter " << a[i] << " es multiplo de 5" << endl;}}
for(i=1;i<=n;i++){f=0;for(g=2;g<a[i];g++){b=a[i]%g;if(b==0){f=1;break;}}if(f==0){cout<<"el caracter " << a[i]<< " es primo" << endl;}}
cout << "introduzca un caracter a buscar "; cin >> q;
for(i=1;i<=n;i++){if(a[i]==q){cout << "se halla el caracter " << q << " en la posicion " << i << endl; c2=c2+1; cout << "se halla el caracter " << q << " un total de " << c2 << " veces" << endl;}
else{cout << "el caracter " << q << " no existe en el vertice posicion " << i << endl;}}
for(i=1;i<=n;i++){if(islower(a[i])){ cout << "los caracteres " << a[i] << " son minusculas. " << endl;} cout << endl;}
for(i=1;i<=n;i++){if(i%2==0 && isdigit(a[i])){ cout << "los caracteres " << a[i] << " son numero que se encuentran en las posiciones pares. " << endl;} cout << endl;}
cout << "Desea correr el programa de nuevo?" << endl; cout << "Para si escriba '1' ,para no escriba '2'  "; cin >> opc;}while(opc==1);}
