// Student ID: 20504093
// BST.h
//

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <algorithm>
using namespace std;

#ifndef BST_H_
#define BST_H_

// T must be Comparable. That is, must support ordering via <
template <typename T>
class BST {
private:
   struct Node {
      T _data;
      Node *_left, *_right;
      Node(const T &d, Node *l = nullptr, Node *r = nullptr) : _data(d), _left(l), _right(r) {}
   };
   Node *_root;
   size_t _size;

   // Helpers
   static Node *_deep_copy(const Node *p)
   {
       if (p == nullptr)
           return nullptr;

       Node* root_copy = new Node(p->_data);

       root_copy->_left = _deep_copy(p->_left);
       root_copy->_right = _deep_copy(p->_right);

       return root_copy;
   }

   bool _insert(Node *&p, const T &elem)
   {
      if (p == NULL)
         {
            p = new Node(elem, NULL, NULL);
            _size++;
            return true;
         }
         else if (elem < p->_data)
            return _insert(p->_left, elem);
         else if (p->_data < elem)
            return _insert(p->_right, elem);

         return false;
   }
   bool _remove(Node *&p, const T &elem)
   {
      if (p == NULL)
            return false;

         if (elem < p->_data)
            return _remove(p->_left, elem);
         if (p->_data < elem)
            return _remove(p->_right, elem);

         // found the node
         if (p->_left != NULL && p->_right !=NULL)
         {
            Node *minNode = _find_min(p->_right);
            p->_data = minNode->_data;
            _remove(p->_right, minNode->_data);
         }
         else
         {
            Node *nodeToRemove = p;
            p = (p->_left != NULL)? p->_left : p->_right;
            delete nodeToRemove;
            _size--;
         }
         return true;
   }
   bool _recursive_delete(Node *&p)
   {
       if (p == nullptr)
           return true;

       _recursive_delete(p->_left);
       _recursive_delete(p->_right);

       delete p;

       _size--;
       p = nullptr;
       return true;
   }

   Node *_find_min(Node *p) const
   {
      if (p == NULL)
         return NULL;
      if (p->_left == NULL)
         return p;
      return _find_min(p->_left);
   }
   Node *_find(Node *p, const T &elem) const
   {
      if (p == NULL)
         return NULL;

      if (elem < p->_data)
         return _find(p->_left, elem);
      if (p->_data < elem)
         return _find(p->_right, elem);
      return p;
   }
   string _to_string(const Node *p) const
   {
      string line;
      ostringstream ostring;

      if(p == NULL)
         return line;

      if(p->_left == NULL && p->_right == NULL)
         return line;

      if(p->_left == NULL)
      {
         ostring << p->_data << " : [null] " << p->_right->_data << endl;
      }

      else if(p->_right == NULL)
      {
         ostring << p->_data << " : " << p->_left->_data << " [null]" << endl;
      }

      else
      {
         ostring << p->_data << " : " << p->_left->_data << " " << p->_right->_data << endl;
      }


      ostring << _to_string(p->_left);

      ostring << _to_string(p->_right);

      line = ostring.str();
      return line;

   }

public:
   BST() : _root(nullptr), _size(0) {}
   virtual ~BST() {_recursive_delete(_root); }

   virtual size_t get_size() const {return _size; }

   virtual bool insert(const T &elem) {return _insert(_root, elem); }
   virtual bool remove(const T &elem) {return _remove(_root, elem); }
   virtual bool clear()
   {
      if(_root == nullptr)
         return false;

      _recursive_delete(_root);
      return true;
   }

   virtual bool contains(const T &elem) const {return _find(_root, elem) != nullptr; }
   virtual T &find(const T &elem) const
   {
      Node *resultNode;

      resultNode = _find(_root, elem);
      if (resultNode == NULL)
         throw Not_found_exception();
       return resultNode->_data;
   }
   virtual string to_string() const
   {
      string line;
      ostringstream ostream;
      ostream << "# Tree rooted at " << _root->_data << endl;
      ostream << "# size = " << _size << endl;
      ostream << _to_string(_root) << endl;
      ostream << "# End of tree ";

      line = ostream.str();
      return line;
   }

   class Not_found_exception : public exception {
   public:
      string to_string() { return "Not found exception"; }
   };

   friend class Tests; // Don't Remove
};





#endif /* BST_H_ */
