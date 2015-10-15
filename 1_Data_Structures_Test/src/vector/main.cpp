/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa para probar la estructura de datos "vector"
 * Practica 1 - Algoritmos y Estructura de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "vector.hpp"

int main(int argc, char **argv)
{
	vector_t vector; //Creo un vector con un size de 10 elementos
	vector_t vector2(10, 1); //Puedo crear un vector así (capacidad, posicion inicial), útil para algoritmos
	
	
	//Dar valores al vector
	for(int i = 0; i < 10; i++){ // Introduzco 10 numeros enteros (0-9) en la cola usando add
		vector.add_back(i+15);
	}
	//	

	//Imprimir el vector que acabamos de crear
	system("clear"); //Limpiamos la pantalla
	vector.write(cout);
	//	
	
	//Está el elemento 4?
	cout << "Existe el elemento 19 en el vector?" << endl;
	int temp = vector.find_dato(19);
	cout << "R: " << (temp==-1?"No":"Sí") << endl << endl;
	//
	
	//Está el elemento 12?
	cout << "Existe el elemento 12 en el vector?" << endl;
	temp = vector.find_dato(12);
	cout << "R: " << (temp==-1?"No":"Sí") << endl << endl;
	//	
	
	//Poner primer elemento del vector a 20
	cout << "- Cambiamos el primer elemento del vector" << endl;
	vector.set_first(20);
	//
	
	//Poner ultimo elemento del vector a 31
	cout << "- Cambiamos el último elemento del vector" << endl;
	vector.set_last(31);
	//
	
	//Primer elemento del vector?
	cout << endl << "Primer elemento del vector?" << endl << "R: " << vector.get_first() << endl << endl;
	//
	
	//Ultimo elemento del vector?
	cout << "Último elemento del vector?" << endl << "R: " << vector.get_last() << endl << endl;
	//
	
	//Nuevo vector concatenando un nuevo vector de 3 elementos y un elemento TDATO
	vector_t v3(3);
	for(int i=0; i<v3.get_sz(); i++)
	{
		v3.set_dato(i,i+99);
	}
	TDATO midato = 881; //Dato del tipo TDATO (de ejemplo)
	vector_t v4 = v3 + midato;
	//
	
	//Insertar elemento delante del vector
	v4.add_front(midato+20);
	//
	//Insertar elemento detras del vector
	v4.add_back(midato-149);
	//
	
	//Mostrar este nuevo vector 'v4'
	cout << "- Hemos creado un nuevo vector:" << endl << endl;
	cout << v4;
	//
	

	cout << "<<<   FIN DEL PROGRAMA   >>>" << endl << endl;
}
