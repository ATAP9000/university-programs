/*
	Nombre: CircunferenciaCentrada.h
	Copyright: (C) noviembre de 2017
	Autor: Gustavo Alzuru
	Fecha: 20/11/2017
	�ltima actualizaci�n: 20/11/2017
	Descripci�n: Archivo de implementaci�n para el m�dulo de clase CircunferenciaCentrada para usar como 
	demostraci�n de la aplicaci�n de la agregaci�n entre clases.  El ejemplo fue modificado 
	a partir del codigo fuente publicado en http://www.unirioja.es/cu/jearansa/0910/archivos/EIPR_Tema02.pdf
*/

#include "CircunferenciaCentrada.h"
#include <math.h> //para usar la funci�n raiz cuadrada sqrt() 

CircunferenciaCentrada::CircunferenciaCentrada() : PI(3.141592) //forma v�lida de inicializar una constante en una clase en C++
{
	radio = 0.0;
	// el centro se crea internamente de forma autom�tica como un punto estandar 0,0 ya que en el encabezado est� definido
	//Sin embargo ser�a algo as�:
	//centro = Punto();
}

CircunferenciaCentrada::CircunferenciaCentrada(double r, double x, double y) : PI(3.141592) //forma v�lida de inicializar una constante en una clase en C++
{
	radio = r;
	// como ya existe un objeto centro por defecto al dispararse la definici�n, basta con modificar los valores del objeto
	centro.setX(x);
	centro.setY(y);
}

double CircunferenciaCentrada::getRadio()
{
	return radio;
}

void CircunferenciaCentrada::setRadio(double nuevoRadio)
{
	radio = nuevoRadio;
}

double CircunferenciaCentrada::getDiametro()
{
	return (2*radio);
}

void CircunferenciaCentrada::setDiametro(double nuevoDiametro)
{
	radio = nuevoDiametro/2;
}

double CircunferenciaCentrada::getPerimetro()
{
	return (2*radio*PI);
}

void CircunferenciaCentrada::setPerimetro(double nuevoPerimetro)
{
	radio = nuevoPerimetro/(2*PI);
}

double CircunferenciaCentrada::getArea()
{
	return (PI*radio*radio);
}

void CircunferenciaCentrada::setArea(double nuevaArea)
{
	radio = sqrt(nuevaArea)/PI;
}

double CircunferenciaCentrada::getXCentro()
{
	return centro.getX();
}

void CircunferenciaCentrada::setXCentro(double nuevoXCentro)
{
	centro.setX(nuevoXCentro);
}

double CircunferenciaCentrada::getYCentro()
{
	return centro.getY();
}

void CircunferenciaCentrada::setYCentro(double nuevoYCentro)
{
	centro.setY(nuevoYCentro);
}

void CircunferenciaCentrada::trasladarCircunferenciaCentrada(double trasl_X, double trasl_Y)
{
	centro.setX(centro.getX()+trasl_X);
	centro.setY(centro.getY()+trasl_Y);
}