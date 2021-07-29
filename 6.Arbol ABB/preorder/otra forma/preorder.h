#ifndef _PREORDER_H_
#define _PREORDER_H_

#include <vector>
#include <iostream>
using namespace std;



void print_vect(vector<int> vec){
for(size_t i = 0; i<vec.size()-1; i++){
            cout << vec[i] << ",";
        }
        cout<<endl;
}
template<typename T>
bool wrap_preorder(vector<T> const &v, T const &t, int begin, int end)
	{
		T root = v[begin];

		if(root == t)
			return true;

		if(end-begin <= 2)
		{
			for(int i = begin;i<=end ;i++){
				//cout<<"end - begin = " <<end - begin<< " v[i] = "<<v[i]<<endl;
				if(v[i]==t)
					return true;
			}
			return false;
		}


		//si la root es el valor return true, else si la diferencia entre begin end  = 2, prgunta por esos dos y es true o false
		if(t>root) //busco en la mitad superior 
			return wrap_preorder(v,t,begin + (end-begin)/2+1,end);
		/*{
			begin =begin + (end-begin)/2+1;
			end = end;
		}*/	
			
		else return wrap_preorder(v,t,begin + 1, begin + (end-begin)/2);//busco en mitad inferior 
		/*{
			begin = begin + 1;
			end = begin + (end-begin)/2;
			//cout<<"v[begin] = " <<v[begin]<< "(end-begin)/2 = "<<(end-begin)/2<<endl;
			
		}*/
		

		return false;
	}


template<typename T>
bool preorder_search(vector<T> const &v, T const &t) {

	if(v.empty())
		return false;
	if(v[0] == t)
		return true;
	
	int begin = 0;
	int end = v.size()-1;

	cout<<"busco t= "<<t<<" en: ";
	print_vect(v);

	return wrap_preorder(v,t, begin, end);




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
