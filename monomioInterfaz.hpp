/*! 
  \file monomioInterfaz.hpp
  \brief MonomioInterfaz declara de manera publica las funciones virtuales de la clase Monomio
  \author Miguel Angel Gavilan Merino
  \date 15 de marzo de 2016
*/

#ifndef MONOMIOINTERFAZ_HPP
#define MONOMIOINTERFAZ_HPP

// Ficheros de cabecera
#include <iostream>


/*!
   \brief Espacio de nombres para la asignatura de Estructura de datos.

*/
namespace ed{

	class MonomioInterfaz
	{
		//! \name Atributos publicos de la clase MonomioInterfaz
		public:
			virtual int getGrado() const = 0;

			virtual double getCoeficiente() const = 0;

			virtual void setGrado(const int & grado) = 0;
	
			virtual void setCoeficiente(const double & coeficiente) = 0;
	}; // Fin de la definicion de la clase MonomioInterfaz

} // \brief Fin de namespace ed

// MONOMIOINTERFAZ_HPP
#endif
