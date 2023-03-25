// Student ID: 20504093
// Graph.h
//

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>

class Graph {
protected:
   struct Edge {
      int _dst;
      std::string _tag;
      Edge(int dst = -1, std::string tag = "") : _dst(dst), _tag(tag) {}
   };
   std::vector<std::vector<Edge> > _nodes;
   int _count = 0;

   // Suggested private helpers. Not tested.
   void add_edge(int src, int dst, std::string tag);
   std::string to_string() const;

public:
   void make_silly_snake();
   void make_mr_sticky();
   void make_driftin_dragonfly();
   void make_slinky_star();
   void make_kathy_da_grate();
   void make_dodos_in_space();
   void make_purty_pitcher();

   friend class Tests; // Don't remove this line.
};

#endif /* GRAPH_H_ */
