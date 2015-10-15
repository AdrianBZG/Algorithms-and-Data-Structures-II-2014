/* Adrian Rodriguez Bazaga
 * alu0100826456@ull.edu.es
 * Clase "DNI" que guarda un valor generado aleatoriamente
 * Práctica 6 - Algoritmos y Estructura de Datos Avanzadas
 */


#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;


template <class Tipo>
class dni_t {

private:

	Tipo valor_;

public:

	dni_t(void);
	dni_t(Tipo v);

	~dni_t(void);
	
	ostream& toStream(ostream& sout) const;
	istream& fromStream(istream& sin);

	void set_valor(Tipo val);	
	Tipo get_valor(void) const;
	
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
	friend istream& operator>>(istream& is, dni_t<Tipo>); 	//Sobrecarga del operador de entrada
	//
	//

};

//Implementación
template<class Tipo>
dni_t<Tipo>::dni_t(void)
{
	srand((time(NULL)+rand()%10000)%1000000);
	valor_=((rand()%RAND_MAX)%100);
}

template<class Tipo>
dni_t<Tipo>::dni_t(Tipo v)
{
	valor_=v;
}

template<class Tipo>
dni_t<Tipo>::~dni_t(void)
{
	valor_=0;
}

template<class Tipo>
ostream& dni_t<Tipo>::toStream(ostream& os) const
{
	os << get_valor() << endl; 
	return os;
}

template<class Tipo>
istream& dni_t<Tipo>::fromStream(istream& is)
{
	Tipo aux1;
	system("clear");		
	cout << "< INDICAR VALOR:" << endl << endl;	
	is >> aux1;	
	set_valor(aux1);
	system("clear");
	return is;
}

template<class Tipo>
void dni_t<Tipo>::set_valor(Tipo val)
{
	valor_=val;
}

template<class Tipo>
Tipo dni_t<Tipo>::get_valor(void) const
{
	return valor_;
}

//Sobrecarga de comparaciones
	
template<class Tipo>
void dni_t<Tipo>::operator=(dni_t v)
{
	this->set_valor(v.get_valor());
}

template<class Tipo>
bool dni_t<Tipo>::operator==(dni_t v)
{	
	return (get_valor()==v.get_valor());		
}

template<class Tipo>	
bool dni_t<Tipo>::operator!=(dni_t v)
{
	return (not(get_valor()!=v.get_valor()));	
}

template<class Tipo>
bool dni_t<Tipo>::operator<(dni_t v)
{	
	return (this->get_valor()<v.get_valor());		
}

template<class Tipo>	
bool dni_t<Tipo>::operator>(dni_t v)
{	
	return (not(this->get_valor()<v.get_valor()));		
}

template<class Tipo>	
bool dni_t<Tipo>::operator<=(dni_t v)
{		
	return (get_valor() == v.get_valor() || get_valor() < v.get_valor());		
}

template<class Tipo>
bool dni_t<Tipo>::operator>=(dni_t v)
{	
	return (get_valor() == v.get_valor() || get_valor() > v.get_valor()); 		
}
	
//
	
//Sobrecarga de E/S
template<class Tipo>
ostream& operator<<(ostream& os, dni_t<int> c)
{
	c.toStream(os);
	return os;
}

template<class Tipo>
istream& operator>>(istream& is, dni_t<Tipo> c)
{
	c.fromStream(is);
	return is;
}
//
//
