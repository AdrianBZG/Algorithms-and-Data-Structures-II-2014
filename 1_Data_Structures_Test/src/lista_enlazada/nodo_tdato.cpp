/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Elemento "nodo del tipo TDATO" para utilizar en la estructura de datos "lista"
 * Practica 1 - Algoritmos y Estructura de Datos Avanzadas
 */
 
#include "nodo_tdato.hpp"

nodo_tdato_t::nodo_tdato_t(TDATO dato):
	nodo_t(),
	dato_(dato){}
	
nodo_tdato_t::nodo_tdato_t(void):
	nodo_t(),
	dato_(0){}
	
nodo_tdato_t::~nodo_tdato_t(void){}
void nodo_tdato_t::set_dato(TDATO dato)
{
	dato_ = dato;
}

void nodo_tdato_t::write(ostream& os)
{
	os << dato_ << " " << endl;
}
