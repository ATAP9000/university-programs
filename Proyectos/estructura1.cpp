#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


struct banco{char nombre[100];int ci;char tel[20]; char tc; double mc;}b[100];
int m,i,w,respuesta1;
double imbc,imc,tamc,tambc,imba,ima,tama,tamba,imbl,iml,taml,tambl;


main(){cout << "Introduzca el numero de clientes  "; cin >> m;
for(i=1;i<=m;i++){cout << "Introduzca el nombre del cliente  " << endl;cin >> b[i].nombre;
cout << "Introduzca la C.I del cliente   "; cin >> b[i].ci;
cout << "Introduzca el telefono del cliente   "; cin >> b[i].tel;
cout << "Introduzca el tipo de cuenta:   "; cin >> b[i].tc;
cout << "Introduzca el monto de la cuenta   "; cin >> b[i].mc;}
for(i=1;i<=m;i++){cout << "Nombre: " << b[i].nombre << endl;
cout << "Cedula: " << b[i].ci << endl;
cout << "Telefono: " << b[i].tel << endl;
cout << "Tipo de cuenta: " << b[i].tc << endl;
cout << "Monto de cuenta: " << b[i].mc << endl;}
cout << "introduzca cedula a buscar  "; cin >> w;
for(i=1;i<=m;i++){if(b[i].ci==w){cout << "Nombre: " << b[i].nombre << endl;
cout << "Telefono: " << b[i].tel << endl;
cout << "Tipo de cuenta: " << b[i].tc << endl;
if(b[i].tc=='c'){imbc=b[i].mc*0.005; imc=b[i].mc*0.0025;
cout << "Los intereses mensuales de la cuenta 'corriente' son de " << imc << endl; cout << "Los intereses bimensuales de la cuenta 'corriente' son de " << imbc << endl;
tamc=b[i].mc+imc;tambc= b[i].mc+imbc;
cout << "El total acumulado cuenta 'corriente' en un mes son de " << tamc << endl; cout << "El total acumulado de la cuenta 'corriente' en 2 meses son de " << tambc << endl;}
if(b[i].tc=='a'){imba=b[i].mc*0.02; ima=b[i].mc*0.01;
cout << "Los intereses mensuales de la cuenta 'corriente' son de " << ima << endl; cout << "Los intereses bimensuales de la cuenta 'corriente' son de " << imba << endl;
tama=b[i].mc+ima;tamba= b[i].mc+imba;
cout << "El total acumulado cuenta 'corriente' en un mes son de " << tama << endl; cout << "El total acumulado de la cuenta 'corriente' en 2 meses son de " << tamba << endl;}
if(b[i].tc=='l'){imbl=b[i].mc*0.0083;iml=b[i].mc*0.0045;
cout << "Los intereses mensuales de la cuenta 'corriente' son de " << iml << endl; cout << "Los intereses bimensuales de la cuenta 'corriente' son de " << imbl << endl;
taml=b[i].mc+iml;tambl= b[i].mc+imbl;
cout << "El total acumulado cuenta 'corriente' en un mes son de " << taml << endl; cout << "El total acumulado de la cuenta 'corriente' en 2 meses son de " << tambl << endl;}
}}}



