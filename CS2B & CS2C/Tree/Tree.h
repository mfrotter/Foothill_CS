// Student ID: 20504093
// Tree.h
//

#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include <iostream>
#include <sstream>

class Tree {
private:
   struct Node { // Inner class
      std::string _data;
      Node *_sibling, *_child;
      static bool is_equal(const Node *p1, const Node *p2);

      Node(std::string s = "") : _data(s), _sibling(nullptr), _child(nullptr) {}
      Node(const Node& that) { *this = that; }
      const Node& operator=(const Node& that); // Deep clone
      ~Node() {_data = ""; delete _sibling; _sibling = nullptr; delete _child; _child = nullptr;}

      std::string get_data() const { return _data; }
      void set_data(std::string s) { _data = s; }

      Node* insert_sibling(Node* p)
          {
            //if p is  null, then we don't do anything
            if (p == nullptr)
              return nullptr;

            //if we don't have a sibling, then make p our sibling
            if (_sibling == nullptr)
              _sibling = p;
            else
            {
              //else we have a sibling.
              Node* next = _sibling;

              //  Go through all of our siblings until we find one that doesn't have a sibling.
              while (next->_sibling)
                next = next->_sibling;

              //set the sibling that doesnt have a sibling to p
              next->_sibling = p;
            }

            return p;
          }

          Node* insert_child(Node* p)
          {
            //if p is null then we don't do anything
            if (p == nullptr)
              return nullptr;

            // if we have a child then we insert p as a sibling at our child.
            if (_child)
              return _child->insert_sibling(p);
            else
            {
              //else we dont have a child, so make p our child.
              _child = p;
            }
            return p;
          }


      std::string to_string() const;

      bool operator==(const Node& that) const
      {
         if(is_equal(this,&that) == true)
            return true;
         else
            return false;
      }
      bool operator!=(const Node& that) const
      {
         if(is_equal(this,&that) == false)
            return true;
         else
            return false;
      }

};

Node *_root;

public:
   Tree();
   ~Tree();

   Tree(const Tree& that) { *this = that; }
   Tree& operator=(const Tree& that); // Deep clone

   std::string to_string() const;
   void make_special_config_1(const std::vector<std::string>& names);

   bool operator==(const Tree& that) const
   {
      {
         if(Node::is_equal(this->_root,that._root) == true)
            return true;
         else
            return false;
      }
   }

   bool operator!=(const Tree& that) const
   {
      if(Node::is_equal(this->_root,that._root) == false)
         return true;
      else
         return false;
   }

friend std::ostream& operator<<(std::ostream& os, const Tree& tree)
   {
      return os;
   };

   friend class Tests; // Don't remove this line
};

#endif /* TREE_H_ */
