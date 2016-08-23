/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Clase "Número racional"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "racional.hpp"
	
	racional_t::racional_t(ENTERO num, ENTERO den)
	{
		try
		{
			if(den == 0)
			{
				throw("El denominador es 0, creación del número racional cancelada (y programa finalizado)");
			}
			ENTERO aux = racional_t::mcd(num,den);
			numerador_.modificar(num/aux);
			denominador_.modificar(den/aux);
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			exit(1);
		}
	}
	
	racional_t::~racional_t(void)
	{
	}
	
	ostream& racional_t::toStream(ostream& os) const
	{
		if(get_denominador() != 1)
		{
			os << get_numerador() << "/" << get_denominador();		//Sin endl, este lo incluye el toStream de la estructura de datos que utilicemos (ej. vector)
		}
		else
		{
			os << get_numerador();									//Sin endl, este lo incluye el toStream de la estructura de datos que utilicemos (ej. vector)
		}
		return os;
	}
	
	istream& racional_t::fromStream(istream& is)
	{
		system("clear");		
		ENTERO aux1, aux2;
		cout << "< INDICAR NUMERADOR:" << endl << endl;	
		is >> aux1;	
		cout << "< INDICAR DENOMINADOR:" << endl << endl;	
		is >> aux2;
		this->modificar(aux1, aux2);	
		system("clear");
		return is;
	}
	
	ENTERO racional_t::mcd(ENTERO e1, ENTERO e2)
	{
		if(e1==0) return e2;
		return mcd(e2%e1, e1);
	}
	
	ENTERO racional_t::mcm(ENTERO e1, ENTERO e2)
	{
		return (e1/racional_t::mcd(e1, e2))*e2;
	}
	
	ENTERO racional_t::get_numerador(void) const 
	{ 
		return numerador_.mostrar(); 
	}
	
	ENTERO racional_t::get_denominador(void) const
	{ 
		return denominador_.mostrar(); 
	}
	
	void racional_t::set_numerador(const ENTERO num) 
	{ 
		this->numerador_=num;
	}
	
	void racional_t::set_denominador(const ENTERO den) 
	{ 
		try
		{
			if(den == 0)
			{
				throw("El denominador indicado es 0, se cancela la modificación del denominador");
			}
			this->denominador_=den;
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			this->denominador_=this->get_denominador();
		}
	}
	
	void racional_t::modificar(const ENTERO num, const ENTERO den) 
	{ 
		try
		{
			if(den == 0)
			{
				throw("El denominador indicado es 0, se cancela la modificación del número");
			}
			this->set_numerador(num);
			this->set_denominador(den);
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			this->set_numerador(this->get_numerador());
			this->set_denominador(this->get_denominador());
		}
	}
	
	void racional_t::sumar(racional_t rac) 
	{ 
		ENTERO aux1 = mcm(this->get_denominador(), rac.get_denominador());		
		this->modificar((aux1/this->get_denominador())*this->get_numerador()+((aux1/rac.get_denominador())*rac.get_numerador()),aux1);				 
	}
	
	void racional_t::restar(racional_t rac) 
	{ 
		ENTERO aux1 = racional_t::mcm(this->get_denominador(), rac.get_denominador());		
		this->modificar(((aux1/rac.get_denominador())*rac.get_numerador())-(aux1/this->get_denominador())*this->get_numerador(),aux1);	
	}
	
	void racional_t::multiplicar(racional_t rac) 
	{ 
		this->set_numerador(this->get_numerador()*rac.get_numerador());
		this->set_denominador(this->get_denominador()*rac.get_denominador());
	}
	
	void racional_t::dividir(racional_t rac) 
	{ 
		this->set_numerador(this->get_numerador()*rac.get_denominador());
		this->set_denominador(this->get_denominador()*rac.get_numerador());
	}
	
	//Comparaciones
	
	bool racional_t::menor_que(racional_t rac) 
	{ 
		return (this->get_denominador()>rac.get_denominador() || (this->get_denominador()==rac.get_denominador() && this->get_numerador()<rac.get_numerador()));
	}
	
	bool racional_t::mayor_que(racional_t rac) 
	{ 
		return (not(menor_que(rac)));
	}
	
	bool racional_t::igual_que(racional_t rac) 
	{ 
		return (this->get_denominador()==rac.get_denominador() && this->get_numerador()==rac.get_numerador());
	}
	
	bool racional_t::distinto_que(racional_t rac) 
	{ 
		return (not(igual_que(rac)));
	}
	
	bool racional_t::mayorigual_que(racional_t rac) 
	{ 
		return (igual_que(rac) || mayor_que(rac)); 
	}
	
	bool racional_t::menorigual_que(racional_t rac) 
	{ 
		return (igual_que(rac) || menor_que(rac)); 
	}
	
	//
	
	//Sobrecarga de comparaciones
	
	void racional_t::operator=(racional_t v)
	{
		this->set_numerador(v.get_numerador());
		this->set_denominador(v.get_denominador());
	}
	
	bool racional_t::operator==(racional_t& v)
	{	
		return igual_que(v);		
	}
	
	bool racional_t::operator!=(racional_t& v)
	{
		return distinto_que(v);		
	}
	
	bool racional_t::operator<(racional_t& v)
	{	
		return menor_que(v);		
	}
	
	bool racional_t::operator>(racional_t& v)
	{	
		return mayor_que(v);		
	}
	
	bool racional_t::operator<=(racional_t& v)
	{		
		return menorigual_que(v);		
	}
	
	bool racional_t::operator>=(racional_t& v)
	{	
		return mayorigual_que(v);			
	}
	
	//
	
	//Sobrecarga de operadores
	
	racional_t operator+(racional_t& r1, racional_t& r2)
	{
		ENTERO aux1 = racional_t::mcm(r1.get_denominador(), r2.get_denominador());		
		racional_t aux((aux1/r1.get_denominador())*r1.get_numerador()+((aux1/r2.get_denominador())*r2.get_numerador()),aux1);	
		return aux;		
	}
	
	racional_t operator-(racional_t& r1, racional_t& r2)
	{
		ENTERO aux1 = racional_t::mcm(r1.get_denominador(), r2.get_denominador());		
		racional_t aux(((aux1/r2.get_denominador())*r2.get_numerador())-(aux1/r1.get_denominador())*r1.get_numerador(),aux1);
		return aux;
	}
	
	racional_t operator*(racional_t& r1, racional_t& r2)
	{
		racional_t aux(r1.get_numerador()*r2.get_numerador(),r1.get_denominador()*r2.get_denominador());
		return aux;
	}
	
	racional_t operator/(racional_t& r1, racional_t& r2)
	{
		racional_t aux(r1.get_numerador()*r2.get_denominador(),r1.get_denominador()*r2.get_numerador());
		return aux;	
	}
	//
	
	//Sobrecarga de E/S
	ostream& operator<<(ostream& os, racional_t& v)
	{
		v.toStream(os);
		return os;
	}
	
	istream& operator>>(istream& is, racional_t& v)
	{
		v.fromStream(is);
		return is;
	}
	//
