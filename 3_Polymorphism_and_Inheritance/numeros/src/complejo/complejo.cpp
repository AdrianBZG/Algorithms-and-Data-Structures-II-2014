/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Clase "Número complejo"
 * Practica 3 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "complejo.hpp"


complejo_t::complejo_t(REAL r,REAL i)
{
	r_=r;
	i_=i;
}

complejo_t::complejo_t(void)
{
	r_=0;
	i_=0;
}

complejo_t::~complejo_t(void)
{
	r_=0;
	i_=0;
}

ostream& complejo_t::toStream(ostream& os) const
{
	char aux[80];

	sprintf(aux,"%3.1lf + %3.1lfi",r_.mostrar(),i_.mostrar());
	os << aux; 
	return os;
}

istream& complejo_t::fromStream(istream& is)
{
	REAL aux1, aux2;
	system("clear");		
	cout << "< INDICAR PARTE REAL:" << endl << endl;	
	is >> aux1;	
	cout << "< INDICAR PARTE IMAGINARIA:" << endl << endl;	
	is >> aux2;	
	modificar(aux1, aux2);
	system("clear");
	return is;
}

void complejo_t::modificar(REAL r, REAL i)
{
	this->set_real(r);
	this->set_imag(i);
}

void complejo_t::set_real(REAL r)
{
	r_=r;
}

void complejo_t::set_imag(REAL i)
{
	i_=i;
}

REAL complejo_t::get_real(void) const
{
	return r_.mostrar();
}

REAL complejo_t::get_imag(void) const
{
	return i_.mostrar();
}

REAL complejo_t::get_modulo(void) const
{
	return sqrt(r_.mostrar()*r_.mostrar()+i_.mostrar()*i_.mostrar());	
}

REAL complejo_t::get_fase(void) const
{
	return atan2(i_.mostrar(),r_.mostrar());	
}

//Operaciones aritméticas

void complejo_t::sumar(complejo_t c1) 
{ 
	this->set_real(this->get_real()+c1.get_real());
	this->set_imag(this->get_imag()+c1.get_imag());
}
	
void complejo_t::restar(complejo_t c1) 
{ 
	this->set_real(this->get_real()-c1.get_real());
	this->set_imag(this->get_imag()-c1.get_imag());
}
	
void complejo_t::multiplicar(complejo_t c1) 
{ 
	this->set_real(this->get_real()*c1.get_real()- this->get_imag()*c1.get_imag());
	this->set_imag(this->get_real()*c1.get_imag()+ c1.get_real()*this->get_imag());
}
	
void complejo_t::dividir(complejo_t c1) 
{ 
	this->set_real((this->get_real()*(c1.get_real()) + this->get_imag()*(c1.get_imag()))/(this->get_imag()*this->get_imag()+c1.get_imag()*c1.get_imag()));
	this->set_imag((this->get_imag()*c1.get_real()-this->get_real()*c1.get_imag())/(c1.get_real()*c1.get_real()+c1.get_imag()*c1.get_imag()));	
}

//

//Comparaciones

bool complejo_t::menor_que(complejo_t c1) 
{ 
	return (get_modulo()<c1.get_modulo());
}
	
bool complejo_t::mayor_que(complejo_t c1) 
{ 
	return (not(get_modulo()<c1.get_modulo()));
}
	
bool complejo_t::igual_que(complejo_t c1) 
{ 
	return (r_.igual_que(c1.get_real()) && i_.igual_que(c1.get_imag()));
}
	
bool complejo_t::distinto_que(complejo_t c1) 
{ 
	return (not(r_.igual_que(c1.get_real()) && i_.igual_que(c1.get_imag())));
}
	
bool complejo_t::mayorigual_que(complejo_t c1) 
{ 
	return (igual_que(c1) || mayor_que(c1)); 
}
	
bool complejo_t::menorigual_que(complejo_t c1) 
{ 
	return (igual_que(c1) || menor_que(c1)); 
}	

//

//Sobrecarga de comparaciones
	
void complejo_t::operator=(complejo_t v)
{
	this->modificar(v.get_real(),v.get_imag());
}
	
bool complejo_t::operator==(complejo_t& v)
{	
	return igual_que(v);		
}
	
bool complejo_t::operator!=(complejo_t& v)
{
	return distinto_que(v);		
}
	
bool complejo_t::operator<(complejo_t& v)
{	
	return menor_que(v);		
}
	
bool complejo_t::operator>(complejo_t& v)
{	
	return mayor_que(v);		
}
	
bool complejo_t::operator<=(complejo_t& v)
{		
	return menorigual_que(v);		
}
	
bool complejo_t::operator>=(complejo_t& v)
{	
	return mayorigual_que(v);			
}
	
//
	
//Sobrecarga de operadores
	
complejo_t operator+(complejo_t& c1, complejo_t& c2)
{
	complejo_t aux(c1.get_real()+c2.get_real(), c1.get_imag()+c2.get_imag());
	return aux;		
}
	
complejo_t operator-(complejo_t& c1, complejo_t& c2)
{
	complejo_t aux(c1.get_real()-c2.get_real(), c1.get_imag()-c2.get_imag());
	return aux;	
}
	
complejo_t operator*(complejo_t& c1, complejo_t& c2)
{	
	complejo_t aux(c1.get_real()*c2.get_real()- c1.get_imag()*c2.get_imag(), c1.get_real()*c2.get_imag()+ c2.get_real()*c1.get_imag());
	return aux;		
}
	
	
complejo_t operator/(complejo_t& c1, complejo_t& c2)
{
	complejo_t aux((c1.get_real()*(c2.get_real()) + c1.get_imag()*(c2.get_imag()))/(c1.get_imag()*c1.get_imag()+c2.get_imag()*c2.get_imag()), (c1.get_imag()*c2.get_real()-c1.get_real()*c2.get_imag())/(c2.get_real()*c2.get_real()+c2.get_imag()*c2.get_imag()));
	return aux;		
}
//
	
//Sobrecarga de E/S
ostream& operator<<(ostream& os, complejo_t& c)
{
	c.toStream(os);
	return os;
}
	
istream& operator>>(istream& is, complejo_t& c)
{
	c.fromStream(is);
	return is;
}
//
