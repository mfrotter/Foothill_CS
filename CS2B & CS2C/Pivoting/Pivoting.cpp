/*
 * Pivoting.cpp
 *
 *  Created on: Jun 4, 2022
 *      Author: mfrot
 */

#include "Pivoting.h"

int main()
{
//   vector<int> qSort{13, 20, 11, 53, 32, 54, 54, 35, 23, 12, 42, 27, 30, 67, 21, 55, 34};
   vector<int> qSort{53, 32, 33, 35, 42, 27, 67, 21, 55, 34};
//    vector<int> qSort{23, 23, 23};


   Pivoting<int> newP;



//   newP.do_qsort(qSort);
//
//   cout << "after sorting, the vector is ";
//
//   for(size_t i = 0; i < qSort.size(); i++)
//      cout << qSort[i] << " ";
//
//   cout << endl;

//   cout << newP.find_kth_least_elem(qSort, 200) << endl;

//   for(size_t i = 0; i < 10; i++)
//   {
//      vector<int> qSort{53, 32, 33, 35, 42, 27, 67, 21, 55, 34};
//      cout << newP.find_kth_least_elem(qSort, i) << endl;
//   }

         cout << newP.find_kth_least_elem(qSort, 5) << endl;

//   cout<< qSort[newP.find_median(qSort)] << endl;

}
