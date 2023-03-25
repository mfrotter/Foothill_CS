/*
 * Trie.cpp
 *
 *  Created on: Mar 21, 2022
 *      Author: mfrot
 */

#include "Trie.h"

Trie::Trie()
{
   _root = new Node;
}

Trie::~Trie()
{
   delete _root; _root = nullptr;
}

void Trie::Node::insert(std::string s)
{
   Node *curr = this;
   for(const char *str = s.c_str(); *str; str++)
   {
      char ch = *str;
      if ((size_t) ch >= curr->next.size())
         curr->next.resize(ch+1);

      if (curr->next[ch] != nullptr)
         curr = curr->next[ch];
      else
         curr = curr->next[ch] = new Node;
   }

   if (curr->next.size() < 1)
      curr->next.resize(1);

   if (curr->next[0] == nullptr)
      curr->next[0] = new Node;
}

bool Trie::Node::lookup(std::string s) const
{
   if(traverse(s) == nullptr)
      return false;
   else
      return true;
}

size_t Trie::Node::get_completions(std::vector<std::string>& completions, size_t limit) const
{
   struct Continuation {
      const Trie::Node *node;
      std::string partial;
      Continuation(const Node *p, std::string s) : node(p), partial(s) {}
   };

   completions.clear();
   Continuation cont(this,"");

   // All string descendants of this node are completions
   std::queue<Continuation> unprocessed_nodes;

   unprocessed_nodes.push(cont);

   while(!unprocessed_nodes.empty()) {
      Continuation cont = unprocessed_nodes.front();
      unprocessed_nodes.pop();

      if(completions.size() == limit)
         return completions.size();

      for(size_t i = 0; i < cont.node->next.size(); i++)
      {
         if(cont.node->next[i] == nullptr)
            continue;
         if(i == 0)
            completions.push_back(cont.partial);// + (char)0);
         else
         {
            Continuation temp(cont.node->next[i], cont.partial + (char)i);
            unprocessed_nodes.push(temp);
         }
      }

   }
   return completions.size();
}

size_t Trie::get_completions(std::string s, std::vector<std::string>& completions, size_t limit) const
{
   const Node *tempNode = _root->traverse(s);
   completions.clear();
   if(tempNode == nullptr)
      return 0;
   return tempNode->get_completions(completions,limit);
}

std::string Trie::to_string(size_t limit) const
{
   std::string lineOne = "# Trie contents\n";
   std::string lineTwo;
   std::vector<std::string> completions;
   size_t newLimit = get_completions("",completions, limit);
   for(size_t i=0; i < newLimit; i++)
   {
      lineTwo += completions[i] + '\n';
   }
   if(newLimit == limit)
      lineTwo = lineTwo + "...\n";

   return lineOne + lineTwo;
}

size_t Trie::trie_sort(std::vector<std::string>& vec) const
{
   vec.clear();
   return get_completions("", vec, -1);
}
