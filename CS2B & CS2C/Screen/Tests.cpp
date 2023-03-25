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
   Screen screen(93,95);
   char c = '.';
   screen.fill(c);

   Point pt(10,5);
   char ch = '*';
//   pt.draw(screen, ch);

//   Line line(3, 1, 4, 5);
//   line.draw(screen, ch);

//   Quadrilateral quad(1, 1, 1, 4, 3, 5, 2, 3);
//   quad.draw(screen, ch);

   Stick_Man man(67,16,0,0);
   man.draw(screen, ch);

   std::cout << screen.to_string() << std::endl;
}

int main()
{
   Tests test;
   test.testStacks();
   //

}
