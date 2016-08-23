/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Clase "Número racional"
 * Practica 2 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "racional.hpp"
	
	racional_t::racional_t(ENTERO num, ENTERO den)
	{
		ENTERO aux = mcd(num,den);
		numerador_.modificar(num/aux);
		denominador_.modificar(den/aux);
	}
	
	racional_t::~racional_t(void)
	{
	}
	
	void racional_t::imprimir(ostream& os)
	{
		os << "< INICIO DE LA IMPRESIÓN" << endl << endl;
		if(get_denominador() != 1)
		{
			os << "El valor del número racional es: " << get_numerador() << "/" << get_denominador() << endl << endl;
		}
		else
		{
			os << "El valor del número racional es: " << get_numerador() << endl << endl;
		}
		os << "< FIN DE LA IMPRESIÓN" << endl << endl;
	}
	
	void racional_t::escribir(istream& is)
	{
		system("clear");		
		ENTERO aux1, aux2;
		cout << "< INDICAR NUMERADOR:" << endl << endl;	
		is >> aux1;	
		cout << "< INDICAR DENOMINADOR:" << endl << endl;	
		is >> aux2;
		this->modificar(aux1, aux2);	
		system("clear");
	}
	
	ENTERO racional_t::mcd(ENTERO e1, ENTERO e2)
	{
		if(e1==0) return e2;
		return mcd(e2%e1, e1);
	}
	
	ENTERO racional_t::mcm(ENTERO e1, ENTERO e2)
	{
		return (e1/mcd(e1, e2))*e2;
	}
	
	ENTERO mcd(ENTERO e1, ENTERO e2)
	{
		if(e1==0) return e2;
		return mcd(e2%e1, e1);
	}
	
	ENTERO mcm(ENTERO e1, ENTERO e2)
	{
		return (e1/mcd(e1, e2))*e2;
	}
	
	ENTERO racional_t::get_numerador(void) 
	{ 
		return numerador_.mostrar(); 
	}
	
	ENTERO racional_t::get_denominador(void) 
	{ 
		return denominador_.mostrar(); 
	}
	
	void racional_t::set_numerador(const ENTERO num) 
	{ 
		this->numerador_=num;
	}
	
	void racional_t::set_denominador(const ENTERO den) 
	{ 
		this->denominador_=den;
	}
	
	void racional_t::modificar(const ENTERO num, const ENTERO den) 
	{ 
		this->set_numerador(num);
		this->set_denominador(den);
	}
	
	void racional_t::sumar(racional_t rac) 
	{ 
		ENTERO aux1 = mcm(this->get_denominador(), rac.get_denominador());		
		this->modificar((aux1/this->get_denominador())*this->get_numerador()+((aux1/rac.get_denominador())*rac.get_numerador()),aux1);				 
	}
	
	void racional_t::restar(racional_t rac) 
	{ 
		ENTERO aux1 = mcm(this->get_denominador(), rac.get_denominador());		
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
		ENTERO aux1 = mcm(r1.get_denominador(), r2.get_denominador());		
		racional_t aux((aux1/r1.get_denominador())*r1.get_numerador()+((aux1/r2.get_denominador())*r2.get_numerador()),aux1);	
		return aux;		
	}
	
	racional_t operator-(racional_t& r1, racional_t& r2)
	{
		ENTERO aux1 = mcm(r1.get_denominador(), r2.get_denominador());		
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
		v.imprimir(os);
		return os;
	}
	
	istream& operator>>(istream& is, racional_t& v)
	{
		v.escribir(is);
		return is;
	}
	//
