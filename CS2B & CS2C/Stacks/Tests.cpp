/*
 * Tests.cpp
 *
 *  Created on: Jan 24, 2022
 *      Author: mfrot
 */

#include <iostream>
#include <sstream>

#include <vector>

#include "Tests.h"

Tests::Tests()
{
   // TODO Auto-generated constructor stub

}

Tests::~Tests()
{
   // TODO Auto-generated destructor stub
}

void Tests::testStacks()
{
//   Pet_Store petStore;
//   size_t n = 7;
//   petStore.populate_with_n_random_pets(n);
//
//   for (size_t i=0; i < n;i++)
//   {
//      cout << petStore._pets[i].to_string() << endl;
//   }
//
//   Pet pet;
//   pet.set_id(37);

   Stack_Int stack;
   for (size_t i=0; i < 12; i++)
   {
      stack.push(rand() % 100 + 1);
      std::cout << stack._data[i] << std::endl;
   }


   std::cout << stack.to_string();


}

int main()
{
   Tests test;
   test.testStacks();

}
