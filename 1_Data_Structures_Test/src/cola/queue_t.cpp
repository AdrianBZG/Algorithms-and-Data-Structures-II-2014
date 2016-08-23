/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Estructura de datos "cola"
 * Practica 1 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "queue_t.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;


queue_t::queue_t(void):
	vector_(0),
	front_(-1),
	rear_(0){}
	
queue_t::~queue_t(void)
{
	front_=-1;
	rear_=0;
}

void queue_t::add(const TDATO dato)
{
	front_++;
	vector_.add_back(dato);
}

TDATO queue_t::extract(void)
{
	if(!empty())
	{
		TDATO aux = vector_.get_dato(rear_);
		rear_++;
		return aux;
	}
	else
	{
		cerr << "Queue underflow!" << endl;
		exit(1);
	}
}

void queue_t::reset(void)
{
	while(!empty())
	{
		TDATO aux = vector_.get_dato(rear_);
		rear_++;
	}	
}
