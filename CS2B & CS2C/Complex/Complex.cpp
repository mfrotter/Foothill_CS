/*
 * Complex.cpp
 *
 *  Created on: Mar 18, 2022
 *      Author: mfrot
 */

#include "Complex.h"

bool Complex::operator==(const Complex& that) const
{
   if(_real == that._real && _imag == that._imag)
      return true;
   else
      return false;
}

bool Complex::operator!=(const Complex& that) const
{
   if(operator==(that))
      return false;
   else
      return true;
}

bool Complex::operator<(const Complex& that) const
{
   if(norm() < that.norm())
      return true;
   else
      return false;
}

Complex Complex::operator+(const Complex& that) const
{
   return (Complex(this->_real+that._real, this->_imag+that._imag));
}

Complex Complex::operator-(const Complex& that) const
{
   return (Complex(_real-that._real, _imag-that._imag));
}

Complex Complex::operator*(const Complex& that) const
{
   return (Complex((that._real * _real)-(that._imag*_imag),(that._imag*_real)+(that._real*_imag)));
}

Complex Complex::reciprocal() const
{
   if(norm_squared() <= Complex::FLOOR)
      throw Div_By_Zero_Exception();
   else
   return(Complex(_real / norm_squared(), -_imag / norm_squared()));
}

Complex Complex::operator/(const Complex& that) const
{
   if(norm_squared(),that.norm_squared() <= Complex::FLOOR)
      throw Div_By_Zero_Exception();
   else
      return (*this * that.reciprocal());
}

std::string Complex::to_string() const
{
   char buf [50];
   sprintf(buf, "(%.11g,%.11g)", _real, _imag);
   return std::string(buf);
}

std::ostream& operator<<(std::ostream& os, const Complex& x)
{
   os << x.to_string();
   return os;
}

Complex& Complex::operator= (const Complex & rhs)
{
if (this!= &rhs)
   {
         this->_real = rhs._real;
         this->_imag = rhs._imag;
   }
   return *this;
}


