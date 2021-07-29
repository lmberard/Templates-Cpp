#include <iostream>
#include <fstream>

using namespace std;

//Template de lista lineal
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

template<typename T>
class List{
    private:

        Node<T>*first;
	    size_t size; 

    public:
        List(){first=0; size=0;}; // Constructor por defecto
        List( const List &orig);    // Constuctor por copia
        ~List();  // Destructor          

        // Getters:
        Node<T>* GetFirst(){return first;};
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

        //friend ostream& operator<<( ostream &output, List &);
};

template<typename T>
List<T>::List( const List &orig){

    Node<T> *iter;
    Node<T> *ant;

    // Itero sobre la lista original: 
    for(iter=orig.GetFirst(), ant=0; iter!=0; iter=iter->GetNext())
    {
        Node<T> *aux = new Node<T>(iter.GetInfo());
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
}

template<typename T>
List<T>::~List(){

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
Node<T>* List<T>::search(const T &data)
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
bool List<T>::contain(const T &data)
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
void List<T>::insert(const T &data){
    
    //Creo el nodo con el dato:
    Node<T> *aux = new Node<T>(data);

    //Configuro los punteros del nodo que será el primero:
    aux->SetNext(first);

    first=aux;

    size++;
}

template<typename T>
void List<T>::include_position(const T &data, size_t pos)
{
    if(pos==0)
    {
        insert(data);
    }
    else{
        Node<T> *aux1=first->GetNext();
        Node<T> *aux2;
        size_t count=1;
        while(((aux1)&&(aux1->GetNext()))&&(count<pos-1))
        {
            aux1=aux1->GetNext();
            count++;
        }
        if(aux1)
        {
            aux2=new Node<T>(data);
            aux2->SetNext(aux1->GetNext());
            aux1->SetNext(aux2);
            size++;
        }
        else{
            append(data);
        }
    }
    size++;
}

template<typename T>
void List<T>::include_data(const T &t, const T &data)
{

    Node<T> *aux1=first->GetNext();
    Node<T> *aux2;
    while(((aux1)&&(aux1->GetNext())))
    {
        if(aux1->GetInfo()==data)
            break;
        aux1=aux1->GetNext();
    }
    if(aux1)
    {
        aux2=new Node<T>(t);
        aux2->SetNext(aux1->GetNext());
        aux1->SetNext(aux2);
        size++;
    }
    else{
        append(t);
    }
    
}

template<typename T>
void List<T>::append(const T &data)
{
    // Si existe la lista, engancho el nodo a la lista como ultimo elemento:
    if( first )
    {
        Node<T> *aux1=first->GetNext();
        Node<T> *aux2;
        while(((aux1)&&(aux1->GetNext())))
        {
            aux1=aux1->GetNext();
        }
        if(aux1)
        {
            aux2=new Node<T>(data);
            aux2->SetNext(aux1->GetNext());
            aux1->SetNext(aux2);
            size++;
        }
    }
    else
    {
        insert(data);
    }
}

template<typename T>
void List<T>::eliminate(const T &data)
{
    Node<T> *iter, *iter_next, *sig=0;

    // Recorro la lista:
    for( iter=first; iter_next!=0 && iter!=0; iter_next=sig)
    {
        sig=iter_next->GetNext();

        //Si el iterador tiene el dato:
        if( data == iter_next->GetInfo())
        {
            Node<T>* ant = iter;
            
            if( ant == 0)
                first=sig; // Si el anterior a iter es nulo, entonces corro el inicio de la lista al siguiente:
            else
                ant->SetNext(sig); //Empalmo el sig del anterior (era el iter) con el sig de iter

            delete iter;    // Borro el iter porque ya estan empalmados los nodos
            size --;
        } 
    }
}

template<typename T>
void List<T>::print()
{
   Node<T>* iter;
    for( iter=first; iter!=0; iter=iter->GetNext() )
    {
        cout<<iter->GetInfo();
    }
    cout<<endl;
}

/*template<typename T>
ostream& operator<<( ostream &output, List<T> &list)
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
    List<int> lis;
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
