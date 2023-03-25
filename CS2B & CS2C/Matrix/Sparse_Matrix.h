// Student ID: 20504093
// Matrix.h
//


#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <algorithm>
using namespace std;
#include "Matrix.h"

#ifndef SPARSE_MATRIX_H_
#define SPARSE_MATRIX_H_

template <typename T>
class Sparse_Matrix
{
private:
   static double constexpr FLOOR = 1e-10;

   struct Node { // private inner
      size_t _col;
      T _val;

      Node(size_t c, const T &v) : _col(c), _val(v) {}
      size_t get_col() const { return _col; }
      const T get_val() const { return _val; }
      void set_val(const T &val) { _val = val; }
      virtual const T &operator=(const T& val) { return _val = val; }

      friend ostream& operator<<(ostream& os, const Node &node) {
         return os << "{ C: " << node.col << ", V: " << node.value << " }";
      }
   };

   vector<list<Node> > _rows;
   size_t _num_rows, _num_cols;
   T _default_val;

public:
   Sparse_Matrix(size_t nr = 0, size_t nc = 0, const T &default_val = T()) :
      _num_rows(nr), _num_cols(nc), _default_val(default_val)
   {
      _rows.resize(nr);
   }

   size_t get_num_rows() const { return _num_rows; };
   size_t get_num_cols() const { return _num_cols; };

   bool is_valid(size_t r, size_t c) const
   {
      if(r >= _num_rows || c >= _num_cols)
         return false;
      if(r < 0 || c < 0)
         return false;
      else
         return true;
   }

   void clear()
   {
      for(size_t i = 1; i < _num_cols; i++)
      {
         _rows[i].clear();
      }
//      _rows[0].set_val(_default_val);
   }

   const T get(size_t r, size_t c) const
   {
      if(!is_valid(r,c))
         return _default_val;
      else
      {
         auto it1 = _rows[r].begin();
         for(size_t i = 0; i < _rows[r].size(); i++)
         {
            if((*it1).get_col() == c)
               return (*it1).get_val();
            std::advance(it1, 1);
         }
         return _default_val;
      }
   }
   bool set(size_t row, size_t col, const T &val)
   {
      if(!is_valid(row,col))
         return false;

      if(_rows[row].empty())
      {
         Node begList(col,val);
         _rows[row].assign(1,begList);
         return true;
      }

      size_t rememberCol;
      auto it = _rows[row].begin();
      for(size_t i = 0; i < _rows[row].size(); i++)
      {
         if((*it).get_col() < col)
         {
            if(i == _rows[row].size() - 1)
            {
               Node begList(col,val);
               _rows[row].push_back(begList);
               return true;
            }
            advance(it, 1);
            continue;
         }

         if((*it).get_col() > col)
         {
            if(i==0)
            {
               Node begList(col,val);
               _rows[row].push_front(begList);
               return true;
            }
            rememberCol = (*it).get_col();
            break;
         }

         else
         {
            if((*it).get_val() == _default_val)
            {
               _rows[row].erase(it);
               return true;
            }
            else
            {
               (*it).set_val(val);
               return true;
            }
         }
      }

      _rows[row].insert(it,Node(rememberCol,val));
      return true;
   }

   Matrix<T> get_slice(size_t r1, size_t c1, size_t r2, size_t c2) const // rect slice
      {
         Matrix<T> matrix(r2-r1+1, c2-c1+1);
         for (size_t i = 0; i < r2-r1+1; i++)
         {
           for (size_t j = 0; j < c2-c1+1; j++)
           {
             matrix.at(i, j) = get(i+r1, j+c1);
           }
         }
         return matrix;
      }

   friend class Tests; // don't remove
};

#endif /* SPARSE_MATRIX_H_ */
