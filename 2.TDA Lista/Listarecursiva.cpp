#include <iostream>

using namespace std;
class lista;

class nodo
{
    friend class lista;
    private:
        int info;
        nodo *sig;
    public:
        nodo(int,nodo *);
};

nodo::nodo(int x,nodo *p=0):info(x),sig(p){}

class lista
{
    private:
        nodo *p;
        void altarec(nodo *&,int);
        void bajarec(nodo *&,int);
        void emiterec(nodo *);
        void destruir(nodo * &);
    public:
        lista();
        ~lista();
        void altafin(int);
        void baja(int);
        void emite();
};

void lista::altafin(int x)
{
    altarec(p,x);
}

void lista::baja(int x)
{
    bajarec(p,x);
}

void lista::altarec(nodo * & q,int x)
{
    if (!q) q=new nodo(x,q);
    else altarec(q->sig, x);
}

void lista::emite()
{
    emiterec(p);
}

void lista::emiterec(nodo * q)
{
    if (q)
    {
        cout<<q->info;
        emiterec( q->sig);
    }
}

void lista::bajarec(nodo *& q,int x)
{
    if(q)
    {
        if(q->info==x)
        {
            nodo *a;
            a=q;
            q=q->sig;
            delete a;
            bajarec(q,x);
        }
        else bajarec(q->sig, x);
    }
}

lista::lista():p(0){}

lista::~lista()
{
    if (p)
        destruir(p);
}

void lista::destruir(nodo * &q)
{
    if (q->sig)
    {
        destruir(q->sig);
    }

    nodo *aux=q;
    q=q->sig;
    delete aux;
}

///////////////////////////////////////////////////////////
int main()
{
    lista l;
    cout<<"alta 1\n";
    l.altafin(1);
    l.emite();
    cout<<"alta 2\n";
    l.altafin(2);
    l.emite();
    cout<<"alta 4\n";
    l.altafin(4);
    l.emite();
    cout<<"alta 4\n";
    l.altafin(4);
    l.emite();
    cout<<"baja 4\n";
    l.baja(4);
    l.emite();
    cout<<"baja 1\n";
    l.baja(1);
    l.emite();
    std::cout<<endl;
    system ("pause");
    return 0;
}
