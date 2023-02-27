/*
	Nombre: Punto.h
	Copyright: (C) noviembre de 2017
	Autor: Gustavo Alzuru
	Fecha: 20/11/2017
	Última actualización: 20/11/2017
	Descripción: Archivo de cabecera para el módulo de clase Punto para usar como 
	demostración de la aplicación de la agregación entre clases.  El ejemplo fue modificado 
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
			//métodos de instancia
			double getX();
			void setX(double nuevoX);
			double getY();
			void setY(double nuevoY);

	};


#endif