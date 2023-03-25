// Pet.cpp
// 2a-Lab-06-Pets
//

#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>

#include "Pet.h"

using namespace std;

// This is a way to properly initialize (out-of-line) a static variable.
size_t Pet::_population = 0;

Pet::Pet(string name, long id, int num_limbs)
{
   _name = name;
   _id = id;
   _num_limbs = num_limbs;
//   _population++;
}

Pet::~Pet()
{
//   _population--;
};

string Pet::get_name() const
{
   return _name;
}

long Pet::get_id() const
{
   return _id;
}

int Pet::get_num_limbs() const
{
   return _num_limbs;
}

bool Pet::set_name(string name)
{
   if (name.length() == 0)
   {
      //cout << "Failure: name length is 0" << endl;
      return false;
   }
   else
   {
      _name = name;
      return true;
   }
}

bool Pet::set_id(long id)
{
   if (id < 0)
   {
      //cout << "Failure: id is negative" << endl;
      return false;
   }
   else
   {
      _id = id;
      return true;
   }

}

bool Pet::set_num_limbs(int num_limbs)
{
   if (num_limbs < 0)
   {
      //cout << "Failure: number of limbs is negative" << endl;
      return false;
   }
   else
   {
      _num_limbs = num_limbs;
      return true;
   }
}

string Pet::to_string() const
{
   string name = "(Name: ";
   string id = ", ID: ";
   string limbCount = ", Limb Count: ";
   string representation = name + Pet::get_name() + id + std::to_string(Pet::get_id()) + limbCount + std::to_string(Pet::get_num_limbs()) + ")";
   return representation;
}

// Fill in the supplied pets vector with n pets whose
// properties are chosen randomly.
// Don't mess with this method more than necessary.

void Pet::get_n_pets(size_t n, std::vector<Pet>& pets, int name_len)
{
   pets.resize(n);
   long prev_id = 0;
   for (size_t i = 0; i < n; i++)
   {
         long id = prev_id + 1 + rand() % 10;
         pets[i].set_id(id);
         pets[i].set_num_limbs(rand() % 9); // up to arachnids
         pets[i].set_name(Pet::make_a_name(name_len));
         prev_id = id;
         //pets.push_back(pets[i]);

         //cout << pets[i].to_string()<< endl;

         // TODO - make and set a name of the requested length
         // TODO - adjust prev_id as necessary
    }
}
// ---------------------------------------------------------------------

string Pet::make_a_name(int len)
{
   string vowel = "aeiou", consonent = "bcdfghjklmnpqrstvwxyz";
   string name = "";
   char character;
   //srand(time(NULL));
   //int consIndex, vowelIndex;
   int random = rand() % 2;

   if ((len == 0))
   {
      return name;
   }


      for (int i = 0; i < len; i++)
      {
         //index = rand() % consonent.length();
         //consIndex = rand() % consonent.length();
         //vowelIndex = rand() % vowel.length();

         if (((random == 1) && i == 0) || ( i >= 1 && consonent.find(character) != std::string::npos))
         {
            character = vowel[rand() % vowel.length()];
            name = name + character;
         }
         else
         {
            character = consonent[rand() % consonent.length()];
            name = name + character;
         }

        // if (consonent.find(character) != std::string::npos)
           // character = vowel[vowelIndex];
         //else
            //character = consonent[consIndex];


      }

   return name;


}

// Optional EC points
// Global helpers
bool operator==(const Pet& pet1, const Pet& pet2)
{
   return pet1.get_name() == pet2.get_name() && pet1.get_id() == pet2.get_id() && pet1.get_num_limbs() == pet2.get_num_limbs();
}

bool operator!=(const Pet& pet1, const Pet& pet2)
{
   return !(pet1.get_name() == pet2.get_name() && pet1.get_id() == pet2.get_id() && pet1.get_num_limbs() == pet2.get_num_limbs());
}

ostream& operator<<(ostream& os, const Pet& pet)
{
   os << pet.to_string() << endl;
   return os;
}

//int main()
//{
//   std::vector<Pet> pets;
//   Pet pet1("hihi",100,4);
//   pet1.set_id(100);
//   pet1.set_name(pet1.make_a_name(5));
//   pet1.set_num_limbs(4);
//   cout << pet1.get_id() << pet1.get_name() << pet1.get_num_limbs() << endl;
//   cout << pet1.to_string() << endl;
//
//
//   pet1.get_n_pets(6, pets, 3);
//
//   cout << pet1 << endl;
//
//   for (int i=0; i < 6;i++)
//   {
//      cout << pets[i] << endl;
//   }
//
//}
