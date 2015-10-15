/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa donde para probar la estructura de datos "pila"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */



#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "stack.cpp"

int main(int argc, char **argv)
{
	stack_t<int> pila; //Creo una pila
	
	for(int i = 0; i < 10; i++){ // Introduzco 10 numeros enteros (0-9) en la pila usando push
		pila.push(i);
	}
	system("clear"); //Limpiamos la pantalla
	cout << "1. IMPRIMIMOS LOS DATOS DE LA PILA (LIFO):" << endl;
	while(!pila.empty()) //Saco datos (pop) de la pila hasta que este vacia
		cout << pila.pop() << endl;
	cout << "< FIN DE LA PILA" << endl << endl;

	cout << "<<<   FIN DEL PROGRAMA   >>>" << endl;
}
