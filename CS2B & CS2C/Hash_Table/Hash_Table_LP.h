// Student ID: 20504093
// Hash_Table_LP.h
//

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <algorithm>
using namespace std;

#ifndef HASH_TABLE_LP_H_
#define HASH_TABLE_LP_H_

template <typename T> size_t Hash(const T &item)
{
         unsigned int k, retVal = 0;

         for(k = 0; k < item.length( ); k++ )
             retVal = 37 * retVal + item[k];

         //cout << retVal % _elems.size() << endl;


         return retVal;
}

template <typename T>
class Hash_Table_LP
{
   //friend class Hash_Table_QP;
protected:
   struct Entry {
      T _data; // payload
      enum STATE { ACTIVE, VACANT, DELETED } _state;
      Entry(const T &d = T(), STATE st = VACANT) : _data(d), _state(st) {}
   };

   static const size_t DEFAULT_INIT_CAPACITY = 3;
   vector<Entry> _elems;
   size_t _size;                    // doesn't count deleted elems
   size_t _num_non_vacant_cells;    // does
   float _max_load_factor;

   virtual size_t _get_hash_modulus(const T &item) const // uses Hash(item), ext.
   {
//      unsigned int k, retVal = 0;
//
//      for(k = 0; k < item.length( ); k++ )
//          retVal = 37 * retVal + item[k];
//
//      //cout << retVal % _elems.size() << endl;
//
//
//      return retVal % _elems.size();

      return Hash<T>(item) % _elems.size();
   }
   virtual void _rehash()
   {
     if(_elems.size() == 0)
        return;

      vector<Entry> elemsCopy = _elems;
      size_t oldTableSize = _elems.size();
      _grow_capacity();

      for(size_t i = 0; i < _elems.size(); i++ )
      {
         _elems[i]._state = Entry::VACANT;
      }

      _size = _num_non_vacant_cells = 0;
      for(size_t i = 0; i < oldTableSize; i++)
      {
         if(elemsCopy[i]._state == Entry::ACTIVE)
            insert( elemsCopy[i]._data);
      }


//      for(size_t i = 0; i < _elems.size();i++)
//      {
//         if(_elems[i]._state == Entry::ACTIVE)
//         {
//            elemsCopy.push_back(_elems[i]);
//         }
//         _elems[i]._state = Entry::VACANT;
//      }
   }

   // Most common overrides
   virtual bool set_max_load_factor(float x)
   {
      if(x > _get_biggest_allowed_max_load_factor() || x <= 0)
         return false;

      else
      {
         _max_load_factor = x;
         return true;
      }
   }
   virtual float _get_biggest_allowed_max_load_factor() const
   {
      float maxloadFactor = 0.75;
      return maxloadFactor;
   }
   virtual size_t _find_pos(const T &item) const
   {
      size_t findPos =_get_hash_modulus(item);
      size_t count = 0;
      //int pos = -1;
      if ( findPos >= _elems.size() )
         findPos -= _elems.size();

      cout << "elem size is " << _elems.size() << endl;
//      cout << "findPos is " << findPos << endl;

      while ( _elems[findPos]._state != Entry::VACANT
         && _elems[findPos]._data != item )
      {
         findPos += 1;
         if ( findPos >= _elems.size() )
            findPos -= _elems.size();
         count++;
         if(count > _elems.size())
         {
//            cout << "ran out of space" << endl;
            return string::npos;
         }
      }

      return findPos;

//      for(size_t i = 0; i < _elems.size(); i++)
//      {
//         if(_elems[i]._state == Entry::VACANT)
//            pos = i;
//
//         if(_elems[i]._data == item)
//            return i;
//      }
//
//      if(pos != -1)
//         return pos;
//
//      return string::npos;
   }
   virtual void _grow_capacity()
   {
      size_t newTableSize = _elems.size() * 2;
      _elems.resize(newTableSize);
   }

public:
   Hash_Table_LP(size_t n = DEFAULT_INIT_CAPACITY)
   {
      if(n <= 0)
         n = DEFAULT_INIT_CAPACITY;
      _elems.resize(n);
      _size = 0;
      _num_non_vacant_cells = 0;
      set_max_load_factor(_get_biggest_allowed_max_load_factor());
   }
   size_t get_size() const { return _size; }
   bool is_empty() const { return _size == 0; }
   bool contains(const T &item)
   {
//      if(is_empty())
//         return false;

      if(find(item) == item)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   T &find(const T &item)
   {
      try
      {
         if(is_empty())
         {
            throw Not_found_exception();
         }

         size_t findPos = _find_pos(item);

         if(_elems[findPos]._state == Entry::VACANT)
            throw Not_found_exception();

         if(findPos == string::npos)
            throw Table_full_exception();

         return _elems[findPos]._data;
      }
      catch(...) {
         cout << "Exception Caught" << endl;
      }

      size_t findPos = _find_pos(item);
      return _elems[findPos]._data;
   }

   bool clear()
   {
      if(is_empty())
         return true;
      if(_elems.clear())
         return true;
      else
         return false;

   }

   bool insert(const T &item)
   {
      size_t findPos = _find_pos(item);

//      cout << "the findpos state is " << _elems[findPos]._state << endl;

      if (findPos == string::npos)
      {
//         cout << "ran out of space" << endl;
         return false;
      }

      if (_elems[findPos]._data == item && _elems[findPos]._state == Entry::ACTIVE)
      {
//         cout << "already inserted" << endl;
         return false;
      }

      if (_elems[findPos]._data == item && _elems[findPos]._state == Entry::DELETED)
      {
//         cout << "made active" << endl;
         _elems[findPos]._state = Entry::ACTIVE;
         _size++;
         return true;
      }



//      cout << "created new" << endl;
      _elems[findPos]._data = item;
      _elems[findPos]._state = Entry::ACTIVE;
//      cout << "the findpos data is " << _elems[findPos]._data << endl;
      _num_non_vacant_cells++;
      _size++;

//      cout << "the _size is " << _size << endl;

      if( _num_non_vacant_cells > _max_load_factor * _elems.size() )
         _rehash();


      return true;
   }

   bool remove(const T &item)
   {
      size_t findPos = _find_pos(item);

      if (findPos == string::npos)
         return false;

      if (_elems[findPos]._data == item && _elems[findPos]._state == Entry::DELETED)
         return false;

      if (_elems[findPos]._data == item && _elems[findPos]._state == Entry::ACTIVE)
      {
         _elems[findPos]._state = Entry::DELETED;
         _size--;
         return true;
      }

      return false;
   }

   class Table_full_exception : public exception {
      public: const string to_string() const throw() { return string("Table full exception"); }
   };

   class Not_found_exception : public exception {
      public: const string to_string() const throw() { return string("Not found exception"); }
   };

   friend class Tests;
};

#endif /* HASH_TABLE_LP_H_ */

