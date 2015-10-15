#pragma once

//
typedef float REAL;
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class real_t{
private:
	REAL valor_;											//Atributo: Valor del número
	
public:
	real_t(REAL val);									//Constructor
	real_t(void);										//Constructor por defecto
	~real_t(void);										//Destructor
	
	void imprimir(ostream& os);								
	void escribir(istream& is);
	
	REAL mostrar(void);
	void modificar(REAL val);

	void sumar(REAL val);
	void restar(REAL val);
	void multiplicar(REAL val);
	void dividir(REAL val);
	
	bool menor_que(REAL val);
	bool mayor_que(REAL val);
	bool igual_que(REAL val);
	bool mayorigual_que(REAL val);
	bool menorigual_que(REAL val);
	bool distinto_que(REAL val);
	
	//Sobrecargas
	void operator=(real_t);								//Sobrecarga del operador '=' para asignar valor al nº natural
	void operator=(REAL);								//Sobrecarga del operador '=' para asignar valor al nº natural
	
	//Comparaciones
	bool operator==(real_t&);							//Igual que	
	bool operator==(REAL);								//Igual que	
	bool operator!=(real_t&);							//Distinto que
	bool operator!=(REAL);								//Distinto que
	bool operator<(real_t&);								//Menor que
	bool operator<(REAL);								//Menor que
	bool operator>(real_t&);								//Mayor que
	bool operator>(REAL);								//Mayor que
	bool operator<=(real_t&);							//Menor o igual que
	bool operator<=(REAL);								//Menor o igual que
	bool operator>=(real_t&);							//Mayor o igual que
	bool operator>=(REAL);								//Mayor o igual que
	//
	
	//Suma
	friend real_t operator+(real_t&, real_t&); 	//Sobrecarga de la suma 
	friend real_t operator+(real_t&, REAL);		// 
	friend real_t operator+(REAL, real_t&);		//
	//
	//Resta
	friend real_t operator-(real_t&, real_t&); 	//Sobrecarga de la resta 
	friend real_t operator-(real_t&, REAL);		//
	friend real_t operator-(REAL, real_t&);		//
	//
	//Mult.
	friend real_t operator*(real_t&, real_t&); 	//Sobrecarga de la multiplicación 
	friend real_t operator*(real_t&, REAL);		//
	friend real_t operator*(REAL, real_t&);		//
	//
	//Div.
	friend real_t operator/(real_t&, real_t&); 	//Sobrecarga de la división 
	friend real_t operator/(real_t&, REAL);		//
	friend real_t operator/(REAL, real_t&);		//
	//
	
	//E/S
	friend ostream& operator<<(ostream& os, real_t&); 	//Sobrecarga del operador de salida
	friend istream& operator>>(istream& is, real_t&); 	//Sobrecarga del operador de entrada
	//
	//
};
