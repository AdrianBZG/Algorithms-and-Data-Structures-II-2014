/* Adrian Rodriguez Bazaga
 * alu0100826456@ull.edu.es
 * Programa para probar la clase "Árbol Binario de Búsqueda"
 * Practica 6 - Algoritmos y Estructuras de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

//Árbol Binario de Búsqueda
#include "ABB.cpp"
//

int main(int argc, char **argv)
{
	ABB<int> test1;
	
	test1.run();
	
	cout << endl << "\t\t<<<\tFIN DEL PROGRAMA\t>>>" << endl;
}
