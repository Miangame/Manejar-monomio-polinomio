/*! 
  \file mainPolinomio.cpp
  \brief Programa para usar el tipo de dato Polinomio
*/

/*!
	\mainpage Plantillas de clases y funciones
	\author Miguel Angel Gavilan Merino
	\date 15 de marzo de 2016
*/

// Ficheros de cabecera
#include <cassert>
#include "polinomio.hpp"
#include "funcionesPolinomio.hpp"


// Uso del espacio de nombres ed
using namespace ed;

// Facilita la entrada y salida
using std::cout;


//! Programa principial que muestra el uso de la clase Monomio
int main()
{

	system("clear");

	// Declaracion de tres polinomios
	Polinomio p, p2(2, 3), p3(p2);

	// Comprobacion del constructor
	assert(p.getNMonomios()==1 && p.getGrado()==1);
	cout << "\n>>>Constructor funciona correctamente...\n" << endl;
	sleep(1);

	// Comprobacion del constructor parametrizado
	assert(p2.getNMonomios()==2 && p2.getGrado()==3);
	cout << "\n>>>Constructor parametrizado funciona correctamente...\n" << endl;
	sleep(1);

	// Comprobacion del constructor de "copia"
	assert(p3.getNMonomios()==p2.getNMonomios() && p3.getGrado()==p2.getGrado());
	cout << "\n>>>Constructor de copia funciona correctamente...\n" << endl;
	sleep(1);

	// Llamada a la funcion menu()
	menu(p, p2, p3);


//Fin del programa
return 0;
}
