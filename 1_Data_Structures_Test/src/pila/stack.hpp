#pragma once

#include "vector.hpp"

class stack_t
{
private:
	vector_t vector_;														//Atributo: Vector que contiene los datos de la pila
	int top_;																//Atributo: Posición del elemento que está arriba de la pila
	
public:
	stack_t(void);															//Constructor por defecto
	~stack_t(void);															//Destructor
		
	void push(TDATO dato);													//Poner elemento en el top de la pila
	TDATO pop(void);														//Sacar elemento del top de la pila
	TDATO top(void);
	
	inline bool empty(void) { return (top_ == -1); }						//Comprobar si la pila está vacía
	
};
