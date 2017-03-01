/*! 
  \file funcionesPolinomio.hpp
  \brief Funcion para mostrar un menu del programa en el main()
  \author Miguel Angel Gavilan Merino
  \date 15 de marzo de 2016
*/

#ifndef FUNCIONESPOLINOMIO_HPP
#define FUNCIONESPOLINOMIO_HPP


// Ficheros de cabecera
#include <iostream>
#include "polinomio.hpp"


// Facilita la entrada y salida
using namespace ed;
using std::cout;
using std::cin;
using std::endl;




//! \name Funcion menu para el programa

/*! 
	\brief Muestra un menu en el main para hacer funcionar el programa
	\pre Se deben pasar 3 Polinomios
	\post Ninguna
	\param p de tipo Polinimio
	\param p2 de tipo Polinomio
	\param p3 de tipo Polinomio
*/
void menu(Polinomio p, Polinomio p2, Polinomio p3)
{	
	int opc;
	int x, res;

	while(opc!=5)
	{
		cout << "\n\n-----Escoja alguna de las siguientes opciones-----\n" << endl;
		cout << "1. Valor de un polinomio para un dato concreto de X" << endl;
		cout << "2. Suma de dos polinomios" << endl;
		cout << "3. Multiplicacion de dos polinomios" << endl;
		cout << "4. Lectura y escritura mediante << y >>" << endl;
		cout << "5. Fin del programa" << endl;
		cout << "Opcion: ";
		cin >> opc;	

		switch(opc)
		{
			case 1:
				cout << "\nIntroduzca valor de X" << endl;
				cin >> x;
				
				cout << "\nIntroduzca un polinomio: " << endl;
				p.leerPolinomio();

				res=p.resuelvePolinomio(x);

				p.escribirPolinomio();
				cout << "\nResultado: " << res << endl;

				sleep(2);
			break;

			case 2:
				cout << "\nIntroduzca el primer polinomio: " << endl;
				p.leerPolinomio();

				cout << "\nIntroduzca el segundo polinomio: " << endl;
				p2.leerPolinomio();
	
				p3=p+p2;
		
				
				cout << "\nEl primer polinomio es:" << endl;
				p.escribirPolinomio();
				cout << "\nEl segundo polinomio es: " << endl;
				p2.escribirPolinomio();
				cout << "\nEl resultado de la suma es: " << endl;
				p3.escribirPolinomio();
				sleep(2);
			break;

			case 3:
				cout << "\nIntroduzca el primer polinomio: " << endl;
				p.leerPolinomio();

				cout << "\nIntroduzca el segundo polinomio: " << endl;
				p2.leerPolinomio();
	
				p3=p*p2;
		
				
				cout << "\nEl primer polinomio es:" << endl;
				p.escribirPolinomio();
				cout << "\nEl segundo polinomio es: " << endl;
				p2.escribirPolinomio();
				cout << "\nEl resultado de la multiplicacion es: " << endl;
				p3.escribirPolinomio();
				sleep(2);
			break;

			case 4:
				cout << "\nIntroduzca el polinomio" << endl;
				cin >> p;
				cout << p;
			break;

			case 5:
				cout << "\n>>>Saliendo del programa...\n" << endl;
				sleep(2);
			break;

			default: 
				cout << "\n>>>Opcion incorrecta, vuelva a introducir una opcion valida..\n" << endl;
				sleep(2);
		}
	}
	//Fin de la funcion
}


// FUNCIONESPOLINOMIO_HPP
#endif
