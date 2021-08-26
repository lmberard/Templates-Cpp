#ifndef _PREORDER_H_
#define _PREORDER_H_

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
bool preorder_search(std::vector<T> const &v, T const &t){

  if(v.empty())
    return false;
  if(v[0]==t)
    return true;
  if(v.size()==1)
    return false;
 
  size_t m = v.size()/2;
  std::vector<T> sub_izq;
  std::vector<T> sub_der;

  if(v[m]<v[0]){
    sub_izq = {v.begin()+1, v.begin()+m+1};
    sub_der = {v.begin()+m+1,v.end()};
  }
  else{
    sub_izq = {v.begin()+1, v.begin()+m};
    sub_der = {v.begin()+m,v.end()};
  }

  if(v[0] < t)
    return preorder_search(sub_der,t);
  return preorder_search(sub_izq,t);
}

#endif
