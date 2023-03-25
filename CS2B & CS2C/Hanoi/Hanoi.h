// Student ID: 20504093
// Hanoi.h
//

#ifndef Hanoi_h
#define Hanoi_h

#include <vector>
#include <iostream>
#include <sstream>

class Hanoi
{
private:

   std::vector<std::vector<std::vector<std::string>>> _cache;

   // TODO: Declare the _cache member using an appropriate
   // level of nesting within std::vectors to put each string
   // of moves. You should be able to access the cache like so:
   // _cache[num_discs][src][dst] = "move1\nmove2\n..."

   std::string lookup_moves(int num_discs, int src, int dst) const;
   std::string get_moves(int num_discs, int src, int dst, int tmp);

public:

   // Use freebie default constructor
   std::string solve(int num_discs, int src, int dst, int tmp);

   friend class Tests; // Don't remove this line
};

#endif
