// Student ID: 20504093
// TODO - Replace the number above with your actual Student ID
// Etox.cpp
// 2a-Lab-01
//
#include <iostream>
#include <sstream>
#include <cmath> // needed for sqrt
#include <cstdlib> // for exit()
using namespace std;

double etox_5_terms(double x)
{
   double etox;
   etox = 1 + x + ((x*x)/2)+ ((x*x*x)/6) + ((x*x*x*x)/24);

   return etox;
}
int main(int argc, char **argv)
{
   string user_input;
   double x;

   cout <<"Enter a value for x: ";
   getline(cin, user_input);
   istringstream(user_input) >>x;

   cout << etox_5_terms(x);

   return 0;
}
