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
   Hanoi hanoi;

   std::cout << hanoi.solve(3,1,2,3);
}

int main()
{
   Tests test;
   test.testStacks();

}
