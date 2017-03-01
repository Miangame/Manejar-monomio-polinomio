/*! 
  \file polinomio.hpp
  \brief Monomio crea un Polinomio con grado, numero de monomios y un vector
  \author Miguel Angel Gavilan Merino
  \date 15 de marzo de 2016
*/

#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP


// Ficheros de cabecera
#include <vector>
#include <iostream>
#include <algorithm>
#include "polinomioInterfaz.hpp"
#include "monomio.hpp"


// Facilita la entrada y salida
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::sort;



/*!
   \brief Espacio de nombres para la asignatura de Estructura de datos.

*/
namespace ed{

	class Polinomio: public ed::PolinomioInterfaz
	{
		//! \name Atributos privados de la clase Polinomio
		private:
			int _NMonomios;
			int _grado;
			vector <Monomio> _monomios;
			

		//! \name Funciones o métodos públicos de la clase Polinomio
		public:

			//! \name Constructores de la clase Polinomio
			/*! 
				\brief Constructor que crea un Polinomio a partir de su numero de monomios y grado
				\attention Función sobrecargada        
			 	\note Los parámetros tienen valores por defecto
				\param NMonomios de tipo int, valor por defecto 1
				\param grado de tipo int, valor por defecto 1
				\pre Ninguna
				\post Ninguna
				\sa setNmonomios(), setGrado()
			*/
			Polinomio(int NMonomios=1, int grado=1)
			{
				setNMonomios(NMonomios);
				setGrado(grado);
			}


			/*! 
				\brief Constructor de "copia" que crea un Polinomio a partir de otro Polinomio
				\attention Función sobrecargada        
				\param p de tipo Polinomio pasado como referencia constante
				\pre El Polinomio p debe existir
				\post Ninguna
			*/
			Polinomio(const Polinomio &p)
			{
				*this=p;
			}



			//! \name Funciones de consulta de Polinomio

			/*! 
				\brief Devuelve el numero de monomios de un Polinomio
				\return componente "NMonomios" de un Polinomio (tipo int)
				\pre El Polinomio debe existir
				\post Ninguna
			*/
			int getNMonomios() const
			{
				return _NMonomios;
			}


			/*! 
				\brief Devuelve el grado de un Polinomio
				\return componente "grado" de un Polinomio (tipo int)
				\pre El Polinomio debe existir
				\post Ninguna
			*/
			int getGrado() const
			{
				return _grado;
			}


			/*! 
				\brief Devuelve el vector de monomios de un Polinomio
				\return componente "monomios" de un Polinomio (tipo vector)
				\pre El Polinomio debe existir
				\post Ninguna
			*/
			vector <ed::Monomio> getVector() const
			{
				return _monomios;
			}
	
 			
 			//! \name Funciones de modificación de Polinomio

			/*! 
				\brief Asigna un valor "NMonomios" a la componente "NMonomios" de un Polinomio
				\param NMonomios de tipo int
				\pre El Polinomio debe existir
				\post Ninguna
			*/	
			void setNMonomios(const int & NMonomios)
			{
				_NMonomios=NMonomios;
			}
		

			/*! 
				\brief Asigna un valor "grado" a la componente "grado" de un Polinomio
				\param grado de tipo int
				\pre El Polinomio debe existir
				\post Ninguna
			*/
			void setGrado(const int & grado)
			{
				_grado=grado;
			}


			/*! 
				\brief Asigna un vector "v" a la componente "monomios" de un Polinomio
				\param v de tipo vector <Monomios>
				\pre El Polinomio debe existir
				\post Ninguna
			*/
			void setVector(const std::vector <ed::Monomio> & v) 
			{
				_monomios=v;
			}



			//! \name Operadores
   
			/*! 
				\brief Operador que "copia" un Polinomio en otro Polinomio
				\attention Se sobrecarga el operador de asignación "="
				\param p de tipo Polinomio pasado como referencia constante
				\pre El Polinomio p debe existir
				\post Ninguna
				\sa getNMonomios(), getGrado(), setNMonomios(), setGrado()
			*/
			Polinomio & operator = (const Polinomio & p)
			{
				if (this != &p)
				{
					setNMonomios(p.getNMonomios());
					setGrado(p.getGrado());
					_monomios=p._monomios;
				}
				return *this;
			}


			/*! 
				\brief Operador que "suma" un Polinomio con otro Polinomio
				\attention Se sobrecarga el operador "+"
				\param p de tipo Polinomio 
				\return Polinomio p2
				\pre El Polinomio p debe existir
				\post Ninguna
			*/
			Polinomio operator + (Polinomio &p)
			{
				Polinomio p2;
				int enc=0;

				if(getGrado() > p.getGrado())
				{
					p2._grado=_grado;
				}
				else
				{
					p2._grado=p._grado;

				}
					p2._monomios=_monomios; 
					p2.setNMonomios(getNMonomios());

					vector <Monomio>::iterator it;		
					vector <Monomio>::iterator it2;
							
						for(it=p._monomios.begin(); it!=p._monomios.end(); it++)
						{
							enc=0;
							for(it2=p2._monomios.begin(); it2!=p2._monomios.end(); it2++)
							{
								if(it-> getGrado()== it2 -> getGrado())
								{
									it2->setCoeficiente(it->getCoeficiente() + it2->getCoeficiente());
									enc=1;
								}
							}
							if(enc==0)
							{
								p2._monomios.push_back(*it);
								p2.setNMonomios(p2.getNMonomios()+1);
							}
						}
				
					return p2;
			}


			/*! 
				\brief Operador que "multiplica" un Polinomio con otro Polinomio
				\attention Se sobrecarga el operador "*"
				\param p de tipo Polinomio
				\return Polinomio p2
				\pre El Polinomio p debe existir
				\post Ninguna
			*/
			Polinomio operator * (Polinomio p)
			{
				Polinomio p2;
				
				vector <Monomio>::iterator it;
				vector <Monomio>::iterator it2;
				
				for(it=_monomios.begin(); it!=_monomios.end(); it++)
				{
					for(it2=p._monomios.begin(); it2!=p._monomios.end(); it2++)
					{
						p2.agregarMonomio((*it) * (*it2));
					}
				}
		
					p2.setGrado(p2._monomios.front().getGrado());
				return p2;
			}



			/*! 
				\brief Operador que pide por pantalla un Polinomio
				\attention Se sobrecarga el operador ">>"
				\param p de tipo Polinomio 
				\param stream de tipo istream
				\return Variable stream de entrada
				\pre El Monomio m debe existir. Si el vector no esta vacio, vaciarlo
				\post Ninguna
			*/
			friend istream &operator>>(istream &stream, Polinomio &p)
			{
				int numero;
				bool esta;
				cout << "\nIntroduce el numero de monomios: "<< endl;
				cin >> numero;
		
				p.setNMonomios(numero);
				if(!p._monomios.empty())
				{
					p._monomios.clear();
				}
				Monomio aux;
				for(int i=0; i<numero; i++)
				{
					do{
						cout<<"\nIntroduzca coeficiente y grado"<<endl;
						stream >> aux;
						esta = p.getMonomio(aux, aux.getGrado());

						if(esta)
						{
							cout << "Error, usted ha metido ya ese grado. " << endl;
						}
					}while(esta);
		
					p._monomios.push_back(aux);
				}
					p.ordenar();
					p.setGrado(p._monomios.front().getGrado());

				return stream;
			}



			/*! 
				\brief Operador que muestra por pantalla un Monomio
				\attention Se sobrecarga el operador "<<"
				\param p de tipo Polinomio 
				\param stream de tipo ostream
				\return Variable stream de salida
				\pre El Polinomio p debe existir
				\post Ninguna
			*/
			friend ostream &operator<<(ostream &stream, Polinomio &p)
			{
				int cont=0;
	
				vector <Monomio>::iterator it;

				for(it=p._monomios.begin(); it!=p._monomios.end(); it++)
				{
					if(cont != 0 && (it->getCoeficiente()>0)) 
					{
				
						stream << "+";
				
					}
						stream << *it;
						cont++;
				}

				stream << endl;
				return stream;
			}



			//! \name Funciones lectura y escritura de la clase Polinomio

			/*! 
				\brief Rellena un Polinomio llamando a la funcion leerMonomio() de la clase Monomio
				\pre El Polinomio debe existir
				\post Ninguna
				\warning Se deben teclear números
			*/
			void leerPolinomio()
			{
				int nMono;
				Monomio m;	
				int i;

				if(!_monomios.empty())
				{
					_monomios.clear();
				}

				cout << "\nIntroduzca el numero de monomios" << endl;
				cin >> nMono;
				setNMonomios(nMono);

				for(i=0; i<nMono; i++)
				{
					m.leerMonomio();
					_monomios.push_back(m);
				}
				
				setNMonomios(nMono);
				calcularGrado();
			}


			/*! 
				\brief Escribe por pantalla un Polinomio de la forma (coeficientex^grado+coeficientex^grado...)
				\pre El Polinomio debe estar relleno
				\post Ninguna
			*/
			void escribirPolinomio()
			{	
				int i;
				Monomio m;
				ordenar();

				for(i=0; i<_monomios.size(); i++)
				{
					m=_monomios[i];
					cout << m;	
					if(i<_monomios.size()-1)
					{
						cout << "+";
					}				
				}
				cout << endl;
			}


			/*! 
				\brief Ordena un polinomio segun el grado de mayor a menor
				\pre El Polinomio debe existir
				\post Ninguna
			*/
			void ordenar()
			{
				Monomio temp;
				int i, j;

				for(i=0; i<(_monomios.size()-1); i++)
				{
					for (j=1; j<_monomios.size(); j++)
					{
						if(_monomios[i].getGrado()<_monomios[j].getGrado())
						{
							temp=_monomios[j];
							_monomios[j]=_monomios[i];
							_monomios[i]=temp;
						}
					}
				}
			}


			/*! 
				\brief Añade un Monomio al Polinomio
				\pre El Polinomio debe existir
				\post Ninguna
			*/
			void agregarMonomio(const Monomio m)
			{
				vector <Monomio>::iterator it;
				bool enc=0;
				
				for(it=_monomios.begin(); it!=_monomios.end(); it++)
				{
					if(it->getGrado() == m.getGrado())
					{
						it->setCoeficiente( it->getCoeficiente() + m.getCoeficiente());
						enc=1;
					}
				}
				if(!enc) _monomios.push_back(m);
				_NMonomios=_monomios.size();
			}


			/*! 
				\brief Devuelve true o false si encuentra un monomio dentro del polinomio
				\pre El Polinomio debe existir
				\post Ninguna
			*/
			bool getMonomio(Monomio & aux, int grado)
			{
				vector <Monomio> :: iterator it;

				if(!_monomios.empty())
				{
					for(it=_monomios.begin(); it!=_monomios.end(); it++)
					{
						if(grado==it->getGrado())
						{
							aux=*it;
							return true;
						}
					}
					
					return false;
				}
				
				return false;
			}


			/*! 
				\brief Funcion para comprobar si el vector esta vacio
				\pre Ninguna
				\post Ninguna
			*/
			bool estaVacia() const
			{
				return (_monomios.empty());
			}
 

			/*! 
				\brief Funcion que calcula el grado maximo de un Polinomio
				\pre El Polinomio debe existir
				\post Ninguna
			*/
			void calcularGrado()
			{
				int i;
				Monomio m;
				int aux=0;

				for (i=0; i<_monomios.size(); i++)
				{
					m=_monomios[i];
					m.getGrado();

					if(m.getGrado()>aux)
					{
						aux=m.getGrado();
					}
				}

				setGrado(aux);
			}


			//! \name Funciones para la resolucion de un Polinomio

			/*! 
				\brief Resuelve un Polinomio para un valor de "x" dado
				\pre El Polinomio debe existir
				\post Ninguna
				\return variable resultado donde se almacena el resultado
			*/
			double resuelvePolinomio(int x)
			{
				double resultado=0.0;

				vector<Monomio>::iterator it;

				for(it=_monomios.begin(); it!=_monomios.end(); it++)
				{
					resultado=resultado + it->resuelveMonomio(x);
				}
				
				return resultado;
			}

			
	}; // Fin de la definicion de la clase Monomio

}// \brief Fin de namespace ed

// POLINOMIO_HPP
#endif
