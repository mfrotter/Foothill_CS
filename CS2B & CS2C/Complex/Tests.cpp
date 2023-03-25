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

}

Tests::~Tests()
{
   // TODO Auto-generated destructor stub
}

void Tests::testStacks()
{
   Complex x = Complex(5,2);
   Complex y = Complex(4,4);
   Complex z = Complex(0,0);

   z.reciprocal();

   //z = x + y;

   std::cout << z << std::endl;
   //std::cout << y << std::endl;
}

int main()
{
   Tests test;
   test.testStacks();

}
