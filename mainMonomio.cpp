/*! 
  \file mainMonomio.cpp
  \brief Programa para usar el tipo de dato Monomio
*/

/*!
	\mainpage Plantillas de clases y funciones
	\author Miguel Angel Gavilan Merino
	\date 15 de marzo de 2016
*/

// Ficheros de cabecera
#include <cassert>
#include "monomio.hpp"
#include "funcionesMonomio.hpp"


// Espacio de nombres ed
using namespace ed;

// Espacio de nombres para la salida de datos
using std::cout;


//! Programa principial que muestra el uso de la clase Monomio
int main()
{
	system("clear");
	
	// Declaracion de tres monomios
	Monomio m, m2(2, 3), m3(m2);

	// Comprobacion del constructor
	assert(m.getCoeficiente()==1.0 && m.getGrado()==1);
	cout << "\n>>>Constructor funciona correctamente...\n" << endl;
	sleep(1);

	// Comprobacion del constructor parametrizado
	assert(m2.getCoeficiente()==2 && m2.getGrado()==3);
	cout << "\n>>>Constructor parametrizado funciona correctamente...\n" << endl;
	sleep(1);

	// Comprobacion del constructor de copia
	assert(m3.getCoeficiente()==m2.getCoeficiente() && m3.getGrado()==m2.getGrado());
	cout << "\n>>>Constructor de copia funciona correctamente...\n" << endl;
	sleep(1);
 	
 	//Llamada a la funcion menu()
	menu(m, m2, m3);

// Fin del programa
return 0;
}
