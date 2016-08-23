/* Adrian Rodriguez Bazaga
 * alu0100826456@ull.edu.es
 * Programa para probar la clase "Árbol AVL"
 * Practica 7 - Algoritmos y Estructuras de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

//Árbol AVL
#include "arbolAVL.cpp"
//

int main(int argc, char **argv)
{
	arbolAVL<int> test1;
	
	test1.run();
	
	cout << endl << "\t\t<<<\tFIN DEL PROGRAMA\t>>>" << endl;
}
