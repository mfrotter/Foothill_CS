/*
 * Queue.cpp
 *
 *  Created on: Mar 21, 2022
 *      Author: mfrot
 */

#include "Set.h"

int main()
{
   const int NUM_ENTRIES = 46;

   std::vector<int> master;
   size_t master_total = 0;
   for (size_t i = 0; i < NUM_ENTRIES; i++)
   {
      int val = rand() % 300;
      master_total += val;
      master.push_back(val);
   }

   // select an arbitrary target.
   size_t target = master_total/2;

   Set<int> master_set(&master);
   Set<int> best_subset = master_set.find_biggest_subset_le(target);

   std::cout << "Target = " << target << std::endl;
   std::cout << "Best sum = " << best_subset.get_sum() << std::endl;
   std::cout << best_subset << std::endl;

//   Set<int> test_empty;
//   std::cout << "test_empty" << std::endl;
//   std::cout << "test_empty.add_elem" << test_empty.add_elem(3) << std::endl;
//   std::cout << "test_empty.get_sum()" << test_empty.get_sum() << std::endl;
//
//   std::cout << "test_empty.add_all_elems():" << test_empty.add_all_elems() << std::endl;
//   std::cout << "test_empty.get_sum()" << test_empty.get_sum() << std::endl;

   std::cout << master_set.add_elem(3) << std::endl;
}
