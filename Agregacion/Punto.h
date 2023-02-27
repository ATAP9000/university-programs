/*
	Nombre: Punto.h
	Copyright: (C) noviembre de 2017
	Autor: Gustavo Alzuru
	Fecha: 20/11/2017
	�ltima actualizaci�n: 20/11/2017
	Descripci�n: Archivo de cabecera para el m�dulo de clase Punto para usar como 
	demostraci�n de la aplicaci�n de la agregaci�n entre clases.  El ejemplo fue modificado 
	a partir del codigo fuente publicado en http://www.unirioja.es/cu/jearansa/0910/archivos/EIPR_Tema02.pdf
*/

#ifndef PUNTO_H
	#define PUNTO_H

	class Punto
	{
		private:
			//atributos de instancia
			double coord_X;
			double coord_Y;
		public:
			//constructores de instancia
			Punto();
			Punto(double X, double Y);
			//m�todos de instancia
			double getX();
			void setX(double nuevoX);
			double getY();
			void setY(double nuevoY);

	};


#endif