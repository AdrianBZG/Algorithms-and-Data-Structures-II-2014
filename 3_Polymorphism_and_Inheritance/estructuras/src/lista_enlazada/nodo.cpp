#pragma once

#include <cstdio>
#include <iostream>

using namespace std;

template<class Tdato> class nodo_t
{
	private:
		Tdato dato_;										//Atributo: Dato tipo TDATO que guarda el nodo
		nodo_t* next_;										//Atributo: Puntero al siguiente nodo
		
	public:
		nodo_t(void);										//Constructor por defecto
		nodo_t(Tdato dato);									//Constructor del nodo con un dato tipo TDATO
		~nodo_t(void);										//Destructor
		void set_next(nodo_t* next);						//Indicar puntero al siguiente nodo
		inline nodo_t* get_next(void) { return next_; }		//Obtener puntero al siguiente nodo
		void write(ostream& os);							//Función virtual para imprimir el nodo (se imprime en la función de nodo_tdato)
		void set_dato(Tdato dato);							//Poner dato en el nodo
		inline Tdato get_dato(void) { return dato_; }		//Obtener dato del nodo
};

template <class Tdato> nodo_t<Tdato>::nodo_t(void):
	next_(NULL),
	dato_(0){}
		
template <class Tdato> nodo_t<Tdato>::nodo_t(Tdato dato):
	next_(NULL),
	dato_(dato){}
	
template <class Tdato> nodo_t<Tdato>::~nodo_t(void){}

template <class Tdato> void nodo_t<Tdato>::set_next(nodo_t<Tdato>* next)
{
	next_ = next;
}

template <class Tdato> void nodo_t<Tdato>::set_dato(Tdato dato)
{
	dato_ = dato;
}

template <class Tdato> void nodo_t<Tdato>::write(ostream& os)
{
	os << dato_ << " " << endl;
}
