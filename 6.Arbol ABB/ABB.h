#include"Nodo.h"
using namespace std;

#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

template <class T>
class ABB
{
    private:
        Nodo <T> *root;
        void inorden(Nodo<T> *& );
        bool buscar (Nodo<T> *& , T);
        void destruir(Nodo<T>*&);

    public:
        ABB() {root = NULL;};
        ~ABB();
        bool buscar(T);
        void alta(T);
        void inorden();
};

template <class T>
bool ABB <T>::buscar (Nodo<T> *& q, T x)
{
    if (!q)
        { return false;}
    else if (q->getData()==x)
        { return true; }
        else if (x<q->getData())
            {return buscar(q->getLeft(), x);}
            else
                {return buscar (q->getRight(), x);}

}

template <class T>
bool ABB <T>::buscar(T x)
{
    return buscar (root, x);
}

template <class T>
void ABB<T>::inorden(Nodo<T> *& q)
{
    if(q)
    {
        inorden(q->getLeft());
        std::cout<<q->getData()<<endl;
        inorden(q->getRight());
    }

}

template <class T>
void ABB<T>::inorden()
{
    inorden(root);
}

template<class T>
void ABB<T>::alta(T x)
{


 if(!root)
    {
       root= new Nodo<T>(x) ;

     }

 else
 {

  Nodo<T> *aux=root;
  bool listo=false;
  while (!listo)
    {
        if (x< aux->getData())
        {
            if (aux->getLeft())
            {
                aux=aux->getLeft();
            }
            else
            {
                aux->setLeft(new Nodo<T>(x));
                listo=true;
            }
        }

        else
            if (x> aux->getData())
        {
            if (aux->getRight())
            {
                aux=aux->getRight();
            }
            else
            {
                aux->setRight(new Nodo<T>(x));
                listo=true;
            }
        }

        else
          {
              listo=true;
          }
   }

  }
}

template <class T>
void ABB<T>::destruir(Nodo<T>* & q)
{
    if(q)
    {
        destruir(q->getLeft());
        destruir(q->getRight());
        delete (q);
    }

}

template <class T>
ABB<T>::~ABB()
{
    destruir(root);
}

#endif // ABB_H_INCLUDED
