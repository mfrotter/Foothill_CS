// Student ID: 20504093
// Graph.h
//

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <algorithm>
#include <cfloat>
using namespace std;

#ifndef GRAPH_H_
#define GRAPH_H_

class Graph
{
public:
   struct Edge {
      int dst;
      float wt;

      Edge(int tgt = -1, float w = 0) : dst(tgt), wt(w) {}
      bool operator==(const Edge &that) const { return dst == that.dst && wt == that.wt; }
      bool operator!=(const Edge &that) const { return dst != that.dst || wt != that.wt; }
   };

protected:
   static double constexpr FLOOR = 1e-6;
   std::vector<std::vector<Edge>> _nodes;
   string _to_string() const
   {
      string line;
      ostringstream ostring;

//      if(is_empty())
//         return "";

      for(size_t i = 0; i < _nodes.size(); i++)
      {
         if(!_nodes[i].empty())
         {
            ostring << i << " : ";
            for(size_t j = 0; j < _nodes[i].size(); j++)
            {
               ostring << "(" << _nodes[i][j].dst << "," << _nodes[i][j].wt << ") ";
            }
            ostring << endl;
         }
      }


      line = ostring.str();
      return line;

   }

public:
   size_t get_num_nodes() const {return _nodes.size(); }
   bool is_empty() const { return _nodes.empty(); }
   void clear() { _nodes.clear(); }
   std::string to_string() const
   {
      return "";
      string line;
      ostringstream ostream;
      ostream << "# Graph - " << get_num_nodes() << " nodes." << endl;
      ostream << "# Edge lists:" << endl;
      ostream << _to_string();
      ostream << "# End of Graph";

      line = ostream.str();
      return line;
   }

   Graph &add_edge(int src, int tgt, float wt, bool replace=true)
   {
      if(src < 0)
         src = 0;
      if(tgt < 0)
         tgt = 0;
//      if(wt <= 0)
//         wt = 0;


      if(_nodes.size() <= (size_t) tgt)
         _nodes.resize(tgt+1);
      if(_nodes.size() <= (size_t) src)
         _nodes.resize(src+1);


      if(!is_empty())
      {

         for(size_t i = 0; i < _nodes[src].size(); i++)
         {
            if(_nodes[src][i].dst == tgt)
            {
               if(replace == true)
               {
                  _nodes[src][i].wt = wt;
                  return *this;
               }
               else
               {
                  _nodes[src][i].wt = _nodes[src][i].wt + wt;
                  return *this;
               }
            }
         }
      }



      if(src != tgt)
      {
         Edge temp = Edge(tgt, wt);
         _nodes[src].push_back(temp);
      }

      return *this;
    }
   float find_edge_weight(int src, int tgt) const
   {
      for(size_t i = 0; i < _nodes[src].size(); i++)
      {
         if(_nodes[src][i].dst == tgt)
         {
            return _nodes[src][i].wt;
         }
      }

      return FLOOR;
   }

   friend class Gx;
   friend class Tests;
};

#endif /* GRAPH_H_ */
