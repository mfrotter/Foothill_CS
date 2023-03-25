/*
 * Sparse_Matrix.cpp
 *
 *  Created on: Apr 25, 2022
 *      Author: mfrot
 */

#include "Sparse_Matrix.h"

int main()
{
//   Matrix<int> matrix(7,7);
//   cout<<matrix;

   Sparse_Matrix<int> matrix(10,10,100);
   matrix.set(1,3,5);
   matrix.set(1,1,7);
   matrix.set(1,5,9);
   cout << matrix.get_slice(1,1,8,8);
}

