#pragma once

//Clase Numero
#include "../numero/numero.hpp"
//

//
#include "real.hpp"
//

using namespace std;

class complejo_t: public Numero {

private:

	real_t r_;
	real_t i_;

public:

	complejo_t(REAL r,REAL i);
	complejo_t(void);

	~complejo_t(void);
	
	//Funciones virtuales heredadas de Numero
	virtual ostream& toStream(ostream& sout) const;
	virtual istream& fromStream(istream& sin);
	//

	void set_real(REAL r);
	void set_imag(REAL i);
	void modificar(REAL r, REAL i);
	
	REAL get_real(void) const;
	REAL get_imag(void) const;
	REAL get_modulo(void) const;
	REAL get_fase(void) const;
	
	// Operaciones y comparaciones
	void sumar(complejo_t c1);
	void restar(complejo_t c1);
	void multiplicar(complejo_t c1);
	void dividir(complejo_t c1);
	
	bool menor_que(complejo_t c1);
	bool mayor_que(complejo_t c1);
	bool igual_que(complejo_t c1);
	bool mayorigual_que(complejo_t c1);
	bool menorigual_que(complejo_t c1);
	bool distinto_que(complejo_t c1);	
	//
	
	//Sobrecargas
	void operator=(complejo_t);								//Sobrecarga del operador '=' para asignar valor al nº natural
	
	//Comparaciones
	bool operator==(complejo_t&);							//Igual que	
	bool operator!=(complejo_t&);							//Distinto que
	bool operator<(complejo_t&);							//Menor que
	bool operator>(complejo_t&);							//Mayor que
	bool operator<=(complejo_t&);							//Menor o igual que
	bool operator>=(complejo_t&);							//Mayor o igual que
	//
	
	//Suma
	friend complejo_t operator+(complejo_t&, complejo_t&); 	//Sobrecarga de la suma 
	//
	//Resta
	friend complejo_t operator-(complejo_t&, complejo_t&); 	//Sobrecarga de la resta 
	//
	//Mult.
	friend complejo_t operator*(complejo_t&, complejo_t&); 	//Sobrecarga de la multiplicación 
	//
	//Div.
	friend complejo_t operator/(complejo_t&, complejo_t&); 	//Sobrecarga de la división 
	//
	
	//E/S
	friend ostream& operator<<(ostream& os, complejo_t&); 	//Sobrecarga del operador de salida
	friend istream& operator>>(istream& is, complejo_t&); 	//Sobrecarga del operador de entrada
	//
	//

};
