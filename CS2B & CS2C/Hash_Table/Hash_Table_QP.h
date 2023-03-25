// Student ID: 20504093
// Hash_Table_QP.h
//

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

#ifndef HASH_TABLE_QP_H_
#define HASH_TABLE_QP_H_

#include "Hash_Table_LP.h"


template <typename T>
class Hash_Table_QP : public Hash_Table_LP<T>
{
public:
   Hash_Table_QP(size_t n = Hash_Table_LP<T>::DEFAULT_INIT_CAPACITY) : Hash_Table_LP<T>(n) {
      this->_max_load_factor = _get_biggest_allowed_max_load_factor();
   }

   size_t testNextPrime(size_t n)
   {
      return _next_prime(n);
   }

protected:
   virtual float _get_biggest_allowed_max_load_factor() const
   {
      float maxloadFactor = 0.49;
      return maxloadFactor;
   }
   virtual size_t _find_pos(const T& item) const
   {
      size_t findPos =  Hash_Table_LP<T>::_get_hash_modulus(item);
      size_t kthOddNum = 1;
      size_t count = 0;
      //int pos = -1;
      if ( findPos >= this->_elems.size() )
         findPos -= this->_elems.size();

//      cout << "elem size is " << this_elems.size() << endl;
//      cout << "findPos is " << findPos << endl;

      while ( this->_elems[findPos]._state != 1
         && this->_elems[findPos]._data != item )
      {
         findPos += kthOddNum;
         kthOddNum += 2;
         if ( findPos >= this->_elems.size() )
            findPos -= this->_elems.size();
         count++;
         if(count > this->_elems.size())
         {
//            cout << "ran out of space" << endl;
            return string::npos;
         }
      }

      return findPos;

   }
   virtual void _grow_capacity()
   {
      size_t newTableSize = _next_prime(this->_elems.size() * 2);
      this->_elems.resize(newTableSize);
   }

   // Private helper
   static size_t _next_prime(size_t n)
   {
      long k, candidate, loopLim;


      // loop doesn't work for 2 or 3
      if (n <= 1 )
         return 2;
      else if(n == 2)
         return 3;
      else if (n == 3)
         return 5;
//      else if (n == 5)
//         return 7;

      if(isPrime(n))
         return _next_prime(n+1);

      for (candidate = (n%2 == 0)? n+1 : n ; true ; candidate += 2)
      {
 //        cout << "the candidate is " << candidate << endl;
         // all primes > 3 are of the form 6k +/- 1
         loopLim = (long)( (sqrt((float)candidate) + 1)/6 );

//         cout << "the loopLim is " << loopLim << endl;

         // we know it is odd.  check for divisibility by 3
         if (candidate%3 == 0)
         {
//            cout << "divisible by 3" << endl;
            continue;
         }

         // now we can check for divisibility by 6k +/- 1 up to sqrt
         for (k = 1; k <= loopLim; k++)
         {
            if (candidate % (6*k - 1) == 0)
            {
//               cout << "candidate is divisible by 6k + 1" << endl;
               break;
            }
            if (candidate % (6*k + 1) == 0)
            {
//               cout << "candidate is divisible by 6k + 1" << endl;
               break;
            }
         }
         if (k > loopLim)
         {
//           cout << "k is greater than loopLim" << endl;
            return candidate;
         }
      }
   }

   static bool isPrime(int n)
   {
       // Corner cases
       if (n <= 1)  return false;
       if (n <= 3)  return true;

       // This is checked so that we can skip
       // middle five numbers in below loop
       if (n%2 == 0 || n%3 == 0) return false;

       for (int i=5; i*i<=n; i=i+6)
           if (n%i == 0 || n%(i+2) == 0)
              return false;

       return true;
   }


   // Don't modify below
   friend class Tests;
};

#endif /* HASH_TABLE_QP_H_ */
