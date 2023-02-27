#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int menu(),sumas(),restas(),multiplicaciones(),divisiones(),potenciales(),raices(),ins(),op1,op2,op3,op4,op5,op6,op7,op8,op9,op10,op11,op12,op13,op14,op15,op16,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,ap1,ap2,ap3,ap4,ap5,ap6,ap7;

main(){cout << "BIENVENIDO AL PROGRAMA BASE DE CALCULOS"; menu(); return 0;}

int menu(){do{ cout << "MENU 1.0" << endl; cout << "1. BIBLIOTECA" << endl; cout << "2. SUMAS" << endl; cout << "3. RESTAS" << endl;
cout << "4. MULTIPLICACIONES" << endl; cout << "5. DIVISIONES" << endl; cout << "6.POTENCIAS" << endl; cout << "7. RAICES" << endl; cout << "8. SALIR" << endl;
cin >> op1;
switch(op1){case 1:{ins();break;} case 2:{ sumas();break;} case 3:{restas();break;} case 4:{multiplicaciones();break;} case 5:{divisiones();break;} case 6:{ void potenciales();}
case 7:{ void raices();}; case 8:{ cout << "USTED HA SELECCIONADO SALIR EL PROGRAMA PORFAVOR COMPRUEBE DE NUEVO" << endl;break;} default:{ cout << "ESA OPCION NO ES VALIDA" << endl;break;}
}cout << "desea continuar usando el programa? 1 para Si y 2 No" << endl; cin >> op2;}while(op2==1);}

int ins(){do{cout << "BIENVENIDO A LA BIBLIOTECA" << endl;cout << "1. DATOS DEL AUTOR" << endl; cout << "2. OBJETIVOS DEL PROGRAMA" << endl; cout << "3. DATOS ADICIONALES" << endl; cout << "4. SALIR DE LA BIBLIOTECA" << endl;
cin >> op3;
switch(op3){ case 1:{cout << "LE EBIN XD" << endl;break;} case 2:{cout << "KYS FUCKING CUNT" << endl;break;} case 3:{cout << "HEH GREETINGS TRAVELER" << endl;break;} case 4:{cout << "saliendo..." << endl;break;} default:{ cout << "ESA OPCION NO ES VALIDA" << endl;break;
}} cout << "DESEA CONTINUAR EN LA BIBLIOTECA? 1 para Si y 2 No" << endl; cin >> op4;}while(op4==1);}

int sumas(){do{ cout << "BIENVENIDO A LA BIBLIOTECA DE SUMAS" << endl; cout << "1. HISTORIA DE LAS SUMAS" << endl; cout << "2. EXPLICACION DE LAS SUMAS" << endl; cout << "3. CALCULADORA DE SUMAS" << endl; cout << "4. DATOS DE LAS SUMAS" << endl;
cout << "5. SALIR" << endl;
cin >> op5;
switch(op5){ case 1:{cout << "LE HISTOREH MEME" << endl;break;} case 2:{cout << "BUT NONE ANSWERED..." << endl;break;} case 3:do{cout << "PORFAVOR INSERTE LOS 2 VALORES" << endl; cout << "VALOR A" << endl; cin >> a; cout << "VALOR B"<< endl; cin >> b; c=a+b;
cout << "EL VALOR DE LA SUMA ES: " << c << endl; cout << "desea continuar usando la calculadora? 1 para Si y 2 No" << endl; cin >> ap1; if(ap1==2){break;}}while(ap1==1); case 4:{cout << "ESTE ES UN MENSAJE DE PRUEBA NO SE ALARME O ERROR LEVE" << endl;break;} case 5:{cout << "saliendo..." << endl;break;}
default:{ cout << "ESA OPCION NO ES VALIDA" << endl;break;}} cout << "DESEA CONTINUAR EN LA BIBLIOTECA? 1 para Si y 2 No" << endl; cin >> op6;}while(op6==1);}

int restas(){do{ cout << "BIENVENIDO A LA BIBLIOTECA DE RESTAS" << endl; cout << "1. HISTORIA DE LAS RESTAS" << endl; cout << "2. EXPLICACION DE LAS RESTAS" << endl; cout << "3. CALCULADORA DE RESTAS" << endl; cout << "4. DATOS DE LAS RESTAS" << endl;
cout << "5. SALIR" << endl;
cin >> op7;
switch(op7){ case 1:{cout << "DATOS RESTADOS :P" << endl;break;} case 2:{cout << "SE RESTO A SI MISMA" << endl;break;} case 3:do{cout << "PORFAVOR INSERTE LOS 2 VALORES" << endl; cout << "VALOR A" << endl; cin >> d; cout << "VALOR B"<< endl; cin >> e; f=d-e;
cout << "EL VALOR DE LA RESTA ES: " << f << endl; cout << "desea continuar usando la calculadora? 1 para Si y 2 No" << endl; cin >> ap2; if(ap2==2){break;}}while(ap2==1); case 4:{cout << "ESTE ES UN MENSAJE DE PRUEBA NO SE ALARME O ERROR LEVE" << endl;break;} case 5:{cout << "saliendo..." << endl;break;}
default:{ cout << "ESA OPCION NO ES VALIDA" << endl;break;}} cout << "DESEA CONTINUAR EN LA BIBLIOTECA? 1 para Si y 2 No" << endl; cin >> op8;}while(op8==1);}

int multiplicaciones(){do{ cout << "BIENVENIDO A LA BIBLIOTECA DE MULTIPLICACIONES" << endl; cout << "1. HISTORIA DE LAS MULTIPLICACIONES" << endl; cout << "2. EXPLICACION DE LAS MULTIPLICACIONES" << endl; cout << "3. CALCULADORA DE MULTIPLICACIONES" << endl; cout << "4. DATOS DE LAS MULTIPLICACIONES" << endl;
cout << "5. SALIR" << endl;
cin >> op9;
switch(op9){ case 1:{cout << "SYNTAX ERROR" << endl;break;} case 2:{cout << "FATAL ERROR" << endl;break;} case 3:do{cout << "PORFAVOR INSERTE LOS 2 VALORES" << endl; cout << "VALOR A" << endl; cin >> g; cout << "VALOR B"<< endl; cin >> h; i=g*h;
cout << "EL VALOR DE LA MULTIPLICACION ES: " << i << endl; cout << "desea continuar usando la calculadora? 1 para Si y 2 No" << endl; cin >> ap3; if(ap3==2){break;}}while(ap3==1); case 4:{cout << "ESTE ES UN MENSAJE DE PRUEBA NO SE ALARME O ERROR LEVE" << endl;break;} case 5:{cout << "saliendo..." << endl;break;}
default:{ cout << "ESA OPCION NO ES VALIDA" << endl;break;}} cout << "DESEA CONTINUAR EN LA BIBLIOTECA? 1 para Si y 2 No" << endl; cin >> op10;}while(op10==1);}

int divisiones(){do{ cout << "BIENVENIDO A LA BIBLIOTECA DE DIVISIONES" << endl; cout << "1. HISTORIA DE LAS DIVISIONES" << endl; cout << "2. EXPLICACION DE LAS DIVISIONES" << endl; cout << "3. CALCULADORA DE DIVISIONES" << endl; cout << "4. DATOS DE LAS DIVISIONES" << endl;
cout << "5. SALIR" << endl;
cin >> op11;
switch(op11){ case 1:{cout << "SE DIVIO ENTRE 0" << endl;break;} case 2:{cout << "INFO NECESARIA" << endl;break;} case 3:do{cout << "PORFAVOR INSERTE LOS 2 VALORES" << endl; cout << "VALOR A" << endl; cin >> j; cout << "VALOR B"<< endl; cin >> k; l=j/k;
cout << "EL VALOR DE LA DIVISION ES: " << l << endl; cout << "desea continuar usando la calculadora? 1 para Si y 2 No" << endl; cin >> ap4; if(ap4==2){break;}}while(ap4==1); case 4:{cout << "ESTE ES UN MENSAJE DE PRUEBA NO SE ALARME O ERROR LEVE" << endl;break;} case 5:{cout << "saliendo..." << endl;break;}
default:{ cout << "ESA OPCION NO ES VALIDA" << endl;break;}} cout << "DESEA CONTINUAR EN LA BIBLIOTECA? 1 para Si y 2 No" << endl; cin >> op12;}while(op12==1);}
