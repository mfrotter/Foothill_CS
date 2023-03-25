// Student ID: 20504093
// TODO - Replace the number above with your actual student ID
//
#ifndef Stacks_h
#define Stacks_h

#include <vector>
#include <sstream>
#include <iostream>

class Stack_Int
{
private:
   std::vector<int> _data;

public:
   // No explicit constructor or destructor
   size_t size() const
   {
      return _data.size();
   }

   bool is_empty() const
   {
      if (_data.size() == 0)
         return true;
      else
         return false;
   }

   void push(int val)
   {
      _data.push_back(val);
   }

   int top(bool& success) const
   {
      if (is_empty() == true)
      {
         success = false;
         return 0;
      }
      else
      {
         success = true;
         return _data[_data.size()-1];
         //return _data[0];
      }

   }

   bool pop()
   {
      if (is_empty() == true)
         return false;
      else
      {
         _data.pop_back();
         return true;
      }
   }

   bool pop(int& val)
   {
      if (is_empty() == true)
      {
         return false;
      }
      else
      {
         val = _data[_data.size()-1];
         _data.pop_back();
         return true;;
      }
   }

   std::string to_string() const
   {
      //std::cout << "Stack (" << _data.size() << " elements):" << std::endl;
      std::string listMember = "";
      std::string listFinal = "";

      if (_data.size() == 0)
         return listFinal;

      if (_data.size() < 10)
      {
         //std::cout << _data.size() << std::endl;
         for (int i = _data.size()-1; i > -1; i--)
         {
            listMember = std::to_string(_data[i]) + '\n';
            listFinal = listFinal + listMember;
         }

         return std::string("Stack (") + std::to_string(_data.size()) + " elements):" + '\n' + listFinal + "Elements, if listed above, are in increasing order of age." ;

      }

      if (_data.size() > 10)
      {
         for (size_t i = _data.size()-1; i > _data.size()-11; i--)
         {
            listMember = std::to_string(_data[i]) + '\n';
            listFinal = listFinal + listMember;
         }

         return std::string("Stack (") + std::to_string(_data.size()) + " elements):" + '\n' + listFinal + "..." + '\n' + "Elements, if listed above, are in increasing order of age." ;


      }

   }

   // Don't remove the following line
   friend class Tests;
};

class Stack_String
{
private:
   std::vector<std::string> _data;

public:
   // No explicit constructor or destructor
   size_t size() const
   {
      return _data.size();
   }

   bool is_empty() const
   {
      if (_data.size() == 0)
         return true;
      else
         return false;
   }

   void push(std::string val)
   {
      _data.push_back(val);
   }

   std::string top(bool& success) const
   {
      if (is_empty() == true)
      {
         success = false;
         return 0;
      }
      else
      {
         success = true;
         return _data[_data.size()-1];
      }

   }

   bool pop()
   {
      if (is_empty() == true)
         return false;
      else
      {
         _data.pop_back();
         return true;
      }
   }

   bool pop(std::string& val)
   {
      if (is_empty() == true)
      {
         return false;
      }
      else
      {
         val = _data[_data.size()-1];
         _data.pop_back();
         return true;;
      }
   }

   std::string to_string() const
   {
      //std::cout << "Stack (" << _data.size() << " elements):" << std::endl;
      std::string listMember = "";
      std::string listFinal = "";

      if (_data.size() == 0)
         return listFinal;

      if (_data.size() < 10)
      {
         for (int i = _data.size()-1; i > -1; i--)
         {
            listMember = _data[i] + '\n';
            listFinal = listFinal + listMember;
         }

         return std::string("Stack (") + std::to_string(_data.size()) + " elements):" + '\n' + listFinal + "Elements, if listed above, are in increasing order of age." ;

      }

      if (_data.size() > 10)
      {
         for (size_t i = _data.size()-1; i > _data.size()-11; i--)
         {
            listMember = _data[i] + '\n';
            listFinal = listFinal + listMember;
         }

         return std::string("Stack (") + std::to_string(_data.size()) + " elements):" + '\n' + listFinal + "..." + '\n' + "Elements, if listed above, are in increasing order of age." ;


      }

   }

   // Don't remove the following line
   friend class Tests;
};

#endif /* Stacks_h */
