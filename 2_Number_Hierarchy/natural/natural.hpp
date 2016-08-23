#pragma once

//
typedef unsigned int NATURAL;
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class natural_t{
private:
	NATURAL valor_;											//Atributo: Valor del número
	
public:
	natural_t(NATURAL val);									//Constructor
	~natural_t(void);										//Destructor
	
	void imprimir(ostream& os);								
	void escribir(istream& is);
	
	NATURAL mostrar(void);
	void modificar(NATURAL val);

	void sumar(NATURAL val);
	void restar(NATURAL val);
	void multiplicar(NATURAL val);
	void dividir(NATURAL val);
	
	bool menor_que(NATURAL val);
	bool mayor_que(NATURAL val);
	bool igual_que(NATURAL val);
	bool mayorigual_que(NATURAL val);
	bool menorigual_que(NATURAL val);
	bool distinto_que(NATURAL val);
	
	//Sobrecargas
	void operator=(natural_t);								//Sobrecarga del operador '=' para asignar valor al nº natural
	void operator=(NATURAL);								//Sobrecarga del operador '=' para asignar valor al nº natural
	
	//Comparaciones
	bool operator==(natural_t&);							//Igual que	
	bool operator==(NATURAL);								//Igual que	
	bool operator!=(natural_t&);							//Distinto que
	bool operator!=(NATURAL);								//Distinto que
	bool operator<(natural_t&);								//Menor que
	bool operator<(NATURAL);								//Menor que
	bool operator>(natural_t&);								//Mayor que
	bool operator>(NATURAL);								//Mayor que
	bool operator<=(natural_t&);							//Menor o igual que
	bool operator<=(NATURAL);								//Menor o igual que
	bool operator>=(natural_t&);							//Mayor o igual que
	bool operator>=(NATURAL);								//Mayor o igual que
	//
	
	//Suma
	friend natural_t operator+(natural_t&, natural_t&); 	//Sobrecarga de la suma 
	friend natural_t operator+(natural_t&, NATURAL);		// 
	friend natural_t operator+(NATURAL, natural_t&);		//
	//
	//Resta
	friend natural_t operator-(natural_t&, natural_t&); 	//Sobrecarga de la resta 
	friend natural_t operator-(natural_t&, NATURAL);		//
	friend natural_t operator-(NATURAL, natural_t&);		//
	//
	//Mult.
	friend natural_t operator*(natural_t&, natural_t&); 	//Sobrecarga de la multiplicación 
	friend natural_t operator*(natural_t&, NATURAL);		//
	friend natural_t operator*(NATURAL, natural_t&);		//
	//
	//Div.
	friend natural_t operator/(natural_t&, natural_t&); 	//Sobrecarga de la división 
	friend natural_t operator/(natural_t&, NATURAL);		//
	friend natural_t operator/(NATURAL, natural_t&);		//
	//
	
	//E/S
	friend ostream& operator<<(ostream& os, natural_t&); 	//Sobrecarga del operador de salida
	friend istream& operator>>(istream& is, natural_t&); 	//Sobrecarga del operador de entrada
	//
	//
};
