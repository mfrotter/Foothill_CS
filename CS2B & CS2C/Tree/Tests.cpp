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
   Tree special, special2;

   std::vector<std::string> names;

   special.make_special_config_1(names);

   //special2._root = special._root;

   Tree::Node hello;
   hello = *special._root;

   std::cout << special.to_string();

   //Tree::Node* aaba = special._root->aaba->insert_sibling(new Tree::Node("AABA"));
   //Node* aaba = _root->insert_sibling(new Node("AABA"));
   //Node* cobo = aaba->insert_child(new Node("COBO"));
}

int main()
{
   Tests test;
   test.testStacks();

}
