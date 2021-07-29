#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#ifndef NULL
#define NULL 0
#endif

template <class T>
class Nodo
{
    private:
        T data;
        Nodo<T> *left, *right;

    public:
        Nodo<T>(T d)
        {
              data=d;
              left=right=NULL;
        }

        T getData(){return data;}
        void setData(T t){data=t;}
        Nodo<T> * &getLeft(){return left;}
        void setLeft(Nodo* p){left = p;}
        Nodo<T> * &getRight(){return right;}
        void setRight(Nodo* p){right = p;}
        ~Nodo(){}
};


#endif // NODO_H_INCLUDED

/*
template <class T>
class nodo
{
    private:
        T info;
        nodo<T> *sig;
    
    public:
        nodo(T x,nodo<T> *p=0):info(x),sig(p){};
        T getInfo() {return info;}
        nodo<T> *getSig() {return sig;}
        void setInfo(T i) {info=i;}
        void setSig (nodo<T> *n) {sig=n;}
};
*/

/*//STACK NODE
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

/*
//QUEUE NODE 

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
*/

/*
//Template de lista lineal - NODO
template<typename T>
class Node{
    private:
        T info;
        Node<T> *next;
    
    public:
        Node(){info=0; next=NULL;};
        Node(T data){info=data; next=NULL; };
        Node(T data, Node<T> *n, Node<T> *p){info=data; next=n;};
        void SetInfo(T data){info=data;};
        void SetNext( Node<T> *n){next=n;};
        
        T GetInfo(){return info;};
        Node<T>* GetNext(){return next;};
    
        friend ostream& operator<<( ostream &output, Node<T> &node){output<<"<--->"<<node.GetInfo(); return output;};
};

*/
