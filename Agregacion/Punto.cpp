/*
	Nombre: Punto.cpp
	Copyright: (C) noviembre de 2017
	Autor: Gustavo Alzuru
	Fecha: 20/11/2017
	Última actualización: 20/11/2017
	Descripción: Archivo de implementación para el módulo de clase Punto para usar como 
	demostración de la aplicación de la agregación entre clases.  El ejemplo fue modificado 
	a partir del codigo fuente publicado en http://www.unirioja.es/cu/jearansa/0910/archivos/EIPR_Tema02.pdf
*/

#include "Punto.h"

Punto::Punto()
{
	coord_X = 0.0;
	coord_Y = 0.0;
}

Punto::Punto(double X, double Y)
{
	coord_X = X;
	coord_Y = Y;
}

double Punto::getX()
{
	return coord_X;
}

void Punto::setX(double nuevoX)
{
	coord_X = nuevoX;
}

double Punto::getY()
{
	return coord_Y;
}

void Punto::setY(double nuevoY)
{
	coord_Y = nuevoY;
}