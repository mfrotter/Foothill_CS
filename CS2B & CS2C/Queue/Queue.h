// Student ID: 20504093
// Shapes.h
//

#ifndef QUEUE_H_
#define QUEUE_H_

#include <vector>
#include <iostream>
#include <sstream>

// TODO: Fill in as necessary

template <typename T>
class Queue {
private:
   std::vector<T> _data;
   size_t _head, _tail;
   static T _sentinel;

public:
   static const int MAX_DISP_ELEMS = 100;

   Queue(size_t size);

   static void set_sentinel(const T& elem) { _sentinel = elem; }
   static T get_sentinel() { return _sentinel; }

   bool is_empty() const
   {
      if(_head == _tail)
         return true;
      else
         return false;
   }

   size_t size() const
   {
      return _tail;
   }
   void resize(size_t size)
   {
      Queue newQueue(size);


      while(!is_empty())
      {
         newQueue.enqueue(_data[_head]);
         dequeue();
      }

      _tail = newQueue._tail;
      _head = newQueue._head;
      _data = newQueue._data;

//      for(size_t i = 0; i < _data.size(); i++)
//      {
//         std::cout << _data[i] << std::endl;
//      }

   }

   const T& peek() const
   {
      if(!is_empty())
         return(_data[_head]);
      else
         return _sentinel;
   }

   bool dequeue()
   {
      if(!is_empty())
      {
         _data.erase(_data.begin());
         //_head = _head % _data.size();
         _tail--;
         return true;
      }
      else
         return false;
   }

   bool enqueue(const T& elem)
   {
      if(_head == (_tail + 1) % _data.size())
         return false;
      else
      {
         //_tail = (_tail) % _data.size();
         _data[_tail] = elem;
         //std::cout << _data[_tail] << std::endl;
         _tail++;
         return true;
      }
   }

   std::string to_string(size_t limit = MAX_DISP_ELEMS) const
   {
      std::string phrase, data;
      size_t count = 0;
      phrase = "# Queue - size = " + std::to_string(_tail) + '\n' + "data :";
      for(size_t i = _head;i < (size_t)_tail; i++)
      {
         if(count == limit)
         {
            data = data + " ...";
                  break;
         }
         data += std::to_string(_data[i]) + " ";
         count++;
      }
      return phrase + data + '\n';
   }

   friend class Tests; // Don't remove this line
};
template <typename T> T Queue<T>::_sentinel = T();

template <typename T>
Queue<T>::Queue(size_t size) {
   _data.resize(size+1);
   _head = 0;
   _tail = 0;
   //std::cout << _data.size() << std::endl;
}

template <typename T>
void popalot(Queue<T>& q)
{
   while(!q.is_empty())
      q.dequeue();
}


// TODO - Fill in the missing implementations. Experiment with the aesthetics by moving
// some of these implementations inline (into your class def above). See which gives
// you more readable code.

#endif /* Queue_h */

