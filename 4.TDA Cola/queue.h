#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <cassert>
#include <cstdlib>

template<typename T>
class queue {
public:
    queue();
    queue(const queue &);
    queue &operator=(const queue &);
    ~queue();

    T pop();
    void pop(T &);
    void push(const T &);
    bool empty() const;
    size_t length() const;
private:
  class nodo{
    public:
      nodo(T const& t): sig_(0), ant_(0), dato_(t){}
    private:
      friend class queue;

      nodo *sig_;
      nodo *ant_;
      T dato_;
  };

  nodo *pri_;
  nodo *ult_;
  size_t tam_;
};

template<typename T>                                                                /*ESTABA EN LISTA.H*/
queue<T>::queue() : pri_(0), ult_(0), tam_(0)
{
}

template<typename T>                                                                /*ESTABA EN LISTA.H*/
queue<T>::queue(const queue &q) : pri_(0), ult_(0), tam_(q.tam_){
	nodo *iter;
	nodo *ant;

	for (iter = q.pri_, ant = 0; iter != 0; iter = iter->sig_){

		nodo *nuevo = new nodo(iter->dato_);
		nuevo->ant_ = ant;
		nuevo->sig_ = 0;

		if (ant != 0)
			ant->sig_ = nuevo;
		if (pri_ == 0)
			pri_ = nuevo;
		ant = nuevo;
	}
	ult_ = ant;
}

template<typename T>                                                                /*ESTABA EN LISTA.H*/
queue<T> &queue<T>::operator=(const queue<T> &rhs){
	nodo *iter;
	nodo *sig;
	nodo *ant;

	if (this != &rhs){
		for (iter = pri_; iter != 0; ){
			sig = iter->sig_;
			delete iter;
			iter = sig;
		}

		pri_ = 0;
		ult_ = 0;

		for (iter = rhs.pri_, ant = 0; iter != 0; iter = iter->sig_){
			nodo *nuevo = new nodo(iter->dato_);
			nuevo->ant_ = ant;
			nuevo->sig_ = 0;
			if (ant != 0)
				ant->sig_ = nuevo;
			if (pri_ == 0)
				pri_ = nuevo;
			ant = nuevo;
		}
		ult_ = ant;
		tam_ = rhs.tam_;
	}

	return *this;
}

template<typename T>                                                                 /*ESTABA EN LISTA.H*/
queue<T>::~queue(){
	for (nodo *p = pri_; p;){
		nodo *q = p->sig_;
		delete p;
		p = q;
	}
}

template<typename T>
T queue<T>::pop(){
    T dato = ult_->dato_;
    nodo *aux;

    aux = ult_;
    ult_ = ult_->ant_;

    if(ult_)
      ult_->sig_ = 0;
    else
      pri_ = 0;

    delete aux;
    tam_--;
    return dato;
}

template<typename T>
void queue<T>::pop(T &top)
{
  top = ult_->dato_;
  nodo *aux;

  aux = ult_;
  ult_ = ult_->ant_;

  if(ult_)
    ult_->sig_ = 0;
  else
    pri_ = 0;

  delete aux;
  tam_--;
}

template<typename T>
void queue<T>::push(const T &item){
  nodo *nuevo = new nodo(item);

  if(empty()){
    pri_ = nuevo;
    ult_ = nuevo;
  }
  else{
   pri_->ant_ = nuevo;
   nuevo->sig_ = pri_;
   pri_ = nuevo;
  }
   tam_++;
}

template<typename T>                                                              /*ESTABA EN LISTA.H*/
bool queue<T>::empty() const{
	return pri_ ? false : true;
}

template<typename T>                                                              /*ESTABA EN LISTA.H*/
size_t queue<T>::length() const{
	return tam_;
}

#endif
