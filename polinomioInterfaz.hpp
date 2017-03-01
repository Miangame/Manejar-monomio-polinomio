/*! 
  \file polinomioInterfaz.hpp
  \brief PolinomioInterfaz declara de manera publica las funciones virtuales de la clase Polinomio
  \author Miguel Angel Gavilan Merino
  \date 15 de marzo de 2016
*/

#ifndef POLINOMIOINTERFAZ_HPP
#define POLINOMIOINTERFAZ_HPP


//Ficheros de cabecera
#include <iostream>
#include <vector>
#include "monomio.hpp"




/*!
   \brief Espacio de nombres para la asignatura de Estructura de datos.

*/
namespace ed{

	class PolinomioInterfaz
	{
		//! \name Atributos privados de la clase PolinomioInterfaz
		public:
			virtual int getGrado() const = 0;

			virtual int getNMonomios() const = 0;

			virtual std::vector <ed::Monomio> getVector() const = 0;

			virtual void setGrado(const int & grado) = 0;
	
			virtual void setNMonomios(const int & NMonomios) = 0;

			virtual void setVector(const std::vector <ed::Monomio>& v) = 0;

			virtual bool estaVacia() const = 0;

			
	};// Fin de la definicion de la clase PolinomioInterfaz

}// \brief Fin de namespace ed


//POLINOMIOINTERFAZ_HPP
#endif
