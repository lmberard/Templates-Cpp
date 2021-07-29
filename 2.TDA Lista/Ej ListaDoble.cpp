// LISTA DOBLE
//un ejemplo simple de lista doble para mostrar el manejo de los punteros

//Se pide a) completar los métodos alta al principio, baja al principio y emitir
//                                 b)Diseñar el template de clase lista Doble en base al este código


#include<iostream>
using namespace std;

class Nodo
{
friend class ListaD ;
public:
Nodo(int v){_info=v;_sig=0;_ant=0;}
private:
int _info;
Nodo  *_sig, *_ant;
};

class ListaD
{
public:
ListaD( ); //constructor
~ListaD( ); //destructor
void AltaPrin (int); //alta al principio
void AltaFin (int); //alta al final
void BajaPrin( ); //borra primer nodo. Escribirla
void BajaFin( ); //borra ultimo nodo
bool Vacia( ) const; //retorna true si lista vacia
void Emitir ( ) const; //emite la lista. Escribirla
private:
Nodo  * _principio;
};

ListaD :: ListaD( ){_principio=0;}

ListaD :: ~ListaD( )
{
Nodo *_aux=_principio;
while ( _principio)
{_principio=_principio->_sig;
delete _aux;
_aux=_principio;
}
}

/*
void ListaD ::AltaPrin (int  _v)
{
 //escribirla
}
*/

void ListaD ::AltaFin (int  _v)
{
Nodo  *_aux1 , *_aux2 ;
_aux1= new Nodo (_v);
_aux1->_info=_v;
_aux1->_sig= 0;
if (Vacia())
{
_principio=_aux1;
_principio->_ant=0;
}
else
{
_aux2=_principio;
while(_aux2->_sig) _aux2=_aux2->_sig;
_aux2->_sig= _aux1;
_aux1->_ant=_aux2;
}
}




void ListaD ::BajaFin ( )
{
Nodo *_aux=_principio;
if (!Vacia( ))
{
if(_principio->_sig == 0)
{
delete _principio;
_principio =0;
}
else
{
while ((_aux->_sig) && (_aux->_sig->_sig)) _aux=_aux->_sig;
delete (_aux->_sig);
_aux->_sig=0;
}
}
}



bool ListaD :: Vacia ( ) const
{
return (_principio ==0);
}
int main()
{
ListaD c1,c2;

c1.AltaFin(5);
// c1.Emitir();

c2.AltaFin(3);
// c2.Emitir();


c1.BajaFin();
// c1.Emitir();
system("pause");
return 0;
}
