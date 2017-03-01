/*! 
  \file monomio.hpp
  \brief Monomio crea un monomio con grado y coeficiente
  \author Miguel Angel Gavilan Merino
  \date 15 de marzo de 2016
*/

#ifndef MONOMIO_HPP
#define MONOMIO_HPP

// Ficheros de cabecera
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "monomioInterfaz.hpp"


// Facilita la entrada y salida
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;


/*!
   \brief Espacio de nombres para la asignatura de Estructura de datos.

*/
namespace ed{

	class Monomio: public ed::MonomioInterfaz
	{
		//! \name Atributos privados de la clase Monomio
		private:
			double _coeficiente;
			int _grado;

		//! \name Funciones o métodos públicos de la clase Monomio
		public:
			//! \name Constructores de la clase Monomio
			/*! 
				\brief Constructor que crea un Monomio a partir de su coeficiente y grado
				\attention Función sobrecargada        
			 	\note Los parámetros tienen valores por defecto
				\param coeficiente de tipo double, valor por defecto 1.0
				\param grado de tipo int, valor por defecto 1
				\pre Ninguna
				\post Ninguna
				\sa setCoeficiente(), setGrado()
			*/
			Monomio(double coeficiente=1.0, int grado=1)
			{
				setCoeficiente(coeficiente);
				setGrado(grado);
			}

			/*! 
				\brief Constructor de "copia" que crea un Monomio a partir de otro Monomio
				\attention Función sobrecargada        
				\param m de tipo Monomio pasado como referencia constante
				\pre El Monomio m debe existir
				\post Ninguna
			*/
			Monomio(const Monomio &m)
			{
				*this=m;
			}


			//! \name Funciones de consulta de Monomio

			/*! 
				\brief Devuelve el "coeficiente" de un Monomio
				\return componente "coeficiente" de un Monomio (tipo double)
				\pre El Monomio debe existir
				\post Ninguna
			*/
			double getCoeficiente() const
			{
				return _coeficiente;
			}


			/*! 
				\brief Devuelve el "grado" de un Monomio
				\return componente "grado" de un Monomio (tipo int)
				\pre El Monomio debe existir
				\post Ninguna
			*/
			int getGrado() const
			{
				return _grado;
			}


			//! \name Funciones de modificación de Monomio

			/*! 
				\brief Asigna un valor "coeficiente" a la componente "coeficiente" de un Monomio
				\param coeficiente de tipo double
				\pre El Monomio debe existir
				\post Ninguna
			*/			
			void setCoeficiente(const double & coeficiente)
			{
				_coeficiente=coeficiente;
			}
		


			/*! 
				\brief Asigna un valor "grado" a la componente "grado" de un Monomio
				\param grado de tipo int
				\pre El Monomio debe existir
				\post Ninguna
			*/	
			void setGrado(const int & grado)
			{
				_grado=grado;
			}


			//! \name Operadores
   
			/*! 
				\brief Operador que "copia" un Monomio en otro Monomio
				\attention Se sobrecarga el operador de asignación "="
				\param m de tipo Monomio pasado como referencia constante
				\pre El Monomio m debe existir
				\post Ninguna
				\sa getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
			*/
			Monomio & operator = (const Monomio & m)
			{
				if (this != &m)
				{
					setCoeficiente(m.getCoeficiente());
					setGrado(m.getGrado());
				}
				return *this;
			}



			/*! 
				\brief Operador que "multiplica" un Monomio con otro Monomio
				\attention Se sobrecarga el operador "*"
				\param m1 de tipo Monomio pasado como referencia constante
				\return Monomio m2
				\pre El Monomio m1 debe existir
				\post Ninguna
			*/
			Monomio operator * (const Monomio & m1)
			{
				Monomio m2;

				m2._grado=_grado+m1._grado;
				m2._coeficiente=_coeficiente*m1._coeficiente;			
				
				return m2;
			}



			/*! 
				\brief Operador que "suma" un Monomio con otro Monomio
				\attention Se sobrecarga el operador "+"
				\param m de tipo Monomio pasado como referencia constante
				\return Monomio m2
				\pre El Monomio m debe existir. Los monomios tienen que tener el mismo grado
				\post Ninguna
			*/
			Monomio operator + (const Monomio &m)
			{
				Monomio m2;
				
				if(_grado==m._grado)
				{
					m2._coeficiente=_coeficiente+m._coeficiente;
					m2._grado=_grado;
				}
				else
				{
					cout << "\nLos monomios no tienen el mismo grado\n" << endl;
					exit(-1);	
				}
			
				return m2;
			}



			/*! 
				\brief Operador que muestra por pantalla un Monomio
				\attention Se sobrecarga el operador "<<"
				\param m de tipo Monomio pasado como referencia constante
				\param stream de tipo ostream
				\return Variable stream de salida
				\pre El Monomio m debe existir
				\post Ninguna
			*/
			friend ostream &operator<<(ostream &stream, Monomio const &m)
			{
				stream << m.getCoeficiente() << "x^" << m.getGrado();
				return stream;
			}



			/*! 
				\brief Operador que pide por pantalla un Monomio
				\attention Se sobrecarga el operador ">>"
				\param m de tipo Monomio pasado como referencia constante
				\param stream de tipo istream
				\return Variable stream de entrada
				\pre El Monomio m debe existir
				\post Ninguna
			*/
			friend istream &operator>>(istream &stream, Monomio &m)
			{
				int grado;
				double coeficiente;
	
				stream >> coeficiente;
				m.setCoeficiente(coeficiente);
	
				stream >> grado;
				m.setGrado(grado);
	
				return stream;
			}


			//! \name Funciones lectura y escritura de la clase Monomio

			/*! 
				\brief Asigna a un Monomio las variables "coeficiente" y "grado" leídas desde el teclado
				\pre El Monomio debe existir
				\post Ninguna
				\warning Se deben teclear números
				\sa setCoeficiente(), setGrado()
			*/
			void leerMonomio()
			{
				int grado;
				double coeficiente;
				cout << "Introduzca el coeficiente" << endl;
				cin >> coeficiente;
				cout << "Introduzca el grado" << endl;
				cin >> grado;
				setGrado(grado);
				setCoeficiente(coeficiente);
			}


			/*! 
				\brief Escribe por pantalla las componentes coeficiente y grado de un Monomio de la forma (coeficientex^grado)
				\pre El Monomio debe tener valores asignados a sus componentes
				\post Ninguna
				\sa getCoeficiente(), getGrado()
			*/
			void escribirMonomio()
			{
				cout << getCoeficiente() << "x^" << getGrado();
			}



			//! \name Funcion para la resolucion de un monomio 

			/*! 
				\brief Resuelve un Monomio para un valor de "x" dado
				\pre El Monomio debe existir
				\post Ninguna
				\return variable res donde se almacena el resultado
				\sa setCoeficiente()
			*/
			double resuelveMonomio(int x)
			{
				double res=0.0;
				int grad;

				grad=pow(x, getGrado());
				res=getCoeficiente()*grad;
				
				return res;
			}

			
	}; // Fin de la definicion de la clase Monomio

} // \brief Fin de namespace ed

// MONOMIO_HPP
#endif





















