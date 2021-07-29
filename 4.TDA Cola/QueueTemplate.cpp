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

template <class T>
class queue{
    private:
        nodo<T>* pqueue;
    public:
        //Constructor/Destructor
        queue(){pqueue=NULL;}
        ~queue();

        //Getters/setters
        void setpqueue(nodo<T>*data){pqueue=data;}
        nodo<T>* getqueue(){return pqueue;}

        //Metodos:
        void enqueue(T data);
        void dequeue();
        bool isempty() const;
        void print() const;
        T tail();
};

//Informa si la cola esta vacia:
template <class T> 
bool queue<T>::isempty() const
{   
    if(pqueue) 
        return false; 
    else return true;
}

//Elimino la cola
template <class T> 
queue<T>::~queue(){
    if(!isempty()){
        nodo<T> *aux=pqueue;
        while(aux){
            pqueue=pqueue->getnext();
            delete aux;
            aux=pqueue;
        }
    }
}

//Ingresa un nodo al pricipio de la lisa:
template <class T> 
void queue<T>::enqueue(T data)
{
    if(isempty())
    {
        nodo<T> *aux=new nodo<T>(data);
        aux->setnext(NULL);
        pqueue=aux;
        return;
    }

    nodo<T> *aux=new nodo<T>(data);
    aux->setnext(pqueue);
    pqueue=aux;
}

//Elimino los elementos en la cola de la lista:
template <class T> 
void queue<T>::dequeue()
{
    if(!isempty())
    {
        nodo<T> *aux=pqueue;
        nodo<T> *last;

        //Recorro hasta el final de la lista
        while((aux->getnext())&&(aux->getnext()->getnext())) 
            {aux=aux->getnext();}

        if(aux)
        {
           last=aux->getnext();
           aux->setnext(0);
           delete last;
        }
    }
}

template <class T> 
T queue<T>::tail()
{
    if(!isempty())
    {
        nodo<T> *aux=pqueue;
        nodo<T> *last;

        while((aux)&&(aux->getnext())) //Recorro hasta el final de la lista
            {aux=aux->getnext();}

        if(aux)
        {
           return aux->getinfo();
        }
    }
}

template <class T> 
void queue<T>::print() const
{
    nodo<T> *aux=pqueue;
    while(aux)
    {
        std::cout<<aux->getinfo()<<std::endl;
        cout<<"------"<<std::endl;
        aux=aux->getnext();
    }
}

int main(){
    queue<int> cola;

    cola.enqueue(1);
    cola.enqueue(2);
    cola.enqueue(3);

    cola.print();

    cout<<"Termino de ingresar elementos"<<endl;

    cola.dequeue();
    cola.dequeue();

    cola.print();

    return 0;
}