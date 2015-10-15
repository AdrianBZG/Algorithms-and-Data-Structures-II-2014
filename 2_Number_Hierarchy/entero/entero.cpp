/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Clase "Número entero"
 * Practica 2 - Algoritmos y Estructura de Datos Avanzadas
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
	
	void entero_t::imprimir(ostream& os)
	{
		os << "< INICIO DE LA IMPRESIÓN" << endl << endl;
		os << "El valor del número entero es: " << valor_ << endl << endl;
		os << "< FIN DE LA IMPRESIÓN" << endl << endl;
	}
	
	void entero_t::escribir(istream& is)
	{
		system("clear");		
		cout << "< INDICAR NÚMERO ENTERO:" << endl << endl;	
		is >> valor_;	
		system("clear");
	}
	
	ENTERO entero_t::mostrar(void) 
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
		valor_=(valor_/val); 
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
		entero_t aux(v1.mostrar()/v2.mostrar());
		return aux;		
	}
	
	entero_t operator/(entero_t& v, ENTERO dato)
	{
		entero_t aux(v.mostrar()/dato);
		return aux;		
	}
	
	entero_t operator/(ENTERO dato, entero_t& v)
	{
		entero_t aux(dato/v.mostrar());
		return aux;	
	}
	//
	
	//Sobrecarga de E/S
	ostream& operator<<(ostream& os, entero_t& v)
	{
		v.imprimir(os);
		return os;
	}
	
	istream& operator>>(istream& is, entero_t& v)
	{
		v.escribir(is);
		return is;
	}
	//
