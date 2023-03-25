// Student ID: 20504093
// Matrix.h
//


#include <vector>
#include <iostream>
#include <sstream>
#include <exception>
#include <iomanip>
using namespace std;

#ifndef MATRIX_H_
#define MATRIX_H_

template<typename T>
class Matrix {
protected:
   std::vector<std::vector<T>> _rows;

public:
   Matrix(size_t nr = 0, size_t nc = 0)
   {
      if(nr > 0 && nc > 0)
         resize(nr,nc);
      else
         resize(0,0);
   }

   size_t get_num_rows() const { return _rows.size(); };
   size_t get_num_cols() const { return (_rows.size()>0? _rows[0].size() : 0); };
   void clear() {_rows.clear(); };

   void resize(size_t nr, size_t nc) { clear(); _rows.resize(nr, vector<T>(nc)); };
   T &at(size_t r, size_t c) // throws OOB
   {
      if (r < 0 || c < 0 || r >= _rows.size() || c >= _rows[r].size())
         throw OOB_exception();
      else
         return _rows[r][c];

   }

   std::string to_string() const
   {
      string first = "# Matrix\n";
      ostringstream ostring;
      string add, added;
      for(size_t i=0; i < get_num_rows(); i++)
      {
         for(size_t j=0; j < get_num_cols(); j++)
         {
            if(j == 0)
               ostring << setw(6) << _rows[i][j];
            else
               ostring << " " << setw(6) << _rows[i][j];
         }
         ostring << endl;
         add = ostring.str();
      }
      return first + add;
   }

   class OOB_exception : public exception {
      public: std::string what() { return "Out of bounds access"; }
   };

// Friends -----------------------------------------------------------

   friend std::ostream &operator<<(std::ostream& os, const Matrix<T> &mat) {
      return os << mat.to_string();
   }

   friend bool operator==(const Matrix<T> &m1, const Matrix<T> &m2) {
      if (m1.get_num_rows() != m2.get_num_rows()) return false;
      if (m1.get_num_cols() != m2.get_num_cols()) return false;
      for(size_t i=0; i < m1.get_num_rows(); i++)
      {
         for(size_t j=0; j < m1._rows[i].size(); j++)
         {
            if(m1._rows[i][j] != m2._rows[i][j])
               return false;
         }

      }

      return true;
   }

   friend bool operator!=(const Matrix<T> &m1, const Matrix<T> &m2) {
      return !(m1 ==  m2);
   }

   friend class Tests; // Don't remove this line

};
#endif /* MATRIX_H_ */
