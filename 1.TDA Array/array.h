#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>
#include <cstdlib>

#define DEFAULT_SIZE 2
#include <iostream>
using namespace std;



template<typename T>
class array {
public:
    array();

    array(const array&);
    array const &operator=(const array&);
    ~array();
    T &operator[](std::size_t);
    T const &operator[](std::size_t) const;
    void pull_back();
    void pull_back(T &);
    void push_back(T const&);
    std::size_t resize(std::size_t);
    std::size_t length() const;
    bool empty() const;


    size_t size;
    T *data;

};
template<class T>
void print(array<T> arr);

template<typename T>
array<T>::array()
{
	data = NULL;
	size = 0;
}

template<typename T>
array<T>::array(const array &r)
{
	size = r.size;
	data = new T [r.size]; //pido memoria para el nuevo que voy a copiar
	for (size_t i = 0; i<size; i++) //copio
		data[i] = r.data[i];
}

template<typename T>
array<T> const &array<T>::operator=(const array<T> &r) //operador asignación
{
	size = r.size;
	data = new T [r.size];

	for(size_t i = 0; i<size; i++)
			data[i]=r.data[i];
    return *this;
}

template<typename T>
array<T>::~array()
{
	delete []data;
	size = 0;
}

template<typename T>
T &array<T>::operator[](std::size_t i)
{
    //static T t;
    return data[i];
}

template<typename T>
T const &array<T>::operator[](std::size_t i) const
{
    //static T t;
    //return t;
	return data[i];
}

template<typename T>
void array<T>::pull_back()
{
	size = resize(size-1);
}

template<typename T>
void array<T>::pull_back(T &t)
{
	t = data [size];
	size = resize(size-1);
}

template<typename T>
void array<T>::push_back(T const &t)
{
	size = resize (size+1);
	data[size-1] = t;
}

template<typename T>
std::size_t array<T>::resize(std::size_t nsz)
{
	if(nsz != size)
	{
		T *aux = new T[nsz];
		if(nsz < size)
			size = nsz;

		for (size_t i = 0; i<size; i++)
			aux[i]=data[i];
		delete []data;
		data = aux;
		size = nsz;
	}	

    return size;
}

template<typename T>
std::size_t array<T>::length() const
{
	//cout << "len = "<< size<<endl;
	if(empty())
		return 0;
	else
    return (int) size;
}

template<typename T>
bool array<T>::empty() const
{
	if(size == 0 || data == NULL)
    	return true;
    else return false;
}



template<class T>
void print(array<T> arr)
{
	cout << "El arreglo contiene: ";
    for (size_t i = 0; i<arr.size; i++)
        cout<< arr.data[i]<< ",";
    cout<<endl;
}
#endif
