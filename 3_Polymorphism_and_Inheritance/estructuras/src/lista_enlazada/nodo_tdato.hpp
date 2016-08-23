#pragma once

#include <cstdio>
#include <iostream>
#include "nodo.hpp"
#include "../common.hpp"

using namespace std;


class nodo_tdato_t:public nodo_t
{
	private:
		TDATO dato_;										//Atributo: Dato tipo TDATO que guarda el nodo
	public:
		nodo_tdato_t(TDATO dato);							//Constructor del nodo con un dato tipo TDATO
		nodo_tdato_t(void); 								//Constructor por defecto, para meter nodos inicializados a 0
		virtual ~nodo_tdato_t(void);						//Destructor
		void set_dato(TDATO dato);							//Poner dato en el nodo
		inline TDATO get_dato(void) { return dato_; }		//Obtener dato del nodo
		virtual void write(ostream& os);					//Mostrar dato del nodo
};
