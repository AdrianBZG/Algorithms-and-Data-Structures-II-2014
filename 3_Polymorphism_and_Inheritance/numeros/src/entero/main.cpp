/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa para probar la clase "Número entero"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "entero.hpp"

int main(int argc, char **argv)
{
	
	ENTERO numero = 10;	
	entero_t numero2(0);
	
	numero2.fromStream(cin);	
	numero2.toStream(cout);	
	
	entero_t numero3(40);
	numero3 = numero-numero3;
	numero3.toStream(cout);

	cout << "<<<   FIN DEL PROGRAMA   >>>" << endl << endl;
}
