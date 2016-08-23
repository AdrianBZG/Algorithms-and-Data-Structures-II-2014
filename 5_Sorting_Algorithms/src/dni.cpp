/* Adrian Rodriguez Bazaga
 * alu0100826456@ull.edu.es
 * Clase "DNI" que guarda un valor generado aleatoriamente
 * Práctica 5 - Algoritmos y Estructura de Datos Avanzadas
 */


#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;


template <class Clave>
class dni_t {

private:

	Clave valor_;

public:

	dni_t(void);
	dni_t(Clave v);

	~dni_t(void);
	
	ostream& toStream(ostream& sout) const;
	istream& fromStream(istream& sin);

	void set_valor(Clave val);	
	Clave get_valor(void) const;
	
	//Sobrecargas
	void operator=(dni_t);								//Sobrecarga del operador '=' para asignar valor
	
	//Comparaciones
	bool operator==(dni_t);							//Igual que	
	bool operator!=(dni_t);							//Distinto que
	bool operator<(dni_t);							//Menor que
	bool operator>(dni_t);							//Mayor que
	bool operator<=(dni_t);							//Menor o igual que
	bool operator>=(dni_t);							//Mayor o igual que
	//
	
	//E/S
	friend ostream& operator<<(ostream& os, dni_t<int>); 	//Sobrecarga del operador de salida
	friend istream& operator>>(istream& is, dni_t<Clave>); 	//Sobrecarga del operador de entrada
	//
	//

};

//Implementación
template<class Clave>
dni_t<Clave>::dni_t(void)
{
	srand((time(NULL)+rand()%10000)%1000000);
	valor_=((rand()%RAND_MAX)%1000000);
}

template<class Clave>
dni_t<Clave>::dni_t(Clave v)
{
	valor_=v;
}

template<class Clave>
dni_t<Clave>::~dni_t(void)
{
	valor_=0;
}

template<class Clave>
ostream& dni_t<Clave>::toStream(ostream& os) const
{
	os << get_valor() << endl; 
	return os;
}

template<class Clave>
istream& dni_t<Clave>::fromStream(istream& is)
{
	Clave aux1;
	system("clear");		
	cout << "< INDICAR VALOR:" << endl << endl;	
	is >> aux1;	
	set_valor(aux1);
	system("clear");
	return is;
}

template<class Clave>
void dni_t<Clave>::set_valor(Clave val)
{
	valor_=val;
}

template<class Clave>
Clave dni_t<Clave>::get_valor(void) const
{
	return valor_;
}

//Sobrecarga de comparaciones
	
template<class Clave>
void dni_t<Clave>::operator=(dni_t v)
{
	this->set_valor(v.get_valor());
}

template<class Clave>
bool dni_t<Clave>::operator==(dni_t v)
{	
	return (get_valor()==v.get_valor());		
}

template<class Clave>	
bool dni_t<Clave>::operator!=(dni_t v)
{
	return (not(get_valor()!=v.get_valor()));	
}

template<class Clave>
bool dni_t<Clave>::operator<(dni_t v)
{	
	return (this->get_valor()<v.get_valor());		
}

template<class Clave>	
bool dni_t<Clave>::operator>(dni_t v)
{	
	return (not(this->get_valor()<v.get_valor()));		
}

template<class Clave>	
bool dni_t<Clave>::operator<=(dni_t v)
{		
	return (get_valor() == v.get_valor() || get_valor() < v.get_valor());		
}

template<class Clave>
bool dni_t<Clave>::operator>=(dni_t v)
{	
	return (get_valor() == v.get_valor() || get_valor() > v.get_valor()); 		
}
	
//
	
//Sobrecarga de E/S
template<class Clave>
ostream& operator<<(ostream& os, dni_t<int> c)
{
	c.toStream(os);
	return os;
}

template<class Clave>
istream& operator>>(istream& is, dni_t<Clave> c)
{
	c.fromStream(is);
	return is;
}
//
//
