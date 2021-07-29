#ifndef _PREORDER_H_
#define _PREORDER_H_

#include <vector>

template<typename T>
bool preorder_search(std::vector<T> const &v, T const &t) {
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

#endif
