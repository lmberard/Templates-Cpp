#ifndef _LIST_H_
#define _LIST_H_

#include <cstdlib>

using namespace std;

template <typename T>
class List{
  public:
    List();
    List(const List &);
    List &operator=(const List &);
    ~List();

    T remove_front();                                                              //ESTOS 4 HABIA QUE PENSAR        
    T remove_back();
    void push_front(const T &);
    void push_back(const T &);

    bool present(const T &) const;

    bool empty() const;
    size_t length() const;

  private:

    class nodo{
      public:
        nodo(T const& t): sig_(0), ant_(0), dato_(t){}
      private:
        friend class List;

        nodo *sig_;
        nodo *ant_;
        T dato_;
    };

    nodo *pri_;
    nodo *ult_;
    size_t tam_;
};

template<typename T>                                                                /*ESTABA EN LISTA.H*/
List<T>::List() : pri_(0), ult_(0), tam_(0)
{
}

template<typename T>                                                                /*ESTABA EN LISTA.H*/
List<T>::List(const List &rhs) : pri_(0), ult_(0), tam_(rhs.tam_){
	nodo *iter;
	nodo *ant;

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
}

template<typename T>                                                                /*ESTABA EN LISTA.H*/
List<T> &List<T>::operator=(const List<T> &rhs){
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
List<T>::~List(){
	for (nodo *p = pri_; p;){
		nodo *q = p->sig_;
		delete p;
		p = q;
	}
}

template<typename T>
T List<T>::remove_front(){
  T dato = pri_->dato_;
  nodo *aux;

  aux = pri_;
  pri_ = pri_->sig_;

  if(pri_)
    pri_->ant_ = 0;
  else
    ult_ = 0;

  delete aux;
  tam_--;
  return dato;
}

template<typename T>
T List<T>::remove_back(){
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
void List<T>::push_front(const T &item){
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

template<typename T>
void List<T>::push_back(const T &item){
 nodo *nuevo = new nodo(item);

 if(empty()){
   pri_ = nuevo;
   ult_ = nuevo;
 }
 else{
  ult_->sig_ = nuevo;
  nuevo->ant_ = ult_;
  ult_ = nuevo;
 }
  tam_++;
}

template<typename T>                                                              /*ESTABA EN LISTA.H*/
bool List<T>::present(const T &item) const
{
	nodo *iter;

	for (iter = pri_; iter != 0; iter = iter->sig_)
		if (item == iter->dato_)
			return true;
	return false;
}

template<typename T>                                                              /*ESTABA EN LISTA.H*/
bool List<T>::empty() const{
	return pri_ ? false : true;
}

template<typename T>                                                              /*ESTABA EN LISTA.H*/
size_t List<T>::length() const{
	return tam_;
}

#endif
