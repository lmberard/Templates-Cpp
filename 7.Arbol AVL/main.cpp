#include <cstdlib>
#include <iostream>
#include "AVL.h"

//Este programa presenta una implementacion muy sencilla de arbol AVL 
//El objetivo es ver como pueden hacerse las rotaciones
// Se le ha agregado métodos para emitir tanto la clave de cada nodo 
//como su factor de balance FB 

using namespace std;


int main()
{   int h;
	arbolAVL<char> t;
	char i;
	std::cout << "Se almacenan datos " << std::endl;
	for (i = i = 'a'; i <= 'h'; ++i)
	t.alta(i);	
    std::cout << "Datos almacenados y FB de cada nodo"<<endl;
    t.EmitirContenido();
	system("pause");
	return 0;
}
