// Student ID: 20504093
// Pivoting.h
//

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <algorithm>
using namespace std;

#ifndef PIVOTING_H_
#define PIVOTING_H_

template<typename T>
class Pivoting
{
private:
   static size_t _partition(vector<T> &elems, size_t lo, size_t hi)
   {

      cout << "the lo is " << lo << " and the hi is " << hi << endl;

      cout << "the vector is size " << elems.size() << " and is made up of ";

      for(size_t p = 0; p < elems.size(); p++)
         cout << elems[p] << " ";

      cout << endl;



      int pivot2 = lo + (hi-lo)/2;
      int pivot = elems[pivot2];
      int i = lo - 1;
      int j = hi + 1;

      while (true)
      {


         do
         {
            cout << "i is " << i << ", elems i is " << elems[i] << " and pivot is " << pivot2 << " and elem pivot is " << pivot << endl;
            i++;
         }
         while( elems[i] < pivot);
         cout << "i is " << i << ", elems i is " << elems[i] << " and pivot is " << pivot2 << " and elem pivot is " << pivot << endl;

         do
         {
            cout << "j is " << j << ", elems j is " << elems[j] << " and pivot is " << pivot2 << " and elem pivot is " << pivot << endl;
            j--;
         }

         while (elems[j] > pivot);
         cout << "j is " << j << ", elems j is " << elems[j] << " and pivot is " << pivot2 << " and elem pivot is " << pivot << endl;


         if (i >= j)
         {
            cout << "the returned j is " << j << " and the elems j is " << elems[j] << endl << endl << endl << endl;
            return j;
         }

         cout << "the swapped i is " << elems[i] << " and the swapped j is " << elems[j] << endl;
         swap(elems[i], elems[j]);

         cout << "the vector after swapping is ";
         for(size_t h = 0; h < elems.size(); h++)
            cout << elems[h] << " ";
         cout << endl << endl;
      }

//      for(i = lo - 1, j = hi + 1; ; )
//      {
//         while( elems[i] < pivot )
//         {
//            cout << "i is " << i << ", elems i is " << elems[i] << " and pivot is " << pivot2 << " and elem pivot is " << pivot << endl;
//            i++;
//         }
//         cout << "i is " << i << ", elems i is " << elems[i] << " and pivot is " << pivot2 << " and elem pivot is " << pivot << endl;
//         while( pivot < elems[j])
//         {
//            cout << "j is " << j << ", elems j is " << elems[j] << " and pivot is " << pivot2 << " and elem pivot is " << pivot << endl;
//            --j;
//         }
//         cout << "j is " << j << ", elems j is " << elems[j] << " and pivot is " << pivot2 << " and elem pivot is " << pivot << endl;
//
//         if(i == j)
//         {
//            cout << "the returned i is " << j << " and the elems i is " << elems[j] << endl << endl << endl << endl;
//            return j;
//         }
//         else
//         {
//            cout << "the swapped i is " << elems[i] << " and the swapped j is " << elems[j] << endl;
//            swap(elems[i], elems[j]);
//
//            cout << "the vector after swapping is ";
//            for(size_t h = 0; h < elems.size(); h++)
//               cout << elems[h] << " ";
//            cout << endl << endl;
//         }
//      }


   }
   static void _do_qsort(vector<T> &elems, size_t lo, size_t hi)
   {

      if (lo >= hi)
         return;


      size_t partition = _partition(elems, lo, hi);

//   size_t partitionlo = _partition(elems, lo, partition - 1);
//   size_t partitionlo2 = _partition(elems, lo, partitionlo - 1);
//   size_t partitionhi = _partition(elems, partition, hi);
//   size_t partitionhi2 = _partition(elems, partition, hi);

//      if(partition - 1 - lo == 1)
//      {
//         cout << "equaled 1 for qsort lo" << endl;
//         return;
//      }

//      if(lo < partition - 1)
//      {
//         cout << "starting qsort lo" << endl;
         _do_qsort(elems, lo, partition);
//      }
//      else
//         cout << "didn't do qsort lo" << endl;


//      if (hi - partition == 1)
//      {
//         cout << "equaled 1 for qsort hi" << endl;
//         return;
//      }

//      if(partition < hi)
//      {
//         cout << "starting qsort hi also hi is " << hi << endl;
         _do_qsort(elems, partition+1, hi);
//      }
//      else
//         cout << "didn't do qsort hi" << endl;

   }

   static T _find_kth_least_elem(vector<T> &elems, size_t lo, size_t hi, size_t k)
   {
//      size_t pivot = _partition(elems, lo ,hi);
//
//      if(lo == hi)
//         return elems[lo];
//
//      if(pivot - lo  == k)
//      {
//         cout << "k found" << endl;
//         return elems[pivot];
//      }
//      if(pivot - lo > k)
//      {
//         cout << "k less than left, starting left" << endl;
//         return _find_kth_least_elem(elems, lo, pivot, k);
//      }
//      else
//      {
//         cout << "k greater than right, starting right" << endl;
//         return _find_kth_least_elem(elems, pivot + 1, hi, k - pivot + lo - 1);
//      }

      while (lo < hi) {
         cout << "lo is less than hi" << endl;
          size_t pivot = _partition(elems, lo, hi);

          if (pivot < k) {
             cout << "pivot is less than k" << endl;
              lo = pivot + 1;
          } else {
             cout << "pivot is greater than or equal to k" << endl;
              hi = pivot;
          }
      }
      cout << "found k" << endl;
      return elems[hi];

   }



public:
   static T find_median(vector<T> &elems)
   {
      size_t median;

      if(elems.size() % 2 != 0)
      {
         median = (elems.size() - 1) / 2;
         cout << "size is even and median is " << median << endl;
         return find_kth_least_elem(elems, median);
      }
      else
      {
         median = (elems.size()) / 2;
         cout << "size is odd and median is " << median << endl;
         return find_kth_least_elem(elems, median);
      }
   }
   static T find_kth_least_elem(vector<T> &elems, size_t k)
   {
      T deFault = T();

      if(k >= 0 && k < elems.size() && elems.size() != 0)
         return _find_kth_least_elem(elems, 0, elems.size() - 1, k);
      else
         return deFault;
   }
   static void do_qsort(vector<T> &elems)
   {
       _do_qsort(elems, 0, elems.size() - 1);
   }

   friend class Tests;
};

#endif /* PIVOTING_H_ */
