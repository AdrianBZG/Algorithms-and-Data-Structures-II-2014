/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Clase "Número natural"
 * Practica 2 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "natural.hpp"
	
	natural_t::natural_t(NATURAL val)
	{
		valor_ = val;
	}
	
	natural_t::~natural_t(void)
	{
	}
	
	void natural_t::imprimir(ostream& os)
	{
		os << "< INICIO DE LA IMPRESIÓN" << endl << endl;
		os << "El valor del número natural es: " << valor_ << endl << endl;
		os << "< FIN DE LA IMPRESIÓN" << endl << endl;
	}
	
	void natural_t::escribir(istream& is)
	{
		system("clear");		
		cout << "< INDICAR NÚMERO NATURAL:" << endl << endl;	
		is >> valor_;	
		system("clear");
	}
	
	NATURAL natural_t::mostrar(void) 
	{ 
		return valor_; 
	}
	
	void natural_t::modificar(const NATURAL val) 
	{ 
		valor_=val; 
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
		valor_=(valor_/val); 
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
		natural_t aux(v1.mostrar()/v2.mostrar());
		return aux;		
	}
	
	natural_t operator/(natural_t& v, NATURAL dato)
	{
		natural_t aux(v.mostrar()/dato);
		return aux;		
	}
	
	natural_t operator/(NATURAL dato, natural_t& v)
	{
		natural_t aux(dato/v.mostrar());
		return aux;	
	}
	//
	
	//Sobrecarga de E/S
	ostream& operator<<(ostream& os, natural_t& v)
	{
		v.imprimir(os);
		return os;
	}
	
	istream& operator>>(istream& is, natural_t& v)
	{
		v.escribir(is);
		return is;
	}
	//
