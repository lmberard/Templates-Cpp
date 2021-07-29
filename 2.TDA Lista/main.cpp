#include <iostream>
#include "ClaseListaT.h"
using namespace std;

int main()
{
   lista <int> l1;
   l1.altaprin(5);
   l1.altaprin(6);
   l1.altapos(8,0);
   l1.emite();

   lista <char> l2;
   l2.altaprin('a');
   l2.altaprin('c');
   l2.altapos('h',1);
   l2.emite();

    return 0;
}
