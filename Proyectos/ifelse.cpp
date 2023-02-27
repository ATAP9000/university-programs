#include <iostream>
#include <limits>
#include <math.h>
double i,sn,suel,suelfin,suelper,a,ss,lh,in,snet,s,opc;
int n,j,cont=0,cont1=0,cont2=0;
bool continuar,continuar1,continuar2;
using namespace std;

main(){do{ cout << "Programa de calculo de sueldo de trabajadores." << endl;
    do{ continuar=false;
         cin.clear(); if(cont>0) cin.ignore(1024, '\n');
         cout << "Introduzca cantidad de trabajadores." << endl; cin >> n;
         cont++;
         if(cin.fail()&&cin.rdstate()){
            cout << "ha ingresado un caracter invalido" << endl;
            continuar=true;
         }}while(continuar);
for(i=1;i<=n;i++){
         do{ continuar1=false;
         cin.clear(); if(cont1>0) cin.ignore(1024, '\n');
         cout << "inserte el salario del trabajador n " << i << "." << endl; cin >> suel;
         cont1++;
         if(cin.fail()&&cin.rdstate()){
            cout << "ha ingresado un caracter invalido" << endl;
            continuar1=true;
         }}while(continuar1);
if(suel<=60000){cout << "El sueldo es de: " << suel << " le corresponde un 38% de aumento." << endl;
a=suel*0.38; cout << "El aumento de sueldo es de: " << a << endl;
sn=suel+a; cout <<  "El sueldo nuevo es de: " << sn << endl;
ss=sn*0.0525; cout << "Descontando un 5,25% del seguro social: " << ss << endl;
lh=sn*0.1025; cout << "Descontando un 10,25% de la caja de ahorro: " << lh << endl;
in=sn*0.045; cout << "Descontando un 4,5% del INCE: " << in << endl;
snet=sn-ss-lh-in; cout << "Dejando con un sueldo neto final de: " << snet << endl;}
if(suel>60000 && suel<=80000){cout << "El sueldo es de: " << suel << " le corresponde un 28% de aumento." << endl;
a=suel*0.28; cout << "El aumento de sueldo es de: " << a << endl;
sn=suel+a; cout <<  "El sueldo nuevo es de: " << sn << endl;
ss=sn*0.0525; cout << "Descontando un 5,25% del seguro social: " << ss << endl;
lh=sn*0.1025; cout << "Descontando un 10,25% de la caja de ahorro: " << lh << endl;
in=sn*0.045; cout << "Descontando un 4,5% del INCE: " << in << endl;
snet=sn-ss-lh-in; cout << "Dejando con un sueldo neto final de: " << snet << endl;}
if(suel>80000){cout << "El sueldo es de: " << suel << " le corresponde un 18% de aumento." << endl;
a=suel*0.18; cout << "El aumento de sueldo es de: " << a << endl;
sn=suel+a; cout <<  "El sueldo nuevo es de: " << sn << endl;
ss=sn*0.0525; cout << "Descontando un 5,25% del seguro social: " << ss << endl;
lh=sn*0.1025; cout << "Descontando un 10,25% de la caja de ahorro: " << lh << endl;
in=sn*0.045; cout << "Descontando un 4,5% del INCE: " << in << endl;
snet=sn-ss-lh-in; cout << "Dejando con un sueldo neto final de: " << snet << endl;}
  do{ continuar2=false;
         cin.clear(); if(cont2>0) cin.ignore(1024, '\n');
         cout << "inserte horas laborales empleadas. " << endl; cin >> j;
         cont2++;
         if(cin.fail()&&cin.rdstate()){
            cout << "ha ingresado un caracter invalido" << endl;
            continuar2=true;
         }}while(continuar2);
suelper=snet/170; cout << "el sueldo es de " << suelper << " por hora," << endl;
if(j<170){ suelfin=snet-(suelper*j); cout << "debido a que no se cumplieron las 170 horas requeridas siendo las horas ejercidas " << 170-j << ", se le descontaran: " << suelfin << " de su salario final." << endl;
cout << "cual es: " << snet-suelfin << "." << endl; }
if(j>170){ suelfin=((suelper*j)-snet)*3; cout << "debido a que se cumplieron las 170 horas requerida y se ejercio unas " << j-170 << " adicionales, se le incluiran: " << suelfin << " a su salario final." <<endl;
cout << "cual es: "  << snet+suelfin << "." << endl; }}
cout << "Desea correr el programa de nuevo?" << endl; cout << "Para si escriba '1' ,para no escriba '2'  "; cin >> opc;}while(opc==1);}
