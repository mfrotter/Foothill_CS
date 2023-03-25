/*
 * Tree.cpp
 *
 *  Created on: Mar 14, 2022
 *      Author: mfrot
 */

#include "Tree.h"

Tree::Tree()
{

   _root = new Node("ROOT");

}

Tree::~Tree()
{
   delete _root; _root = nullptr;
}


Tree& Tree::operator=(const Tree& that)
{
   if (this!= &that)
   {
      if(that._root != nullptr)
      {
         delete _root;
         _root = new Node();
         *this->_root = *that._root;
      }
   }
   return *this;
}

bool Tree::Node::is_equal(const Tree::Node *p1, const Tree::Node *p2)
{
   bool childisEqual;
   bool siblingisEqual;
   if(p1->_child != nullptr && p2->_child != nullptr)
   {
      if(p1->_child->_data == p2->_child->_data)
         childisEqual = is_equal(p1->_child, p2->_child);
      else
         return false;

   }
   else if(p1->_child == nullptr && p2->_child == nullptr)
      childisEqual = true;

   if(p1-> _sibling != nullptr && p2->_sibling != nullptr)
   {
      if(p1->_sibling->_data == p2->_sibling->_data)
         siblingisEqual = is_equal(p1->_sibling,p2->_sibling);
      else
         return false;
   }
   else if(p1-> _sibling == nullptr && p2->_sibling == nullptr)
      siblingisEqual = true;

   return childisEqual && siblingisEqual;

   return false;
}

const Tree::Node& Tree::Node::operator=(const Tree::Node& that)
{
   if (this!= &that)
   {
      if(that._child != nullptr)
      {
         if(_child != nullptr)
         delete _child;
         _child = new Node();
         *this->_child = *that._child;
      }

      if(that._sibling != nullptr)
      {
         if(_sibling != nullptr)
         delete _sibling;
         _sibling = new Node();
         *this->_sibling = *that._sibling;
      }

         this->_data = that._data;

   }
   return *this;
}

std::string Tree::Node::to_string() const
{
   std::string partOne = this->_data + " :";
   std::string partTwo, newPartTwo, partFour, partFive;
   Node* next = _child;
   while(next != nullptr)
   {
      partTwo += " " + next->_data;

        next = next->_sibling;
   }
   std:: string partThree = "\n";
   if(this->_child != nullptr)
   {
      partFour += "# Child of " + this->_data + '\n';
      partFour += _child->to_string();
   }

   if(this->_sibling != nullptr)
   {
      partFive += "# Next sib of " + this->_data + '\n';
      partFive += _sibling->to_string();
   }

   return partOne + partTwo + partThree + partFour + partFive;

}

std::string Tree::to_string() const
{
   std::string phrase, phrase2;
   phrase = "# Tree rooted at " + _root->_data + '\n' + "# The following lines are of the form:" + '\n' + "#   node: child1 child2..." + '\n' + _root->to_string() + "# End of Tree" + '\n';

   return phrase;
}

void Tree::make_special_config_1(const std::vector<std::string>& names)
{

  Node* aaba = _root->insert_sibling(new Node(names[0]));
  Node* cobo = aaba->insert_child(new Node(names[4]));
  //Node* dibi =
  cobo->insert_child(new Node(names[12]));
  Node* coco = aaba->insert_child(new Node(names[5]));
  //Node* didi =
  coco->insert_child(new Node(names[13]));

  Node* abab = _root->insert_sibling(new Node(names[1]));
  Node* codo = abab->insert_child(new Node(names[6]));
  //Node* difi =
  codo->insert_child(new Node(names[14]));
  Node* cofo = abab->insert_child(new Node(names[7]));
  //Node* digi =
  cofo->insert_child(new Node(names[15]));

  Node* abba = _root->insert_sibling(new Node(names[2]));
  Node* cogo = abba->insert_child(new Node(names[8]));
  //Node* dihi =
  cogo->insert_child(new Node(names[16]));
  Node* coho = abba->insert_child(new Node(names[9]));
  //Node* diji =
  coho->insert_child(new Node(names[17]));

  Node* baba = _root->insert_sibling(new Node(names[3]));
  Node* cojo = baba->insert_child(new Node(names[10]));
  //Node* diki =
  cojo->insert_child(new Node(names[18]));
  Node* coko = baba->insert_child(new Node(names[11]));
  //Node* dili =
  coko->insert_child(new Node(names[19]));

  //std::cout << to_string();

}
