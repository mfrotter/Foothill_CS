// Student ID: 20504093
// Set.h
//

#include <vector>
#include <iostream>
#include <sstream>

#ifndef SET_H_
#define SET_H_

template<typename T>
class Set
{

private:
   std::vector<T> *_master_ptr;
   std::vector<size_t> _elems; // List of indices into this->master
   size_t _sum;

public:
   Set(std::vector<T> *mast_ptr = nullptr) : _master_ptr(mast_ptr), _sum(0) {}

   const size_t size() const {return _elems.size();}
   const std::vector<T> *get_master_ptr() const { return _master_ptr; }
   const size_t get_sum() const { return _sum; }

   bool add_elem(size_t n) // n is the index in master
   {
      if(_master_ptr != nullptr && n < _master_ptr->size() && !_master_ptr->empty() && n >= 0)
      {
         _elems.push_back(n);
         _sum = _sum + (_master_ptr->at(n));
         return true;
      }
      else
         return false;
   }
   bool add_all_elems() // Add everything in the master
   {

      if(_master_ptr != nullptr && !_master_ptr->empty())
      {
         for(size_t i = 0; i < _master_ptr->size(); i++)
         {
            _elems.push_back(i);
            _sum = _sum + _master_ptr->at(i);
         }
         return true;
      }
      else
         return false;
   }

   Set<T> find_biggest_subset_le(size_t target)
   {
      Set<T> emptyList(_master_ptr);
      std::vector<Set<T>> viableCandidates;
      viableCandidates.push_back(emptyList);

      if(target == 0)
         return emptyList;

      add_all_elems();

      if(target > get_sum())
         return *this;

      for(size_t i = 0; i < _master_ptr->size(); i++)
      {
         size_t oldViableSize = viableCandidates.size();
         for(size_t j = 0; j < oldViableSize; j++)
         {

            Set<T> newSub;
            newSub = viableCandidates[j];
            newSub.add_elem(i);
            if(newSub.get_sum() < target)
               viableCandidates.push_back(newSub);
            if(newSub.get_sum() == target)
               return newSub;
         }
      }

      std::vector<int> differenceTarget;
      int difference;
      int maxDifference = 999999;
      int correctIndex;
      for(size_t i = 0; i < viableCandidates.size(); i++)
      {
         difference = abs(target - viableCandidates[i].get_sum());
         if(difference < maxDifference)
         {
            maxDifference = difference;
            correctIndex = i;
         }

      }

      return viableCandidates[correctIndex];

   }

   friend std::ostream &operator<<(std::ostream& os, const Set<T> &set)
   {
      const std::vector<T> *mast_ptr = set.get_master_ptr();
      os << "{\n";
      for (size_t index : set._elems)
         os << " " << mast_ptr->at(index) << "\n";
      return os << "}";
   }

   friend class Tests; // Don't remove this line

};

//

#endif /* SET_H_ */
