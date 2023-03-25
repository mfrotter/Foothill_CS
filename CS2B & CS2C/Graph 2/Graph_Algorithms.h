// Student ID: 20504093
// Graph_Algorithms.h
//

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <algorithm>
#include <cfloat>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

#include "Graph.h"


#ifndef GRAPH_ALGORITHMS_H_
#define GRAPH_ALGORITHMS_H_

class Gx
{
private:
   struct NW { // package three co-used qtys
      int node, pred;
      float weight;
      NW(int n, int m, float wt) : node(n), pred(m), weight(wt) {}
      bool operator<(const NW &that) const {return this->weight > that.weight; }
      bool operator>(const NW &that) const {return this->weight < that.weight; }
   };

   struct Node {
       int vertex;
       float weight;
   };

   struct compmin
   {
       bool operator()(const Node &lhs, const Node &rhs) const {
           return lhs.weight > rhs.weight;
       }
   };

   struct compmax
   {
       bool operator()(const Node &lhs, const Node &rhs) const {
           return lhs.weight < rhs.weight;
       }
   };

   static float _get_max_capacity_path(const Graph &g, int src, int dst, std::vector<int> &path)
   {
      int source = src;

      if(src == dst)
      {
         path.push_back(src);
         return 0;
      }

      vector<bool> visited;
      vector<float> pred;
      vector<float> dist;

      path.resize(0);

      int adjecent;
      visited.resize(g.get_num_nodes(), false);
      pred.resize(g.get_num_nodes(), -1);
      dist.resize(g.get_num_nodes(), 0);


      priority_queue<Node,vector<Node>, compmax> max_heap;

      visited[src] = true;
      dist[src] = 0;
      max_heap.push({src, FLT_MAX});

      while(!max_heap.empty())
       {
           // Dequeue a vertex from queue and print it
           Node node = max_heap.top();
//           cout << "the vertex to be compared is " << node.vertex << endl;
           max_heap.pop();

           src = node.vertex;

           // Get all adjacent vertices of the dequeued
           // vertex s. If a adjacent has not been visited,
           // then mark it visited and enqueue it
           for (size_t i = 0; i < g._nodes[src].size(); i++)
           {
              adjecent = g._nodes[src][i].dst;
//              cout << "dist[src] + weight = " <<  dist[src] + g._nodes[src][i].wt << " for adjecent " << adjecent << endl;
              if (!visited[adjecent] && (dist[src] + g._nodes[src][i].wt) > dist[adjecent])
              {
//                 cout << "adjecent " << adjecent << " was less than dist[adjecent]" << endl;

                  dist[adjecent] = dist[src] + g._nodes[src][i].wt;
                  pred[adjecent] = src;

//                  cout << "before pushing, the weight of vertex " << adjecent << " is " << dist[adjecent] << endl;
                  max_heap.push({adjecent, dist[adjecent]});;
//                  cout << "the top of heap is " << max_heap.top().vertex << " with weight " << max_heap.top().weight << endl;
              }

//              cout << "g._nodes[src][i].dst is " << g._nodes[src][i].dst << " and weight is " << dist[src] + g._nodes[src][i].wt << " and min_heap.top().weight is " << max_heap.top().weight << endl;
           }

           visited[src] = true;

       }

      if (dst != source && dist[dst] != INT_MAX)
      {
         int crawl = dst;
           path.push_back(crawl);
           while (pred[crawl] != -1)
           {
              path.push_back(pred[crawl]);
              crawl = pred[crawl];
           }

           std::reverse(path.begin(), path.end());
//           for(size_t i = 0; i < path.size(); i++)
//              cout << "the vector is " << path[i] << endl;
//           cout << endl;

//           cout << g.to_string() << endl;

           return dist[dst];
      }

      path.clear();

      return 0;
   }

   static float _get_capacity_of_this_path(const Graph &g, const std::vector<int> &path)
   {
      float capacity = 0;
      vector<float> capvec;
      capvec.resize(0);

      if(path.size() == 0)
         return 0;

      for(size_t i = 0; i < path.size()-1; i++)
      {
//         cout << "path+1 is " << path[i+1] << endl;
         for(size_t j = 0; j < g._nodes[path[i]].size(); j++)
         {
            if(g._nodes[path[i]][j].dst == path[i+1])
            {
//               cout << "the dst is " << g._nodes[path[i]][j].dst << endl;
               capvec.push_back(g._nodes[path[i]][j].wt);
//               capacity += g._nodes[path[i]][j].wt;
//               cout << "capacity is " << capacity << endl;
            }
         }
      }

      if(capvec.size() != 0)
      {
         capacity = *min_element(capvec.begin(), capvec.end());

         return capacity;
      }
      else
         return 0;
   }


   static bool _is_cyclic(const Graph &g, size_t node, std::vector<bool> seen, std::vector<bool>& cycle_free)
   {
      if(seen[node] == false)
      {
          // Mark the current node as visited and part of recursion stack
          seen[node] = true;
          cycle_free[node] = true;

          // Recur for all the vertices adjacent to this vertex
          for(size_t i = 0; i < g._nodes[node].size(); i++)
          {
              if ( !seen[g._nodes[node][i].dst] && _is_cyclic(g, g._nodes[node][i].dst, seen, cycle_free) )
                  return true;
              else if (cycle_free[g._nodes[node][i].dst])
                  return true;
          }

      }
      cycle_free[node] = false;  // remove the vertex from recursion stack

      return false;
   }

public:
   static bool is_cyclic(const Graph &g)
   {
      vector<bool> seen, cycle_free;
      seen.resize(g.get_num_nodes());
      cycle_free.resize(g.get_num_nodes());

      for(size_t i = 0; i < g.get_num_nodes(); i++)
      {
         seen[i] = false;
         cycle_free[i] = false;
      }


      for(size_t i = 0; i < g.get_num_nodes(); i++)
      {
         if( !seen[i] && _is_cyclic(g,i,seen,cycle_free))
            return true;
      }

      return false;

   }
   static bool prune_unreachables(Graph &g, int src)
   {
      if(src < 0 || (size_t) src > g.get_num_nodes())
         return false;

      int adjecent;

      vector<int> reachable;

      reachable.push_back(src);
//
//      for(size_t i = 0; i < g._nodes[src].size(); i++)
//      {
//         reachable.push_back(g._nodes[src][i].dst);
//      }
//
//      for(size_t i = 0; i < g.get_num_nodes(); i++)
//      {
//         if(std::find(reachable.begin(), reachable.end(), i) == reachable.end())
//            g._nodes[i].clear();
//      }
//
//      return true;


       // Mark all the vertices as not visited
       vector<bool> visited;
       visited.resize(g.get_num_nodes(),false);

       // Create a queue for BFS
       list<int> queue;

       // Mark the current node as visited and enqueue it
       visited[src] = true;
       queue.push_back(src);

       while(!queue.empty())
       {
           // Dequeue a vertex from queue and print it
           src = queue.front();
           queue.pop_front();

           // Get all adjacent vertices of the dequeued
           // vertex s. If a adjacent has not been visited,
           // then mark it visited and enqueue it
           for (size_t i = 0; i < g._nodes[src].size(); i++)
           {
              adjecent = g._nodes[src][i].dst;
               if (!visited[adjecent])
               {
                   visited[adjecent] = true;
                   queue.push_back(adjecent);
                   reachable.push_back(adjecent);
               }
           }
       }

       for(size_t i = 0; i < g.get_num_nodes(); i++)
       {
          if(std::find(reachable.begin(), reachable.end(), i) == reachable.end())
             g._nodes[i].clear();
       }

       return true;

   }
   static size_t get_shortest_unweighted_path(const Graph &g, int src, int dst, std::vector<int> &path)
   {
      if(src == dst)
      {
         path.push_back(src);
         return 1;
      }

      vector<bool> visited;
      vector<int> pred;
      vector<int> dist;

      path.resize(0);

      int adjecent;
      visited.resize(g.get_num_nodes(), false);
      pred.resize(g.get_num_nodes(), -1);
      dist.resize(g.get_num_nodes(), -1);


      list<int> queue;

      visited[src] = true;
      dist[src] = 0;
      queue.push_back(src);

      while(!queue.empty())
       {
           // Dequeue a vertex from queue and print it
           src = queue.front();
           queue.pop_front();

           // Get all adjacent vertices of the dequeued
           // vertex s. If a adjacent has not been visited,
           // then mark it visited and enqueue it
           for (size_t i = 0; i < g._nodes[src].size(); i++)
           {
              adjecent = g._nodes[src][i].dst;
//              cout << "adjecent is " << adjecent << endl;
              if (!visited[adjecent])
              {
                  visited[adjecent] = true;
                  dist[adjecent] = dist[src] + 1;
                  pred[adjecent] = src;
                  queue.push_back(adjecent);

                  if(g._nodes[src][i].dst == dst)
                  {
                     int crawl = dst;
                     path.push_back(crawl);
                     while (pred[crawl] != -1)
                     {
                        path.push_back(pred[crawl]);
                        crawl = pred[crawl];
                     }

                     std::reverse(path.begin(), path.end());
                     for(size_t i = 0; i < path.size(); i++)
                        cout << "the vector is " << path[i] << endl;
                     cout << endl;
                     return dist[dst]+1;
                  }
              }
           }
       }

      path.clear();

      return string::npos;
   }

   static size_t get_shortest_weighted_path(const Graph &g, int src, int dst, std::vector<int> &path)
   {
      int source = src;

      if(src == dst)
      {
         path.push_back(src);
         return 1;
      }

      vector<bool> visited;
      vector<float> pred;
      vector<float> dist;

      path.resize(0);

      int adjecent;
      visited.resize(g.get_num_nodes(), false);
      pred.resize(g.get_num_nodes(), -1);
      dist.resize(g.get_num_nodes(), INT_MAX);


      priority_queue<Node,vector<Node>, compmin > min_heap;

      visited[src] = true;
      dist[src] = 0;
      min_heap.push({src, 0});

      while(!min_heap.empty())
       {
           // Dequeue a vertex from queue and print it
           Node node = min_heap.top();
//           cout << "the vertex to be compared is " << node.vertex << endl;
           min_heap.pop();

           src = node.vertex;

           // Get all adjacent vertices of the dequeued
           // vertex s. If a adjacent has not been visited,
           // then mark it visited and enqueue it
           for (size_t i = 0; i < g._nodes[src].size(); i++)
           {
              adjecent = g._nodes[src][i].dst;
//              cout << "dist[src] + weight = " <<  dist[src] + g._nodes[src][i].wt << " for adjecent " << adjecent << endl;
              if (!visited[adjecent] && (dist[src] + g._nodes[src][i].wt) < dist[adjecent])
              {
//                 cout << "adjecent " << adjecent << " was less than dist[adjecent]" << endl;

                  dist[adjecent] = dist[src] + g._nodes[src][i].wt;
                  pred[adjecent] = src;

//                  cout << "before pushing, the weight of vertex " << adjecent << " is " << dist[adjecent] << endl;
                  min_heap.push({adjecent, dist[adjecent]});;
//                  cout << "the top of heap is " << min_heap.top().vertex << " with weight " << min_heap.top().weight << endl;
              }

//              cout << "g._nodes[src][i].dst is " << g._nodes[src][i].dst << " and weight is " << dist[src] + g._nodes[src][i].wt << " and min_heap.top().weight is " << min_heap.top().weight << endl;
           }

           visited[src] = true;

       }

      if (dst != source && dist[dst] != INT_MAX)
      {
         int crawl = dst;
           path.push_back(crawl);
           while (pred[crawl] != -1)
           {
              path.push_back(pred[crawl]);
              crawl = pred[crawl];
           }

           std::reverse(path.begin(), path.end());
//           for(size_t i = 0; i < path.size(); i++)
//              cout << "the vector is " << path[i] << endl;
//           cout << endl;

           return path.size();
      }

      path.clear();

      return string::npos;
   }

   static float get_max_flow(const Graph &g, int src, int dst)
   {
      vector<int> path;
      path.resize(0);

      size_t v, u;

      Graph residual;

      float max_flow = 0;
      float path_flow = INT_MAX;

      for(size_t i = 0; i < g._nodes.size(); i++)
      {
         if(!g._nodes[i].empty())
         {
            for(size_t j = 0; j < g._nodes[i].size(); j++)
               residual.add_edge(i, g._nodes[i][j].dst, g._nodes[i][j].wt, true);

         }
      }

      _get_max_capacity_path(residual,src,dst,path);
      while(_get_capacity_of_this_path(residual,path) > 0)
      {

         path_flow = _get_capacity_of_this_path(residual,path);

//         cout << "path_flow is " << path_flow << endl;

//         for(size_t i = 0; i < path.size(); i++)
//            cout << "the vector is " << path[i] << endl;
//         cout << endl;


         for (size_t i = 0; i < path.size() - 1; i++)
         {
//            cout << "i is " << i << endl;
            v = path[i+1];
            u = path[i];

//            cout << "u is " << u << " and v is " << v << endl;

            residual.add_edge(u, v, -path_flow, false);
            residual.add_edge(v, u, path_flow, false);

//            for(size_t i = 0; i < residual._nodes[u].size(); i++)
//            {
//               if(residual._nodes[u][i].dst == v)
//               {
//                  residual._nodes[u][i].wt -= path_flow;
//               }
//            }
//            residual._nodes[u][v].wt -= path_flow;
//            residual._nodes[v][u].wt += path_flow;

            v--;
         }

         _get_max_capacity_path(residual,src,dst,path);

         max_flow += path_flow;

      }

      return max_flow;

   }

   friend class Tests; // Don't remove

};

#endif /* GRAPH_ALGORITHMS_H_ */
