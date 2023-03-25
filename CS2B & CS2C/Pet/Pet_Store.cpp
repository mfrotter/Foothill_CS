// Pet_Store.cpp

#include <iostream>
#include <sstream>

#include <vector>

#include "Pet_Store.h"

using namespace std;

Pet_Store::Pet_Store(size_t n)
{
   _pets.resize(n);
   _sort_order = NONE;
}

//void Pet_Store::set_vector(vector<Pet> pets)
//{
//   _pets = pets;
//}
//
//vector<Pet> Pet_Store::get_vector() const
//{
//   return _pets;
//}

void Pet_Store::set_size(size_t n)
{
   _pets.resize(n);
}

size_t Pet_Store::get_size() const
{
   return _pets.size();
}

void Pet_Store::clear()
{
  _pets.clear();
}

void Pet_Store::populate_with_n_random_pets(size_t n)
{
   Pet_Store::_sort_pets_by_id();
   int name_len = 7;
   Pet::get_n_pets(n, _pets, name_len);

//   long prev_id = 0;
//      for (size_t i = 0; i < n; i++)
//      {
//            long id = prev_id + 1 + rand() % 10;
//            _pets[i].set_id(id);
//            _pets[i].set_num_limbs(rand() % 9); // up to arachnids
//            _pets[i].set_name(Pet::make_a_name(name_len));
//            prev_id = id;
//            //cout << _pets[i].to_string()<< endl;
//       }

}

// These two functions can be conveniently made anonymous "lambda" functions
// defined within the scope of the functions where they're used (but only
// c++-11 on. For now we're just going to leave them here. It's straightforward
// to move them in. Just look up c++ lambda functions if you want. If you want
// to know but don't understand it, I'm happy to explain what they are. Ask me
// in the forums. It's not necessary to know about it to ace this course.
//
// You are free to experiment by hacking the functions below, but restore their
// correct functionalities before submitting your lab.
//
bool Pet_Store::_id_compare(const Pet& p1, const Pet& p2)
{
return p1.get_id() < p2.get_id();
}

bool Pet_Store::_name_compare(const Pet& p1, const Pet& p2)
{
return p1.get_name() < p2.get_name();
}

void Pet_Store::_sort_pets_by_id()
{
std::sort(_pets.begin(), _pets.end(), Pet_Store::_id_compare);
_sort_order = BY_ID;
}

void Pet_Store::_sort_pets_by_name()
{
std::sort(_pets.begin(), _pets.end(), Pet_Store::_name_compare);
_sort_order = BY_NAME;
}

bool Pet_Store::find_pet_by_id_lin(long id, Pet& pet)
{
   Pet_Store::_sort_pets_by_id();
   size_t index = 0;
   bool found = false;
   while ((!found) && (index < _pets.size()))
   {
//      cout << _pets[index].get_id() << endl;
//      cout << id << endl;
   if (id == _pets[index].get_id())
      found = true;
   else
      index++;
   }

   if (found)
   {
      //cout << "found" << endl;
      pet.set_id(_pets[index].get_id());
      pet.set_name(_pets[index].get_name());
      pet.set_num_limbs(_pets[index].get_num_limbs());
      return true;
   }
   else
   {
     // cout << "not found" << endl;
      return false;
   }
}

bool Pet_Store::find_pet_by_name_lin(string name, Pet& pet)
{
   Pet_Store::_sort_pets_by_name();
   size_t index = 0;
   bool found = false;
   while ((!found) && (index < _pets.size()))
   if (name == _pets[index].get_name())
      found = true;
   else
      index++;

   if (found)
   {
      pet.set_id(_pets[index].get_id());
      pet.set_name(_pets[index].get_name());
      pet.set_num_limbs(_pets[index].get_num_limbs());
      return true;
   }
   else
      return false;
}

// When this method starts, the _pets[] vector must be sorted in
// non-descending order by _id. If it is not already, then it will be resorted.

bool Pet_Store::find_pet_by_id_bin(long id, Pet& pet)
{
   Pet_Store::_sort_pets_by_id();
   int mid;
   bool found;
   int first = 0;
   int last = _pets.size();

   found = false;
   while ((first <= last) && !(found))
   {
      mid = (first + last) / 2;
      if (id == _pets[mid].get_id())
      {
         found = true;
         pet.set_id(_pets[mid].get_id());
         pet.set_name(_pets[mid].get_name());
         pet.set_num_limbs(_pets[mid].get_num_limbs());
         return true;
      }
      else if (id < _pets[mid].get_id())
      {
         last = mid - 1;
      }
      else if (id > _pets[mid].get_id())
      {
         first = mid + 1;
      }
   }
   return false;
}

// When this method is called, the _pets[] vector must be sorted in
// lexicographic non-descending order by _name. If it is not already,
// then it will be resorted.

bool Pet_Store::find_pet_by_name_bin(string name, Pet& pet)
{
   Pet_Store::_sort_pets_by_name();
      int mid;
      bool found;
      int first = 0;
      int last = _pets.size();

      found = false;
      while ((first <= last) && !(found))
      {
         mid = (first + last) / 2;
         if (name == _pets[mid].get_name())
         {
            found = true;
            pet.set_id(_pets[mid].get_id());
            pet.set_name(_pets[mid].get_name());
            pet.set_num_limbs(_pets[mid].get_num_limbs());
            return true;
         }
         else if (name < _pets[mid].get_name())
         {
            last = mid - 1;
         }
         else if (name > _pets[mid].get_name())
         {
            first = mid + 1;
         }
      }
      return false;
}

// Return a string representation of the pets with indexes n1 through n2
// inclusive, exclusive of non-existent indices
// Each pet is on a line by itself.

string Pet_Store::to_string(size_t n1, size_t n2)
{
   string toString, resultString;
   if (_pets.size() >= n2)
   {
      for (;n1 <= n2; n1++)
      {
         toString = _pets[n1].Pet::to_string() + '\n';
         resultString = resultString + toString;
      }

   }
   return resultString;
}

//int main()
//{
//   Pet_Store petStore;
//   size_t n = 4;
//   petStore.populate_with_n_random_pets(n);
//
//}
