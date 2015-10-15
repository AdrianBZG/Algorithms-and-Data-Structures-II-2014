#pragma once
#include "vector.hpp"

using namespace std;

class queue_t{

	private:
		vector_t vector_;															//Atributo: Vector donde se guardarán los datos de la cola
		int front_;																	//Atributo: Posición del primer elemento
		int rear_;																	//Atributo: Posición del último elemento
	public:
		queue_t(void);																//Constructor por defecto
		~queue_t(void);																//Destructor
		void add(TDATO dato);														//Añadir elemento a la cola
		TDATO extract(void);														//Extraer elemento de la cola
		
		void reset(void);															//Dejar la cola vacía
		
		inline int find_dato(const TDATO dato) { return(vector_.find_dato(dato)); }	//Buscar dato en la cola
		inline bool empty(void) { return(front_<rear_); }							//Devolver si la cola está vacía

};
