/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa donde para probar la estructura de datos "lista simplemente enlazada"
 * Practica 1 - Algoritmos y Estructura de Datos Avanzadas
 */


#include "lista.hpp"
#include "nodo_tdato.hpp"
#include <iostream>

#define LISTA_SIZE 10

int main(void)
{
	//Listas simp. enlaz.
	lista_t L1;
	lista_t L2;
	//
	
	
	cout << "< L1: LISTA DE "<< LISTA_SIZE << " ELEMENTOS INSERTANDO POR EL INICIO >" << endl;
	for(int i=0;i<LISTA_SIZE;i++)
	{
		L1.insert_begin(new nodo_tdato_t(i+2));
	}
	cout << "- Mostramos los elementos de la lista L1: - " << endl;
	L1.write(std::cout);
	cout << endl << endl;
	
	
	
	cout << "< L2: LISTA DE "<< LISTA_SIZE << " ELEMENTOS INSERTANDO POR EL FINAL >" << endl;
	for(int i=0;i<LISTA_SIZE;i++)
	{
		L2.insert_end(new nodo_tdato_t(i+33));
	}
	L2.insert_end(new nodo_tdato_t);
	cout << "- Mostramos los elementos de la lista L2: - " << endl;
	L2.write(std::cout);
	cout << endl;
}
