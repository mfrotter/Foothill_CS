/*
 * Lazy_BST.cpp
 *
 *  Created on: May 11, 2022
 *      Author: mfrot
 */

#include "Lazy_BST.h"

int main()
{
   //int k;
   Lazy_BST<int> searchTree;


//   searchTree.insert("ugine");
//   searchTree.insert("itage");
//   searchTree.insert("yiqej");
//   searchTree.insert("anogi");
//   searchTree.insert("odujo");
//   searchTree.insert("anaqe");
//   searchTree.insert("foroy");
//   searchTree.insert("ezuke");
//   searchTree.insert("giley");
//   searchTree.insert("apala");
//   searchTree.insert("azuku");
//   searchTree.insert("aqepo");
//   searchTree.insert("ceyod");
//   searchTree.insert("asaru");
//   searchTree.insert("diluj");
//   searchTree.insert("nejow");
//   searchTree.insert("osuye");
//   searchTree.insert("monum");
//   searchTree.insert("nohik");
//   searchTree.insert("kufob");
//   searchTree.insert("nicar");
//   searchTree.insert("turin");
//   searchTree.insert("telad");
//   searchTree.insert("qofug");
//   searchTree.insert("oxoju");
//   searchTree.insert("qupov");
//   searchTree.insert("wibij");
//   searchTree.insert("uteyo");
//   searchTree.insert("wetod");
//   searchTree.insert("vogeq");
//   searchTree.insert("wejex");
//
//   searchTree.remove("ugine");
//   searchTree.remove("itage");
//   searchTree.remove("yiqej");
//   searchTree.remove("anogi");
//   searchTree.remove("odujo");
//   searchTree.remove("foroy");
//   searchTree.remove("ezuke");
//   searchTree.remove("giley");
//   searchTree.remove("nejow");
//   searchTree.remove("osuye");
//   searchTree.remove("turin");
//   searchTree.remove("telad");
//   searchTree.remove("qofug");
//   searchTree.remove("qupov");
//   searchTree.remove("wibij");
//
//   searchTree.insert("imazi");
//   searchTree.remove("pepex");

//   searchTree.insert(20);
//   searchTree.remove(30);


   searchTree.insert(50);
   searchTree.insert(20);
   searchTree.insert(30);
   searchTree.insert(70);
   searchTree.insert(10);
   searchTree.insert(60);
   searchTree.insert(5);
   cout << searchTree.to_string() << endl;

   searchTree.remove(50);

      searchTree.collect_garbage();

      cout << searchTree.to_string() << endl;

      searchTree.remove(30);

      searchTree.collect_garbage();

      cout << searchTree.to_string() << endl;

      searchTree.remove(60);

      searchTree.collect_garbage();

      cout << searchTree.to_string() << endl;




//      searchTree.remove(50);
//      searchTree.remove(60);
//
//      cout << searchTree.to_string() << endl;

//   searchTree.remove(10);
//
//   searchTree.remove(20);
//
//   cout << searchTree.to_string() << endl;
//
//   searchTree.collect_garbage();
//
//   cout << searchTree.to_string() << endl;


//   searchTree.remove(20);
//
//   cout << "real size: " << searchTree.get_real_size() << endl;
//   cout << "size: "<< searchTree.get_size() << endl;
//
//   cout << searchTree.to_string() << endl;
//
//   searchTree.remove(30);
//
//   cout << "real size: " << searchTree.get_real_size() << endl;
//   cout << "size: "<< searchTree.get_size() << endl;
//
//   cout << searchTree.to_string() << endl;
//
//   searchTree.collect_garbage();
//
//   cout << searchTree.to_string() << endl;

   return 0;
}
