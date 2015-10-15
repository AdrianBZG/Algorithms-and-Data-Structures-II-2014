/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Estructura de datos "lista simplemente enlazada"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */

#pragma once
#include <cstdio>
#include <iostream>
#include "nodo.cpp"

using namespace std;


template<class Tdato> class lista_t{
	private:
		nodo_t<Tdato>* inicio_;										//Atributo: Puntero al nodo del principio de la lista
		nodo_t<Tdato>* fin_;										    //Atributo: Puntero al nodo del final de la lista
	public:
		lista_t(void);											//Constructor por defecto
		virtual ~lista_t(void);								    //Destructor
		void write(ostream& os);								//Mostrar lista
		void reset(void);										//Vaciar lista
		inline bool empty(void) { return (inicio_==NULL); }		//Comprobar si la lista está vacía
		void insert_empty(nodo_t<Tdato>* n);							//Insertar nodo en caso de que la lista esté vacía (se usa en insert_begin & insert_end)
		void insert_begin(nodo_t<Tdato>* n);							//Insertar nodo al principio de la lista
		void insert_end(nodo_t<Tdato>* n);								//Insertar nodo al final de la lista
		nodo_t<Tdato>* extract_begin(void);							//Extraer nodo del principio de la lista
		nodo_t<Tdato>* extract_end(void);								//Extraer nodo del final de la lista
};

template <class Tdato> lista_t<Tdato>::lista_t(void):
	inicio_(NULL),
	fin_(NULL){}
	
template <class Tdato> lista_t<Tdato>::~lista_t(void)
{
	inicio_=NULL;
	fin_=NULL;
}

template <class Tdato> void lista_t<Tdato>::write(ostream& os)
{
	nodo_t<Tdato>* aux = inicio_;
	while(aux != NULL)
	{
		aux->write(os);
		aux=aux->get_next();
	}
}

template <class Tdato> void lista_t<Tdato>::insert_empty(nodo_t<Tdato>* n)
{
	inicio_=n;
	fin_=n;
}

template <class Tdato> void lista_t<Tdato>::insert_begin(nodo_t<Tdato>* n)
{
	if(empty()) insert_empty(n);
	else { 
	  n->set_next(inicio_);
	  inicio_=n;
	}
}

template <class Tdato> void lista_t<Tdato>::insert_end(nodo_t<Tdato> *n)
{
	if(empty()) insert_empty(n);
	else {
	fin_->set_next(n);
	fin_=n;
	}
}

template <class Tdato> nodo_t<Tdato>* lista_t<Tdato>::extract_begin(void){
	if(inicio_==fin_)
	{
		nodo_t<Tdato>* aux=inicio_;
		inicio_=NULL;
		fin_=NULL;
		return aux;
	}
	else
	{
		nodo_t<Tdato>* aux = inicio_;
		inicio_=inicio_->get_next();
		return aux;
	}
}

template <class Tdato> nodo_t<Tdato>* lista_t<Tdato>::extract_end(void)
{
	if(inicio_==fin_)
	{
		nodo_t<Tdato>* aux=inicio_;
		inicio_=NULL;
		fin_=NULL;
		return aux;
	}
	else
	{
		nodo_t<Tdato>* aux=inicio_;
		while(aux->get_next() != fin_)
			aux=aux->get_next();
	    
	    fin_= aux;
	    aux=aux->get_next();
	    fin_->set_next(NULL);
	    return aux;
	}
}
