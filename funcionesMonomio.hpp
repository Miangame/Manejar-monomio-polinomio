/*! 
  \file funcionesMonomio.hpp
  \brief Funcion para mostrar un menu del programa en el main()
  \author Miguel Angel Gavilan Merino
  \date 15 de marzo de 2016
*/

#ifndef FUNCIONESMONOMIO_HPP
#define FUNCIONESMONOMIO_HPP


// Funciones de cabecera
#include <iostream>
#include "monomio.hpp"


// Facilita la entrada y salida
using namespace ed;
using std::cout;
using std::cin;
using std::endl;




//! \name Funcion menu para el programa

/*! 
	\brief Muestra un menu en el main para hacer funcionar el programa
	\pre Se deben pasar 3 monomios
	\post Ninguna
	\param m de tipo Monomio
	\param m2 de tipo Monomio
	\param m3 de tipo Monomio
*/
void menu(Monomio m, Monomio m2, Monomio m3)
{	
	int opc;
	int x;
	double res;
	
	while(opc!=4)
	{
		cout << "\n\n-----Escoja alguna de las siguientes opciones-----\n" << endl;
		cout << "1. Valor de un monomio para un dato concreto de X" << endl;
		cout << "2. Multiplicacion de dos monomios" << endl;
		cout << "3. Suma de dos monomios con el mismo grado" << endl;
		cout << "4. Fin del programa" << endl;
		cout << "Opcion: ";
		cin >> opc;	

		switch(opc)
		{
			case 1:
				cout << "\nIntroduzca valor de X" << endl;
				cin >> x;
				
				cout << "\nIntroduzca un monomio: " << endl;
				m.leerMonomio();

				res=m.resuelveMonomio(x);

				m.escribirMonomio();
				cout << "\nResultado: " << res << endl;

				sleep(2);
			break;

			case 2:
				cout << "\nIntroduzca el primer monomio: " << endl;
				m.leerMonomio();

				cout << "\nIntroduzca el segundo monomio: " << endl;
				m2.leerMonomio();
	
				m3=m*m2;
		
				
				cout << "\nEl primer monomio es:" << endl;
				m.escribirMonomio();
				cout << "\nEl segundo monomio es: " << endl;
				m2.escribirMonomio();
				cout << "\nEl resultado de la multiplicacion es: " << endl;
				m3.escribirMonomio();
				sleep(2);
			break;

			case 3:
				cout << "\nIntroduzca el primer monomio: " << endl;
				m.leerMonomio();

				cout << "\nIntroduzca el segundo monomio: " << endl;
				m2.leerMonomio();
	
				m3=m+m2;
		
				
				cout << "\nEl primer monomio es:" << endl;
				m.escribirMonomio();
				cout << "\nEl segundo monomio es: " << endl;
				m2.escribirMonomio();
				cout << "\nEl resultado de la suma es: " << endl;
				m3.escribirMonomio();
				sleep(2);
			break;

			case 4:
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



// FUNCIONESMONOMIO_HPP
#endif
