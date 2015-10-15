/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Clase "Número entero"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "entero.hpp"
	
	entero_t::entero_t(ENTERO val)
	{
		valor_ = val;
	}
	
	entero_t::entero_t(void)
	{
		valor_ = 0;
	}
	
	entero_t::~entero_t(void)
	{
	}
	
	ostream& entero_t::toStream(ostream& sout) const
	{
		sout << valor_;			//Sin endl, este lo incluye el toStream de la estructura de datos que utilicemos (ej. vector)
		return sout;
	}
	
	istream& entero_t::fromStream(istream& sin)
	{
		system("clear");		
		cout << "< INDICAR NÚMERO ENTERO:" << endl << endl;	
		sin >> valor_;	
		system("clear");
		return sin;
	}
	
	ENTERO entero_t::mostrar(void) const
	{ 
		return valor_; 
	}
	
	void entero_t::modificar(const ENTERO val) 
	{ 
		valor_=val; 
	}
	
	void entero_t::sumar(const ENTERO val) 
	{ 
		valor_=valor_+val; 
	}
	
	void entero_t::restar(const ENTERO val) 
	{ 
		valor_=valor_-val; 
	}
	
	void entero_t::multiplicar(const ENTERO val) 
	{ 
		valor_=(valor_*val); 
	}
	
	void entero_t::dividir(const ENTERO val) 
	{ 
		try
		{
			if(val == 0)
			{
				throw("Error en la división, división entre 0: se cancela la división");
			}
			valor_=(valor_/val); 
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			valor_=valor_;
		}
	}
	
	//Comparaciones
	
	bool entero_t::menor_que(const ENTERO val) 
	{ 
		return (valor_<val);
	}
	
	bool entero_t::mayor_que(const ENTERO val) 
	{ 
		return (valor_>val);
	}
	
	bool entero_t::igual_que(const ENTERO val) 
	{ 
		return (valor_==val);
	}
	
	bool entero_t::distinto_que(const ENTERO val) 
	{ 
		return (valor_!=val);
	}
	
	bool entero_t::mayorigual_que(const ENTERO val) 
	{ 
		return (igual_que(val) || mayor_que(val)); 
	}
	
	bool entero_t::menorigual_que(const ENTERO val) 
	{ 
		return (igual_que(val) || menor_que(val)); 
	}
	
	//
	
	//Sobrecarga de comparaciones
	
	void entero_t::operator=(entero_t v)
	{
		this->valor_ = v.mostrar();	
	}
	
	void entero_t::operator=(ENTERO v)
	{
		this->valor_ = v;	
	}
	
	bool entero_t::operator==(entero_t& v)
	{	
		return igual_que(v.mostrar());		
	}
	
	bool entero_t::operator==(ENTERO v)
	{	
		return igual_que(v);		
	}
	
	bool entero_t::operator!=(entero_t& v)
	{
		return distinto_que(v.mostrar());		
	}
	
	bool entero_t::operator!=(ENTERO v)
	{	
		return distinto_que(v);		
	}
	
	bool entero_t::operator<(entero_t& v)
	{	
		return menor_que(v.mostrar());		
	}
	
	bool entero_t::operator<(ENTERO v)
	{	
		return menor_que(v);		
	}
	
	bool entero_t::operator>(entero_t& v)
	{	
		return mayor_que(v.mostrar());		
	}
	
	bool entero_t::operator>(ENTERO v)
	{	
		return mayor_que(v);		
	}
	
	bool entero_t::operator<=(entero_t& v)
	{		
		return menorigual_que(v.mostrar());		
	}
	
	bool entero_t::operator<=(ENTERO v)
	{	
		return menorigual_que(v);		
	}
	
	bool entero_t::operator>=(entero_t& v)
	{	
		return mayorigual_que(v.mostrar());			
	}
	
	bool entero_t::operator>=(ENTERO v)
	{	
		return mayorigual_que(v);		
	}
	
	//
	
	//Sobrecarga de operadores
	
	entero_t operator+(entero_t& v1, entero_t& v2)
	{
		entero_t aux(v1.mostrar()+v2.mostrar());
		return aux;		
	}
	
	entero_t operator+(entero_t& v, ENTERO dato)
	{
		entero_t aux(v.mostrar()+dato);
		return aux;			
	}
	
	entero_t operator+(ENTERO dato, entero_t& v)
	{
		entero_t aux(dato+v.mostrar());
		return aux;		
	}
	
	entero_t operator-(entero_t& v1, entero_t& v2)
	{
		entero_t aux(v1.mostrar()-v2.mostrar());
		return aux;	
	}
	
	entero_t operator-(entero_t& v, ENTERO dato)
	{
		entero_t aux(v.mostrar()-dato);
		return aux;		
	}
	
	entero_t operator-(ENTERO dato, entero_t& v)
	{
		entero_t aux(dato-v.mostrar());
		return aux;		
	}
	
	entero_t operator*(entero_t& v1, entero_t& v2)
	{
		entero_t aux(v1.mostrar()*v2.mostrar());
		return aux;		
	}
	
	entero_t operator*(entero_t& v, ENTERO dato)
	{
		entero_t aux(v.mostrar()*dato);
		return aux;			
	}
	
	entero_t operator*(ENTERO dato, entero_t& v)
	{
		entero_t aux(dato*v.mostrar());
		return aux;		
	}
	
	entero_t operator/(entero_t& v1, entero_t& v2)
	{
		try
		{
			if(v2.mostrar() == 0)
			{
				throw("Error en la división, división entre 0: se devuelve el valor del primer número");
			}
			entero_t aux(v1.mostrar()/v2.mostrar());
			return aux;		
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			entero_t aux(v1.mostrar());
			return aux;		
		}
	}
	
	entero_t operator/(entero_t& v, ENTERO dato)
	{
		try
		{
			if(dato == 0)
			{
				throw("Error en la división, división entre 0: se devuelve el valor del primer número");
			}
			entero_t aux(v.mostrar()/dato);
			return aux;
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			entero_t aux(v.mostrar());
			return aux;		
		}	
	}
	
	entero_t operator/(ENTERO dato, entero_t& v)
	{
		try
		{
			if(v.mostrar() == 0)
			{
				throw("Error en la división, división entre 0: se devuelve el valor del primer número");
			}
			entero_t aux(dato/v.mostrar());
			return aux;	
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			entero_t aux(dato);
			return aux;		
		}
	}
	//
	
	//Sobrecarga de E/S
	ostream& operator<<(ostream& os, entero_t& v)
	{
		v.toStream(os);
		return os;
	}
	
	istream& operator>>(istream& is, entero_t& v)
	{
		v.fromStream(is);
		return is;
	}
	//
