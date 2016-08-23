/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa para probar la clase "Número"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

//Tipos de numero y estructuras de datos
#include "numero.hpp"
#include "../entero/entero.hpp"
#include "../natural/natural.hpp"
#include "../racional/racional.hpp"
#include "../real/real.hpp"
#include "../complejo/complejo.hpp"
#include "../../../estructuras/src/vector/vector.cpp"
#include "../../../estructuras/src/pila/stack.cpp"
#include "../../../estructuras/src/cola/queue_t.cpp"
#include "../../../estructuras/src/lista_enlazada/lista.cpp"
//

int main(int argc, char **argv)
{
	
	Vector<Numero*> mi_vector;
	stack_t<Numero*> mi_pila;
	queue_t<Numero*> mi_cola;
	lista_t<Numero*> mi_lista;
	
	Numero* numero1 = new entero_t(10);
	Numero* numero2 = new entero_t(-25);
	Numero* numero3 = new natural_t(5);
	Numero* numero4 = new racional_t(5,10);
	Numero* numero5 = new real_t(3.1416);
	Numero* numero6 = new complejo_t(3,7);

	cout << endl << "\t\t\t<<<   INICIO DEL PROGRAMA   >>>" << endl << endl;
	
	//VECTOR:
	mi_vector.push_back(numero1);
	mi_vector.push_back(numero2);
	mi_vector.push_back(numero3);
	mi_vector.push_back(numero4);
	mi_vector.push_back(numero5);
	mi_vector.push_back(numero6);
	
	//Imprimimos el vector
	cout << "VECTOR: ";
	mi_vector.toStream(cout);
	cout << endl;
	//
	//FIN VECTOR
	
	
	//PILA:
	mi_pila.push(numero1);
	mi_pila.push(numero2);
	mi_pila.push(numero3);
	mi_pila.push(numero4);
	mi_pila.push(numero5);
	mi_pila.push(numero6);
	
	cout << "<<<   ----------------   >>>" << endl << endl;
	
	//Imprimimos la pila
	cout << "PILA:" << endl;
	while(!mi_pila.empty())
	{
		mi_pila.pop()->toStream(cout);
		cout << endl;
	}
	//
	//FIN PILA
		
	
	//COLA:
	mi_cola.add(numero1);
	mi_cola.add(numero2);
	mi_cola.add(numero3);
	mi_cola.add(numero4);
	mi_cola.add(numero5);
	mi_cola.add(numero6);
	
	cout << endl << "<<<   ----------------   >>>" << endl << endl;
	
	//Imprimimos la cola
	cout << "COLA:" << endl;
	while(!mi_cola.empty())
	{
		mi_cola.extract()->toStream(cout);
		cout << endl;
	}
	//
	//FIN COLA
			
	
	//LISTA ENLAZADA:
	mi_lista.insert_end(new nodo_t<Numero*>(numero1));
	mi_lista.insert_end(new nodo_t<Numero*>(numero2));
	mi_lista.insert_end(new nodo_t<Numero*>(numero3));
	mi_lista.insert_end(new nodo_t<Numero*>(numero4));
	mi_lista.insert_end(new nodo_t<Numero*>(numero5));
	mi_lista.insert_end(new nodo_t<Numero*>(numero6));
	
	cout << endl << "<<<   ----------------   >>>" << endl << endl;
	
	//Imprimimos la lista enlazada
	cout << "LISTA ENLAZADA:" << endl;
	while(!mi_lista.empty())
	{
		mi_lista.extract_begin()->get_dato()->toStream(cout);
		cout << endl;
	}
	//
	//FIN LISTA ENLAZADA
	
	
	//Otra forma de crear los Numeros
	//////////////////////////////////
	
	/*
	entero_t numero_entero(10);
	entero_t numero_entero2(-25);
	natural_t numero_natural(5);
	racional_t numero_racional(5,10);
	real_t numero_real(3.1416);
	complejo_t numero_complejo(3,7);
	
	Numero* numero1 = &numero_entero;
	Numero* numero2 = &numero_natural;
	Numero* numero3 = &numero_entero2;
	Numero* numero4 = &numero_racional;
	Numero* numero5 = &numero_real;
	Numero* numero6 = &numero_complejo;
	*/
	
	//////////////////////////////////

	

	cout << endl << endl << "\t\t\t<<<   FIN DEL PROGRAMA   >>>" << endl << endl;
}
