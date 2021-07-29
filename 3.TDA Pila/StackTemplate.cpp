#include <iostream>

using namespace std;

template <class T>
class nodo{
    private:
        T info;
        nodo<T>* next;
    
    public:
        nodo(T data, nodo<T>*sig=0){info=data; next=sig;}
        T getinfo(){return info;}
        nodo<T>* getnext(){return next;}
        void setinfo(T data){info=data;}
        void setnext(nodo<T>*sig){next=sig;}
};

template<typename T>
class stack {
private:
	nodo<T> *pstack;
    size_t size;

public:
	stack();
	stack(const stack &);
	stack &operator=(const stack &);
	~stack();

    nodo<T>* getpstack(){return pstack;}
    size_t getsize(){return size;}

	void pop();
	void pop(T &);
	void push(const T &);
	bool empty() const;
	size_t length() const;
	T top();
    void print() const;

};

template<typename T>
stack<T>::stack() 
{
	pstack=NULL;
	size=0;
}

template<typename T>
stack<T>::stack(const stack &st)
{
	pstack=st.getpstack();
}

template<typename T>
stack<T> &stack<T>::operator=(const stack<T> &rhs)
{
	if(!pstack && !rhs.empty()){
		stack<T> copy=rhs;
		while(!copy.empty())
		{
			nodo<T> *aux=new nodo<T>(copy.top());
    		aux->setnext(pstack);
    		pstack=aux;
    		size++;
			copy.pop();
		}
	}
	return *this;
}

template<typename T>
stack<T>::~stack()
{
	if(pstack)
    {
        nodo<T> *aux=pstack;

        while(aux)
        {
            pstack=pstack->getnext();
            delete aux;
            size--;
            aux=pstack;
        }
    }
}

template<typename T>
void stack<T>::pop()
{
	if(pstack)
    {
        nodo<T> *aux=pstack;
        pstack=pstack->getnext();
        delete aux;
        size--;
    }  
}

template <class T> T stack<T>::top()
{
    return pstack->getinfo();
}

template<typename T>
void stack<T>::pop(T &ref)
{
	if(pstack)
    {
        if((pstack->getinfo()!=ref)&&(pstack->getnext()))
        {
            
            nodo<T> *aux1=pstack, *aux2=pstack->getnext();
            while((aux2->getinfo()!=ref)&&(aux2->getnext()!=NULL))
            {
                aux1=aux2;
                aux2=aux2->getnext();
            }
 
            if(aux2->getinfo()==ref)
            {   
                aux1->setnext(aux2->getnext());
                size--;
                delete aux2; 
            }
        }
        else if(pstack->getinfo()==ref)
        {
            nodo<T> *aux=pstack;
            pstack=pstack->getnext();
            size--;
            delete aux;
        }
    }
}

template<typename T>
void stack<T>::push(const T &top)
{
	if(!pstack)
    {
        nodo<T> *aux=new nodo<T>(top);
        aux->setnext(pstack);
        pstack=aux;
        size++;
        return;
    }

    nodo<T> *aux=new nodo<T>(top);
    aux->setnext(pstack);
    pstack=aux;
    size++;
}

template<typename T>
bool stack<T>::empty() const
{
	if(pstack)
		return false;
	else return true;
}

template<typename T>
size_t stack<T>::length() const
{
	if(pstack)
	{
		return size;
	}
	return 0;
}

template <class T> 
void stack<T>::print() const
{
    nodo<T> *aux=pstack;
    while(aux)
    {
        cout<<aux->getinfo()<<endl;
        cout<<"------"<<endl;
        aux=aux->getnext();
    }
}

int main()
{
    stack<int> st;

    st.push(1);
    st.print();
    st.push(2);
    st.print();
    st.push(3);
    st.print();
    st.push(4);
    st.print();

    st.pop();
    st.print();

    return 0;
}