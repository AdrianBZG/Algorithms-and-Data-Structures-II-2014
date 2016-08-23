/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa para probar la clase "Número real"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
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
	
	numero2.fromStream(cin);	
	numero2.toStream(cout);	
	
	real_t numero3(40.5678);
	numero3 = numero-numero3;
	numero3.toStream(cout);

	cout << "<<<   FIN DEL PROGRAMA   >>>" << endl << endl;
}
