#pragma once

#include <cstdio>
#include <iostream>

using namespace std;

class nodo_t
{
	private:
		nodo_t* next_;										//Atributo: Puntero al siguiente nodo
		
	public:
		nodo_t(void);										//Constructor por defecto
		virtual ~nodo_t(void);								//Destructor
		void set_next(nodo_t* next);						//Indicar puntero al siguiente nodo
		inline nodo_t* get_next(void) { return next_; }		//Obtener puntero al siguiente nodo
		virtual void write(ostream& os)=0;					//Función virtual para imprimir el nodo (se imprime en la función de nodo_tdato)
};
