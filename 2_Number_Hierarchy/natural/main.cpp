/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa para probar la clase "Número natural"
 * Practica 2 - Algoritmos y Estructura de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "natural.hpp"

int main(int argc, char **argv)
{
	
	NATURAL numero = 10;	
	natural_t numero2(0);
	
	numero2.escribir(cin);	
	numero2.imprimir(cout);	
	
	natural_t numero3(40);
	numero3 = numero3-numero;
	numero3.imprimir(cout);

	cout << "<<<   FIN DEL PROGRAMA   >>>" << endl << endl;
}
