/* Adrian Rodriguez Bazaga
 * alu0100826456@ull.edu.es
 * Clase "ABB"
 * Práctica 6 - Algoritmos y Estructura de Datos Avanzadas
 */


#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>
#include <limits>

//Incluimos el nodoBB
#include "nodoBB.cpp"
//

using namespace std;


template <class Tipo>
class ABB {

private:

	nodoBB<Tipo>* raiz_;
	unsigned modo_ = 0;
	vector< vector < unsigned > > estadisticas_;

public:

	ABB(void);
	~ABB(void);	
	
	nodoBB<Tipo>* Buscar(Tipo clave_dada);
	nodoBB<Tipo>* BuscarRama(nodoBB<Tipo>* nodo, Tipo clave_dada, int& contador);
	
	//Modos
	void run();
	void run_demostracion();
	void run_estadisticas();
	void run_estudio();
	void run_estadisticas_estudio(int N, int P);
	void set_modo(unsigned m);
	//
	
	void mostrar_estadisticas();
	
	void Insertar(Tipo clave_dada);
	void InsertarRama(nodoBB<Tipo>*& nodo, Tipo clave_dada, int& contador);
	
	void Eliminar(Tipo clave_dada);
	void EliminarRama(nodoBB<Tipo>*& nodo, Tipo clave_dada);
	
	void Sustituye(nodoBB<Tipo>* eliminado, nodoBB<Tipo>*& sust);
	
	inline bool Vacio() { return raiz_==NULL; }
	
	void recorrer_preorden(nodoBB<Tipo>* nodo);
	void recorrer_inorden(nodoBB<Tipo>* nodo);
	void recorrer_postorden(nodoBB<Tipo>* nodo);
	void recorrer_niveles();
	
	void procesa(Tipo dat, ostream& os);
	
	inline nodoBB<Tipo>* get_raiz() { return raiz_; }
};

//Implementación
template<class Tipo>
ABB<Tipo>::ABB(void)
{
	raiz_ = NULL;
}

template<class Tipo>
ABB<Tipo>::~ABB(void)
{
	raiz_ = NULL;
}

template<class Tipo>
void ABB<Tipo>::run()
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
void ABB<Tipo>::run_estudio()
{
	system("clear");
	modo_ = 2;
	
	cout << "ESTUDIO DE LA VARIACIÓN DEL COMPORTAMIENTO EN EL ABB" << endl;
	cout << "----------------------------------------------------" << endl << endl << endl;
	
	cout << "ABB CON N=10, P=5" << endl;
	run_estadisticas_estudio(10,5);
	
	cout << "ABB CON N=100, P=50" << endl;
	run_estadisticas_estudio(100,50);
	
	cout << "ABB CON N=1000, P=500" << endl;
	run_estadisticas_estudio(1000,500);
	
	cout << "ABB CON N=10000, P=5000" << endl;
	run_estadisticas_estudio(10000,5000);
	
	cout << "ABB CON N=100000, P=50000" << endl;
	run_estadisticas_estudio(100000,50000);
}

template<class Tipo>
void ABB<Tipo>::run_demostracion()
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
			Insertar(aux);
			recorrer_niveles();
		}
		
		if(opc == 2)
		{
			system("clear");
			cout << "Introduce el valor de la clave a eliminar..." << endl;
			cin >> aux;
			Eliminar(aux);
			recorrer_niveles();
		}
	}
	
	system("clear");
}

template<class Tipo>
void ABB<Tipo>::run_estadisticas()
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
		Insertar(banco_pruebas[i].get_valor());
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
void ABB<Tipo>::run_estadisticas_estudio(int N, int P)
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
		Insertar(banco_pruebas[i].get_valor());
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
nodoBB<Tipo>* ABB<Tipo>::Buscar(Tipo clave_dada)
{
	int contador = 0;
	nodoBB<Tipo>* result = BuscarRama(raiz_, clave_dada, contador);
	if(modo_ != 0) estadisticas_[0].push_back(contador);
	return result;
}

template<class Tipo>
void ABB<Tipo>::set_modo(unsigned m)
{
	modo_ = m;
}

template<class Tipo>
nodoBB<Tipo>* ABB<Tipo>::BuscarRama(nodoBB<Tipo>* nodo, Tipo clave_dada, int& contador)
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

template<class Tipo>
void ABB<Tipo>::Insertar(Tipo clave_dada)
{
	int contador = 0;
	InsertarRama(raiz_, clave_dada, contador);
	if(modo_ != 0) estadisticas_[0].push_back(contador);
}

template<class Tipo>
void ABB<Tipo>::InsertarRama(nodoBB<Tipo>*& nodo, Tipo clave_dada, int& contador)
{
	if(nodo == NULL)
	{
		nodo = new nodoBB<Tipo>(clave_dada);
		if(modo_ != 0) contador++;
	}
	else if(clave_dada < nodo->get_clave())
	{
		if(modo_ != 0) contador++;
		InsertarRama(nodo->get_izq(), clave_dada, contador);
	}
	else
	{
		if(modo_ != 0) contador++;
		InsertarRama(nodo->get_der(), clave_dada, contador);
	}
}

template<class Tipo>
void ABB<Tipo>::Eliminar(Tipo clave_dada)
{
	EliminarRama(raiz_, clave_dada);
}

template<class Tipo>
void ABB<Tipo>::EliminarRama(nodoBB<Tipo>*& nodo, Tipo clave_dada)
{
	if(nodo == NULL) return;
	
	if(clave_dada < nodo->get_clave())
	{
		EliminarRama(nodo->get_izq(), clave_dada);
	}
	else if(clave_dada > nodo->get_clave())
	{
		EliminarRama(nodo->get_der(), clave_dada);
	}
	else //Caso de clave_dada == nodo->clave_
	{
		nodoBB<Tipo>* Eliminado = nodo;
		
		if(nodo->get_der() == NULL)
		{
			nodo = nodo->get_izq();
		}
		else if(nodo->get_izq() == NULL)
		{
			nodo = nodo->get_der();
		}
		else
		{
			Sustituye(Eliminado, nodo->get_izq());
		}
	}
}

template<class Tipo>
void ABB<Tipo>::Sustituye(nodoBB<Tipo>* eliminado, nodoBB<Tipo>*& sust)
{
	if(sust->get_der() != NULL)
	{
		Sustituye(eliminado, sust->get_der());
	}
	else
	{
		eliminado->set_clave(sust->get_clave());
		eliminado = sust;
		sust = sust->get_izq();
	}
}
	
template<class Tipo>
void ABB<Tipo>::recorrer_preorden(nodoBB<Tipo>* nodo)
{
	if(nodo == NULL) return;
	
	procesa(nodo->get_clave(), cout);
	recorrer_preorden(nodo->get_izq());
	recorrer_preorden(nodo->get_der());
}

template<class Tipo>
void ABB<Tipo>::recorrer_inorden(nodoBB<Tipo>* nodo)
{
	if(nodo == NULL) return;
	
	recorrer_inorden(nodo->get_izq());
	procesa(nodo->get_clave(), cout);
	recorrer_inorden(nodo->get_der());
}

template<class Tipo>
void ABB<Tipo>::recorrer_postorden(nodoBB<Tipo>* nodo)
{
	if(nodo == NULL) return;
	
	recorrer_postorden(nodo->get_izq());
	recorrer_postorden(nodo->get_der());
	procesa(nodo->get_clave(), cout);
}

template<class Tipo>
void ABB<Tipo>::procesa(Tipo dat, ostream& os)
{
	cout << "[" << dat << "]";
}

template<class Tipo>
void ABB<Tipo>::recorrer_niveles()
{
	typedef pair<nodoBB<Tipo>*, int> MiPar;
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
