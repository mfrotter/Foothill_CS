// Student ID: 20504093
// Trie.h
//

#ifndef TRIE_H_
#define TRIE_H_

#include <vector>
#include <iostream>
#include <sstream>
#include <queue>

class Trie {
private:
   struct Node {
      std::vector<Trie::Node *> next;

      ~Node()
      {
         for(size_t i = 0; i < next.size(); i++)
         {
            delete next[i];
            next[i] = nullptr;
         }
      }

      void insert(std::string s);
      const Node *traverse(std::string s) const
      {
         const Trie::Node *instance = this;
         for(const char *str = s.c_str(); *str; str++)
         {
            char ch = *str;
            if ((size_t) ch >= instance->next.size())
               return nullptr;

            if (instance->next[ch] != nullptr)
               instance = instance->next[ch];
            else
               return nullptr;
         }

         return instance;
      }
      bool lookup(std::string s) const;
      size_t get_completions(std::vector<std::string>& completions, size_t limit) const;
   } *_root;

   // Private Trie:: helper. Returns the interior node traversing s from _root
   const Node *traverse(std::string s) const { return _root->traverse(s); }

public:
   Trie();
   ~Trie();

   void insert(std::string s) {_root->insert(s); }
   bool lookup(std::string s) const { return _root->lookup(s); }
   size_t get_completions(std::string s, std::vector<std::string>& completions, size_t limit) const;
   size_t trie_sort(std::vector<std::string>& vec) const;

   std::string to_string(size_t n) const;
   std::ostream& operator<<(std::ostream& os) { return os << to_string(100); }

   friend class Tests; // Don't remove

};

#endif /* TRIE_H_ */
