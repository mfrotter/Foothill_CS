/*
 * BST.cpp
 *
 *  Created on: May 11, 2022
 *      Author: mfrot
 */

#include <iostream>
#include <string>
using namespace std;
#include "BST.h"

int main()
{
   //int k;
   BST<int> searchTree;


   searchTree.insert(50);
   searchTree.insert(20);
   searchTree.insert(30);
   searchTree.insert(70);
   searchTree.insert(10);
   searchTree.insert(60);
   searchTree.insert(5);
   cout << searchTree.to_string() << endl;


   searchTree.remove(20);

   cout << searchTree.to_string() << endl;

   return 0;
}

