/* Adrian Rodriguez Bazaga
 * alu0100826456
 * Estructura de datos "vector"
 * Práctica 3 - Algoritmos y Estructura de Datos Avanzadas
 */
 
#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class  Vector {
private:

    T* data;													//Datos del vector de tipo T
    unsigned int size_;											//Tamaño del vector
    unsigned int capacity_;										//Capacidad del vector
    typedef T* Iterator;										//Tipo Iterator, que es un puntero de T
    
public:

    Vector();													//Constructor por defecto
    Vector(const Vector<T>& v);									//Constructor de copia
    ~Vector();													//Destructor

    unsigned int capacity() const;								//Comprobar capacidad del vector
    unsigned int size() const;									//Comprobar tamaño del vector
    bool empty() const;											//Comprobar si el vector está vacio
    Iterator begin();											//Devuelve un iterador al principio del vector
    Iterator end();												//Devuelve un iterador al final del vector
    bool find_dato(T value);									//Buscar un dato en el vector
    T& front();													//Acceder al elemento del frente del vector
    T& back();													//Acceder al elemento de detrás del vector
    T& at(unsigned int index);									//Acceder a elemento del vector
    void push_back(const T& value);								//Insertar elemento detrás del vector
    void pop_back();											//Eliminar elemento de detrás del vector

    void resize(unsigned int size);								//Cambiar tamaño del vector
    void reserve(unsigned int capacity);						//Reservar espacio en el vector
    
    ostream& toStream(ostream& os);								//Salida de datos

    T & operator[](unsigned int index);							//Sobrecarga de la indexación []
    Vector<T> & operator = (const Vector<T> &);					//Sobrecarga de la igualación
    
    void clear();												//Limpiar vector
};

template<class T>
Vector<T>::Vector() {
    capacity_ = 0;
    size_ = 0;
    data = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> & v) {
    size_ = v.size_;
    capacity_ = v.capacity_;
    try
    {
		data = new T[size_];
    }
    catch(exception& e)
    {
		cerr << "Error en la reserva de memoria (" << e.what() << ")" << endl;
		exit(1);
	}
    for (unsigned int i = 0; i < size_; i++)
        data[i] = v.data[i];
}

template <class T>
bool Vector<T>:: empty() const {
    return size_ == 0;
}

template<class T>
Vector<T>& Vector<T>::operator = (const Vector<T> & v) {
    delete[] data;
    size_ = v.size_;
    capacity_ = v.capacity_;
    try
    {
		data = new T [capacity_];
	}
    catch(exception& e)
    {
		cerr << "Error en la reserva de memoria (" << e.what() << ")" << endl;
		exit(1);
	}
	
    for (unsigned int i = 0; i < size_; i++)
        data[i] = v.data[i];
        
    return *this;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::begin() {
    return data;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::end() {
    return data + size();
}

template<class T>
T& Vector<T>::front() {
    return data[0];
}

template<class T>
T& Vector<T>::back() {
    return data[size_ - 1];
}

template<class T>
void Vector<T>::push_back(const T & v) {
    if (size_ >= capacity_) {
        reserve(size_+1);
    }
    data [size_++] = v;
}

template<class T>
void Vector<T>::pop_back() {
    size_--;
}

template<class T>
void Vector<T>::reserve(unsigned int capacity) {
	
	T * newData;
	try
	{
		newData = new T[capacity];
    }
    catch(exception& e)
    {
		cerr << "Error en la reserva de memoria (" << e.what() << ")" << endl;
		delete[] data;
		exit(1);
	}

    for (unsigned int i = 0; i < size_; i++)
        newData[i] = data[i];

    capacity_ = capacity;
    delete[] data;
    data = newData;
}

template<class T>
unsigned int Vector<T>::size() const {
    return size_;
}

template<class T>
void Vector<T>::resize(unsigned int size) {
    reserve(size);
    size_ = size;
}

template<class T>
T& Vector<T>::operator[](unsigned int index) {
	try
	{
		if(index < 0 || index > size_)
		{
			throw("Error en el acceso a un elemento del vector, se devuelve el elemento en la posición 0");
		}
		return data[index];
	}
	catch(const char* msg)
	{
		cerr << msg << endl;
		return data[0];
	}
}

template<class T>
T& Vector<T>::at(unsigned int index) {
	try
	{
		if(index < 0 || index > size_)
		{
			throw("Error en el acceso a un elemento del vector, se devuelve el elemento en la posición 0");
		}
		return data[index];
	}
	catch(const char* msg)
	{
		cerr << msg << endl;
		return data[0];
	}
}

template <class T> 
bool Vector<T>::find_dato(T value) {
	for(int i=0; i<size_; i++)
	{
		if(this->at(i) == value)
		{
			return true; //Elemento encontrado, devolvemos true
		}
	}
	
	return false; //No encontrado, devolvemos false
}

template<class T>
unsigned int Vector<T>::capacity()const {
    return capacity_;
}

template<class T>
Vector<T>::~Vector() {
    delete[] data;
}

template <class T>
void Vector<T>::clear() {
    capacity_ = 0;
    size_ = 0;
    data = 0;
}

template<>
ostream& Vector<Numero*>::toStream(ostream& os) {
	for(int i=0; i<this->size(); i++)
    {
		if(i==0)
		{
			os << "{ ";
			this->at(i)->toStream(cout);
			os << ", ";
		}
		else if(i!=0 && i!=size()-1)
		{
			this->at(i)->toStream(cout);
			os << ", ";
		}
		else
		{
			this->at(i)->toStream(cout);
			os << " }" << endl;
		}
	}
	return os;
}

template <class T>
ostream& Vector<T>::toStream(ostream& os) {
    for(int i=0; i<this->size(); i++)
    {
		if(i==0)
		{
			os << "{ " << this->at(i) << ", ";
		}
		else if(i!=0 && i!=size()-1)
		{
			os << this->at(i) << ", ";
		}
		else
		{
			os << this->at(i) << " }" << endl;
		}
	}
	return os;
}

#endif
