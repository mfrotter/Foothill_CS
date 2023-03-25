/*
 * Graph.cpp
 *
 *  Created on: Mar 22, 2022
 *      Author: mfrot
 */

#include "Graph.h"

void Graph::add_edge(int src, int dst, std::string tag)
{
   _count++;
   if(src < 0)
      src = 0;
   if(dst < 0)
      dst = 0;


   if(_nodes.size() <= (size_t) dst)
         _nodes.resize(dst+1);

//   if((int) _nodes.size() <= _count)
//      _nodes.resize(_count + 1);

   Edge temp = Edge(dst, tag);
   _nodes[src].push_back(temp);
 }

void Graph::make_silly_snake()
{
   _nodes.clear();
   add_edge(0,1, "i-see");
   add_edge(1,2, "the-silly-snake");
   add_edge(2,3, "i-be");
   add_edge(3,4, "you-saw-me");
   add_edge(4,5, "once-like");
   add_edge(5,0, "kekule");
}

void Graph::make_mr_sticky()
{
   _nodes.clear();
   add_edge(0,1, ".");
   add_edge(1,2, ".");
   add_edge(1,3, ".");
   add_edge(1,4, ".");
   add_edge(4,5, ".");
   add_edge(4,6, ".");
}
void Graph::make_driftin_dragonfly()
{
   _nodes.clear();
   add_edge(0,1, "dis-be-me-head");
   add_edge(1,2, "me");
   add_edge(1,5, "dis-be-me");
   add_edge(5,6, "front-right");
   add_edge(6,7, "me-right");
   add_edge(7,8, "back");
   add_edge(8,2, "be-dis");
   add_edge(1,9, "dis-be-me");
   add_edge(9,10, "front-left");
   add_edge(10,11, "and-left");
   add_edge(11,12, "back");
   add_edge(12,2, "be-dis");
   add_edge(2,3, "long-tail");
   add_edge(3,4, "be-dis");
}
void Graph::make_slinky_star()
{
   _nodes.clear();
   add_edge(0,1, "-");
   add_edge(1,2, "-");
   add_edge(0,3, "-");
   add_edge(3,4, "-");
   add_edge(0,5, "-");
   add_edge(5,6, "-");
   add_edge(0,7, "-");
   add_edge(7,8, "-");
   add_edge(0,9, "-");
   add_edge(9,10, "-");
   add_edge(0,11, "-");
   add_edge(11,12, "-");
   add_edge(0,13, "-");
   add_edge(13,14, "-");
}
void Graph::make_kathy_da_grate()
{
   _nodes.clear();
   add_edge(0,1, "-");
   add_edge(1,2, "-");
   add_edge(2,3, "-");
   add_edge(3,4, "-");
   add_edge(4,0, "-");
   add_edge(0,5, "-");
   add_edge(5,6, "-");
   add_edge(1,7, "-");
   add_edge(7,8, "-");
   add_edge(2,9, "-");
   add_edge(9,10, "-");
   add_edge(3,11, "-");
   add_edge(11,12, "-");
   add_edge(4,13, "-");
   add_edge(13,14, "-");
}
void Graph::make_dodos_in_space()
{
   _nodes.clear();
   std::string dodo;
   for(size_t i = 0; i < 50; i+=2)
   {
         dodo = "Yippee-Dodo-#" + std::to_string(i);
         add_edge(i,i+1,dodo);
   }
}
void Graph::make_purty_pitcher()
{
   _nodes.clear();
   add_edge(0,1, "i-see");
   add_edge(1,2, "the-silly-snake");
   add_edge(2,3, "i-be");
   add_edge(3,4, "you-saw-me");
   add_edge(4,5, "once-like");
   add_edge(5,0, "kekule");
}
