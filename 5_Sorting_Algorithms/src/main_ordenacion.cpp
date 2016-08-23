/* Adrian Rodriguez Bazaga
 * alu0100826456@ull.edu.es
 * Programa para probar la clase "Ordenacion"
 * Practica 5 - Algoritmos y Estructuras de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "ordenacion.cpp"

int main(int argc, char **argv)
{
	ordenacion_t<int> test1;

	test1.run();
	
	cout << endl << endl << "<<<\tFIN DEL PROGRAMA\t>>>" << endl << endl;
}
