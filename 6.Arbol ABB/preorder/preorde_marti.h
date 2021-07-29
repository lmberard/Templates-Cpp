#ifndef _PREORDER_H_
#define _PREORDER_H_

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

template<typename T>
bool esta_balanceado(vector<T> const &v);

template<typename T>
bool preorder_search(std::vector<T> const &v, T const &t) {

	if(v.empty()) //si el vector está vacio salgo 
		return false;

	if(v[0] == t)// primero pregunto por la raiz
		return true;

	//Ahora voy a comparar el valor de t con la raiz, si es mayor, buscaré en 
	//la mitad superior del arreglo(lo que serua el subarbol derecho). 
	//Si es menor, buscaré en la mitad inferior del arreglo.


	if (!esta_balanceado(v)) 
	{
		for(size_t k = 0; k< v.size();k++){
			if(v[k] == t)
				return true;
		}
	}

	size_t i = 1;
	size_t pivote;
	if(v.size()%2 == 0)
			pivote = v.size()/2;
		else pivote = round(v.size()/2);
	if(t<v[0])
	{
		

		for(; i<= pivote; i++)
		{
			if(v[i] == t)
				return true;
		}
	}
	else if(t>v[0])
	{
		for(i = pivote  ; i<v.size(); i++ )
		{
			if(v[i] == t)
				return true;
		}
	}

	return false;
	//Se podría plantear una función recursiva a la cual le voy pasando particiones del arreglo pero no sé si me va a dar el tiempo para pensarlo bien y codearlo

	// Esta función espera recibir un arreglo de Ts (v) con el
	// recorrido preorden de un árbol binario de búsqueda, y un
	// elemento (t) que puede o no estar presente en el árbol.
	//
	// Usando el recorrido preorden, la función realiza una
	// búsqueda de manera eficiente para determinar el elemento
	// pasado (t) está o no presente en el árbol (v).
	//
	// Es decir, la función retorna true o false en función de
	// la presencia o no de (t) en (v).
	//
	// Ejemplo 1: supongamos el árbol binario de búsqueda que
	// contiene 4 elementos: -1, 4, 6 y 8.
	// 
	//       4     => En este caso, la representación preorder 
	//    -1   6   => del árbol es el vector v = {4, -1, 6, 8}. 
	//           8 => Aquí,
	//
	//  preorder_search(v, 4) debe ser true. En cambio,
	//  preorder_search(v, 0) debe ser false.
	//
	// Ejemplo 2: supongamos el árbol binario de búsqueda que
	// contiene 4 elementos: 1, 2, 3.
	// 
	//       2     => En este caso, la representación preorder 
	//     1   3   => del árbol es el vector v = {2, 1, 3}.
	//
	// De la misma forma, preorder_search(v, 1) es true, pero 
	// preorder_search(v, -1) debe ser false.
#if 0
	// Implementación naïve - uso interno. Este fragmento no será
	// tenido en cuenta como una solución válida, solo se usa por
	// el staff para desarrollar los casos de prueba!
	for (size_t k = 0; k < v.size(); ++k) {
		if (v[k] == t)
			return true;
	}
#endif
	return false;
}

//El nombre de esta funcion no es apropiado, en realidad me dice si tengo rama solo para un lado
template<typename T>
bool esta_balanceado(vector<T> const &v)
{
	if(v[v.size()]<v[0])
		return false;
	return true;
}

#endif
