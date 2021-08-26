#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

template<typename T>
class array {
public:
    array();
    array(const array&);
    array const &operator=(const array&);
    ~array();

    T &operator[](size_t);
    T const &operator[](size_t) const;

    void pull_back();
    void pull_back(T &);
    void push_back(T const&);

    size_t resize(size_t);

    size_t length() const;
    bool empty() const;
private:
    // Importante:
    //
    // El soporte para array<> *debe* ser provisto mediante una estructura
    // de nodos simplemente enlazados. No se considerarán otros esquemas de
    // almacenamiento como válidos en este ejercicio.
    //
    // ...

    class nodo{
      private:
        friend class array;

        nodo *sig_;
        size_t index_;
        T dato_;
      public:
        nodo(): sig_(0), index_(0), dato_(0){}
        nodo(T const& t): sig_(0), index_(0), dato_(t){}
    };

    nodo *pri_;
    size_t tam_;
};

template<typename T>                                                                /*ESTABA EN LISTA.H*/
array<T>::array() : pri_(0), tam_(0)
{
}

template<typename T>
array<T>::array(const array &r):pri_(0), tam_(r.tam_){
  if(!r.empty()){
    nodo* p = r.pri_;
    pri_ = new nodo(p->dato_);
    nodo *q = pri_;

    p = p->sig_;

    while(p){
      q->sig_ = new nodo(p->dato_);
      q->index_ = p->index_;
      q = q->sig_;
      p = p->sig_;
    }
  }
}

template<typename T>
array<T>const &array<T>::operator=(array const & r){
  nodo* iter;
  nodo* sig;

  if(this != &r){
    for (iter = pri_; iter != 0; ){
      sig = iter->sig_;
      delete iter;
      iter = sig;
    }

    pri_ = 0;

    for (iter = r.pri_; iter != 0; iter = iter->sig_){
      nodo *nuevo = new nodo(iter->dato_);
      nuevo->index_ = iter->index_;
      if(pri_ == 0){
        pri_ = nuevo;
        sig = pri_;
      }
      if (pri_ != 0){
  			sig->sig_ = nuevo;
        sig = sig->sig_;
      }
    }
    tam_ = r.tam_;
  }
  return *this;
}

template<typename T>
array<T>::~array(){
  for(nodo* p = pri_;p;){
    nodo *q = p->sig_;
    delete p;
    p = q;
  }
}

/**********************************************************************************************/
template<typename T>
T &array<T>::operator[](size_t i)
{

    nodo* iter = pri_;
    while((iter->index_ != i) && iter->sig_)
      iter = iter->sig_;
    if(!iter->sig_ && (iter->index_ != i)){
        nodo* nuevo = new nodo();
        nuevo->index_ = tam_-1;
        iter->sig_ = nuevo;
        tam_++;
        return iter->dato_;
    }
    if(!pri_){
      pri_ = new nodo();
      tam_++;
      return pri_->dato_;
    }
    return iter->dato_;
}

/**********************************************************************************************/

template<typename T>
T const &array<T>::operator[](size_t i) const
{
    nodo* iter = pri_;
    while((iter->index_ != i) && iter)
      iter = iter->sig_;
    return iter->dato_;
}

template<typename T>
void array<T>::pull_back(){
  if(pri_ && !pri_->sig_){
    nodo *iter = pri_;
    delete iter;
    pri_ = 0;
    tam_--;
  }
  if(pri_ && pri_->sig_){
    nodo *iter = pri_;
    nodo *aux = iter->sig_;
    while(aux && aux->sig_){
      iter = iter->sig_;
      aux = aux->sig_;
    }
    delete aux;
    iter->sig_ = 0;
    tam_--;
  }
}

template<typename T>
void array<T>::pull_back(T &t){
  if(pri_ && !pri_->sig_){
    nodo *iter = pri_;
    t = iter->dato_;
    delete iter;
    pri_ = 0;
    tam_--;
  }
  if(pri_ && pri_->sig_){
    nodo *iter = pri_;
    nodo *aux = iter->sig_;
    while(aux && aux->sig_){
      iter = iter->sig_;
      aux = aux->sig_;
    }
    t = aux->dato_;
    delete aux;
    iter->sig_ = 0;
    tam_--;
  }
}

template<typename T>
void array<T>::push_back(T const & t){

  nodo *iter = pri_;
  while(iter && iter->sig_)
    iter = iter->sig_;
  if(iter){
    iter->sig_ = new nodo(t);
    iter->index_ = tam_-1;
  }
  else
    pri_ = new nodo(t);
  tam_++;
}

template<typename T>
size_t array<T>::resize(size_t nsz)
{
    tam_ = nsz;
    return tam_;
}

template<typename T>                                                              /*ESTABA EN LISTA.H*/
size_t array<T>::length() const{
	return tam_;
}

template<typename T>
bool array<T>::empty()const{
  return pri_? false:true;
}

#endif
