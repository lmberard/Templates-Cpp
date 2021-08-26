#ifndef _STACK_H_
#define _STACK_H_

#include <cstdlib>

using namespace std;

template<typename T>
class set{
public:
	set();
	set(const set &);
	set &operator=(const set &);
	~set();

	void add(T const &);
	void del(T const &);
	bool present(T const &) const;
	bool empty() const;
	size_t size() const;

	static set join(const set &, const set &);
private:
	void expand();
	void contract();

	size_t tos_;
	size_t len_;
	T* ptr_;
};

template<typename T>																															/*CONSTRUCTOR BÁSICO, ESTÁ DENTRO DEL TEMPLATE STACK.H*/
set<T>::set()
	:tos_(0),
	len_(0),
	ptr_(0)
	{
	}

template<typename T>																														  /*CONSTRUCTOR POR COPIA, ESTÁ DENTRO DEL TEMPLATE STACK.H*/
set<T>::set(const set &rhs){
  ptr_ = new T[len_ = rhs.tos_];
  for(tos_ = 0; tos_ < rhs.tos_ ; ++tos_)
    ptr_[tos_] = rhs.ptr_[tos_];
}

template<typename T>																															/*OPERADOR IGUAL, ESTÁ DENTRO DEL TEMPLATE STACK.H*/
set<T> &set<T>::operator=(const set<T> &rhs){
  if(this!= &rhs){
    if(rhs.tos_ > len_){
      delete[] ptr_; len_ = 0;
      ptr_ = new T[len_ = rhs.tos_];
    }
    for(tos_ = 0; tos_ < rhs.tos_;++tos_)
      ptr_[tos_] = rhs.ptr_[tos_];
  }
  return *this;
}

template<typename T>																															/*DESTRUCTOR, ESTÁ DENTRO DEL TEMPLATE STACK.H*/
set<T>::~set(){
  delete[] ptr_;
}

template<typename T>																															/*SE PUEDE IMPLEMENTAR CON UN PUSH, ESTÁ DENTRO DEL TEMPLATE STACK.H*/
void set<T>::add(const T &item){
	if(!present(item)){
  	if(tos_ >= len_)
			expand();
  	ptr_[tos_++]=item;
	}
}

template<typename T>																															//ESTO NO PUEDE SER IMPLEMENTADO CON UN PULL PORQUE TENES QUE SABER
void set<T>::del(const T &item){																									//QUÉ ESTAS SACANDO. HAY QUE PENSAR :$
	for(size_t i = 0; i < tos_; i++)
		if(ptr_[i] == item){
			for(size_t j = i; j <tos_-1;j++)
				ptr_[j] = ptr_[j+1];
			tos_--;
			contract();
		}
}

template<typename T>																															//HAY QUE PENSAR, NO ESTA EN STACK.H PERO ES FACIL
bool set<T>::present(const T &item) const{
	for(size_t i = 0; i < tos_; i++)
		if(ptr_[i] == item)
			return true;
	return false;
}

template <typename T>																															/*SE FIJA SI ESTA VACIO EL SET, ESTÁ DENTRO DEL TEMPLATE STACK.H*/
bool set<T>::empty() const{
  return tos_ == 0? true:false;
}

template<typename T>																															/*SE FIJA EL TAMAÑO DEL SET, ESTÁ DENTRO DEL TEMPLATE STACK.H*/
size_t set<T>::size() const{
  return tos_;
}

template<typename T>																															//LA FIGU DIFICIL, LO QUE ES MUY PARTICULAR SE PUEDE PENSAR COMO
set<T> set<T>::join(const set<T> &s1, const set<T> &s2)														// UN CONJUNTO DE FUNCIONES MAS SIMPLES. EN ESTE CASO OPERADOR IGUAL
{																																									// Y LA FUNCION ADD
	set<T> res;

	res = s1;
	for(size_t i = 0; i < s2.tos_; i++)
		res.add(s2.ptr_[i]);

	return res;
}

template<typename T>																															/*FUNCIONES AUXILIARES, ESTÁN DENTRO DEL TEMPLATE STACK.H*/
void set<T>::expand(){
  size_t len = 1;
  size_t tos;
  T *ptr = 0;

  if(len_ != 0)
    len = len_ + 1;

  ptr = new T[len];

  for(tos = 0; tos < tos_; ++tos)
	  ptr[tos] = ptr_[tos];

  delete[] ptr_;
  tos_ = tos;
  len_ = len;
  ptr_ = ptr;
}

template<typename T>
void set<T>::contract(){
  size_t tos;
  T *ptr = 0;

  if(len_ != 0){
  	ptr = new T[len_ = tos_+1];

  	for(tos = 0; tos < tos_; ++tos)
	  	ptr[tos] = ptr_[tos];

  	delete[] ptr_;
  	tos_ = tos;
  	ptr_ = ptr;
	}
}
#endif
