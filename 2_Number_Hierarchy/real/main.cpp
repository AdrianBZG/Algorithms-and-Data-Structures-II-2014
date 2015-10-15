/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa para probar la clase "Número real"
 * Practica 2 - Algoritmos y Estructura de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "real.hpp"

int main(int argc, char **argv)
{
	
	REAL numero = 10.1234;	
	real_t numero2(0);
	
	numero2.escribir(cin);	
	numero2.imprimir(cout);	
	
	real_t numero3(40.5678);
	numero3 = numero-numero3;
	numero3.imprimir(cout);

	cout << "<<<   FIN DEL PROGRAMA   >>>" << endl << endl;
}
