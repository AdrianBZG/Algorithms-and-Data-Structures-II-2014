/* Adrian Rodriguez Bazaga
 * alu0100826456@ull.edu.es
 * Clase "arbolAVL"
 * Práctica 7 - Algoritmos y Estructura de Datos Avanzadas
 */


#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>
#include <limits>
#include <algorithm>

//Incluimos el nodoAVL
#include "nodoAVL.cpp"
//

using namespace std;


template <class Tipo>
class arbolAVL {

private:

	nodoAVL<Tipo>* raiz_;
	unsigned modo_ = 0;
	vector< vector < unsigned > > estadisticas_;

public:

	arbolAVL(void);
	~arbolAVL(void);	
	
	nodoAVL<Tipo>* Buscar(Tipo clave_dada);
	nodoAVL<Tipo>* BuscarRama(nodoAVL<Tipo>* nodo, Tipo clave_dada, int& contador);
	
	//Modos
	void run();
	void run_demostracion();
	void run_estadisticas();
	void run_estudio();
	void run_estadisticas_estudio(int N, int P);
	void set_modo(unsigned m);
	//
	
	//Rotaciones, balanceo, diferencia y altura
	nodoAVL<Tipo>* rotacion_II(nodoAVL<Tipo>* nodo);
	nodoAVL<Tipo>* rotacion_DD(nodoAVL<Tipo>* nodo);
	nodoAVL<Tipo>* rotacion_ID(nodoAVL<Tipo>* nodo);
	nodoAVL<Tipo>* rotacion_DI(nodoAVL<Tipo>* nodo);
	
	nodoAVL<Tipo>* balanceo(nodoAVL<Tipo>* nodo, int& contador);
	int diferencia(nodoAVL<Tipo>* nodo);
	int altura(nodoAVL<Tipo>* nodo);
	//
	
	void mostrar_estadisticas();
	
	//Inserción
	void Insertar(nodoAVL<Tipo>* raiz, Tipo clave_dada);
	nodoAVL<Tipo>* Insertar_Bal(nodoAVL<Tipo>* &raiz, Tipo clave_dada, int& contador);
	//
	
	//Eliminación
	void Eliminar(nodoAVL<Tipo>* &raiz, Tipo clave_dada);
	Tipo EliminarMinimo(nodoAVL<Tipo>* &raiz);
	//
	
	inline bool Vacio() { return raiz_==NULL; }
	
	void recorrer_preorden(nodoAVL<Tipo>* nodo);
	void recorrer_inorden(nodoAVL<Tipo>* nodo);
	void recorrer_postorden(nodoAVL<Tipo>* nodo);
	void recorrer_niveles();
	
	void procesa(Tipo dat, ostream& os);
	
	inline nodoAVL<Tipo>* get_raiz() { return raiz_; }
};

//Implementación
template<class Tipo>
arbolAVL<Tipo>::arbolAVL(void)
{
	raiz_ = NULL;
}

template<class Tipo>
arbolAVL<Tipo>::~arbolAVL(void)
{
	raiz_ = NULL;
}

template<class Tipo>
void arbolAVL<Tipo>::run()
{
	int opc = 9999;	
	
	while(opc < 0 || opc > 2)
	{
		//Elementos menu
		system("clear");
		cout << "[0] Modo demostración" << endl;
		cout << "[1] Modo estadísticas" << endl;
		cout << "[2] Estudio de la variación" << endl;
		cout << "Selecciona una opción..." << endl << endl;
		cin >> opc;
		//
		
		if(opc == 0)
		{
			run_demostracion();
		}
		
		if(opc == 1)
		{
			run_estadisticas();
		}
		
		if(opc == 2)
		{
			run_estudio();
		}
	}
}

template<class Tipo>
void arbolAVL<Tipo>::run_estudio()
{
	system("clear");
	modo_ = 2;
	
	cout << "ESTUDIO DE LA VARIACIÓN DEL COMPORTAMIENTO EN EL arbolAVL" << endl;
	cout << "----------------------------------------------------" << endl << endl << endl;
	
	cout << "arbolAVL CON N=10, P=5" << endl;
	run_estadisticas_estudio(10,5);
	
	cout << "arbolAVL CON N=100, P=50" << endl;
	run_estadisticas_estudio(100,50);
	
	cout << "arbolAVL CON N=1000, P=500" << endl;
	run_estadisticas_estudio(1000,500);
	
	cout << "arbolAVL CON N=10000, P=5000" << endl;
	run_estadisticas_estudio(10000,5000);
	
	cout << "arbolAVL CON N=50000, P=25000" << endl;
	run_estadisticas_estudio(50000,25000);
}

template<class Tipo>
void arbolAVL<Tipo>::run_demostracion()
{
	int opc = 9999;
	Tipo aux;
	
	modo_ = 0;
	
	while(opc != 0)
	{
		//Elementos menu
		system("clear");
		cout << "[0] Salir" << endl;
		cout << "[1] Insertar clave" << endl;
		cout << "[2] Eliminar clave" << endl;
		cout << "Selecciona una opción..." << endl << endl;
		cin >> opc;
		//
		
		if(opc == 1)
		{
			system("clear");
			cout << "Introduce el valor de la clave a insertar..." << endl;
			cin >> aux;
			Insertar(raiz_, aux);
			recorrer_niveles();
		}
		
		if(opc == 2)
		{
			system("clear");
			cout << "Introduce el valor de la clave a eliminar..." << endl;
			cin >> aux;
			Eliminar(raiz_, aux);
			recorrer_niveles();
		}
	}
	
	system("clear");
}

template<class Tipo>
void arbolAVL<Tipo>::run_estadisticas()
{
	int N;
	int P;
	int max, min;
	max = 0;
	min = 9999999;
	vector< dni_t<Tipo> > banco_pruebas;
	vector< unsigned > aux;
	
	modo_ = 1;
	
	//Parámetros del experimento
	system("clear");
	cout << "Introduce el tamaño del árbol:" << endl;
	cin >> N;
	
	system("clear");
	cout << "Introduce el número de pruebas:" << endl;
	cin >> P;
	//
	
	//Reservar espacio para las estadísticas
	estadisticas_.reserve(2*P);
	aux.reserve(2*P);
	//
	
	
	//Creamos el banco de pruebas con 2*N DNI aleatorios
	for(int i=0; i<2*N; i++)
	{
		dni_t<Tipo> aux;
		banco_pruebas.push_back(aux);
	}
	//
	
	
	//Comienzo del experimento
	
	for(int i=0; i<N; i++) //Inserción
	{
		Insertar(raiz_, banco_pruebas[i].get_valor());
	}
	
	aux = estadisticas_[0];
	
	estadisticas_.clear();
	//Busqueda de elementos ya insertados
	for(int i=0; i<N; i++)
	{
		Buscar(banco_pruebas[i].get_valor());
	}
	//
	
	//Busqueda de elementos no insertados
	for(int i=N; i<2*N; i++)
	{
		Buscar(banco_pruebas[i].get_valor());
	}
	//
	
	
	//Mostramos estadisticas
	system("clear");
	//De la busqueda
	
	for(unsigned i=0; i<estadisticas_[0].size(); i++)
	{
		if(estadisticas_[0][i] < min)
		{
			min = estadisticas_[0][i];
		}
		if(estadisticas_[0][i] > max)
		{
			max = estadisticas_[0][i];
		}
	}
	
	cout << "\t\tN\tP\tMínimo\tMedio\tMáximo" << endl;
	cout << "Búsqueda\t" << N << "\t" << P << "\t" << min << "\t" << (min+max)/2 << "\t" << max << endl;
	//
	//De la insercion

	max = 0;
	min = 9999999;
	
	for(unsigned i=0; i<aux.size(); i++)
	{
		if(aux[i] < min)
		{
			min = aux[i];
		}
		if(aux[i] > max)
		{
			max = aux[i];
		}
	}
	
	cout << "Inserción\t" << N << "\t" << P << "\t" << min << "\t" << (min+max)/2 << "\t" << max << endl;
	//
	//	
	//
	
}

template<class Tipo>
void arbolAVL<Tipo>::run_estadisticas_estudio(int N, int P)
{

	int max, min;
	max = 0;
	min = 9999999;
	vector< dni_t<Tipo> > banco_pruebas;
	vector< unsigned > aux;
	
	modo_ = 2;
	
	//Reservar espacio para las estadísticas
	estadisticas_.reserve(2*P);
	aux.reserve(2*P);
	//
	
	
	//Creamos el banco de pruebas con 2*N DNI aleatorios
	for(int i=0; i<2*N; i++)
	{
		dni_t<Tipo> aux;
		banco_pruebas.push_back(aux);
	}
	//
	
	
	//Comienzo del experimento
	
	for(int i=0; i<N; i++) //Inserción
	{
		Insertar(raiz_, banco_pruebas[i].get_valor());
	}
	
	aux = estadisticas_[0];
	
	estadisticas_.clear();
	//Busqueda de elementos ya insertados
	for(int i=0; i<N; i++)
	{
		Buscar(banco_pruebas[i].get_valor());
	}
	//
	
	//Busqueda de elementos no insertados
	for(int i=N; i<2*N; i++)
	{
		Buscar(banco_pruebas[i].get_valor());
	}
	//
	
	
	//Mostramos estadisticas
	
	//De la busqueda
	
	for(unsigned i=0; i<estadisticas_[0].size(); i++)
	{
		if(estadisticas_[0][i] < min)
		{
			min = estadisticas_[0][i];
		}
		if(estadisticas_[0][i] > max)
		{
			max = estadisticas_[0][i];
		}
	}
	
	cout << "\t\tN\tP\tMínimo\tMedio\tMáximo" << endl;
	cout << "Búsqueda\t" << N << "\t" << P << "\t" << min << "\t" << (min+max)/2 << "\t" << max << endl;
	//
	//De la insercion

	max = 0;
	min = 9999999;
	
	for(unsigned i=0; i<aux.size(); i++)
	{
		if(aux[i] < min)
		{
			min = aux[i];
		}
		if(aux[i] > max)
		{
			max = aux[i];
		}
	}
	
	cout << "Inserción\t" << N << "\t" << P << "\t" << min << "\t" << (min+max)/2 << "\t" << max << endl << endl << endl;
	//
	//	
	//
	
}

template<class Tipo>
nodoAVL<Tipo>* arbolAVL<Tipo>::Buscar(Tipo clave_dada)
{
	int contador = 0;
	nodoAVL<Tipo>* result = BuscarRama(raiz_, clave_dada, contador);
	if(modo_ != 0) estadisticas_[0].push_back(contador);
	return result;
}

template<class Tipo>
void arbolAVL<Tipo>::set_modo(unsigned m)
{
	modo_ = m;
}

template<class Tipo>
nodoAVL<Tipo>* arbolAVL<Tipo>::BuscarRama(nodoAVL<Tipo>* nodo, Tipo clave_dada, int& contador)
{
	if(nodo == NULL)
	{
		if(modo_ != 0)
		{
			contador++;
		}
		return NULL;
	}
	
	if(clave_dada == nodo->get_clave())
	{
		if(modo_ != 0)
		{
			contador++;
		}
		return nodo;
	}
	
	if(clave_dada < nodo->get_clave())
	{
		if(modo_ != 0)
		{
			contador++;
		}
		return BuscarRama(nodo->get_izq(), clave_dada, contador);
	}
	
	if(modo_ != 0)
	{
		contador++;
	}
	return BuscarRama(nodo->get_der(), clave_dada, contador);
}

//Rotaciones
template<class Tipo>
nodoAVL<Tipo>* arbolAVL<Tipo>::rotacion_II(nodoAVL<Tipo>* nodo)
{
	nodoAVL<Tipo>* temp = nodo->get_izq();
	nodo->get_izq() = temp->get_der();
	temp->get_der() = nodo;
	return temp;
}

template<class Tipo>
nodoAVL<Tipo>* arbolAVL<Tipo>::rotacion_DD(nodoAVL<Tipo>* nodo)
{
	nodoAVL<Tipo>* temp = nodo->get_der();
	nodo->get_der() = temp->get_izq();
	temp->get_izq() = nodo;
	return temp;
}

template<class Tipo>
nodoAVL<Tipo>* arbolAVL<Tipo>::rotacion_ID(nodoAVL<Tipo>* nodo)
{
	nodoAVL<Tipo>* temp = nodo->get_izq();
	nodo->get_izq() = rotacion_DD(temp);
	return rotacion_II(nodo);
}

template<class Tipo>
nodoAVL<Tipo>* arbolAVL<Tipo>::rotacion_DI(nodoAVL<Tipo>* nodo)
{
	nodoAVL<Tipo>* temp = nodo->get_der();
	nodo->get_der() = rotacion_II(temp);
	return rotacion_DD(nodo);
}
//

//Balanceo, altura, diferencia
template<class Tipo>
nodoAVL<Tipo>* arbolAVL<Tipo>::balanceo(nodoAVL<Tipo>* nodo, int& contador)
{
	int factor_balanceo = diferencia(nodo);
	
	if(factor_balanceo > 1)
	{
		if(modo_ != 0) contador++;
		if(diferencia(nodo->get_izq()) > 0)
		{
			if(modo_ != 0) contador++;
			nodo = rotacion_II(nodo);
		}
		else
		{
			if(modo_ != 0) contador++;
			nodo = rotacion_ID(nodo);
		}
	}
	else if(factor_balanceo < -1)
	{
		if(modo_ != 0) contador++;
		if(diferencia(nodo->get_der()) > 0)
		{
			if(modo_ != 0) contador++;
			nodo = rotacion_DI(nodo);
		}
		else
		{
			if(modo_ != 0) contador++;
			nodo = rotacion_DD(nodo);
		}
	}
	
	return nodo;
}

template<class Tipo>
int arbolAVL<Tipo>::altura(nodoAVL<Tipo>* nodo)
{
	int h = 0;
	if(nodo != NULL)
	{
		int altura_i = altura(nodo->get_izq());
		int altura_d = altura(nodo->get_der());
		int altura_max = max(altura_i, altura_d);
		h = altura_max+1;
	}
	
	return h;
}

template<class Tipo>
int arbolAVL<Tipo>::diferencia(nodoAVL<Tipo>* nodo)
{
	int altura_i = altura(nodo->get_izq());
	int altura_d = altura(nodo->get_der());
	int factor_balanceo = altura_i-altura_d;
	return factor_balanceo;
}

//

template<class Tipo>
void arbolAVL<Tipo>::Insertar(nodoAVL<Tipo>* raiz, Tipo clave_dada)
{
	int contador = 0;
	Insertar_Bal(raiz_, clave_dada, contador);
	if(modo_ != 0) estadisticas_[0].push_back(contador);
}

template<class Tipo>
nodoAVL<Tipo>* arbolAVL<Tipo>::Insertar_Bal(nodoAVL<Tipo>* &raiz, Tipo clave_dada, int& contador)
{
	if(raiz == NULL)
	{
		if(modo_ != 0) contador++;
		raiz = new nodoAVL<Tipo>(clave_dada);
		return raiz;
	}
	else if(clave_dada < raiz->get_clave())
	{
		if(modo_ != 0) contador++;
		raiz->get_izq() = Insertar_Bal(raiz->get_izq(), clave_dada, contador);
		raiz = balanceo(raiz, contador);
	}
	else if(clave_dada >= raiz->get_clave())
	{
		if(modo_ != 0) contador++;
		raiz->get_der() = Insertar_Bal(raiz->get_der(), clave_dada, contador);
		raiz = balanceo(raiz, contador);
	}
	
	return raiz;
}

template<class Tipo>
void arbolAVL<Tipo>::Eliminar(nodoAVL<Tipo>* &raiz, Tipo clave_dada)
{
	nodoAVL<Tipo>* aux;
	if(raiz == NULL)
	{
		return; //Elemento no encontrado
	}
	else if(clave_dada < raiz->get_clave())
	{
		Eliminar(raiz->get_izq(), clave_dada);
	}
	else if(clave_dada > raiz->get_clave())
	{
		Eliminar(raiz->get_der(), clave_dada);
	}
	else if((raiz->get_izq() == NULL) && (raiz->get_der() == NULL))
	{
		aux = raiz;
		free(aux);
		raiz=NULL;
		//Elemento eliminado
	}
	else if(raiz->get_izq() == NULL)
	{
		aux = raiz;
		free(aux);
		raiz=raiz->get_der();
		//Elemento eliminado
	}
	else
	{
		raiz->set_clave(EliminarMinimo(raiz->get_der()));
	}
}

template<class Tipo>
Tipo arbolAVL<Tipo>::EliminarMinimo(nodoAVL<Tipo>* &raiz)
{
	int aux;
	
	if(raiz->get_izq() == NULL)
	{
		aux=raiz->get_clave();
		raiz=raiz->get_der();
		return aux;
	}
	else
	{
		aux=EliminarMinimo(raiz->get_izq());
		return aux;
	}

}

template<class Tipo>
void arbolAVL<Tipo>::recorrer_preorden(nodoAVL<Tipo>* nodo)
{
	if(nodo == NULL) return;
	
	procesa(nodo->get_clave(), cout);
	recorrer_preorden(nodo->get_izq());
	recorrer_preorden(nodo->get_der());
}

template<class Tipo>
void arbolAVL<Tipo>::recorrer_inorden(nodoAVL<Tipo>* nodo)
{
	if(nodo == NULL) return;
	
	recorrer_inorden(nodo->get_izq());
	procesa(nodo->get_clave(), cout);
	recorrer_inorden(nodo->get_der());
}

template<class Tipo>
void arbolAVL<Tipo>::recorrer_postorden(nodoAVL<Tipo>* nodo)
{
	if(nodo == NULL) return;
	
	recorrer_postorden(nodo->get_izq());
	recorrer_postorden(nodo->get_der());
	procesa(nodo->get_clave(), cout);
}

template<class Tipo>
void arbolAVL<Tipo>::procesa(Tipo dat, ostream& os)
{
	cout << "[" << dat << "]";
}

template<class Tipo>
void arbolAVL<Tipo>::recorrer_niveles()
{
	typedef pair<nodoAVL<Tipo>*, int> MiPar;
	queue<MiPar> Q;
	int nivel;
	int nivel_actual = 0;
	Q.push(make_pair(this->get_raiz(), 0));
	
	//
	system("clear");
	cout << "<<<\tESTADO ACTUAL DEL ÁRBOL: RECORRIDO POR NIVELES\t>>>" << endl << endl;
	cout << "Nivel 0: ";
	//
	while(!Q.empty())
	{
		MiPar par;
		par = Q.front();
		Q.pop();
		
		if(par.second > nivel_actual)
		{
			nivel_actual = par.second;
			cout << endl;
			cout << "Nivel " << nivel_actual << ": ";
		}
		
		if(par.first != NULL)
		{
			procesa(par.first->get_clave(), cout);
			Q.push(make_pair(par.first->get_izq(), par.second+1));
			Q.push(make_pair(par.first->get_der(), par.second+1));
		}
		else
		{
			//Nada: Subárbol  vacío
			//Por lo tanto imprimimos un punto
			cout << "[.]";
		}
	}
	
	//Tecla para continuar
	cout << endl << endl;
	cout << "Presiona ENTER para continuar...";
	cin.ignore ( numeric_limits<streamsize>::max(), '\n' );
	cin.get();
	//
}
//
