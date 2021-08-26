#ifndef _MSET_H_
#define _MSET_H_

#include <cstdlib>

using namespace std;

template<typename T>
class mset {
public:
	mset();
	mset(const mset &);
	mset &operator=(const mset &);
	~mset();

	void add(T const &);
	void del(T const &);
	bool present(T const &) const;
	bool empty() const;
	size_t size() const;

	static mset mset_union(const mset &, const mset &);
	static mset mset_intersect(const mset &, const mset &);
private:
	void expand();
	void contract();

	size_t tos_;
	size_t len_;
	T* ptr_;
};

template<typename T>																															/*IGUAL QUE SET.H*/
mset<T>::mset()
	:tos_(0),
	len_(0),
	ptr_(0)
	{
	}

template<typename T>																														  /*IGUAL QUE SET.H*/
mset<T>::mset(const mset &rhs){
  ptr_ = new T[len_ = rhs.tos_];
  for(tos_ = 0; tos_ < rhs.tos_ ; ++tos_)
    ptr_[tos_] = rhs.ptr_[tos_];
}

template<typename T>																															/*IGUAL QUE SET.H*/
mset<T> &mset<T>::operator=(const mset<T> &rhs){
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

template<typename T>																															/*IGUAL QUE SET.H*/
mset<T>::~mset(){
  delete[] ptr_;
}

template<typename T>																															/*IGUAL QUE SET.H*/
void mset<T>::add(const T &item){
  	if(tos_ >= len_)
			expand();
  	ptr_[tos_++]=item;
}

template<typename T>																															//CON LA IMPLEMENTACION ANTERIOR BORRABA TODAS LAS APARICIONES DE UN ELEMENTO
void mset<T>::del(const T &item){																									//EL TEST EVALUA QUE CADA BORRADO BORRA UNA APARICION DEL ELEMENTO QUE SE
	size_t i = 0;																																		//QUIERE BORRAR, POR ESO ES UN POCO DIFERENTE
	while(i < tos_ && ptr_[i] != item)
		i++;

	if(i < tos_){
		for(size_t j = i; j <tos_-1;j++)
			ptr_[j] = ptr_[j+1];
		tos_--;
		contract();
	}
}

template<typename T>																															/*IGUAL QUE SET.H*/
bool mset<T>::present(const T &item) const{
	for(size_t i = 0; i < tos_; i++)
		if(ptr_[i] == item)
			return true;
	return false;
}

template <typename T>																															/*IGUAL QUE SET.H*/
bool mset<T>::empty() const{
  return tos_ == 0? true:false;
}

template<typename T>																															/*IGUAL QUE SET.H*/
size_t mset<T>::size() const{
  return tos_;
}

template<typename T>
mset<T> mset<T>::mset_union(const mset<T> &s1, const mset<T> &s2){								/*IGUAL QUE LA FUNCION JOIN DE SET.H*/
	mset<T> res;

	res = s1;
	for(size_t i = 0; i < s2.tos_; i++)
		res.add(s2.ptr_[i]);

	return res;
}

template<typename T>
mset<T> mset<T>::mset_intersect(const mset<T> &s1, const mset<T> &s2)							//EL TEST NO VERIFICA SI ESTO ESTA BIEN
{																																									/*ESTA NO ESTABA EN SET.H!!*/
	mset<T> res;

	for(size_t i = 0; i < s1.tos_; i++)
		for(size_t j = 0; j < s2.tos_; j++)
			if(s1.ptr_[i] == s2.ptr_[j])
				res.add(s1.ptr_[i]);

	return res;
}

template<typename T>																															/*FUNCIONES AUXILIARES, ESTÁN DENTRO DEL TEMPLATE STACK.H*/
void mset<T>::expand(){																														/*IGUAL QUE SET.H*/
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
void mset<T>::contract(){
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
