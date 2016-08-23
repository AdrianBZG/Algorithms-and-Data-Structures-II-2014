/* Adrian Rodriguez Bazaga
 * alu0100826456@ull.edu.es
 * Clase "nodoBB"
 * Práctica 6 - Algoritmos y Estructura de Datos Avanzadas
 */


#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>

//Incluimos el nodoBB
#include "dni.cpp"
//

using namespace std;


template <class Tipo>
class nodoBB {

private:

	dni_t<Tipo> clave_;
	nodoBB<Tipo>* izq_;
	nodoBB<Tipo>* der_;

public:

	nodoBB(Tipo dat, nodoBB<Tipo>* izq, nodoBB<Tipo>* der);
	nodoBB(Tipo dat);
	nodoBB();
	~nodoBB(void);	
	
	nodoBB<Tipo>*& get_izq();
	nodoBB<Tipo>*& get_der();
	Tipo get_clave();
	void set_clave(Tipo dat);

};

//Implementación
template<class Tipo>
nodoBB<Tipo>::nodoBB(Tipo dat, nodoBB<Tipo>* izq, nodoBB<Tipo>* der)
{
	clave_ = dni_t<Tipo>(dat);
	izq_ = izq;
	der_ = der;
}

template<class Tipo>
nodoBB<Tipo>::nodoBB(Tipo dat)
{
	clave_ = dni_t<Tipo>(dat);
	izq_ = NULL;
	der_ = NULL;
}

template<class Tipo>
nodoBB<Tipo>::nodoBB()
{
	dni_t<Tipo> dato;
	clave_ = dato;
	izq_ = NULL;
	der_ = NULL;
}

template<class Tipo>
nodoBB<Tipo>::~nodoBB(void)
{
	izq_ = NULL;
	der_ = NULL;
}

template<class Tipo>
nodoBB<Tipo>*& nodoBB<Tipo>::get_izq()
{
	return izq_;
}

template<class Tipo>
nodoBB<Tipo>*& nodoBB<Tipo>::get_der()
{
	return der_;
}

template<class Tipo>
Tipo nodoBB<Tipo>::get_clave()
{
	return clave_.get_valor();
}

template<class Tipo>
void nodoBB<Tipo>::set_clave(Tipo dat)
{
	clave_ = dni_t<Tipo>(dat);
}
//
