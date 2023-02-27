/*
	Nombre: CircunferenciaCentrada.h
	Copyright: (C) noviembre de 2017
	Autor: Gustavo Alzuru
	Fecha: 20/11/2017
	Última actualización: 20/11/2017
	Descripción: Archivo de cabecera para el módulo de clase CircunferenciaCentrada para usar como 
	demostración de la aplicación de la agregación entre clases.  El ejemplo fue modificado 
	a partir del codigo fuente publicado en http://www.unirioja.es/cu/jearansa/0910/archivos/EIPR_Tema02.pdf
	
	Se parte de la suposición que un objeto circunferencia centrada esta conformado por:
		-- las características y métodos propios de una circunferencia  
		-- y un objeto Centro que determinará precisamente el centro de la circunferencia
*/

#include "Punto.h"

class CircunferenciaCentrada 
{
	private:
		double const PI;    //constante. Se inicializará su valor en los constructores de la clase
		double radio;
		Punto centro;  //aquí se hace la agregación indicando que una circunferencia centrada contiene un objeto centro
	public:

		//constructores de instancias
		CircunferenciaCentrada();
		CircunferenciaCentrada(double r, double x, double y);

		//métodos de instancias
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