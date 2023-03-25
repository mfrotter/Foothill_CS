/*
 * Special_Heap.cpp
 *
 *  Created on: Jun 9, 2022
 *      Author: mfrot
 */

#include "Special_Heap.h"
#include "Heap.h"

int main()
{
   // first set of tests --------------------
//   vector<int> qSort{53, 32, 33, 35, 42, 27, 67, 21, 55, 34};
   vector<int> qSort{31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
//   vector<int> qSort;
//   vector<int> arr(200);

//   for(int x = 0; x < 200; ++x)
//      arr[x] = x;
//   Heap<int> heap(qSort);
//   Heap<int> heap(arr);
//
//   string s1 = "nureyev", s2 = "ailey", s3 = "nijinsky";

//      string substrate =
//         "asdlkfj asdoiBIUYVuwer slkdjLJfwoe89)B)(798rjMG0293lkJLJ42lk3j)(*";
//      string str_array[500];
//      unsigned int k, limit;
//
//      substrate = substrate + substrate;
//
//      for (k = 0; k < substrate.length() - 6; k++)
//         str_array[k] = substrate.substr(k, 5);
//      limit = k;


//      vector<int> days;

//      days.push_back("Sunday");
//      days.push_back("Monday");
//      days.push_back("Tuesday");
//      days.push_back("Wednesday");
//      days.push_back("Thursday");
//      days.push_back("Friday");
//      days.push_back("Saturday");

      Special_Heap<int> heap2(qSort);
//
//      for(size_t i = 31; i > 0; i--)
//         heap2.insert(i);


//
//      for (k = 0; k < limit; k++)
//      {
//         cout << "the element inserted was " << str_array[k] << " ";
//         heap2.insert(str_array[k]);
//      }
//      cout << "\n#strings generated: " << limit
//         << "\n#elements in heap: " << heap2.get_size() << endl;

//   heap.insert(5);
//   heap.insert(3);
//   heap.insert(6);
//   heap.insert(7);
//   heap.insert(2);
//   heap.insert(6);
//   heap.insert(8);

//            for(size_t i = 1; i < heap2.get_size()+1; i++)
//               cout << heap2.get_elems(i) << " ";

   cout << heap2.to_string() << endl;

   heap2.get_least_k(4);

   cout << heap2.to_string() << endl;

//   for(size_t i = 1; i < 7; i++)
//   {
//      cout << heap.get_elems(i) << " ";
//   }
//
//   cout << endl;
//
//
//
//      for(size_t i = 0; i < 125; i++)
//      {
//         cout << "removed " << heap2.peek_min() << endl;
//         heap2.delete_min();
//      }
}


