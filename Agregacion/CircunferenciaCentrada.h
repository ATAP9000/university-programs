/*
	Nombre: CircunferenciaCentrada.h
	Copyright: (C) noviembre de 2017
	Autor: Gustavo Alzuru
	Fecha: 20/11/2017
	�ltima actualizaci�n: 20/11/2017
	Descripci�n: Archivo de cabecera para el m�dulo de clase CircunferenciaCentrada para usar como 
	demostraci�n de la aplicaci�n de la agregaci�n entre clases.  El ejemplo fue modificado 
	a partir del codigo fuente publicado en http://www.unirioja.es/cu/jearansa/0910/archivos/EIPR_Tema02.pdf
	
	Se parte de la suposici�n que un objeto circunferencia centrada esta conformado por:
		-- las caracter�sticas y m�todos propios de una circunferencia  
		-- y un objeto Centro que determinar� precisamente el centro de la circunferencia
*/

#include "Punto.h"

class CircunferenciaCentrada 
{
	private:
		double const PI;    //constante. Se inicializar� su valor en los constructores de la clase
		double radio;
		Punto centro;  //aqu� se hace la agregaci�n indicando que una circunferencia centrada contiene un objeto centro
	public:

		//constructores de instancias
		CircunferenciaCentrada();
		CircunferenciaCentrada(double r, double x, double y);

		//m�todos de instancias
		double getRadio();
		void setRadio(double nuevoRadio);
		double getDiametro();
		void setDiametro(double nuevoDiametro);
		double getPerimetro();
		void setPerimetro(double nuevoPerimetro);
		double getArea();
		void setArea(double nuevaArea);
		double getXCentro();
		void setXCentro(double nuevoXCentro);
		double getYCentro();
		void setYCentro(double nuevoYCentro);
		void trasladarCircunferenciaCentrada(double trasl_X, double trasl_Y);
};