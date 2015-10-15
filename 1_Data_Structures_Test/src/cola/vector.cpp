/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Estructura de datos "vector"
 * Practica 1 - Algoritmos y Estructura de Datos Avanzadas
 */

#include "vector.hpp"

	vector_t::vector_t(void):
	datos_(NULL),
	posinicial_(0),
	sz_(0)
	{}
	
	vector_t::vector_t(int sz):
	datos_(NULL),
	posinicial_(0),
	sz_(sz)
	{	
		datos_ = new TDATO [sz_];
	}
	
	vector_t::vector_t(int sz, int posini):
	datos_(NULL),
	posinicial_(posini),
	sz_(sz)
	{	
		datos_ = new TDATO [sz_];
	}
	
	vector_t::~vector_t(void)
	{
		if (datos_ != NULL){
			delete [] datos_;
			datos_ = NULL;
		}
	}
	
	TDATO vector_t::get_dato(const int pos) { return datos_[pos-posinicial_]; }
	
	TDATO vector_t::get_last() { return datos_[sz_]; }
	
	TDATO vector_t::get_first() { return datos_[0]; }
	
	void vector_t::set_dato(const int pos, const TDATO dato)
	{
		datos_[pos-posinicial_] = dato;
	}
	
	void vector_t::set_last(const TDATO dato)
	{
		datos_[sz_] = dato;
	}
	
	void vector_t::set_first(const TDATO dato)
	{
		datos_[0] = dato;
	}
	
	void vector_t::reset(void)
	{
		for(int i=0; i<this->get_sz(); i++)
		{
			this->set_dato(i, 0);
		}
	}
	
	void vector_t::write(ostream& os)
	{
		cout << "< INICIO DE LA IMPRESIÓN" << endl << endl;
		cout << "{ ";
		for(int i = 0; i < get_sz(); i++){
			if(i!=get_sz()-1)
			{
				cout << get_dato(i+posinicial_) << ", ";
			}
			else
			{
				cout << get_dato(i+posinicial_);
			}
		}
		cout << " }" << endl << endl;;
		cout << "< FIN DE LA IMPRESIÓN" << endl << endl;
	}
	
	void vector_t::read(istream& is)
	{
		system("clear");
		
		//Redimensionar
		char answer = 'Z';
		int size = 1;
		cout << "Redimensionar el vector? (s/n)" << endl;
		is >> answer;
		if(answer == 's' || answer == 'S')
		{
			cout << "Indica la capacidad del vector:" << endl;
			is >> size;
			this->resize(size);
		}		
		//
		
		
		this->reset(); //Borramos datos del vector
		
		
		cout << "< INDICAR DATOS DEL VECTOR:" << endl << endl;
		for(int i = 0; i < this->get_sz(); i++){
			cout << "Dato de la posición " << i+1 << ":" << endl;
			TDATO dato_leido;
			is >> dato_leido;
			this->set_dato(i, dato_leido);
		}
		
		system("clear");
	}
	
	void vector_t::resize(const int size)
	{
		// Reubicamos mem. dinamica y alteramos tamaño, luego reseteamos
		delete [] datos_;
		datos_ = new TDATO [size];		
		this->sz_ = size;
		this->reset();
		//		
		
	}
	
	void vector_t::replace(const int pos, TDATO dato)
	{
		this->set_dato(pos-posinicial_, dato);
	}
	
	void vector_t::add_front(const TDATO dato)
	{
		//Respaldo auxiliar con el elemento insertado delante
		vector_t aux(this->get_sz()+1);
		
		aux.set_dato(0, dato);
		
		for(int i=1;i<this->get_sz()+1;i++)
		{
			aux.set_dato(i,this->get_dato(i-1));
		}
		//
		
		// Reubicamos mem. dinamica y ponemos los elementos
		delete [] datos_;
		datos_ = new TDATO [aux.get_sz()];
		
		this->sz_ = aux.get_sz();
		for(int j=0; j<this->sz_; j++)
		{
			this->set_dato(j, aux.get_dato(j));
		}
		//		
	}
	
	void vector_t::add_back(const TDATO dato)
	{
		//Respaldo auxiliar con el elemento insertado detras
		vector_t aux(this->get_sz()+1);
		
		aux.set_dato(aux.get_sz()-1, dato);
		
		for(int i=0;i<this->get_sz();i++)
		{
			aux.set_dato(i,this->get_dato(i));
		}
		//
		
		// Reubicamos mem. dinamica y ponemos los elementos
		delete [] datos_;
		datos_ = new TDATO [aux.get_sz()];
		
		this->sz_ = aux.get_sz();
		for(int j=0; j<this->sz_; j++)
		{
			this->set_dato(j, aux.get_dato(j));
		}
		//
		
	}
	
	int vector_t::find_dato(const TDATO dato)
	{
		for(int i=0; i<sz_; i++)
		{
			if(datos_[i] == dato)
			{
				return i; //Elemento encontrado, devolvemos su posición
			}
		}
		
		return -1; //No encontrado, devolvemos -1
	}
	
	
	vector_t vector_t::operator=(vector_t& v)
	{
		vector_t aux(v.get_sz());
		
		for(int i=0; i<v.get_sz(); i++)
		{
			aux.set_dato(i, v.get_dato(i));
		}
		
		return aux;		
	}
	
	vector_t operator+(vector_t& v1, vector_t& v2)
	{
		vector_t aux(v1.get_sz()+v2.get_sz());
		
		for(int i=0; i<v1.get_sz(); i++)
		{
			aux.set_dato(i, v1.get_dato(i));
		}
		for(int j=0; j<v2.get_sz(); j++)
		{
			aux.set_dato(j+(v1.get_sz()), v2.get_dato(j));
		}
		return aux;		
	}
	
	TDATO vector_t::operator[](const int pos)
	{
		return this->get_dato(posinicial_-pos);
	}
	
	vector_t operator+(vector_t& v, TDATO dato)
	{
		vector_t aux(v.get_sz()+1);
		
		for(int i=0; i<v.get_sz(); i++)
		{
			aux.set_dato(i, v.get_dato(i));
		} 
		
		aux.set_dato(v.get_sz(),dato);
		return aux;
	}
	
	vector_t operator+(TDATO dato, vector_t& v)
	{
		vector_t aux(v.get_sz()+1);
		
		for(int i=1; i<v.get_sz()+1; i++)
		{
			aux.set_dato(i, v.get_dato(i));
		} 
		
		aux.set_dato(0,dato);
		return aux;
	}
	
	ostream& operator<<(ostream& os, vector_t& v)
	{
		v.write(os);
		return os;
	}
	
	istream& operator>>(istream& is, vector_t& v)
	{
		v.read(is);
		return is;
	}
