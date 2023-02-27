#include <iostream>
#include <math.h>
using namespace std;
int i,n,j,sn,suel,a,ss,lh,in,snet,op,s,opc;

main(){do{ cout << "Introduzca cantidad de trabajadores." << endl; cin >> n;
for(i=1;i<=n;i++){ cout << "1.Trabajador de salario hasta 20000." << endl; cout << "2.Trabajador de salario desde 20000 hasta 30000." << endl; cout << "3.Trabajador de salario desde 30000 hasta 40000." << endl; cout << "3.Trabajador de salario mayor a 40000." << endl;
cin >> op;
switch(op){case 1:{ cout << "inserte el sueldo " << endl; cin >> suel; if(suel<20000){cout << "El sueldo es de: " << suel << " le corresponde un 40%" << endl;
a=suel*0.4; cout << "El aumento de sueldo es de: " << a << endl;
sn=suel+a; cout <<  "El sueldo nuevo es de: " << sn << endl;
ss=sn*0.0425; cout << "Descontando un 4,25% del seguro social: " << ss << endl;
lh=sn*0.01; cout << "Descontando un 1% de la ley de politica habitacional: " << lh << endl;
in=sn*0.05; cout << "Descontando un 5% de la renta a no se que: " << in << endl;
snet=sn-ss-lh-in; cout << "Dejando con un sueldo neto final de: " << snet << endl; break;
}else{cout << "Error dato no aceptado, "; i=i-1;}}
case 2:{ cout << "inserte el suelo " << endl; cin >> suel; if(suel>=20000 && suel<30000){cout << "El sueldo es de: " << suel << " le corresponde un 20%" << endl;
a=suel*0.2; cout << "El aumento de sueldo es de: " << a << endl;
sn=suel+a; cout <<  "El sueldo nuevo es de: " << sn << endl;
ss=sn*0.0425; cout << "Descontando un 4,25% del seguro social: " << ss << endl;
lh=sn*0.01; cout << "Descontando un 1% de la ley de politica habitacional: " << lh << endl;
in=sn*0.05; cout << "Descontando un 5% de la renta a no se que: " << in << endl;
snet=sn-ss-lh-in; cout << "Dejando con un sueldo neto final de: " << snet << endl; break;
}else{cout << "Error dato no aceptado, "; i=i-1;}}
case 3:{ cout << "inserte el sueldo " << endl; cin >> suel; if(suel>=30000 && suel<40000){cout << "El sueldo es de: " << suel << " le corresponde un 10%" << endl;
a=suel*0.1; cout << "El aumento de sueldo es de: " << a << endl;
sn=suel+a; cout <<  "El sueldo nuevo es de: " << sn << endl;
ss=sn*0.0425; cout << "Descontando un 4,25% del seguro social: " << ss << endl;
lh=sn*0.01; cout << "Descontando un 1% de la ley de politica habitacional: " << lh << endl;
in=sn*0.05; cout << "Descontando un 5% de la renta a no se que: " << in << endl;
snet=sn-ss-lh-in; cout << "Dejando con un sueldo neto final de: " << snet << endl; break;
}else{cout << "Error dato no aceptado, "; i=i-1;}}
case 4:{ cout << "inserte el sueldo " << endl; cin >> suel; if(suel>40000){cout << "El sueldo es de: " << suel << " le corresponde un 5%" << endl;
a=suel*0.05; cout << "El aumento de sueldo es de: " << a << endl;
sn=suel+a; cout <<  "El sueldo nuevo es de: " << sn << endl;
ss=sn*0.0425; cout << "Descontando un 4,25% del seguro social: " << ss << endl;
lh=sn*0.01; cout << "Descontando un 1% de la ley de politica habitacional: " << lh << endl;
in=sn*0.05; cout << "Descontando un 5% de la renta a no se que: " << in << endl;
snet=sn-ss-lh-in; cout << "Dejando con un sueldo neto final de: " << snet << endl; break;
}else{cout << "Error dato no aceptado, " << endl; i=i-1;}}
default:{cout << "Opcion invalida " << endl;; i=i-1;}while(i>1);}}
cout << "Desea correr el programa de nuevo?" << endl; cout << "Para si escriba '1' ,para no escriba '2'  "; cin >> opc;}while(opc==1);}

