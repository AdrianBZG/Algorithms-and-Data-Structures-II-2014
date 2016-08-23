#pragma once

//Clase Numero
#include "../numero/numero.hpp"
//

//
#include "entero.hpp"
//

using namespace std;

class racional_t: public Numero{
private:
	entero_t numerador_;									//Atributo: Valor del numerador
	entero_t denominador_;									//Atributo: Valor del denominador
	
	
public:
	racional_t(ENTERO num, ENTERO den);						//Constructor
	~racional_t(void);										//Destructor
	
	//Funciones virtuales heredadas de Numero
	virtual ostream& toStream(ostream& sout) const;
	virtual istream& fromStream(istream& sin);
	//
	
	void modificar(ENTERO num, ENTERO den);
	
	ENTERO get_numerador(void) const;
	ENTERO get_denominador(void) const;
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
	static ENTERO mcd(ENTERO e1, ENTERO e2);				//MCD static para llamarlo tanto desde funciones miembro como funciones amigas (operadores de abajo)
	static ENTERO mcm(ENTERO e1, ENTERO e2);				//MCM static para llamarlo tanto desde funciones miembro como funciones amigas (operadores de abajo)
	
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
