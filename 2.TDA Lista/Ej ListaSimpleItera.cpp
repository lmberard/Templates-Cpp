
// Agregar en este código los métodos que se pide
// 'Separarlo' en .h el .cpp y main

#include <iostream>
using namespace std;

class nodo
{
private:
int info;
nodo *sig;
public:
nodo(int,nodo *);
int Getinfo() {return info;}
nodo *Getsig() {return sig;}
void Setinfo(int i) {info=i;}
void Setsig (nodo *n) {sig=n;}
};

nodo::nodo(int x,nodo *p=0){info=x; sig=p;}

class lista
{
private:
nodo *p;
public:
lista();             //constructor sin argumentos; (agregar el constructor copia)
~lista();             //destructor
void altafin(int);   // alta al final
void altaprin(int);  //alta al principio
void baja(int);      //baja de la primera aparicion de un elemento determinado
                     // modificarlo para que realice la baja de todas las apariciones
bool esta(int);      // retorna un bool indicando si el entero pasado por argumento está en la lista
void emite();        //emite la lista
};


void lista::altafin(int x)
{
nodo *aux=p;
while ((aux)&&(aux->Getsig()))
aux=aux->Getsig();
if (aux)
{
aux->Setsig(new nodo(x,0));
}
else p=new nodo(x,p);
}

void lista::altaprin(int x)
{
p=new nodo(x,p);
}

void lista::baja(int x)//Elimina la primera aparicion del dato pasado por argumento
{
if (p)
{
if((p->Getinfo()!=x) && (p->Getsig()))
{
nodo *aux1 =p, *aux2 =p->Getsig();
while ((aux2->Getinfo()!=x) && (aux2->Getsig()!=NULL))
{
aux1=aux2 ;
aux2 =aux2->Getsig();
}
if (aux2->Getinfo()==x)
{
aux1->Setsig(aux2->Getsig());

delete aux2;
}
}
else if(p->Getinfo()==x)
{
nodo *aux =p;
p=p->Getsig();
delete aux;
}
}
}
lista::~lista()
{
if (p)
{
nodo *aux=p;
while (aux)
{
p=p->Getsig();
delete aux;
aux=p;
}
}
}
bool lista::esta(int x) 
{
nodo *aux=p;
while(aux)
  {
   if (aux->Getinfo() == x) return true;
                       else aux=aux->Getsig();
  }
  return false;
}
void lista::emite()
{
nodo *aux=p;
while (aux)
{
cout<<aux->Getinfo();
aux=aux->Getsig();
}
}
lista::lista():p(0){}
int main()
{
lista l;
cout<<"\n alta al final de 1\n";
l.altafin(1);
l.emite();
cout<<"\n alta al final de 2\n";
l.altafin(2);
l.emite();
cout<<"\n alta al final de 3\n";
l.altafin(3);
l.emite();
cout<<"\n alta al final de 4\n";
l.altafin(4);
l.emite();
cout<<"\n alta al principio de 5\n";
l.altaprin(5);
l.emite();
cout<<"\n baja 4\n";
l.baja(4);
l.emite();
cout<<"\n baja 1\n";
l.baja(1);
l.emite();
cout<<endl;
system("pause");
return 0;

}
