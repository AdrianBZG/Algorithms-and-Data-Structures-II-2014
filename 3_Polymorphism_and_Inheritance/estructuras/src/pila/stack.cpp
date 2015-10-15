/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Estructura de datos "pila"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */
 
#pragma once

#include "vector.cpp"

template<class Tdato> class stack_t
{
private:
	Vector<Tdato> vector_;													//Atributo: Vector que contiene los datos de la pila
	int top_;																//Atributo: Posición del elemento que está arriba de la pila
	
public:
	stack_t(void);															//Constructor por defecto
	~stack_t(void);															//Destructor
		
	void push(Tdato dato);													//Poner elemento en el top de la pila
	Tdato pop(void);														//Sacar elemento del top de la pila
	
	inline bool empty(void) { return (top_ == -1); }						//Comprobar si la pila está vacía
	
};

template <class Tdato> stack_t<Tdato>::stack_t(void):
	vector_(),
	top_(-1)
{}
	
template <class Tdato> stack_t<Tdato>::~stack_t(void)
{
	top_ = -1;
}
	
template <class Tdato> void stack_t<Tdato>::push(Tdato dato){		
	top_ ++;
	vector_.push_back(dato);
}
	
	
template <class Tdato> Tdato stack_t<Tdato>::pop(void)
{
	try
	{
		if(empty())
		{
			throw("Error al extraer elemento de la pila, la pila está vacía");
		}
		Tdato aux = vector_.at(top_);
		top_ --;		
		return aux;
	}
	catch(const char* msg)
	{
		cerr << msg << endl;
		exit(1);
	}
}
