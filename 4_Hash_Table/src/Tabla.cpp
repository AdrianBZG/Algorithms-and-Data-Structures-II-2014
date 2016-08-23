/*
 * Adrián Rodríguez Bazaga
 * alu0100826456@ull.edu.es
 * Práctica 4: Algoritmos y Estructuras de Datos
 * Tabla Hash
 * */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

struct item {
	int key;
	item *next;
};

template <class Clave>
class Hash {

public:
    Hash();
    ~Hash();
    bool Insertar(int key);
    int hash(int key);
    bool Buscar(int key);
    int getSize();
    //Estadísticas
    void est_insertar();
    void est_buscar();
    void est_mostrar();
    //
    void run();
    void run_estadisticas();

private:

	//Parámetros principales
    int nCeldas = 0;
    int nBloques = 0;
    int factor = 0;
    int nPruebas = 0;
    int nIntentos = 0;
    int fDisp = 0;
    int fExpl = 0;
    int size = 0;
    //
    
    //Parámetros estadísticas
    int BnComparaciones = 0;
    int InComparaciones = 0;
    int b_min = 0;
    int b_med = 0;
    int b_max = 0;
    //

	vector<item*> hashTable;
    
    //Funciones de dispersión privadas
    int disp_modulo(int key);
    int disp_suma(int key);
    int disp_pseudoaleatoria(int key);
    //
    //Funciones de exploración privadas
    bool exploracion(int key);
    bool expl_lineal(int key);
    bool expl_cuadratica(int key);
    bool expl_dispdoble(int key);
    bool expl_redisp(int key);
    //
};

template<class Clave>
Hash<Clave>::Hash() 
{    
	run();
	int num_registros = int(nCeldas*(factor*0.01));
    for (int i = 0; i < num_registros; ++i)
    {		
        item* dummy = new item;
        dummy->key = -1;
        dummy->next = NULL;
        hashTable.push_back(dummy);
    }
    
	run_estadisticas();
	
}

template<class Clave>
Hash<Clave>::~Hash()
{
    hashTable.clear();
}

template<class Clave>
bool Hash<Clave>::Insertar(int key)
{
    int hashIndex = hash(key);
    if (hashTable.at(hashIndex)->key == -1)
    {
        ++size;
        hashTable[hashIndex]->key = key;
        return true;
    }
    else
    {
        return false;
    }
}

template<class Clave>
int Hash<Clave>::hash(int key)
{
	int valor;
	
	switch(fDisp){
		case 0: valor = disp_modulo(key); break;
		case 1: valor = disp_suma(key); break;
		case 2: valor = disp_pseudoaleatoria(key); break;
	}
	
	return valor%int((nCeldas*(factor*0.01)));
}

//Funciones de dispersión
template<class Clave>
int Hash<Clave>::disp_modulo(int key)
{
	return key;
}

template<class Clave>
int Hash<Clave>::disp_suma(int key)
{
	int d = 0;
	int x = key;
	int y;
	
	while(x > 0) 
	{ 
		y = x%10; 
		d=d+y; 
		x=x/10;
	}
	return (d);
}

template<class Clave>
int Hash<Clave>::disp_pseudoaleatoria(int key)
{
	srand(key); 
	return rand();
}
//
//Funciones de exploración
template<class Clave>
bool Hash<Clave>::exploracion(int key)
{
	bool result = false;
	
	switch(fExpl){
		case 0: result = expl_lineal(key); break;
		case 1: result = expl_cuadratica(key); break;
		case 2: result = expl_dispdoble(key); break;
		case 3: result = expl_redisp(key); break;
	}
	
	return result;
}

template<class Clave>
bool Hash<Clave>::expl_lineal(int key)
{
	int contador = 0;
	int aux = key;
	//
	while(contador < nIntentos)
	{
		aux = (hash(aux)+contador)%int((nCeldas*(factor*0.01)));
		if(hashTable[aux]->key == key)
		{
			return true;
		}
		
		contador++;	
		//Estadísticas
		BnComparaciones = contador;
		//	
	}
	//
	return false;
}

template<class Clave>
bool Hash<Clave>::expl_cuadratica(int key)
{
	int contador = 0;
	int aux = key;
	//
	while(contador < nIntentos)
	{
		aux = (hash(aux)+contador*contador)%int((nCeldas*(factor*0.01)));		
		if(hashTable[aux]->key == key)
		{
			return true;
		}
		
		contador++;	
		//Estadísticas
		BnComparaciones = contador;
		//	
	}
	//
	return false;
}

template<class Clave>
bool Hash<Clave>::expl_dispdoble(int key)
{
	int contador = 0;
	int aux = key;
	//
	while(contador < nIntentos)
	{
		aux = (hash(aux)+(contador*disp_modulo(aux)))%int((nCeldas*(factor*0.01)));
		if(hashTable[aux]->key == key)
		{
			return true;
		}
		
		contador++;	
		//Estadísticas
		BnComparaciones = contador;
		//	
	}
	//
	return false;
}

template<class Clave>
bool Hash<Clave>::expl_redisp(int key)
{
	int contador = 0;
	bool result = false;
	//
	while(contador < nIntentos)
	{
		switch(contador%3){
			case 0: result = expl_lineal(key); break;
			case 1: result = expl_cuadratica(key); break;
			case 2: result = expl_dispdoble(key); break;
		}
		
		if(result)
		{
			return true;
		}
		
		contador++;	
		//Estadísticas
		BnComparaciones = contador;
		//	
	}
	//
	return false;
}
//

template<class Clave>
bool Hash<Clave>::Buscar(int key)
{
	bool resultado = false;
	int intentos_aux = 0;
	while(!resultado && intentos_aux < nIntentos)
	{
		resultado = exploracion(key);
		intentos_aux++;
	}

    return resultado;
}

template<class Clave>
int Hash<Clave>::getSize()
{
    return (nCeldas*(factor*0.01));
}

template<class Clave>
void Hash<Clave>::est_insertar()
{
    //int clave = int(15000000+30000000 * rand() / RAND_MAX);
    
    for(int i=0; i < (nCeldas*(factor*0.01)); i++)
    {
		int clave = 30000000+i;
		//int clave = int(15000000+30000000 * rand() / RAND_MAX);
		Insertar(clave);
	}
}

template<class Clave>
void Hash<Clave>::est_buscar()
{
    int maximo = 0;
    int minimo = int(nCeldas*(factor*0.01));
    int media = 0;
    
    //int clave = int(15000000+50000000 * rand() / RAND_MAX);
    
    for(int i=0; i < nPruebas; i++)
    {
		int contador = 0;
		//int clave = 30000000+i;
		int clave = int(15000000+50000000 * rand() / RAND_MAX);
		Buscar(clave);
		contador = BnComparaciones;
		media =+ contador;
		if(maximo < contador)
		{
			maximo = contador;
		}
		if(minimo > contador)
		{
			minimo = contador;
		}
	}
	media = maximo/2;
	//
	b_min = minimo;
	b_med = media;
	b_max = maximo;
	//
}

template<class Clave>
void Hash<Clave>::est_mostrar()
{
    cout << "COMPARACIONES EN INSERCIONES Y BÚSQUEDAS" << endl;
    
    cout << "\tCeldas\tBloques\tDispersión\tExploración\tCarga\tPruebas" << endl;
    cout << "\t" << nCeldas << "\t" << nBloques;
    switch(fExpl){
		case 0: cout << "\tMódulo\t\t"; break;
		case 1: cout << "\tSuma\t\t"; break;
		case 2: cout << "\tPseudo-aleatoria\t"; break;
	}
    switch(fExpl){
		case 0: cout << "Lineal\t\t"; break;
		case 1: cout << "Cuadrática\t"; break;
		case 2: cout << "Doble\t\t"; break;
		case 3: cout << "Redispersión\t"; break;
	}
	cout << factor << "\t" << nPruebas << endl;
	
	cout << endl << "\t\tNúmero de comparaciones:" << endl;
	cout << "\t\tMínimo\tMedio\tMáximo" << endl;
	cout << "Búsqueda\t" << b_min << "\t" << b_med << "\t" << b_max << endl;
	cout << "Inserción\t" << b_min << "\t" << b_med << "\t" << b_max << endl;
}

template<class Clave>
void Hash<Clave>::run()
{
	system("clear");
	cout << "Número de celdas de la tabla: " << endl;
	cin >> nCeldas;
	system("clear");
	
	cout << "Número de registros de las celdas: " << endl;
	cin >> nBloques;
	system("clear");
	
	cout << "Método de dispersión: " << endl;
	cout << " [0] Módulo" << endl;
	cout << " [1] Suma" << endl;
	cout << " [2] Pseudo-aleatoria" << endl;
	cin >> fDisp;
	system("clear");
	
	cout << "Método de exploración: " << endl;
	cout << " [0] Lineal" << endl;
	cout << " [1] Cuadrática" << endl;
	cout << " [2] Dispersión doble" << endl;
	cout << " [3] Re-dispersión" << endl;
	cin >> fExpl;
	system("clear");
	
	cout << "Factor de carga (en %): " << endl;
	cin >> factor;
	system("clear");
	
	cout << "Número de pruebas: " << endl;
	cin >> nPruebas;
	system("clear");
	
	cout << "Número de intentos en búsquedas: " << endl;
	cin >> nIntentos;
	system("clear");
}

template<class Clave>
void Hash<Clave>::run_estadisticas()
{
	//Comienzo de estadísticas
	est_insertar();
	est_buscar();
	est_mostrar();
	//
}

#endif
