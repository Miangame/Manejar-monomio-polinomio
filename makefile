CPPFLAGS = -g -c -Wall -ansi 

OBJETOS_MONOMIO =  monomio.o 
OBJETOS_POLINOMIO = polinomio.o

All: mainMonomio.x mainPolinomio.x clean

mainMonomio.x: mainMonomio.o $(OBJETOS_MONOMIO)
	g++ -o mainMonomio.x mainMonomio.o $(OBJETOS_MONOMIO)

mainPolinomio.x:  mainPolinomio.o  $(OBJETOS_POLINOMIO) $(OBJETOS_MONOMIO)
	g++ -o mainPolinomio.x  mainPolinomio.o $(OBJETOS_POLINOMIO) $(OBJETOS_MONOMIO)


mainMonomio.o: mainMonomio.cpp  monomio.hpp monomioInterfaz.hpp funcionesMonomio.hpp
	g++ $(CPPFLAGS) mainMonomio.cpp  


monomio.o: monomio.cpp monomio.hpp monomioInterfaz.hpp
	g++ $(CPPFLAGS) monomio.cpp


mainPolinomio.o: mainPolinomio.cpp polinomio.hpp polinomioInterfaz.hpp monomio.hpp monomioInterfaz.hpp funcionesPolinomio.hpp
	g++ $(CPPFLAGS) mainPolinomio.cpp   

polinomio.o: polinomio.cpp polinomio.hpp polinomioInterfaz.hpp monomio.hpp monomioInterfaz.hpp
	g++ $(CPPFLAGS) polinomio.cpp   

clean:
	rm -f $(OBJETOS)
