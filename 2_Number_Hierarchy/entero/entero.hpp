#pragma once

//
typedef int ENTERO;
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class entero_t{
private:
	ENTERO valor_;											//Atributo: Valor del número
	
public:
	entero_t(ENTERO val);									//Constructor
	entero_t(void);											//Constructor por defecto
	~entero_t(void);										//Destructor
	
	void imprimir(ostream& os);								
	void escribir(istream& is);
	
	ENTERO mostrar(void);
	void modificar(ENTERO val);

	void sumar(ENTERO val);
	void restar(ENTERO val);
	void multiplicar(ENTERO val);
	void dividir(ENTERO val);
	
	bool menor_que(ENTERO val);
	bool mayor_que(ENTERO val);
	bool igual_que(ENTERO val);
	bool mayorigual_que(ENTERO val);
	bool menorigual_que(ENTERO val);
	bool distinto_que(ENTERO val);
	
	//Sobrecargas
	void operator=(entero_t);								//Sobrecarga del operador '=' para asignar valor al nº natural
	void operator=(ENTERO);								//Sobrecarga del operador '=' para asignar valor al nº natural
	
	//Comparaciones
	bool operator==(entero_t&);							//Igual que	
	bool operator==(ENTERO);								//Igual que	
	bool operator!=(entero_t&);							//Distinto que
	bool operator!=(ENTERO);								//Distinto que
	bool operator<(entero_t&);								//Menor que
	bool operator<(ENTERO);								//Menor que
	bool operator>(entero_t&);								//Mayor que
	bool operator>(ENTERO);								//Mayor que
	bool operator<=(entero_t&);							//Menor o igual que
	bool operator<=(ENTERO);								//Menor o igual que
	bool operator>=(entero_t&);							//Mayor o igual que
	bool operator>=(ENTERO);								//Mayor o igual que
	//
	
	//Suma
	friend entero_t operator+(entero_t&, entero_t&); 	//Sobrecarga de la suma 
	friend entero_t operator+(entero_t&, ENTERO);		// 
	friend entero_t operator+(ENTERO, entero_t&);		//
	//
	//Resta
	friend entero_t operator-(entero_t&, entero_t&); 	//Sobrecarga de la resta 
	friend entero_t operator-(entero_t&, ENTERO);		//
	friend entero_t operator-(ENTERO, entero_t&);		//
	//
	//Mult.
	friend entero_t operator*(entero_t&, entero_t&); 	//Sobrecarga de la multiplicación 
	friend entero_t operator*(entero_t&, ENTERO);		//
	friend entero_t operator*(ENTERO, entero_t&);		//
	//
	//Div.
	friend entero_t operator/(entero_t&, entero_t&); 	//Sobrecarga de la división 
	friend entero_t operator/(entero_t&, ENTERO);		//
	friend entero_t operator/(ENTERO, entero_t&);		//
	//
	
	//E/S
	friend ostream& operator<<(ostream& os, entero_t&); 	//Sobrecarga del operador de salida
	friend istream& operator>>(istream& is, entero_t&); 	//Sobrecarga del operador de entrada
	//
	//
};
