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



#ifndef LAZY_BST_H_
#define LAZY_BST_H_

template <typename T>
class Lazy_BST {
protected:
   struct Node {
      T _data;
      Node *_left, *_right;
      bool _is_deleted;

      Node(const T &d) : _data(d), _left(nullptr), _right(nullptr), _is_deleted(false) {}
   };
   Node *_root;
   size_t _size, _real_size;

   // Private helpers
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

   bool _insert(Node *&p, const T &elem)
   {
      if (p == NULL)
      {
         p = new Node(elem);
         _size++;
         _real_size++;
         return true;
      }

      if (p->_is_deleted == true && p->_data == elem)
      {
         p->_is_deleted = false;
         //cout << "was inserted" << endl;
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
      if (p->_is_deleted == true && p->_data == elem)
      {
         return false;
      }

         if (elem < p->_data)
            return _remove(p->_left, elem);
         if (p->_data < elem)
            return _remove(p->_right, elem);

         // found the node
         if (p->_left != NULL && p->_right !=NULL)
         {
//            Node *minNode = _find_min(p->_right);
//            p->_data = minNode->_data;
            //cout << "is found" << endl;
            p->_is_deleted = true;
//            _remove(p->_right, minNode->_data);
            _size--;
         }
         else
         {
            //p = (p->_left != NULL)? p->_left : p->_right;
            //cout << p->_data << " set to deleted" << endl;
            p->_is_deleted = true;
            _size--;
         }
         return true;
   }

   bool _collect_garbage(Node *&p)
   {
      //bool removed = false;
      if (p == NULL)
      {
         //cout << "NULL?" << endl;
         return false;
      }



      //cout << "we got this far" << endl;

      _collect_garbage(p->_left);

      //cout << "here?" << endl;
      _collect_garbage(p->_right);

      if (p->_is_deleted == true)
      {
         _really_remove(p,p->_data);
         return true;
      }

//      if (removed == true)
//      {
//         //cout << "removed" << endl;
//         _collect_garbage(_root);
//         return true;
//      }

      //cout << "finished?" << endl;
      return true;
   }

   Node *_find_min(Node *p) const
   {
      //T min = NULL;
      if (p == NULL)
         return NULL;

//      if(p->_is_deleted == false)
//         if(min == NULL)
//            min = p->_data;

      if(_find_min(p->_left) != NULL)
         return _find_min(p->_left);
      if(p->_is_deleted == false)
         return p;

      if(_find_min(p->_right) != NULL)
         return _find_min(p->_right);

      return NULL;

//      _find_min2(p->_left, min);
//      _find_min2(p->_right, min);
//
//      return _find(_root, min);
   }

   void _find_min2(Node *p, T &min) const
   {
      if (p == NULL)
         return;

      if(p->_is_deleted == false)
         if(p->_data < min || min == NULL)
            min = p->_data;

      _find_min2(p->_left, min);
      _find_min2(p->_right, min);
   }

   Node *_find_real_min(Node *p) const
   {
      if (p == NULL)
         return NULL;
      if (p->_left == NULL)
         return p;
      return _find_real_min(p->_left);
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

   bool _really_remove(Node *&p, const T &elem)
   {
      if (p == NULL)
            return false;

         if (elem < p->_data)
         {
            //cout << elem << " #1" << endl;
            return _really_remove(p->_left, elem);
         }
         if (p->_data < elem)
         {
            //cout << elem << " #2" << endl;
            return _really_remove(p->_right, elem);
         }

         // found the node
         if (p->_left != NULL && p->_right !=NULL)
         {
            //cout << elem << " #3" << endl;
            Node *minNode = _find_real_min(p->_right);
            p->_data = minNode->_data;
            p->_is_deleted = minNode ->_is_deleted;
            _really_remove(p->_right, minNode->_data);
         }
         else
         {
            //cout << elem << " #4" << endl;
            Node *nodeToRemove = p;
            p = (p->_left != NULL)? p->_left : p->_right;
            delete nodeToRemove;
            _real_size--;
         }
         return true;
   }

   string _to_string(const Node *p) const
   {
      string line;
      ostringstream ostring;

      if(p == NULL)
         return line;

      if(p->_left == NULL && p->_right == NULL)
         return line;

      if(p->_is_deleted == true)
      {
         ostring << p->_data << "* : ";
      }

      else
      {
         ostring << p->_data << " : ";
      }

      if(p->_left == NULL)
      {
         ostring << "[null] ";
      }

      else if(p->_left->_is_deleted == true)
      {
         ostring << p->_left->_data << "* ";
      }

      else
      {
         ostring << p->_left->_data << " ";
      }

      if(p->_right == NULL)
      {
         ostring << "[null]" << endl;
      }

      else if(p->_right-> _is_deleted == true)
      {
         ostring << p->_right->_data << "*" << endl;
      }

      else
      {
         ostring << p->_right->_data << endl;
      }


      ostring << _to_string(p->_left);

      ostring << _to_string(p->_right);

      line = ostring.str();
      return line;

   }

public:
   Lazy_BST() : _root(nullptr), _size(0), _real_size(0) {}
   ~Lazy_BST() { _recursive_delete(_root); }

   size_t get_size() const { return _size;}
   size_t get_real_size() const { return _real_size; }
   bool insert(const T &elem) { return _insert(_root, elem); }
   bool remove(const T &elem) { return _remove(_root, elem); }
   bool collect_garbage() {return _collect_garbage(_root); }
   T find_Min() {return _find_min(_root)->_data; }
   bool contains(const T &elem) const { return _find(_root, elem) != nullptr; }
   const T &find(const T &elem) const
   {
      Node *resultNode;

      resultNode = _find(_root, elem);
      if (resultNode == NULL)
         throw Not_found_exception();
       return resultNode->_data;
   }

   string to_string() const
   {
      string line;
      ostringstream ostream;
      if (_root->_is_deleted == true)
         ostream << "# Tree rooted at " << _root->_data << "*" << endl;
      else
         ostream << "# Tree rooted at " << _root->_data << endl;
      ostream << "# size = " << _size << endl;
      ostream << _to_string(_root) << endl;
      ostream << "# End of tree ";

      line = ostream.str();
      return line;
   }

   bool clear()
   {
      if(_root == nullptr)
         return false;

      _recursive_delete(_root);
      return true;
   }

   class Not_found_exception : public exception {
   public:
      string what() { return "Element not found exception"; }
   };
   friend class Tests; // Don't remove this line
};




#endif /* LAZY_BST_H_ */
