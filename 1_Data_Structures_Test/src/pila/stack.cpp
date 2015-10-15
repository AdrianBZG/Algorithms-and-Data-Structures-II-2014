/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Estructura de datos "pila"
 * Practica 1 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "stack.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;


	stack_t::stack_t(void):
		vector_(0),
		top_(-1)
		{}
	
	stack_t::~stack_t(void)
	{
		top_ = -1;
	}
	
	void stack_t::push(TDATO dato){		
		top_ ++;
		vector_.add_back(dato);
	}
	
	
	TDATO stack_t::pop(void)
	{
		if (!empty()){
			TDATO aux = vector_.get_dato((top_));
			top_ --;
			
			return aux;
		}
		else{
			cerr << "STACK UNDERFLOW!!" << endl;
			exit(1);
		}
	}
	
	
	TDATO stack_t::top(void)
	{
		if (!empty()){
			return vector_.get_dato((top_));
		} else{
			cerr << "STACK IS EMPTY!!" << endl;
			exit(1);			
		}
	}
	
	
