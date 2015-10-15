/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Estructura de datos "cola"
 * Práctica 3 - Algoritmos y Estructura de Datos Avanzadas
 */
 

#pragma once
#include "vector.cpp"

using namespace std;

template<class Tdato> class queue_t{

	private:
		Vector<Tdato> vector_;															//Atributo: Vector donde se guardarán los datos de la cola
		int front_;																		//Atributo: Posición del primer elemento
		int rear_;																		//Atributo: Posición del último elemento
	public:
		queue_t(void);																	//Constructor por defecto
		~queue_t(void);																	//Destructor
		void add(Tdato dato);															//Añadir elemento a la cola
		Tdato extract(void);															//Extraer elemento de la cola
		
		void reset(void);																//Dejar la cola vacía
		
		inline bool empty(void) { return(front_<rear_); }								//Devolver si la cola está vacía

};

template <class Tdato> queue_t<Tdato>::queue_t(void):
	vector_(),
	front_(-1),
	rear_(0){}
	
template <class Tdato> queue_t<Tdato>::~queue_t(void)
{
	front_=-1;
	rear_=0;
}

template <class Tdato> void queue_t<Tdato>::add(const Tdato dato)
{
	front_++;
	vector_.push_back(dato);
}

template <class Tdato> Tdato queue_t<Tdato>::extract(void)
{
	try
	{
		if(empty())
		{
			throw("Error al extraer elemento de la cola, la cola está vacía");
		}
		Tdato aux = vector_.at(rear_);
		rear_++;
		return aux;
	}
	catch(const char* msg)
	{
		cerr << msg << endl;
		exit(1);
	}
}

template <class Tdato> void queue_t<Tdato>::reset(void)
{
	while(!empty())
	{
		Tdato aux = vector_.pop_back();
		rear_++;
	}	
}
