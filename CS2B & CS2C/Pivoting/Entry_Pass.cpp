// Student ID: 20504093
// Entry_Pass.cpp
//

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <algorithm>
using namespace std;

   void my_questing_sort_in_place(vector<int> &elems)
   {
      size_t i;
      int key, j, ONE;
      for (ONE = elems.size()/2; ONE > 0; ONE /= 2)
      {
         for (i = ONE; i < elems.size(); i++)
         {
             key = elems[i];
             j = i - ONE;

             while (j >= 0 && elems[j] > key)
             {
                 elems[j + ONE] = elems[j];
                 j = j - ONE;
             }
             elems[j + ONE] = key;
         }
      }
   }

//   int main()
//   {
//      vector<int> qSort{13, 20, 11, 53, 32, 54, 54, 35, 23, 12, 42, 27, 30, 67, 21, 55, 34};
//      my_questing_sort_in_place(qSort);
//
//         for(size_t i = 0; i < qSort.size(); i++)
//            cout << qSort[i] << " ";
//
//         cout << endl;
//   }
