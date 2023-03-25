// Playlist.cpp

#include <iostream>
#include <sstream>

#include <vector>

#include "Playlist.h"

using namespace std;

class Song_Entry;
class Node;

Playlist::Playlist()
{
   Song_Entry Default(-1,"HEAD");
   _tail = new Node(Default);
   _tail->get_song();
   _tail->get_next();
   _head = _tail;
   _prev_to_current = _tail;
   _t = _tail;
   _size = 0;

}

Playlist::~Playlist()
{
   clear();
   delete _head;
}

Playlist *Playlist::insert_at_cursor(const Song_Entry& s)
{
   Node* newNode = new Node;
   newNode->get_song() = s;
   newNode->insert_next(_prev_to_current->get_next());
   _prev_to_current->insert_next(newNode);
   if(newNode->get_next() == nullptr)
      _tail = newNode;
   _size++;
   return this;

//   Node* newNode = new Node;
//   newNode->data = s;
//   newNode->next=_prev_to_current->next;
//   _prev_to_current->next = newNode;
//   if(newNode->next == nullptr)
//      _tail = newNode;
//   _size++;
//   return this;


}

Playlist *Playlist::push_back(const Song_Entry& s)
{

   _tail = new Node;
   _tail->get_song() = s;
   _tail->insert_next(nullptr);

   if(_head->get_next() == nullptr)
   {
      //cout << "hi" << endl;
      _head->insert_next(_tail);
      //cout << _tail->get_song() << endl;;
      _size++;
      return this;
   }



   Node *last = _head;
   //cout << "we here" << endl;
   while (last->get_next() != nullptr)
   {
      last = last->get_next();
      //cout << "we here 2" << endl;
      //cout << last->get_next()->get_song() << endl;
   }
   last->insert_next(_tail);
   _size++;
   return this;
}

Playlist *Playlist::push_front(const Song_Entry& s)
{
   Node* newNode = new Node;
   newNode->get_song() = s;
   newNode->insert_next(_head->get_next());
   _head->insert_next(newNode);
   if(newNode->get_next() == nullptr)
      _tail = newNode;
   //_prev_to_current = _head;
   _size++;
   return this;
}

Playlist *Playlist::advance_cursor()
{
   if (_prev_to_current == _tail)
      return nullptr;
   _prev_to_current= _prev_to_current->get_next();
   return this;
}

Playlist *Playlist::circular_advance_cursor()
{
   if (_prev_to_current->get_next() == _tail)
   {
      _prev_to_current = _head;
      return this;
   }
   _prev_to_current= _prev_to_current->get_next();
   return this;
}

Playlist::Song_Entry& Playlist::get_current_song() const
{
   if (_prev_to_current->get_next() != nullptr)
      return _prev_to_current->get_next()->get_song();
   else
      return _head->get_song();
}

Playlist *Playlist::remove_at_cursor()
{
   {
      _t = _prev_to_current;
      if (_t->get_next() == nullptr)
      {
         return nullptr;
      }

      _t = _t->get_next();
      if (_t->get_next() == nullptr)
      {
         _tail = _prev_to_current;
         _tail->insert_next(nullptr);
         _size--;
         return this;
      }

      _t = _t->get_next();
      _prev_to_current->insert_next(_t);
      _size--;
      return this;

   }
}

Playlist *Playlist::rewind()
{
   _prev_to_current = _head;
   return this;
}

Playlist *Playlist::clear()
{
   rewind();
   size_t permaSize = _size;
   for(size_t i=0; i < permaSize; i++)
   {
      remove_at_cursor();
   }

   return this;

}

Playlist::Song_Entry& Playlist::find_by_id(int id) const
{
   Node *_p = _head;
   while(_p != nullptr)
   {
      if(_p->get_song().get_id() == id)
      {
         return _p->get_song();
      }

      _p = _p->get_next();
   }
      return _head->get_song();
}

Playlist::Song_Entry& Playlist::find_by_name(string id) const
{
   Node *_p = _head;
   while(_p != nullptr)
   {
      if(_p->get_song().get_name() == id)
      {
         return _p->get_song();
      }

      _p = _p->get_next();
   }
      return _head->get_song();
}

string Playlist::to_string() const
{
   std::string newSong = "";
         std::stringstream prevSong;
         //std::string newName = "";
               //std::string prevName = "";
         std::stringstream ellipses;
         int count = 0;
         Node *_p = _prev_to_current->get_next();
         while(_p != nullptr && count < 25)
         {
            if(_p == _tail)
               prevSong << _p->get_song() << " [T]" << std::endl;
            else if(_p == _prev_to_current)
               prevSong << _p->get_song() << " [P]" << std::endl;
            else
               prevSong <<_p->get_song() << std::endl;
            _p = _p->get_next();
            newSong = prevSong.str();
            if(count == 24)
               ellipses << "..." << std::endl;
            count++;
         }
         return std::string("Playlist: ") + std::to_string(_size) + std::string(" entries.") + '\n' + newSong + ellipses.str();// + '\n'; // + std::string(", name: "); //+ newName + std::string(" }")+ ellipses;

}
