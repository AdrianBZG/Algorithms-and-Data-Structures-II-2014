/* Adrian Rodriguez Bazaga
 * alu0100826456@ull.edu.es
 * Clase "nodoAVL"
 * Práctica 7 - Algoritmos y Estructura de Datos Avanzadas
 */


#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>

//Incluimos el DNI
#include "dni.cpp"
//

using namespace std;


template <class Tipo>
class nodoAVL {

private:

	dni_t<Tipo> clave_;
	int bal_;
	nodoAVL<Tipo>* izq_;
	nodoAVL<Tipo>* der_;

public:

	nodoAVL(Tipo dat, nodoAVL<Tipo>* izq, nodoAVL<Tipo>* der);
	nodoAVL(Tipo dat);
	nodoAVL();
	~nodoAVL(void);	
	
	nodoAVL<Tipo>*& get_izq();
	nodoAVL<Tipo>*& get_der();
	Tipo get_clave();
	void set_clave(Tipo dat);

};

//Implementación
template<class Tipo>
nodoAVL<Tipo>::nodoAVL(Tipo dat, nodoAVL<Tipo>* izq, nodoAVL<Tipo>* der)
{
	clave_ = dni_t<Tipo>(dat);
	bal_ = 0;
	izq_ = izq;
	der_ = der;
}

template<class Tipo>
nodoAVL<Tipo>::nodoAVL(Tipo dat)
{
	clave_ = dni_t<Tipo>(dat);
	bal_ = 0;
	izq_ = NULL;
	der_ = NULL;
}

template<class Tipo>
nodoAVL<Tipo>::nodoAVL()
{
	dni_t<Tipo> dato;
	clave_ = dato;
	izq_ = NULL;
	der_ = NULL;
}

template<class Tipo>
nodoAVL<Tipo>::~nodoAVL(void)
{
	izq_ = NULL;
	der_ = NULL;
}

template<class Tipo>
int nodoAVL<Tipo>::get_bal()
{
	return bal_;
}

template<class Tipo>
void nodoAVL<Tipo>::set_bal(int dat)
{
	bal_ = dat;
}

template<class Tipo>
nodoAVL<Tipo>*& nodoAVL<Tipo>::get_izq()
{
	return izq_;
}

template<class Tipo>
nodoAVL<Tipo>*& nodoAVL<Tipo>::get_der()
{
	return der_;
}

template<class Tipo>
Tipo nodoAVL<Tipo>::get_clave()
{
	return clave_.get_valor();
}

template<class Tipo>
void nodoAVL<Tipo>::set_clave(Tipo dat)
{
	clave_ = dni_t<Tipo>(dat);
}
//
