#include <iostream>
#include "ABB.h"

using namespace std;

int main()
{
    ABB <int> conj1;
    conj1.alta(4);
    conj1.alta(30);
    conj1.alta(14);
    conj1.alta(500);
    conj1.alta(400);
    conj1.alta(10);
    conj1.alta(14);
    conj1.inorden();

    ABB <char> conj2;
    conj2.alta('f');
    conj2.alta('g');
    conj2.alta('a');
    conj2.alta('m');
    conj2.alta('y');
    conj2.alta('h');
    conj2.alta('b');
    conj2.inorden();




    return 0;
}
