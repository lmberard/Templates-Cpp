#include <iostream>
using namespace std;

#ifndef AVL_H_
#define AVL_H_

template <class T>
class arbolAVL
{
	//////////////////////////////////////////////////////////////////////
	private:  
		class NodoAVL 
		{
			public:
				T info;
				int FB;
				NodoAVL *izq, *der, *padre;

				NodoAVL(T k, NodoAVL *p)  
				{
					info=k;
					FB=0;
					padre=p;
					izq=der=NULL;
				}	 
		};
			
		NodoAVL *raiz; 	 

		void reFB(NodoAVL *n) 
		{
			setFB(n);

			if (n->FB == -2) {
				if (altura(n->izq->izq) >= altura(n->izq->der))
				n = rota_der(n);
				else
				n = rot_izq_der(n);
			}
			else if (n->FB == 2) {
				if (altura(n->der->der) >= altura(n->der->izq))
				n = rota_izq(n);
				else
				n = rot_der_izq(n);
			}
			if (n->padre != NULL) {
				reFB(n->padre);
			}
			else {
				raiz = n;
			}
		}

		NodoAVL* rota_izq(NodoAVL *a) 
		{
			NodoAVL *b = a->der;
			b->padre = a->padre;
			a->der = b->izq;

			if (a->der != NULL)
			a->der->padre = a;
			b->izq = a;
			a->padre = b;

			if (b->padre != NULL) 
			{
				if (b->padre->der == a) 
				{
					b->padre->der = b;
				}
				else 
				{
					b->padre->izq = b;
				}
			}
			setFB(a);
			setFB(b);
			return b;
		}

		NodoAVL* rota_der(NodoAVL *a)
		{
			NodoAVL *b = a->izq;
			b->padre = a->padre;
			a->izq = b->der;
			if (a->izq != NULL)
			a->izq->padre = a;
			b->der = a;
			a->padre = b;
			
			if (b->padre != NULL) 
			{
				if (b->padre->der == a)
				{
					b->padre->der = b;
				}
				else 
				{
					b->padre->izq = b;
				}
			}
			
			setFB(a);
			setFB(b);
			return b;
		}

		NodoAVL* rot_izq_der(NodoAVL *n)
		{
			n->izq = rota_izq(n->izq);
			return rota_der(n);
		}

		NodoAVL* rot_der_izq(NodoAVL *n)
		{
			n->der = rota_der(n->der);
			return rota_izq(n);
		}

		int altura(NodoAVL *n)
		{
			if (n == NULL)
			return -1;
			return 1 + std::max(altura(n->izq), altura(n->der));
		}

		void setFB(NodoAVL *n)
		{
			n->FB = altura(n->der) - altura(n->izq);
		}

		void EmitirContenidoRec(NodoAVL *n)
		{
			if (n) 
			{
				EmitirContenidoRec(n->izq);
				
				cout<< (n-> info) <<"   "<< n->FB << endl;
				
				EmitirContenidoRec(n->der);
			}
		}


	//////////////////////////////////////////////////////////////////////
	public:
			
		arbolAVL() {raiz=NULL;}

		~arbolAVL()
		{
			delete raiz;
		}

		bool alta(T info)
		{
			if (raiz == NULL) 
			{
				raiz = new NodoAVL(info, NULL);
			}
			else 
			{
				NodoAVL *n = raiz,*padre;
				while (true) 
				{
					if (n->info == info)
					return false;
					padre = n;
					bool goizq = n->info > info;
					n = goizq ? n->izq : n->der;
					if (n == NULL) 
					{
						if (goizq) 
						{
							padre->izq = new NodoAVL(info, padre);
						}
						else 
						{
							padre->der = new NodoAVL(info, padre);
						}
						reFB(padre);
						break;
					}
				}
			}

			return true;
		}

		void borrar(const T dato_a_borrar)
		{
			if (!raiz)
			return;

			NodoAVL	*n = raiz,*padre  = raiz,*delNode = NULL,*child   = raiz;

			while (child != NULL)
			{
				padre = n;
				n = child;
				child = dato_a_borrar >= n->info ? n->der : n->izq;
				if (dato_a_borrar == n->info)
				delNode = n;
			}

			if (delNode != NULL) 
			{
				delNode->info = n->info;

				child = n->izq != NULL ? n->izq : n->der;

				if (raiz->info == dato_a_borrar) 
				{
					raiz = child;
				}
				else 
				{
					if (padre->izq == n) {
						padre->izq = child;
				}
					else 
					{
						padre->der = child;
					}

					reFB(padre);
			}
			}
		}

		void EmitirContenido() 
		{
			EmitirContenidoRec(raiz);
			std::cout << std::endl;
		}

};

#endif //AVL_H_
