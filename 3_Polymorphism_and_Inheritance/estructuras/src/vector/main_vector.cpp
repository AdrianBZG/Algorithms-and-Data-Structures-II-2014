/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa para probar la estructura de datos "vector"
 * Práctica 3 - Algoritmos y Estructura de Datos Avanzadas
 */


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <exception>
#include <new>

using namespace std;

#include "vector.cpp"

int main(int argc, char **argv)
{
	Vector<int> t;
	for(int i=0; i<10; i++)
	{
		t.push_back(i+10);
	}
	
	Vector<double> x;
	for(int j=0; j<10; j++)
	{
		x.push_back(j+10.1234);
	}
	
	cout << "t: ";
	t.toStream(cout);
	cout << endl;
	
	//Está el elemento 19?
	cout << "Existe el elemento 19 en el vector?" << endl;
	bool temp = t.find_dato(19);
	cout << "R: " << (temp?"Sí":"No") << endl << endl;
	//
	
	//Está el elemento 8?
	cout << "Existe el elemento 8 en el vector?" << endl;
	temp = t.find_dato(8);
	cout << "R: " << (temp?"Sí":"No") << endl << endl;
	//	
	cout << endl;
	
	
	cout << "x: ";
	x.toStream(cout);
	cout << endl;
}
