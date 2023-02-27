/*======================================================
/	MODULO: Ejemplo del uso de agregación de clases 
/	AUTOR/ES: Gustavo Adolfo Alzuru Jiménez
/	VERSIÓN: 1.0
/	ULTIMA REVISIÓN: 20-11-2017
/
/	DESCRIPCIÓN: Uso de las clases Punto y CircunferenciaCentrada
/                definidas en sus respectivos módulos Punto.h y CircunferenciaCentrada.h
				 Ejemplo tomado del código fuente publicado en http://www.unirioja.es/cu/jearansa/0910/archivos/EIPR_Tema02.pdf
/
/	UTILIZACIÓN: crear objetos de tipo CircunferenciaCentrada con objetos de tipo Punto agregados.  
/	
/	
/========================================================*/

#include "CircunferenciaCentrada.h"
#include <iostream>

using namespace std;

int main()
{
	cout<<"*****************************************"<<endl;
	cout<<"PRUEBA DE OBJETOS CIRCUNFERENCIA CENTRADA"<<endl;
	cout<<"*****************************************"<<endl;
	cout<<endl;
	cout<<"Se crea circunferencia estandar "<<endl;

	CircunferenciaCentrada C1;
	cout<<"Circunferencia de radio: "<<C1.getRadio()<<" y centro: "<<(double)C1.getXCentro()<<","<<(double)C1.getYCentro()<<endl;
	cout<<endl;

	cout<<"Se crea otra circunferencia con valores específicos: centro 0.5,1.5 y radio 2.5"<<endl;
	CircunferenciaCentrada C2(2.5,0.5,1.5);
	cout<<"Circunferencia de radio: "<<C2.getRadio()<<" y centro: "<<(double)C2.getXCentro()<<","<<(double)C2.getYCentro()<<endl;
	cout<<endl;

	//cout << "\n\nEl total es: " << fixed << setprecision(2) << total << endl;
	system("pause");
	return 0;
}