/*
 * Queue.cpp
 *
 *  Created on: Mar 21, 2022
 *      Author: mfrot
 */

#include "Queue.h"

//template <typename T>
//bool Queue<T>::enqueue(const T& elem)
//{
//   if(_head == (_tail + 1) & _data.size())
//      return false;
//   else
//   {
//      _tail = (_tail) % _data.size();
//      _data[_tail] = elem;
//   }
//}
//
//template <typename T> bool Queue<T>::dequeue()
//{
//   if(!is_empty())
//   {
//      _data.erase(_head);
//      _head = _head % _data.size();
//      return true;
//   }
//   else
//      return false;
//}
//
//template <typename T> const T& Queue<T>::peek() const
//{
//   return(_data[_head]);
//}
//
//template <typename T> bool Queue<T>::is_empty() const
//{
//   if(_head == _tail)
//      return true;
//   else
//      return false;
//}
//
//template <typename T> void Queue<T>::resize(size_t size)
//{
//   Queue newQueue;
//
//   while(!is_empty())
//   {
//      newQueue.enqueue(_head);
//      dequeue();
//   }
//
//   //newQueue._data = _data;
//}
//
//template <typename T>
//void popalot(Queue<T>& q)
//{
//   while(!q.is_empty())
//      q.dequeue();
//}
//
//template <typename T> std::string Queue<T>::to_string(size_t lim) const
//{
//   std::string phrase, data;
//   int count = 0;
//   phrase = "# Queue - size = " + std::to_string(_data.size()) + '\n';
//   for(size_t i = _data[_head];i < _data[_tail]; i++)
//   {
//      if(count == lim)
//      {
//         data = data + " ...";
//               break;
//      }
//      data += std::to_string(_data[i]) + " ";
//      count++;
//   }
//   return phrase + data + '\n';
//}

int main()
{
   Queue<size_t> nQueue(10);
   nQueue.enqueue(5);
   nQueue.enqueue(8);
   nQueue.enqueue(11);
   nQueue.enqueue(4);
   nQueue.enqueue(54);
   nQueue.enqueue(0);
   nQueue.enqueue(3);
   nQueue.dequeue();
  // std::cout << nQueue.size() << std::endl;
   nQueue.resize(3);

   //std::cout << nQueue.to_string();
}
