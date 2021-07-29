#include <iostream>
#include <fstream>

using namespace std;

//Una lista doblemente enlazada es una lista lineal en la 
//que cada Node tiene dos enlaces, uno al Node siguiente, 
//y otro al anterior.
template<typename T>
class Node{
    private:
        T info;
        Node<T> *next;
        Node<T> *previous;
    
    public:
        Node(){info=0; next=NULL; previous=NULL;};
        Node(T data){info=data; next=NULL; previous=NULL;};
        Node(T data, Node<T> *n, Node<T> *p){info=data; next=n; previous=p;};
        void SetInfo(T data){info=data;};
        void SetNext( Node<T> *n){next=n;};
        void SetPrevious(Node<T> *p){previous=p;};
        T GetInfo(){return info;};
        Node<T>* GetNext(){return next;};
        Node<T>* GetPrevious(){return previous;};
        friend ostream& operator<<( ostream &output, Node<T> &node){output<<"<--->"<<node.GetInfo(); return output;};
};

template<typename T>
class DoubleList{
    private:

        Node<T>*first;
	    Node<T>*last;
	    size_t size; 
    public:
        DoubleList(){first=0; last=0; size=0;}; // Constructor por defecto
        DoubleList( const DoubleList &orig);    // Constuctor por copia
        ~DoubleList();  // Destructor          

        // Getters:
        Node<T>* GetFirst(){return first;};
        Node<T>* GetLast(){return last;};
        size_t GetSize(){return size;};

        bool empty(){ return first ? false : true; }; //Esta vacia la lista?
        Node<T>* search(const T &data);//Busco un elemento y devuelve el Node
        bool contain(const T &data);//Busco un elemento y devuelve bool si lo encuentra

        void insert(const T &data); //inserta un Node al principio

        void include_position(const T &data, size_t pos); //inserto Node segun su posicion en la lista
        void include_data(const T &t, const T &data); //inserto Node luego de la ocurrencia de data en la lista
        void append(const T &data); //inserta un Node al final
        void eliminate(const T &data);//Elimina Node segun el dato

        void print();

        //friend ostream& operator<<( ostream &output, DoubleList &);
};

template<typename T>
DoubleList<T>::DoubleList( const DoubleList &orig){

    Node<T> *iter;
    Node<T> *ant;

    // Itero sobre la lista original: 
    for(iter=orig.GetFirst(), ant=0; iter!=0; iter=iter->GetNext())
    {
        Node<T> *aux = new Node<T>(iter.GetInfo());
        aux->SetPrevious(ant);
        aux->SetNext(0);

        //Enganco el odo en la lista si no es el primero:
        if( ant!=0)
            ant->SetNext(aux);

        //Si no hay nodo primero en la lista, este sera el recién creado:
        if( first == 0)
            first = aux;
        
        //El último nodo sera el recien creado cuando vuelva a iterar:
        ant=aux;
    }

    //Por ultimo, el ultimo nodo creado sera el nodo final de la lista:
    last=ant;
}

template<typename T>
DoubleList<T>::~DoubleList(){

    // Tomo el primer nodo de la lista mientras halla lista:
    for(Node<T>* aux=first; aux;)
    {
        // Tomo el siguiente nodo de la lista:
        Node<T>* aux_next= aux->GetNext();
        // Destruyo el primer nodo de la lista:
        delete aux;
        // Paso al sigueinte nodo:
        aux = aux_next;
    }

}

template<typename T>
Node<T>* DoubleList<T>::search(const T &data)
{
    Node<T> *iter;

    // Itero sobre la lista hasta encontrar el dato o terminar la lista:
    for( iter=first; iter!=0; iter=iter->GetNext() )
    {
        // Verifico si el nodo tiene la informacion buscada:
        if( data==iter->GetInfo())
            return iter;
    }
    return 0;
}

template<typename T>
bool DoubleList<T>::contain(const T &data)
{
    Node<T> *iter;

    // Itero sobre la lista hasta encontrar el dato o terminar la lista:
    for( iter=first; iter!=0; iter=iter->GetNext() )
    {
        // Verifico si el nodo tiene la informacion buscada:
        if( data==iter->GetInfo())
            return true;
    }
    return false;
}


template<typename T>
void DoubleList<T>::insert(const T &data){
    
    //Creo el nodo con el dato:
    Node<T> *aux = new Node<T>(data);

    //Configuro los punteros del nodo que será el primero:
    aux->SetNext(first);
    // Como todavia no conzco el anterior, debo ver el estado de la lista, lo dejo en 0:
    aux->SetPrevious(0);

    // Si existe la lista, engancho el nodo a la lista como primer elemento:
    if( first )
        first->SetPrevious(aux);
    first=aux;

    // Actualizo el ultimo, porque lo agrego al inicio:
    if( !last )
        last=aux;

    size++;
}

template<typename T>
void DoubleList<T>::include_position(const T &data, size_t pos)
{
    if(size<pos)
        return ;

    Node<T> *iter;
    size_t i;

    // Itero sobre la lista hasta encontrar el dato o terminar la lista:
    for( iter=first, i=0; i<pos; iter=iter->GetNext(), i++);

    // Si encuentro el nodo:
    if(iter)
    {
        // Creo el nodo a agregar:
        Node<T> *aux = new Node<T>(data);

        // Si iter no es el ultimo nodo en la lista, engancho aux como el anterior al proxmo de iter:
        if( iter->GetNext()!=0 )
            iter->GetNext()->SetPrevious(aux);
        
        // Engancho el nuevo nodo entre iter y el siguiente de iter:
        aux->SetNext(iter->GetNext());

        // Engancho aux como siguiente de iter:
        aux->SetPrevious(iter);
        iter->SetNext(aux);

        // Si aux queda como el ultimo de la lista, actualizo last:
        if( last== iter)
            last=aux;
    }

    size++;
}

template<typename T>
void DoubleList<T>::include_data(const T &t, const T &data)
{
    if( contain(data) == false)
        return ;

    Node<T> *iter;

    // Itero sobre la lista hasta encontrar el dato o terminar la lista:
    for( iter=first; iter!=0; iter=iter->GetNext())
        if( iter->GetInfo()==data)
            break;

    // Si encuentro el nodo:
    if(iter)
    {
        // Creo el nodo a agregar:
        Node<T> *aux = new Node<T>(t);

        // Si iter no es el ultimo nodo en la lista, engancho aux como el anterior al proxmo de iter:
        if( iter->GetNext()!=0 )
            iter->GetNext()->SetPrevious(aux);
        
        // Engancho el nuevo nodo entre iter y el siguiente de iter:
        aux->SetNext(iter->GetNext());

        // Engancho aux como siguiente de iter:
        aux->SetPrevious(iter);
        iter->SetNext(aux);

        // Si aux queda como el ultimo de la lista, actualizo last:
        if( last== iter)
            last=aux;
    }

    size++;
}

template<typename T>
void DoubleList<T>::append(const T &data)
{
    //Creo el nodo con el dato:
    Node<T> *aux = new Node<T>(data);

    //Configuro los punteros del nodo que será el ultimo:
    aux->SetNext(0);
    // Como todavia no conzco el anterior, debo ver el estado de la lista, lo dejo en 0:
    aux->SetPrevious(last);

    // Si existe la lista, engancho el nodo a la lista como ultimo elemento:
    if( last )
        last->SetNext(aux);
    last=aux;

    // Actualizo el  primero en caso de no haber lista:
    if( !first )
        first=aux;

    size++;
}

template<typename T>
void DoubleList<T>::eliminate(const T &data)
{
    Node<T> *iter, *sig=0;

    // Recorro la lista:
    for( iter=first; iter!=0; iter=sig)
    {
        sig=iter->GetNext();

        //Si el iterador tiene el dato:
        if( data == iter->GetInfo())
        {
            Node<T>* ant = iter->GetPrevious();
            
            
            if( ant == 0)
                first=sig; // Si el anterior a iter es nulo, entonces corro el inicio de la lista al siguiente:
            else
                ant->SetNext(sig); //Empalmo el sig del anterior (era el iter) con el sig de iter

            if( sig == 0)
                last = ant; //Si el siguiente es nulo, recorto la lista y dejo como el ult al ant del iter
            else
                sig->SetPrevious(ant); // Empalmo el ant del sig (era el iter) al ant del iter.

            delete iter;    // Borro el iter porque ya estan empalmados los nodos
            size --;
        } 
    }
}

template<typename T>
void DoubleList<T>::print()
{
   Node<T>* iter;
    for( iter=first; iter!=0; iter=iter->GetNext() )
    {
        cout<<iter->GetInfo();
    }
    cout<<endl;
}

/*template<typename T>
ostream& operator<<( ostream &output, DoubleList<T> &list)
{
    Node<T>* iter;
    for( iter=list.GetFirst(); iter!=0; iter=iter->GetNext() )
    {
        output<<iter;
    }
    output<<endl;
    return output;
}*/



int main(void)
{
    DoubleList<int> lis;
    Node<int> *nodito;

    lis.append(1);
    lis.append(2);
    lis.append(3);

    cout<<"Termino apend"<<endl;

    lis.print();

    lis.insert(0);
    lis.insert(-1);
    lis.insert(-2);

    cout<<"Termino insert"<<endl;

    lis.print();

    lis.eliminate(-1);
    lis.eliminate(1);

    cout<<"Elimino dos nodos"<<endl;
    lis.print();

    cout<<"Inserto un nodo"<<endl;
    lis.include_position(6,2);
    
    lis.print();

    nodito=lis.search(6);
    cout<<"Node encontrado:"<<nodito->GetInfo()<<endl;

    if( lis.contain(8))
        cout<<"Contiene el valor 8"<<endl;
    else
        cout<<"No contiene el valor 8"<<endl;

    return 0;
}
