/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Estructura de datos "lista simplemente enlazada"
 * Practica 1 - Algoritmos y Estructura de Datos Avanzadas
 */
 

#include "lista.hpp"


lista_t::lista_t(void):
	inicio_(NULL),
	fin_(NULL){}
	
lista_t::~lista_t(void)
{
	inicio_=NULL;
	fin_=NULL;
}

void lista_t::write(ostream& os)
{
	nodo_t* aux = inicio_;
	while(aux != NULL)
	{
		aux->write(os);
		aux=aux->get_next();
	}
}

void lista_t::insert_empty(nodo_t* n)
{
	inicio_=n;
	fin_=n;
}

void lista_t::insert_begin(nodo_t* n)
{
	if(empty()) insert_empty(n);
	else { 
	  n->set_next(inicio_);
	  inicio_=n;
	}
}

void lista_t::insert_end(nodo_t *n)
{
	if(empty()) insert_empty(n);
	else {
	fin_->set_next(n);
	fin_=n;
	}
}

nodo_t* lista_t::extract_begin(void){
	if(inicio_==fin_)
	{
		nodo_t* aux=inicio_;
		inicio_=NULL;
		fin_=NULL;
		return aux;
	}
	else
	{
		nodo_t* aux = inicio_;
		inicio_=inicio_->get_next();
		return aux;
	}
}

nodo_t* lista_t::extract_end(void)
{
	if(inicio_==fin_)
	{
		nodo_t* aux=inicio_;
		inicio_=NULL;
		fin_=NULL;
		return aux;
	}
	else
	{
		nodo_t* aux=inicio_;
		while(aux->get_next() != fin_)
			aux=aux->get_next();
	    
	    fin_= aux;
	    aux=aux->get_next();
	    fin_->set_next(NULL);
	    return aux;
	}
}
