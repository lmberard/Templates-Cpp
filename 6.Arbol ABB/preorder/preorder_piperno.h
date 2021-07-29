#ifndef _PREORDER_H_
#define _PREORDER_H_

#include <vector>
#include<iostream>
using namespace std;

// devuelve la posicion del ulltimo elemento del subarbol izquierdo, si no hay subarbol izquierdo devuelve 0 (es O(log(n)) análogamente a busqueda binaria)
template<typename T>
std::size_t	find_separation(std::vector<T> const &v, std::size_t first, std::size_t last)
{
	if(v.size()<=1)
		return 0;

	if(first >= last){
		if(v[0] < v[first]) //quiero devolver siempre el final del subarbol izquierdo (para que sea consistente), y si no existe devuelvo la posición de la raíz
			return first-1;
		else
			return first;
	}

	std::size_t middle = (last-first)/2 + first;
	if(v[0] < v[middle])
		return find_separation(v, first, middle);
	else
		return find_separation(v, middle+1, last);
}

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

	//caso base 1 (si el vector está vacío devuelvo )
	if(v.size() == 0)
	{
		return false;
	}

	//caso base 2 (si la raíz es el elemento, devuelvo true)
	if(v[0] == t)
		return true;

	std::size_t separation = find_separation(v,1,v.size()-1);

	if(v[0] > t){
		std::vector<T> aux(v.begin()+1, v.begin()+separation+1); // si el buscado es menor a la raíz, me quedo con el subarbol izquierdo (en caso de que no haya subarbol izquierdo va a crear un array de tamaño 0)
		return preorder_search(aux,t);
	}
	else{
		std::vector<T> aux(v.begin()+separation+1, v.end()); // si el buscado es mayor a la raíz me quedo con el subarbol derecho (es O(n)) (si no hay, crea un array de tamaño 0)
		return preorder_search(aux,t);
	}


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

//el algoritmo se repite log(n) veces analogamente a la busqueda en un arbol binario, pero en cada iteración hace un slice del vector que es de O(n), y además busca la separación que es O(logn)
//entonces me queda O(log(n))*(O(n)+O(log(n)) que pertenece a O(nlog(n))