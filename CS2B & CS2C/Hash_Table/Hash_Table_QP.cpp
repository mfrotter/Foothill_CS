/*
 * Hash_Table_QP.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: mfrot
 */

#include "Hash_Table_QP.h"
#include "Hash_Table_LP.h"


int main()
{
   Hash_Table_QP<string> hashTable(0);

   for(size_t i = 0; i < 1500; i++)
   cout << "i is "<< i << " and next prime is " << hashTable.testNextPrime(i) << endl;

//   cout << "next prime is " << hashTable.testNextPrime(5) << endl;

//   string e1 = "Jane Austin";
//   string e2 = "Rene Descartes";
//   string e3 = "John Locke";
//
//
//   if (  hashTable.insert(e1) )
//      cout << "inserted " << e1 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.insert(e1) )
//      cout << "inserted " << e1 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.insert(e2) )
//      cout << "inserted " << e2 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.insert(e2) )
//      cout << "inserted " << e2 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.insert(e3) )
//      cout << "inserted " << e3 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.insert(e3) )
//      cout << "inserted " << e3 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.contains(e3) )
//      cout << "contains " << e3 << endl << endl;
//
//   if (  hashTable.remove(e1) )
//      cout << "removed " << e1 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.remove(e1) )
//      cout << "removed " << e1 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.remove(e2) )
//      cout << "removed " << e2 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.remove(e2) )
//      cout << "removed " << e2 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.remove(e3) )
//      cout << "removed " << e3 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.remove(e3) )
//      cout << "removed " << e3 << endl;
//   cout << "the size of the hash table is " << hashTable.get_size() << endl << endl;
//
//   if (  hashTable.contains(e3) )
//      cout << "contains " << e3 << endl;


}

