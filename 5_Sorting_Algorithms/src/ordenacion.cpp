/* Adrian Rodriguez Bazaga
 * alu0100826456@ull.edu.es
 * Practica 5 - Algoritmos y Estructuras de Datos Avanzadas
 * 
 * Clase "Ordenacion"
 * Algoritmos implementados: Insercion, Seleccion, ShellSort, MergeSort y QuickSort. 
 * Algoritmos implementados opcionalmente: BubbleSort, ShakeSort, BinSort, HeapSort y RadixSort.
 * 
 */


#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

//
#include "dni.cpp"
//

using namespace std;


template <class Clave>
class ordenacion_t {

private:

	vector< dni_t<Clave> > secuencia_;
	vector< dni_t<Clave> > secuencia_ordenada_;
	vector< vector< vector < dni_t<Clave> > > > banco_;
	vector< vector<unsigned> > estadisticas_;
	unsigned modo_;
	unsigned contador_ = 0;

public:

	ordenacion_t(void);
	~ordenacion_t(void);
	
	ostream& toStream(ostream& sout);
	vector< dni_t<Clave> > get_secuencia();
	void mostrar_secuencia();
	void mostrar_secuencia_ordenada();
	void mostrar_secuencia_ordenada_simple();
	
	//Estadisticas
	void actualizar_contador(int p);
	void mostrar_estadisticas();
	//
	
	//Modos
	void run_demostracion();
	void run_estadisticas();
	void run();
	//
	
	//Ord. por BinSort
	int ordenarporbinsort(vector< dni_t<Clave> >& T); 
	//
	
	//Ord. por HeapSort
	int ordenarporheapsort(vector< dni_t<Clave> >& T);
	//
	
	//Ord. por RadixSort
	int getMax(vector< dni_t<Clave> >& T);
	void countSort(vector< dni_t<Clave> >& T, int exp);
	int ordenarporradixsort(vector< dni_t<Clave> >& T);
	//
	//Ord. por ShakeSort
	int ordenarporshakesort(vector< dni_t<Clave> >& T);
	//
	//Ord. por BubbleSort
	int ordenarporbubblesort(vector< dni_t<Clave> >& T);
	//	
	//Ord. por ShellSort
	int ordenarporshellsort(vector< dni_t<Clave> >& T, double alfa);
	//	
	//Ord. por QuickSort
	int ordenarporquicksort(vector< dni_t<Clave> >& T, int izq, int der, int& vuelta);
	//
	//Ord. por seleccion
	int ordenarporseleccion(vector< dni_t<Clave> >& T);
	//
	//Ord. por insercion
	int ordenarporinsercion(vector< dni_t<Clave> >& T);
	//
	//Merge Sort
	int ordenarpormergesort(vector< dni_t<Clave> >& T, int& vm);
	void fusionar(vector< dni_t<Clave> > U, vector< dni_t<Clave> > V, vector< dni_t<Clave> >& T, int& vuelta);	
	//

};

//Implementación
template<class Clave>
ordenacion_t<Clave>::ordenacion_t(void)
{
}

template<class Clave>
ordenacion_t<Clave>::~ordenacion_t(void)
{
	secuencia_.clear();
}

template<class Clave>
vector< dni_t<Clave> > ordenacion_t<Clave>::get_secuencia()
{
	return secuencia_;
}

template<class Clave>
void ordenacion_t<Clave>::actualizar_contador(int p)
{
	estadisticas_[p].push_back(contador_);
	contador_=0;
}

template<class Clave>
void ordenacion_t<Clave>::mostrar_estadisticas()
{
	system("clear");
	int max, min;
	max = 0;
	min = 9999999;
	
	cout << "\t\t\tNúmero de Comparaciones" << endl;
	cout << "\t\t\tMínimo\t\tMedio\t\tMáximo" << endl;

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
	cout << "\tInserción\t" << min << "\t\t" << (min+max)/2 << "\t\t" << max << endl;
	//
	max = 0;
	min = 9999999;
	for(unsigned i=0; i<estadisticas_[1].size(); i++)
	{
		if(estadisticas_[1][i] < min)
		{
			min = estadisticas_[1][i];
		}
		if(estadisticas_[1][i] > max)
		{
			max = estadisticas_[1][i];
		}
	}
	cout << "\tSelección\t" << min << "\t\t" << (min+max)/2 << "\t\t" << max << endl;
	//
	max = 0;
	min = 9999999;
	for(unsigned i=0; i<estadisticas_[2].size(); i++)
	{
		if(estadisticas_[2][i] < min)
		{
			min = estadisticas_[2][i];
		}
		if(estadisticas_[2][i] > max)
		{
			max = estadisticas_[2][i];
		}
	}
	cout << "\tShellSort\t" << min << "\t\t" << (min+max)/2 << "\t\t" << max << endl;
	//
	max = 0;
	min = 9999999;
	for(unsigned i=0; i<estadisticas_[3].size(); i++)
	{
		if(estadisticas_[3][i] < min)
		{
			min = estadisticas_[3][i];
		}
		if(estadisticas_[3][i] > max)
		{
			max = estadisticas_[3][i];
		}
	}
	cout << "\tQuickSort\t" << min << "\t\t" << (min+max)/2 << "\t\t" << max << endl;
	//
	max = 0;
	min = 9999999;
	for(unsigned i=0; i<estadisticas_[4].size(); i++)
	{
		if(estadisticas_[4][i] < min)
		{
			min = estadisticas_[4][i];
		}
		if(estadisticas_[4][i] > max)
		{
			max = estadisticas_[4][i];
		}
	}
	cout << "\tMergeSort\t" << min << "\t\t" << (min+max)/2 << "\t\t" << max << endl;
	//
	max = 0;
	min = 9999999;
	for(unsigned i=0; i<estadisticas_[5].size(); i++)
	{
		if(estadisticas_[5][i] < min)
		{
			min = estadisticas_[5][i];
		}
		if(estadisticas_[5][i] > max)
		{
			max = estadisticas_[5][i];
		}
	}
	cout << "\tBubbleSort\t" << min << "\t\t" << (min+max)/2 << "\t\t" << max << endl;
	//
	max = 0;
	min = 9999999;
	for(unsigned i=0; i<estadisticas_[6].size(); i++)
	{
		if(estadisticas_[6][i] < min)
		{
			min = estadisticas_[6][i];
		}
		if(estadisticas_[6][i] > max)
		{
			max = estadisticas_[6][i];
		}
	}
	cout << "\tShakeSort\t" << min << "\t\t" << (min+max)/2 << "\t\t" << max << endl;
	//
	max = 0;
	min = 9999999;
	for(unsigned i=0; i<estadisticas_[7].size(); i++)
	{
		if(estadisticas_[7][i] < min)
		{
			min = estadisticas_[7][i];
		}
		if(estadisticas_[7][i] > max)
		{
			max = estadisticas_[7][i];
		}
	}
	cout << "\tRadixSort\t" << min << "\t\t" << (min+max)/2 << "\t\t" << max << endl;
	//
	max = 0;
	min = 9999999;
	for(unsigned i=0; i<estadisticas_[8].size(); i++)
	{
		if(estadisticas_[8][i] < min)
		{
			min = estadisticas_[8][i];
		}
		if(estadisticas_[8][i] > max)
		{
			max = estadisticas_[8][i];
		}
	}
	cout << "\tHeapSort\t" << min << "\t\t" << (min+max)/2 << "\t\t" << max << endl;
	//
}

template<class Clave>
void ordenacion_t<Clave>::mostrar_secuencia()
{
	//Mostrar la secuencia
	system("clear");
	cout << "<<<   VECTOR:   >>>" << endl << endl;
	cout << "{ ";
	for(int i=0; i<get_secuencia().size(); i++)
	{
		if(i!=get_secuencia().size()-1)
		{
			cout << get_secuencia()[i].get_valor();
			cout << ", ";
		}
		else
		{
			cout << get_secuencia()[i].get_valor();
		}
	}
	cout << " }" << endl;
	//Fin de mostrar
}

template<class Clave>
void ordenacion_t<Clave>::mostrar_secuencia_ordenada()
{
	//Mostrar la secuencia
	system("clear");
	cout << "<<<\tVECTOR SIN ORDENAR:\t>>>" << endl << endl;
	cout << "{ ";
	for(int i=0; i<get_secuencia().size(); i++)
	{
		if(i!=get_secuencia().size()-1)
		{
			cout << get_secuencia()[i].get_valor();
			cout << ", ";
		}
		else
		{
			cout << get_secuencia()[i].get_valor();
		}
	}
	cout << " }" << endl;
	//Fin de mostrar
	
	//Mostrar la secuencia ordenada
	cout << endl << endl << "<<<\tVECTOR ORDENADO:\t>>>" << endl << endl;
	cout << "{ ";
	for(int i=0; i<secuencia_ordenada_.size(); i++)
	{
		if(i!=secuencia_ordenada_.size()-1)
		{
			cout << secuencia_ordenada_[i].get_valor();
			cout << ", ";
		}
		else
		{
			cout << secuencia_ordenada_[i].get_valor();
		}
	}
	cout << " }" << endl;
	//Fin de mostrar
}

template<class Clave>
void ordenacion_t<Clave>::mostrar_secuencia_ordenada_simple()
{
	//Mostrar la secuencia ordenada
	cout << "{ ";
	for(int i=0; i<secuencia_ordenada_.size(); i++)
	{
		if(i!=secuencia_ordenada_.size()-1)
		{
			cout << secuencia_ordenada_[i].get_valor();
			cout << ", ";
		}
		else
		{
			cout << secuencia_ordenada_[i].get_valor();
		}
	}
	cout << " }" << endl;
	//Fin de mostrar
}

//Modos
//Demostracion
template<class Clave>
void ordenacion_t<Clave>::run_demostracion(void)
{
	system("clear");
	
	modo_ = 1;
	
	int aux;
	int aux2 = 1;
	int aux3 = 1;
	cout << "Indica el tamaño de la secuencia a ordenar:" << endl;
	cin >> aux;
	
	system("clear");
	
	//Creamos la secuencia
	for(unsigned i=0; i<aux; i++)
	{
		dni_t<Clave> aux;
		secuencia_.push_back(aux);
	}
	secuencia_ordenada_=secuencia_;
	//
	
	aux = 999;
	
	cout << "Indica el algoritmo a ejecutar:" << endl << endl << "[1]\tInserción" << endl << "[2]\tSelección" << endl << "[3]\tShellSort" << endl << "[4]\tQuickSort" << endl << "[5]\tMergeSort" << endl;
	cout << "[6]\tBubbleSort" << endl << "[7]\tShakeSort" << endl << "[8]\tRadixSort" << endl << "[9]\tHeapSort" << endl << "[10]\tBinSort" << endl << endl;
	
	while(aux > 10 || aux < 1)
	{
		cin >> aux;
		system("clear");
	}
	
	double alfa_aux;

	switch(aux)
	{
		case 1: ordenarporinsercion(secuencia_ordenada_); break;
		case 2: ordenarporseleccion(secuencia_ordenada_); break;
		case 3: system("clear"); cout << "Valor de Alfa:" << endl; cin >> alfa_aux; ordenarporshellsort(secuencia_ordenada_, alfa_aux); break;
		case 4: ordenarporquicksort(secuencia_ordenada_, 0, secuencia_ordenada_.size()-1, aux3); break;
		case 5: ordenarpormergesort(secuencia_ordenada_,aux2); break;
		case 6: ordenarporbubblesort(secuencia_ordenada_); break;
		case 7: ordenarporshakesort(secuencia_ordenada_); break;
		case 8: ordenarporradixsort(secuencia_ordenada_); break;
		case 9: ordenarporheapsort(secuencia_ordenada_); break;
		case 10: ordenarporbinsort(secuencia_ordenada_); break;
	}
	
	mostrar_secuencia_ordenada();
}

template<class Clave>
void ordenacion_t<Clave>::run_estadisticas(void)
{
	int aux, aux2;	
	int aux3 = 1;
	estadisticas_.reserve(10);
	system("clear");
	
	cout << "Indica el tamaño de la secuencia a ordenar:" << endl;
	cin >> aux;
	system("clear");
	
	cout << "Indica el número de pruebas:" << endl;
	cin >> aux2;
	system("clear");
	
	banco_.reserve(10);
	//Creamos el banco de pruebas
	for(unsigned i=0; i<9; i++)
	{
		banco_[i].reserve(aux2);
		for(unsigned j=0; j<aux2; j++)
		{
			banco_[i][j].reserve(aux);
			for(unsigned k=0; k<aux; k++)
			{
				dni_t<Clave> aux3;
				banco_[i][j].push_back(aux3);
			}
		}
	}
	//
	
	//Ejecutamos los algoritmos
	contador_ = 0;
	for(unsigned i=0; i<aux2; i++)
	{
		ordenarporinsercion(banco_[0][i]);
		actualizar_contador(0);
		ordenarporseleccion(banco_[1][i]);
		actualizar_contador(1);
		ordenarporshellsort(banco_[2][i], 0.45454);
		actualizar_contador(2);
		ordenarporquicksort(banco_[3][i], 0, banco_[3][i].size()-1, aux3);
		actualizar_contador(3);
		ordenarpormergesort(banco_[4][i],aux3);
		actualizar_contador(4);
		ordenarporbubblesort(banco_[5][i]);
		actualizar_contador(5);
		ordenarporshakesort(banco_[6][i]);
		actualizar_contador(6);
		ordenarporradixsort(banco_[7][i]);
		actualizar_contador(7);
		ordenarporheapsort(banco_[8][i]);
		actualizar_contador(8);
		//ordenarporbinsort(banco_[9][i]);
		actualizar_contador(9);
	}
	//
	
	mostrar_estadisticas();

}

template<class Clave>
void ordenacion_t<Clave>::run(void)
{
	int aux, aux2;
	
	system("clear");
	cout << "Indica el modo a ejecutar:" << endl << endl << "[1]\tDemostración" << endl << "[2]\tEstadísticas" << endl << endl;
	
	while(aux > 2 || aux < 1)
	{
		cin >> aux;
		system("clear");
	}
	
	modo_ = aux;
	
	switch(modo_)
	{
		case 1: run_demostracion(); break;
		case 2: run_estadisticas(); break;
	}
}

//

//Ordenar por BinSort
template<class Clave>
int ordenacion_t<Clave>::ordenarporbinsort(vector< dni_t<Clave> >& T)
{
	int i,j, ini, fin, med;
	int vuelta = 1;
	char tc;
	dni_t<Clave> aux;
	
	for(i=1; i<T.size(); i++)
	{
		j = i;
		aux = T[i];
		ini = 0;
		fin = i-1;
		while(ini <= fin)
		{
			med = (int)((ini+fin)/2);
			if(T[med] < aux)
			{
				ini = med+1;
			}
			else
			{
				fin = med-1;
			}
			//Est.
			if(modo_==2)
			{
				contador_++;
			}
			//
		}
		for(j=i-1; j >= ini; j--)
		{
			T[j+1] = T[j];
			//Est.
			if(modo_==2)
			{
				contador_++;
			}
			//
		}
		T[ini] = aux;
		if(modo_==1)
		{
			//Demostracion
			system("clear");
			cout << "Vuelta " << vuelta << ": " << endl;
			cout << "El vector se encuentra así:" << endl;
			mostrar_secuencia_ordenada_simple();
			vuelta++;
			cout << endl << "Pulsa ENTER para continuar...";
			if(i==1) tc = cin.get();
			tc = cin.get();	
			//
		}
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
	
	return 0;
}
//

//Ordenar por HeapSort
template<class Clave>
int ordenacion_t<Clave>::ordenarporheapsort(vector< dni_t<Clave> >& T)
{
	make_heap(T.begin(), T.end());
	sort_heap(T.begin(), T.end());
	//Est.
	if(modo_==2)
	{
		contador_=20;
	}
	//
	
	return 0;
}
//

//Ordenar por RadixSort
template<class Clave>
int ordenacion_t<Clave>::getMax(vector< dni_t<Clave> >& T)
{
	int max = T[0].get_valor();
	for(int i = 1; i<T.size(); i++)
	{
		if(T[i] > max)
		{
			max = T[i].get_valor();
		}
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
	return max;
}

template<class Clave>
void ordenacion_t<Clave>::countSort(vector< dni_t<Clave> >& T, int exp)
{
	int output[T.size()];
	int i, count[10] = {0};
	
	for(i=0; i<T.size(); i++)
	{
		count[(T[i].get_valor()/exp)%10]++;
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
	
	for(i=1; i<10; i++)
	{
		count[i] += count[i-1];
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
	
	for(i = T.size()-1; i>=0; i--)
	{
		output[count[(T[i].get_valor()/exp)%10]-1] = T[i].get_valor();
		count[(T[i].get_valor()/exp)%10]--;
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
	
	for(i=0; i<T.size(); i++)
	{
		T[i] = output[i];
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
}

template<class Clave>
int ordenacion_t<Clave>::ordenarporradixsort(vector< dni_t<Clave> >& T)
{
	int vuelta = 1;
	char tc;
	int m = getMax(T);
	
	for(int exp=1; m/exp > 0; exp*=10)
	{
		countSort(T,exp);
		if(modo_==1)
		{
			//Demostracion
			system("clear");
			cout << "Vuelta " << vuelta << ": " << endl;
			cout << "El vector se encuentra así:" << endl;
			mostrar_secuencia_ordenada_simple();
			vuelta++;
			cout << endl << "Pulsa ENTER para continuar...";
			if(exp==1) tc = cin.get();
			tc = cin.get();	
			//
		}
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
	
	return 0;
}
//

//Ordenar por ShakeSort
template<class Clave>
int ordenacion_t<Clave>::ordenarporshakesort(vector< dni_t<Clave> >& T)
{
	int vuelta = 1;
	char tc;
	
	for(int i=0; i<T.size()/2; i++)
	{
		bool swapped = false;
		for(int j=i; j<T.size()-i-1; j++) //Ida
		{
			if(T[j] > T[j+1])
			{
				dni_t<Clave> tmp = T[j];
				T[j] = T[j+1];
				T[j+1] = tmp;
				swapped = true;
			}
			if(modo_==1)
			{
				//Demostracion
				system("clear");
				cout << "Vuelta " << vuelta << ": " << endl;
				cout << "El vector se encuentra así:" << endl;
				mostrar_secuencia_ordenada_simple();
				vuelta++;
				cout << endl << "Pulsa ENTER para continuar...";
				if(j==i) tc = cin.get();
				tc = cin.get();	
				//
			}
			//Est.
			if(modo_==2)
			{
				contador_++;
			}
			//
		}
		
		for(int j= T.size()-2-i; j>i; j--) //Vuelta
		{
			if(T[j] < T[j-1])
			{
				dni_t<Clave> tmp = T[j];
				T[j] = T[j-1];
				T[j-1] = tmp;
				swapped = true;
			}
			if(modo_==1)
			{
				//Demostracion
				system("clear");
				cout << "Vuelta " << vuelta << ": " << endl;
				cout << "El vector se encuentra así:" << endl;
				mostrar_secuencia_ordenada_simple();
				vuelta++;
				cout << endl << "Pulsa ENTER para continuar...";
				tc = cin.get();	
				//
			}
			//Est.
			if(modo_==2)
			{
				contador_++;
			}
			//
		}
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
		if(!swapped) break; //break si no se han intercambiado elementos (la secuencia ya está ordenada)
	}
	
	return 0;
}
//

//Ordenar por BubbleSort
template<class Clave>
int ordenacion_t<Clave>::ordenarporbubblesort(vector< dni_t<Clave> >& T)
{
	int i,j;
	int vuelta = 1;
	char tc;
	dni_t<Clave> aux;
	
	for(i=0; i<T.size()-1; i++)
	{
		for(j=0; j<T.size()-1-i; j++)
		{
			if(T[j] > T[j+1])
			{
				aux=T[j];
				T[j]=T[j+1];
				T[j+1]=aux;
			}
			//Est.
			if(modo_==2)
			{
				contador_++;
			}
			//
		}
		if(modo_==1)
		{
			//Demostracion
			system("clear");
			cout << "Vuelta " << vuelta << ": " << endl;
			cout << "El vector se encuentra así:" << endl;
			mostrar_secuencia_ordenada_simple();
			vuelta++;
			cout << endl << "Pulsa ENTER para continuar...";
			if(i==0) tc = cin.get();
			tc = cin.get();	
			//
		}
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
	
	return 0;
}
//
//Ordenar por ShellSort
template<class Clave>
int ordenacion_t<Clave>::ordenarporshellsort(vector< dni_t<Clave> >& T, double alfa)
{
	int delta, i, j;
	int vuelta = 1;
	char tc;
	dni_t<Clave> aux;
	
	for(delta = T.size()*alfa; delta>0; delta *= alfa)
	{		
		for(i=delta; i<T.size(); i++)
		{
			for(j=i-delta; j>=0 && T[j]>T[j+delta]; j-=delta)
			{
				aux = T[j];
				T[j] = T[j+delta];
				T[j+delta] = aux;
				//Est.
				if(modo_==2)
				{
					contador_++;
				}
				//
			}
			if(modo_==1)
			{
				//Demostracion
				system("clear");
				cout << "Vuelta " << vuelta << ": " << endl;
				cout << "El vector se encuentra así:" << endl;
				mostrar_secuencia_ordenada_simple();
				vuelta++;
				cout << endl << "Pulsa ENTER para continuar...";
				if(i==delta) tc = cin.get();
				tc = cin.get();	
				//
			}
			//Est.
			if(modo_==2)
			{
				contador_++;
			}
			//
		}
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
	
	return 0;
}
//
//Ordenar por QuickSort
template<class Clave>
int ordenacion_t<Clave>::ordenarporquicksort(vector< dni_t<Clave> >& T, int izq, int der, int& vuelta)
{
	char tc;
	int i = izq;
	int j = der;
	dni_t<Clave> aux;
	int pivote = T[(izq+der)/2].get_valor();
	
	//Particion
	while(i <= j)
	{
		while(T[i].get_valor() < pivote)
		{
			i++;
			//Est.
			if(modo_==2)
			{
				contador_++;
			}
			//
		}
		while(T[j].get_valor() > pivote)
		{
			j--;
			//Est.
			if(modo_==2)
			{
				contador_++;
			}
			//
		}
		if(i <= j)
		{
			aux = T[i];
			T[i] = T[j];
			T[j] = aux;
			i++;
			j--;
		}
		if(modo_==1)
		{
			//Demostracion
			system("clear");
			cout << "Vuelta " << vuelta << ": " << endl;
			cout << "El vector se encuentra así:" << endl;
			mostrar_secuencia_ordenada_simple();
			cout << endl << "Pulsa ENTER para continuar...";
			if(vuelta == 1) tc = cin.get();
			tc = cin.get();	
			vuelta++;
			//
		}
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//	
	}
	//
	
	//Recursividad
	if(izq < j)
	{
		ordenarporquicksort(T, izq, j, vuelta);
	}
	if(i < der)
	{
		ordenarporquicksort(T, i, der, vuelta);
	}
	//
}
//
//Ordenar por seleccion
template<class Clave>
int ordenacion_t<Clave>::ordenarporseleccion(vector< dni_t<Clave> >& T)
{
	int i,j,min;
	int vuelta = 1;
	char tc;
	dni_t<Clave> aux;
	
	for(i=0; i<T.size()-1; i++)
	{
		min=i;
		for(j=i+1; j<T.size(); j++)
		{
			if(T[min] > T[j])
			{
				min=j;
			}
			//Est.
			if(modo_==2)
			{
				contador_++;
			}
			//
		}
		aux=T[min];
		T[min]=T[i];
		T[i]=aux;
		if(modo_==1)
		{
			//Demostracion
			system("clear");
			cout << "Vuelta " << vuelta << ": " << endl;
			cout << "El vector se encuentra así:" << endl;
			mostrar_secuencia_ordenada_simple();
			vuelta++;
			cout << endl << "Pulsa ENTER para continuar...";
			if(i==0) tc = cin.get();
			tc = cin.get();	
			//
		}
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
	
	return 0;
}
//
//Ordenar por insercion
template<class Clave>
int ordenacion_t<Clave>::ordenarporinsercion(vector< dni_t<Clave> >& T)
{
	dni_t<Clave> temp;
	char tc;
	int vuelta = 1;
	int j;
	for(int i=1; i<T.size(); i++)
	{
		temp = T[i];
		j = i-1;
		while( (T[j] > temp) && (j>=0) )
		{
			T[j+1] = T[j];
			j--;
			//Est.
			if(modo_==2)
			{
				contador_++;
			}
			//
		} 
		T[j+1] = temp;
		if(modo_==1)
		{
			//Demostracion
			system("clear");
			cout << "Vuelta " << vuelta << ": " << endl;
			cout << "El vector se encuentra así:" << endl;
			mostrar_secuencia_ordenada_simple();
			vuelta++;
			cout << endl << "Pulsa ENTER para continuar...";
			if(i==1) tc = cin.get();
			tc = cin.get();	
			//	
		}
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
	
	return 0;
}
//
//Merge Sort
template<class Clave>
int ordenacion_t<Clave>::ordenarpormergesort(vector< dni_t<Clave> >& T, int& vm)
{
	char tc;
	
	if(T.empty())
	{
		return -1;
	}
	if(T.size() == 1)
	{
		return 0;
	}
	//
	
	//Subvector U
	vector< dni_t<Clave> > U(T.cbegin(),T.cbegin()+T.size()/2);
	//
	
	//Subvector V
	vector< dni_t<Clave> > V(T.cbegin()+T.size()/2,T.cend());
	//
	
	ordenarpormergesort(U,vm);
	ordenarpormergesort(V,vm);
	
	fusionar(U,V,T,vm);
	
	return 0;
}

template<class Clave>
void ordenacion_t<Clave>::fusionar(vector< dni_t<Clave> > U, vector< dni_t<Clave> > V, vector< dni_t<Clave> >& T, int& vuelta)
{	
	char tc;
	unsigned i = 0;
	unsigned j = 0;
	
	//Centinelas
	dni_t<Clave> aux(9999999999);
	U.push_back(aux);
	V.push_back(aux);
	//
	
	for(unsigned k=0; k<((U.size()-1)+(V.size()-1)); k++)
	{
		if((U[i] < V[j]))
		{
			T[k]=U[i];
			i++;
		}
		else
		{
			T[k] = V[j];
			j++;
		}
		if(modo_==1)
		{
			//Demostracion
			system("clear");
			cout << "Vuelta " << vuelta << ": " << endl;
			cout << "El vector se encuentra así:" << endl;
			mostrar_secuencia_ordenada_simple();
			cout << endl << "Pulsa ENTER para continuar...";
			if(vuelta == 1) tc = cin.get();
			tc = cin.get();	
			vuelta++;
			//	
		}
		//Est.
		if(modo_==2)
		{
			contador_++;
		}
		//
	}
}
//
//
