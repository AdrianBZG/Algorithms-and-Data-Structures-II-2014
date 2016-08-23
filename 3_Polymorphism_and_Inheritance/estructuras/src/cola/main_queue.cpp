/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa para probar la estructura de datos "cola"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "queue_t.cpp"

int main(int argc, char **argv)
{
	queue_t<int> cola; //Creo una cola
	
	for(int i = 0; i < 10; i++){ // Introduzco 10 numeros enteros (0-9) en la cola usando add
		cola.add(i);
	}
	system("clear"); //Limpiamos la pantalla

	//Imprimir
	cout << "IMPRIMIMOS LOS DATOS DE LA COLA (FIFO):" << endl;
	while(!cola.empty()) //Saco datos (extract) de la cola hasta que esté vacia
		cout << cola.extract() << endl;	
	cout << "< FIN DE LA IMPRESIÓN" << endl << endl;
	//
	

	cout << "<<<   FIN DEL PROGRAMA   >>>" << endl << endl;
}
