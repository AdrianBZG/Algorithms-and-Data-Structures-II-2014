#pragma once

//
#include "entero.hpp"
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class racional_t{
private:
	entero_t numerador_;									//Atributo: Valor del numerador
	entero_t denominador_;									//Atributo: Valor del denominador
	
	
public:
	racional_t(ENTERO num, ENTERO den);						//Constructor
	~racional_t(void);										//Destructor
	
	void imprimir(ostream& os);								
	void escribir(istream& is);
	
	ENTERO mostrar(void);
	void modificar(ENTERO num, ENTERO den);
	
	ENTERO get_numerador(void);
	ENTERO get_denominador(void);
	void set_numerador(ENTERO num);
	void set_denominador(ENTERO num);

	void sumar(racional_t rac);
	void restar(racional_t rac);
	void multiplicar(racional_t rac);
	void dividir(racional_t rac);
	
	bool menor_que(racional_t rac);
	bool mayor_que(racional_t rac);
	bool igual_que(racional_t rac);
	bool mayorigual_que(racional_t rac);
	bool menorigual_que(racional_t rac);
	bool distinto_que(racional_t rac);
	
	//Sobrecargas
	void operator=(racional_t);								//Sobrecarga del operador '=' para asignar valor al nº natural
	
	//Comparaciones
	bool operator==(racional_t&);							//Igual que	
	bool operator!=(racional_t&);							//Distinto que
	bool operator<(racional_t&);							//Menor que
	bool operator>(racional_t&);							//Mayor que
	bool operator<=(racional_t&);							//Menor o igual que
	bool operator>=(racional_t&);							//Mayor o igual que
	//
	ENTERO mcd(ENTERO e1, ENTERO e2);
	ENTERO mcm(ENTERO e1, ENTERO e2);
	friend ENTERO mcd(ENTERO e1, ENTERO e2);				//MCD amigo para poder llamarlo desde los operadores friend de abajo
	friend ENTERO mcm(ENTERO e1, ENTERO e2);				//MCM amigo para poder llamarlo desde los operadores friend de abajo
	
	//Suma
	friend racional_t operator+(racional_t&, racional_t&); 	//Sobrecarga de la suma 
	//
	//Resta
	friend racional_t operator-(racional_t&, racional_t&); 	//Sobrecarga de la resta 
	//
	//Mult.
	friend racional_t operator*(racional_t&, racional_t&); 	//Sobrecarga de la multiplicación 
	//
	//Div.
	friend racional_t operator/(racional_t&, racional_t&); 	//Sobrecarga de la división 
	//
	
	//E/S
	friend ostream& operator<<(ostream& os, racional_t&); 	//Sobrecarga del operador de salida
	friend istream& operator>>(istream& is, racional_t&); 	//Sobrecarga del operador de entrada
	//
	//
};
