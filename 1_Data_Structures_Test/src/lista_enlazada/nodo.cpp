/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Elemento "nodo" para utilizar en la estructura de datos "lista"
 * Practica 1 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "nodo.hpp"

nodo_t::nodo_t(void):
	next_(NULL){}
	
nodo_t::~nodo_t(void){}

void nodo_t::set_next(nodo_t* next)
{
	next_ = next;
}
