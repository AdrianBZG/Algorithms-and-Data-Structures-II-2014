/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa para probar la clase "Número racional"
 * Practica 2 - Algoritmos y Estructura de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "racional.hpp"

int main(int argc, char **argv)
{
	
	racional_t numero2(78, 156);
	numero2.imprimir(cout);	
	
	racional_t numero3(124, 254);
	numero3 = numero3 - numero2;
	numero3.imprimir(cout);
	
	numero2 = numero2 * numero3;
	numero2.imprimir(cout);

	cout << "<<<   FIN DEL PROGRAMA   >>>" << endl << endl;
}
