// Student ID: 20504093
// Special_Heap.h
//

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <algorithm>
using namespace std;

#include "Heap.h"

#ifndef SPECIAL_HEAP_H_
#define SPECIAL_HEAP_H_

// This is a sub-class of heap that provides a single method called
// get_k_smallest(size_t k), which has a worst performance of O(k log N)

template <typename T>
class Special_Heap : public Heap<T>
{
public:
   Special_Heap() :Heap<T>() {};
   Special_Heap(const vector<T> &vec) : Heap<T>(vec) {}

   const vector<T> &get_least_k(size_t k)
   {
      T temp;

      if(k > Heap<T>::_size)
         return Heap<T>::_elems;

      for(size_t i = 0; i < k; i++)
      {
         temp = Heap<T>::peek_min();
         Heap<T>::delete_min();
         Heap<T>::_elems[Heap<T>::_size + 1] = temp;
      }

//      cout << Heap<T>::to_string();

      Heap<T>::_size = 0;



      return Heap<T>::_elems;
   }

   friend class Tests; // Don't remove this line
};

#endif /* SPECIAL_HEAP_H_ */
