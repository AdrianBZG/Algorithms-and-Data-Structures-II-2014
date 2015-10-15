/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Clase "Número real"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "real.hpp"
	
	real_t::real_t(REAL val)
	{
		valor_ = val;
	}
	
	real_t::real_t(void)
	{
		valor_ = 0;
	}
	
	real_t::~real_t(void)
	{
	}
	
	ostream& real_t::toStream(ostream& sout) const
	{
		sout << valor_;					//Sin endl, este lo incluye el toStream de la estructura de datos que utilicemos (ej. vector)
		return sout;
	}
	
	istream& real_t::fromStream(istream& sin)
	{
		system("clear");		
		cout << "< INDICAR NÚMERO REAL:" << endl << endl;	
		sin >> valor_;	
		system("clear");
		return sin;
	}
	
	REAL real_t::mostrar(void) const
	{ 
		return valor_; 
	}
	
	void real_t::modificar(const REAL val) 
	{ 
		valor_=val; 
	}
	
	void real_t::sumar(const REAL val) 
	{ 
		valor_=valor_+val; 
	}
	
	void real_t::restar(const REAL val) 
	{ 
		valor_=valor_-val; 
	}
	
	void real_t::multiplicar(const REAL val) 
	{ 
		valor_=(valor_*val); 
	}
	
	void real_t::dividir(const REAL val) 
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
	
	//Comparaciones (se usa una precisión Épsilon de 1E-4)
	
	bool real_t::menor_que(const REAL val) 
	{ 
		return (valor_<(val-1E-4));
	}
	
	bool real_t::mayor_que(const REAL val) 
	{ 
		return (not(valor_<(val-1E-4)));
	}
	
	bool real_t::igual_que(const REAL val) 
	{ 
		return (fabs(valor_-val)<1E-4);
	}
	
	bool real_t::distinto_que(const REAL val) 
	{ 
		return (not(fabs(valor_-val)<1E-4));
	}
	
	bool real_t::mayorigual_que(const REAL val) 
	{ 
		return (igual_que(val) || mayor_que(val)); 
	}
	
	bool real_t::menorigual_que(const REAL val) 
	{ 
		return (igual_que(val) || menor_que(val)); 
	}
	
	//
	
	//Sobrecarga de comparaciones
	
	void real_t::operator=(real_t v)
	{
		this->valor_ = v.mostrar();	
	}
	
	void real_t::operator=(REAL v)
	{
		this->valor_ = v;	
	}
	
	bool real_t::operator==(real_t& v)
	{	
		return igual_que(v.mostrar());		
	}
	
	bool real_t::operator==(REAL v)
	{	
		return igual_que(v);		
	}
	
	bool real_t::operator!=(real_t& v)
	{
		return distinto_que(v.mostrar());		
	}
	
	bool real_t::operator!=(REAL v)
	{	
		return distinto_que(v);		
	}
	
	bool real_t::operator<(real_t& v)
	{	
		return menor_que(v.mostrar());		
	}
	
	bool real_t::operator<(REAL v)
	{	
		return menor_que(v);		
	}
	
	bool real_t::operator>(real_t& v)
	{	
		return mayor_que(v.mostrar());		
	}
	
	bool real_t::operator>(REAL v)
	{	
		return mayor_que(v);		
	}
	
	bool real_t::operator<=(real_t& v)
	{		
		return menorigual_que(v.mostrar());		
	}
	
	bool real_t::operator<=(REAL v)
	{	
		return menorigual_que(v);		
	}
	
	bool real_t::operator>=(real_t& v)
	{	
		return mayorigual_que(v.mostrar());			
	}
	
	bool real_t::operator>=(REAL v)
	{	
		return mayorigual_que(v);		
	}
	
	//
	
	//Sobrecarga de operadores
	
	real_t operator+(real_t& v1, real_t& v2)
	{
		real_t aux(v1.mostrar()+v2.mostrar());
		return aux;		
	}
	
	real_t operator+(real_t& v, REAL dato)
	{
		real_t aux(v.mostrar()+dato);
		return aux;			
	}
	
	real_t operator+(REAL dato, real_t& v)
	{
		real_t aux(dato+v.mostrar());
		return aux;		
	}
	
	real_t operator-(real_t& v1, real_t& v2)
	{
		real_t aux(v1.mostrar()-v2.mostrar());
		return aux;	
	}
	
	real_t operator-(real_t& v, REAL dato)
	{
		real_t aux(v.mostrar()-dato);
		return aux;		
	}
	
	real_t operator-(REAL dato, real_t& v)
	{
		real_t aux(dato-v.mostrar());
		return aux;		
	}
	
	real_t operator*(real_t& v1, real_t& v2)
	{
		real_t aux(v1.mostrar()*v2.mostrar());
		return aux;		
	}
	
	real_t operator*(real_t& v, REAL dato)
	{
		real_t aux(v.mostrar()*dato);
		return aux;			
	}
	
	real_t operator*(REAL dato, real_t& v)
	{
		real_t aux(dato*v.mostrar());
		return aux;		
	}
	
	real_t operator/(real_t& v1, real_t& v2)
	{
		try
		{
			if(v2.mostrar() == 0)
			{
				throw("Error en la división, división entre 0: se devuelve el valor del primer número");
			}
			real_t aux(v1.mostrar()/v2.mostrar());
			return aux;		
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			real_t aux(v1.mostrar());
			return aux;		
		}	
	}
	
	real_t operator/(real_t& v, REAL dato)
	{
		try
		{
			if(dato == 0)
			{
				throw("Error en la división, división entre 0: se devuelve el valor del primer número");
			}
			real_t aux(v.mostrar()/dato);
			return aux;
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			real_t aux(v.mostrar());
			return aux;		
		}	
	}
	
	real_t operator/(REAL dato, real_t& v)
	{
		try
		{
			if(v.mostrar() == 0)
			{
				throw("Error en la división, división entre 0: se devuelve el valor del primer número");
			}
			real_t aux(dato/v.mostrar());
			return aux;	
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			real_t aux(dato);
			return aux;		
		}
	}
	//
	
	//Sobrecarga de E/S
	ostream& operator<<(ostream& os, real_t& v)
	{
		v.toStream(os);
		return os;
	}
	
	istream& operator>>(istream& is, real_t& v)
	{
		v.fromStream(is);
		return is;
	}
	//
