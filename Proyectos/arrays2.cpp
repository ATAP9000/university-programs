l#include <iostream>
using namespace std;

int a[100],n,i,c1=0,b[100],c2=0,p1,p2,op,opc,f1,f2;

main(){cout << "¿cuantos alumnos son? "; cin>>n;
for(i=1;i<=n;i++){cout << "introduzca nota del primer parcial del alumno " << i << endl; cin>>a[i];}
for(i=1;i<=n;i++){cout << a[i] << endl;}
for(i=1;i<=n;i++){c1=c1+a[i];} p1=c1/n; cout << "el promedio de los primeros parciales son de " << p1 << endl;
for(i=1;i<=n;i++){cout << "introduzca la nota del segundo parcial del alumno" << i << endl; cin>>b[i];}
for(i=1;i<=n;i++){cout << b[i] << endl;}
for(i=1;i<=n;i++){c2=c2+b[i];} p2=c2/n; cout << "el promedio del los segundos parciales son de " << p2 << endl; cout << "desea mayorar las notas del primer parcial?  (si=1 , no=2) " ; cin>>op;
if(op==1){f1=10/p1; for(i=1;i<=n;i++){cout << a[i]*f1 << endl;} cout << "desea mayorar tambien las notas del segundo parcial? " ; cin>>opc;
if(op==1&&opc==1){for(i=1;i<=n;i++){cout << (a[i]*f1)+b[i]+(f2/2) << endl;
for(i=1;i<=n;i++){if(a[i]%2==0){cout "el numero " << a[i] << " es par" << endl;}}}}}}

terminar

