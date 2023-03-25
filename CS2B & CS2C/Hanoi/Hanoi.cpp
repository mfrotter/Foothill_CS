/*
 * Hanoi.cpp
 *
 *  Created on: Mar 8, 2022
 *      Author: mfrot
 */

#include <iostream>
#include <sstream>

#include <vector>

#include "Hanoi.h"

std::string Hanoi::lookup_moves(int num_discs, int src, int dst) const
{
   std::string result = "";


   if(_cache[num_discs][src][dst] != "")
      return result = std::to_string(src) + "->" + std::to_string(dst) + '\n';
   else
      return "";
}

std::string Hanoi::get_moves(int num_discs, int src, int dst, int tmp)
{
   std::string result = "";
   if (num_discs == 0)
   {
      result = "";
   }
   else if (num_discs == 1)
   {
      if(_cache.size() < (unsigned int) num_discs + 1)
      {
         _cache.resize(num_discs + 1);
      }

      if(_cache[num_discs].size() < (unsigned int) src+1)
      {
         _cache[num_discs].resize(src+1);
      }

      if(_cache[num_discs][src].size() < (unsigned int) dst+1)
         _cache[num_discs][src].resize(dst+1);




       std::string lookup = lookup_moves(num_discs, src, dst);
       if(lookup != "")
          result = lookup;
     else
     {
     result = std::to_string(src) + "->" + std::to_string(dst) + '\n';
     _cache[num_discs][src][dst] = result;
     }
   }
   else
   {
      result = get_moves(num_discs - 1, src, tmp, dst);
      if(_cache.size() < (unsigned int) num_discs + 1)
      {
         _cache.resize(num_discs + 1);
      }

      if(_cache[num_discs].size() < (unsigned int) src+1)
      {
         _cache[num_discs].resize(src+1);
      }

      if(_cache[num_discs][src].size() < (unsigned int) dst+1)
         _cache[num_discs][src].resize(dst+1);


      if(lookup_moves(num_discs - 1, src, dst) != "")
         result += lookup_moves(num_discs - 1, src, dst);
      else
      {
      result += std::to_string(src) + "->" + std::to_string(dst) + '\n';
      _cache[num_discs][src][dst] = result;
      }
      result += get_moves(num_discs - 1, tmp, dst, src);
      //_cache.clear();
   }

   return result;
}

std::string Hanoi::solve(int num_discs, int src, int dst, int tmp)
{
   std::string phrase = "# Below, 'A->B' means 'move the top disc on pole A to pole B'\n";
   return phrase + get_moves(num_discs, src, dst, tmp);
}
