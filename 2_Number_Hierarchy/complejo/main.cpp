/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Programa para probar la clase "Número complejo"
 * Practica 2 - Algoritmos y Estructura de Datos Avanzadas
 */


#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "complejo.hpp"

int main(int argc, char **argv)
{
	
	// Declaración de cuatro variables de tipo complejo
	complejo_t a(1,2),b(2,3),c(3,4),d(5,6); //LLAMAMIENTO DE LA FUNCION CONSTRUCTORA

	// Muestra los número complejos

	cout << endl;
	a.imprime_complejo(cout);
	cout << endl;
	b.imprime_complejo(cout);
	cout << endl;
	c.imprime_complejo(cout);
	cout << endl;
	d.imprime_complejo(cout);
	cout << endl;
	cout << endl;

	// Muestra la variable a			
	cout << "Parte real      : "<< a.get_real()<< std::endl;
	cout << "Parte imaginaria: "<< a.get_imag()<< std::endl;
	cout << "Módulo          : "<< a.get_modulo()<< std::endl;
	cout << "Fase            : "<< a.get_fase()<<std::endl;
	cout << endl;

	// Altera una de las variables
	cout << "Cambiando número: ";a.imprime_complejo(cout); 
	a.set_real(5);
	cout << " a ";a.imprime_complejo(cout); cout << endl;
	cout << endl;

	//Suma compleja
	cout << "Suma            : "; c.imprime_complejo(cout); cout << " + ";a.imprime_complejo(cout); cout << " = ";
	c.sumar(a);
	c.imprime_complejo(cout);
	cout << endl;
	cout << endl;

	//Producto complejo
	cout << "Multiplicación  : "; d.imprime_complejo(cout); cout << " * ";a.imprime_complejo(cout); cout << " = ";
	d.multiplicar(a);
	d.imprime_complejo(cout);
	cout << endl;
	cout << endl;
	
	//División complejo
	cout << "División	: "; b.imprime_complejo(cout); cout << " / ";a.imprime_complejo(cout); cout << " = ";
	b.dividir(a);
	b.imprime_complejo(cout);
	cout << endl;
	cout << endl;
	
	//Prueba de la sobrecarga de la suma
	complejo_t x;
	complejo_t y(1,2);
	complejo_t z(3,4);
	
	x = y + z;
	
	//Prueba de la sobrecarga de la salida
	cout << "Número complejo 'x': " << x << endl << endl;



	cout << "<<<   FIN DEL PROGRAMA   >>>" << endl << endl;
}
