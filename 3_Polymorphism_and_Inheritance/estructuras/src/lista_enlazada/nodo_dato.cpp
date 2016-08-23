#pragma once

#include <cstdio>
#include <iostream>
#include "nodo.cpp"

using namespace std;


template<class Tdato> class nodo_dato_t:public nodo_t
{
	private:
		Tdato dato_;										//Atributo: Dato tipo TDATO que guarda el nodo
	public:
		nodo_dato_t(Tdato dato);							//Constructor del nodo con un dato tipo TDATO
		nodo_dato_t(void); 									//Constructor por defecto, para meter nodos inicializados a 0
		virtual ~nodo_dato_t(void);							//Destructor
		void set_dato(Tdato dato);							//Poner dato en el nodo
		virtual inline Tdato get_dato(void) { return dato_; }		//Obtener dato del nodo
		virtual void write(ostream& os);					//Mostrar dato del nodo
};

template <class Tdato> nodo_dato_t<Tdato>::nodo_dato_t(Tdato dato):
	nodo_t(),
	dato_(dato){}
	
template <class Tdato> nodo_dato_t<Tdato>::nodo_dato_t(void):
	nodo_t(),
	dato_(0){}
	
template <class Tdato> nodo_dato_t<Tdato>::~nodo_dato_t(void){}

template <class Tdato> void nodo_dato_t<Tdato>::set_dato(Tdato dato)
{
	dato_ = dato;
}

template <class Tdato> void nodo_dato_t<Tdato>::write(ostream& os)
{
	os << dato_ << " " << endl;
}

