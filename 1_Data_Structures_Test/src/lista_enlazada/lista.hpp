#pragma once
#include <cstdio>
#include <iostream>
#include "nodo.hpp"

using namespace std;


class lista_t{
	private:
		nodo_t* inicio_;										//Atributo: Puntero al nodo del principio de la lista
		nodo_t* fin_;										    //Atributo: Puntero al nodo del final de la lista
	public:
		lista_t(void);											//Constructor por defecto
		virtual ~lista_t(void);								    //Destructor
		void write(ostream& os);								//Mostrar lista
		void reset(void);										//Vaciar lista
		inline bool empty(void) { return (inicio_==NULL); }		//Comprobar si la lista está vacía
		void insert_empty(nodo_t* n);							//Insertar nodo en caso de que la lista esté vacía (se usa en insert_begin & insert_end)
		void insert_begin(nodo_t* n);							//Insertar nodo al principio de la lista
		void insert_end(nodo_t* n);								//Insertar nodo al final de la lista
		nodo_t* extract_begin(void);							//Extraer nodo del principio de la lista
		nodo_t* extract_end(void);								//Extraer nodo del final de la lista
};
