/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa donde para probar la estructura de datos "lista simplemente enlazada"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */


#include "lista.cpp"
#include "nodo_dato.cpp"
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
		L1.insert_end(new nodo_dato_t<int>(i));
		L1.insert_end(new nodo_dato_t<double>(i+0.5587));
	}
	cout << "- Mostramos los elementos de la lista L1: - " << endl;
	L1.write(std::cout);
	cout << endl << endl;
	
	
	
	cout << "< L2: LISTA DE "<< LISTA_SIZE << " ELEMENTOS INSERTANDO POR EL FINAL >" << endl;
	for(int i=0;i<LISTA_SIZE;i++)
	{
		L2.insert_begin(new nodo_dato_t<int>(i+33));
	}
	cout << "- Mostramos los elementos de la lista L2: - " << endl;
	L2.write(std::cout);
	cout << endl;
}
