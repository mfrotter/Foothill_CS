// Student ID: 20504093
// Heap.h
//

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <algorithm>
using namespace std;

#ifndef HEAP_H_
#define HEAP_H_

// Notes:
// - T must implement operator<() via get_sentinel<T>)_ { return min_possible }
// - The max size of a heap = capacity - 1 because elem 0 is a sentinel
// - Capacity is simply elems.size() (= max_size + 1)

template <typename T> T get_sentinel();
//{
//   return 0;
//}

template <typename T>
class Heap
{
protected:
   vector<T> _elems;
   size_t _size;
   static const int INIT_HEAP_CAPACITY = 128;

   // private helpers
   bool _percolate_down(size_t pos)
   {
      if(is_empty())
         return false;

      size_t child;
      T tmp;

//      cout << "did we start?" << endl;

      for( tmp = _elems[pos]; 2 * pos <= _size; pos = child )
      {
         child = 2 * pos;
         // if 2 children, get the lesser of the two
         if( child < _size && _elems[child + 1] < _elems[child] )
            child++;
         if( _elems[child] < tmp )
         {
            _elems[pos] = _elems[child];
//            cout << to_string() << endl;
         }
         else
            break;
      }
      _elems[pos] = tmp;

//      cout << to_string() << endl;
      return true;
   }

   bool _heapify()
   {
      if(is_empty())
         return false;

      int k;

      for(k = _size/2; k > 0; k-- )
      {
//         cout << "k is " << k << endl;
         _percolate_down(k);
      }



      return true;
   }

   string _to_string() const
   {
      string line;
      ostringstream ostring;

//      if(is_empty())
//         return "";

      for(size_t i = 1; i < _size; i++)
      {
         if((i * 2) + 1 <= _size)
            ostring << _elems[i] << " : " << _elems[i*2] << " " << _elems[(i*2)+1] << endl;
         else if(i*2 <= _size)
            ostring << _elems[i] << " : " << _elems[i*2] << " -" << endl;
//         else if(i*2 == _size)
//            ostring << _elems[i] << " : - -" << endl;
      }

//      cout << "do we get here" << endl;

      line = ostring.str();
      return line;

   }

public:
   Heap()
   {
      size_t capacity;

      _size = 0;

//      cout << "the size is " << get_size() << endl;

      // choose a capacity that is exactly 2^N - 1 for some N (esthetic)
      // which leads to mCapacity 2^N, internally -- user asks for 127, we
      // reserve 128, if they want 128, we have to reserve 256.
      for (capacity = INIT_HEAP_CAPACITY;
            capacity <= _size;
            capacity = 2 * capacity
         )
      {
         if (capacity < 0)
         {
            capacity = INIT_HEAP_CAPACITY; // give up - overflow
            break;
         }
      }

//      cout << "capacity is " << capacity << endl;
      _elems.resize(capacity);
      _elems[0] = get_sentinel<T>();
   }
   Heap(const vector<T>& vec)
   {
      size_t k;// capacity;


      _size = vec.size();
//      _size = 0;

//      // find the first perfect tree size > items.size() and INIT_CAPACITY
//      for (capacity = INIT_HEAP_CAPACITY;
//         capacity <= _size;
//         capacity = 2 * capacity
//         )
//      {
//         if (capacity < 0)
//            capacity = _size + 1; // give up - overflow, and not perfect
//
//      }
//
//      cout << "capacity is " << capacity;
      _elems.resize(_size+1);
      _elems[0] = get_sentinel<T>();

      // copy starting with position 1 - no ordering yet
      for(k = 0; k < _size; k++ )
         _elems[k+1] = vec[k];

//      cout << "the size is " << _size << endl;
//
//      for(k = 0; k < vec.size(); k++ )
//      {
//         insert(vec[k]);
//      }

//      cout << "the vector prior to heapify looks like this:" << endl;
//      for(size_t i = 1; i < _size+1; i++)
//         cout << _elems[i] << " ";
      //      cout << to_string() << endl;

      cout << endl;

      // order the heap




      _heapify();

//      cout << "the vector after heapify looks like this:" << endl;
//      for(size_t i = 1; i < _size+1; i++)
//         cout << _elems[i] << " ";
//      cout << to_string() << endl;

   }

   virtual bool is_empty() const { return _size == 0; }
   virtual bool insert(const T &elem)
   {
      int hole, capacity;

      if( _size == _elems.size() - 1 )
      {
         capacity = 2 * _elems.size();
         _elems.resize(capacity);
      }

      // percolate up
      hole = ++_size;
      for( ; hole > 1 && elem < _elems[hole/2]; hole /= 2 )
         _elems[hole] = _elems[hole/2];
//      cout << "hole is " << hole << endl;
      _elems[hole] = elem;

      return true;
   }
   virtual bool delete_min()
   {
      if(is_empty())
         return false;

      _elems[1] = _elems[_size];
      _size--;
      _percolate_down(1);

      return true;
   }
   virtual const T &peek_min() const
   {
      if(is_empty())
         return _elems[0];
      else
         return _elems[1];
   }

   virtual string to_string() const
   {
      return "";
      string line;
      ostringstream ostream;
      ostream << "# Heap with min = " << peek_min() << endl;
      ostream << "# size = " << _size << endl;
      ostream << _to_string() << endl;
      ostream << "# End of heap";

      line = ostream.str();
      return line;
   }

   T get_elems(int index)
   {
      return _elems[index];
   }

   size_t get_size()
   {
      return _size;
   }

   friend class Tests; // Don't remove this line
};

#endif /* HEAP_H_ */
