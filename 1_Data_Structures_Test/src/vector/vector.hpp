#pragma once
#include "../common.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class vector_t{
private:
	TDATO* datos_;											//Atributo: Puntero a datos del vector
	int sz_;												//Atributo: Tamaño del vector
	int posinicial_;										//Atributo: Posición inicial deseada cuando se hace referencia al vector
	
public:
	vector_t(void);											//Constructor por defecto (vector vacío, requiere utilizar 'add_front ó add_back'
	vector_t(int sz);										//Constructor del vector con un tamaño especifico
	vector_t(int sz, int posini);							//Constructor del vector con tamaño y posición inicial (para algoritmos)
	~vector_t(void);										//Destructor
	
	TDATO get_dato(const int pos);							//Obtener el elemento del vector que está en la posición 'pos'
	TDATO get_last();										//Obtener último elemento del vector
	TDATO get_first();										//Obtener primer elemento del vector
	void set_dato(const int pos, const TDATO dato);			//Poner elemento en el vector en la posición 'pos'
	void set_last(const TDATO dato);						//Poner elemento en la última posición del vector
	void set_first(const TDATO dato);						//Poner elemento en la primera posición del vector
	
	void add_front(const TDATO dato);						//Añadir elemento por delante del vector
	void add_back(const TDATO dato);						//Añadir elemento por detrás del vector
	
	void reset(void);										//Reiniciar datos del vector
	
	void write(ostream& os);								//Mostrar vector
	void read(istream& is);									//Dar datos al vector por un flujo de entrada
	
	void resize(const int size);							//Redimensionar vector
	void replace(const int pos, TDATO dato);				//Reemplazar un elemento en la posición 'pos'
	
	int find_dato(TDATO dato);								//Buscar un dato en el vector
	
	inline int get_sz(void) { return sz_; }					//Devuelve el tamaño del vector
	inline int get_posinicial(void) { return posinicial_; }	//Devuelve la posición inicial del vector
	
	vector_t operator=(vector_t&);							//Sobrecarga del operador '=' para copiar vectores

	friend vector_t operator+(vector_t&, vector_t&); 		//Sobrecarga de la concatenación con dos vectores
	friend vector_t operator+(vector_t&, TDATO);			//Sobrecarga de la concatenación con vector y elemento
	friend vector_t operator+(TDATO, vector_t&);			//Sobrecarga de la concatenación con elemento y vector
	TDATO operator[](const int pos);						//Sobrecarga del operador [] para obtener dato de una posición del vector (vector[0])
	
	friend ostream& operator<<(ostream& os, vector_t&); 	//Sobrecarga del operador de salida para mostrar el vector
	friend istream& operator>>(istream& is, vector_t&); 	//Sobrecarga del operador de entrada para dar datos al vector
};
