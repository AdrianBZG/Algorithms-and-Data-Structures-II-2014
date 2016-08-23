/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Clase "Número natural"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "natural.hpp"
	
	natural_t::natural_t(NATURAL val)
	{
		int natural_a_entero = static_cast<int>(val);   	 //Para comprobar si el signo es negativo
		
		try
		{
			if(natural_a_entero < 0)
			{
				throw("Error en la creación del número natural, valor fuera de rango: se creará el número con el valor pasado a positivo");
			}
			valor_ = val;
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			valor_ = (NATURAL)(natural_a_entero*(-1));		//Colocamos el valor en positivo
		}
	}
	
	natural_t::~natural_t(void)
	{
	}
	
	ostream& natural_t::toStream(ostream& sout) const
	{
		sout << valor_;										//Sin endl, este lo incluye el toStream de la estructura de datos que utilicemos (ej. vector)
		return sout;
	}
	
	istream& natural_t::fromStream(istream& sin)
	{
		NATURAL aux;										//Variable NATURAL auxiliar
		
		system("clear");				
		cout << "< INDICAR NÚMERO NATURAL:" << endl << endl;
		
		try
		{	
			sin >> aux;
			int natural_a_entero = static_cast<int>(aux);    //Para comprobar si el signo es negativo
			if(natural_a_entero < 0)
			{
				throw("Error en la creación del número natural, valor fuera de rango: se pide de nuevo el número");
			}
			valor_ = aux;
			system("clear");
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			fromStream(sin);
		}
		return sin;
	}
	
	NATURAL natural_t::mostrar(void) const
	{ 
		return valor_; 
	}
	
	void natural_t::modificar(const NATURAL val) 
	{ 
		int natural_a_entero = static_cast<int>(val);    //Para comprobar si el signo es negativo
		
		try
		{
			if(natural_a_entero < 0)
			{
				throw("Error en la modificación del número natural, valor fuera de rango: se coloca el valor en positivo");
			}
			valor_=val; 
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			valor_ = (NATURAL)(natural_a_entero*(-1));		//Colocamos el valor en positivo
		}
		
	}
	
	void natural_t::sumar(const NATURAL val) 
	{ 
		valor_=valor_+val; 
	}
	
	void natural_t::restar(const NATURAL val) 
	{ 
		if(valor_<val)
		{
			cerr << "Operación no realizada (RESTA) ya que da negativo y por lo tanto está fuera del rango de N (" << val << " es mayor que " << this->mostrar() << ")" << endl;
		}
		else
		{
			valor_=valor_-val; 
		}
	}
	
	void natural_t::multiplicar(const NATURAL val) 
	{ 
		valor_=(valor_*val); 
	}
	
	void natural_t::dividir(const NATURAL val) 
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
	
	bool natural_t::menor_que(const NATURAL val) 
	{ 
		return (valor_<val);
	}
	
	bool natural_t::mayor_que(const NATURAL val) 
	{ 
		return (valor_>val);
	}
	
	bool natural_t::igual_que(const NATURAL val) 
	{ 
		return (valor_==val);
	}
	
	bool natural_t::distinto_que(const NATURAL val) 
	{ 
		return (valor_!=val);
	}
	
	bool natural_t::mayorigual_que(const NATURAL val) 
	{ 
		return (igual_que(val) || mayor_que(val)); 
	}
	
	bool natural_t::menorigual_que(const NATURAL val) 
	{ 
		return (igual_que(val) || menor_que(val)); 
	}
	
	//
	
	//Sobrecarga de comparaciones
	
	void natural_t::operator=(natural_t v)
	{
		this->valor_ = v.mostrar();	
	}
	
	void natural_t::operator=(NATURAL v)
	{
		this->valor_ = v;	
	}
	
	bool natural_t::operator==(natural_t& v)
	{	
		return igual_que(v.mostrar());		
	}
	
	bool natural_t::operator==(NATURAL v)
	{	
		return igual_que(v);		
	}
	
	bool natural_t::operator!=(natural_t& v)
	{
		return distinto_que(v.mostrar());		
	}
	
	bool natural_t::operator!=(NATURAL v)
	{	
		return distinto_que(v);		
	}
	
	bool natural_t::operator<(natural_t& v)
	{	
		return menor_que(v.mostrar());		
	}
	
	bool natural_t::operator<(NATURAL v)
	{	
		return menor_que(v);		
	}
	
	bool natural_t::operator>(natural_t& v)
	{	
		return mayor_que(v.mostrar());		
	}
	
	bool natural_t::operator>(NATURAL v)
	{	
		return mayor_que(v);		
	}
	
	bool natural_t::operator<=(natural_t& v)
	{		
		return menorigual_que(v.mostrar());		
	}
	
	bool natural_t::operator<=(NATURAL v)
	{	
		return menorigual_que(v);		
	}
	
	bool natural_t::operator>=(natural_t& v)
	{	
		return mayorigual_que(v.mostrar());			
	}
	
	bool natural_t::operator>=(NATURAL v)
	{	
		return mayorigual_que(v);		
	}
	
	//
	
	//Sobrecarga de operadores
	
	natural_t operator+(natural_t& v1, natural_t& v2)
	{
		natural_t aux(v1.mostrar()+v2.mostrar());
		return aux;		
	}
	
	natural_t operator+(natural_t& v, NATURAL dato)
	{
		natural_t aux(v.mostrar()+dato);
		return aux;			
	}
	
	natural_t operator+(NATURAL dato, natural_t& v)
	{
		natural_t aux(dato+v.mostrar());
		return aux;		
	}
	
	natural_t operator-(natural_t& v1, natural_t& v2)
	{
		if(v1.mostrar()<v2.mostrar())
		{
			cerr << "Operación no realizada (RESTA) ya que da negativo y por lo tanto está fuera del rango de N (" << v2.mostrar() << " es mayor que " << v1.mostrar() << ")" << endl;
			natural_t aux(0);
			return aux;
		}
		else
		{
			natural_t aux(v1.mostrar()-v2.mostrar());
			return aux;	
		}
	}
	
	natural_t operator-(natural_t& v, NATURAL dato)
	{
		if(v.mostrar()<dato)
		{
			cerr << "Operación no realizada (RESTA) ya que da negativo y por lo tanto está fuera del rango de N (" << v.mostrar() << " es mayor que " << dato << ")" << endl;
			natural_t aux(0);
			return aux;
		}
		else
		{
			natural_t aux(v.mostrar()-dato);
			return aux;	
		}		
	}
	
	natural_t operator-(NATURAL dato, natural_t& v)
	{
		if(dato<v.mostrar())
		{
			cerr << "Operación no realizada (RESTA) ya que da negativo y por lo tanto está fuera del rango de N (" << dato << " es mayor que " << v.mostrar() << ")" << endl;
			natural_t aux(0);
			return aux;
		}
		else
		{
			natural_t aux(dato-v.mostrar());
			return aux;	
		}		
	}
	
	natural_t operator*(natural_t& v1, natural_t& v2)
	{
		natural_t aux(v1.mostrar()*v2.mostrar());
		return aux;		
	}
	
	natural_t operator*(natural_t& v, NATURAL dato)
	{
		natural_t aux(v.mostrar()*dato);
		return aux;			
	}
	
	natural_t operator*(NATURAL dato, natural_t& v)
	{
		natural_t aux(dato*v.mostrar());
		return aux;		
	}
	
	natural_t operator/(natural_t& v1, natural_t& v2)
	{
		try
		{
			if(v2.mostrar() == 0)
			{
				throw("Error en la división, división entre 0: se devuelve el valor del primer número");
			}
			natural_t aux(v1.mostrar()/v2.mostrar());
			return aux;		
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			natural_t aux(v1.mostrar());
			return aux;		
		}
	}
	
	natural_t operator/(natural_t& v, NATURAL dato)
	{
		try
		{
			if(dato == 0)
			{
				throw("Error en la división, división entre 0: se devuelve el valor del primer número");
			}
			natural_t aux(v.mostrar()/dato);
			return aux;
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			natural_t aux(v.mostrar());
			return aux;		
		}
	}
	
	natural_t operator/(NATURAL dato, natural_t& v)
	{
		try
		{
			if(v.mostrar() == 0)
			{
				throw("Error en la división, división entre 0: se devuelve el valor del primer número");
			}
			natural_t aux(dato/v.mostrar());
			return aux;	
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			natural_t aux(dato);
			return aux;		
		}
	}
	//
	
	//Sobrecarga de E/S
	ostream& operator<<(ostream& os, natural_t& v)
	{
		v.toStream(os);
		return os;
	}
	
	istream& operator>>(istream& is, natural_t& v)
	{
		v.fromStream(is);
		return is;
	}
	//
