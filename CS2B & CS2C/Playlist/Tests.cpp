/*
 * Tests.cpp
 *
 *  Created on: Jan 24, 2022
 *      Author: mfrot
 */

#include <iostream>
#include <sstream>

#include <vector>

#include "Tests.h"

Tests::Tests()
{
   // TODO Auto-generated constructor stub

}

Tests::~Tests()
{
   // TODO Auto-generated destructor stub
}

void Tests::testStacks()
{

Playlist::Node newNode;

//Playlist::Node* test = new Playlist::Node;
//Playlist::Node::insert_next(Playlist::Node test);

Playlist playlist;
Playlist::Song_Entry song;
song.set_id(1);
song.set_name("song");

Playlist::Song_Entry song2;
song2.set_id(2);
song2.set_name("song2");

Playlist::Song_Entry song3;
song3.set_id(3);
song3.set_name("song3");

Playlist::Song_Entry song4;
song4.set_id(4);
song4.set_name("song4");

Playlist::Song_Entry song5;
song5.set_id(5);
song5.set_name("song5");


//playlist.insert_at_cursor(song);
//playlist.insert_at_cursor(song2);
//playlist.push_front(song);
//playlist.push_front(song2);
//playlist.push_front(song3);
//playlist.push_front(song4);
//playlist.push_back(song);
//std:: cout << playlist._head->get_next()->get_song()<< std::endl;
playlist.push_back(song);
playlist.push_back(song2);
playlist.push_back(song3);
playlist.push_back(song4);
playlist.push_back(song5);
//playlist.rewind();
//std::cout << playlist.get_current_song() << std::endl;
//playlist.advance_cursor();
//std::cout << playlist.get_current_song()<< std::endl;
//playlist.advance_cursor();
//std::cout << playlist.get_current_song()<< std::endl;
//playlist.advance_cursor();
//std::cout << playlist.get_current_song()<< std::endl;

//std:: cout << playlist._tail->get_next()->get_song()<< std::endl;
//playlist.push_front(song2);
//playlist.push_front(song3);
//playlist.insert_at_cursor(song2);
//std::cout << playlist._prev_to_current->get_song() << std::endl;
//std::cout <<playlist.get_current_song() << std::endl;
//playlist.advance_cursor();
//std::cout << playlist._tail->get_song();
//playlist.rewind();
std::cout << playlist.to_string();
//std::cout << song.get_id();
//std::cout << song.get_name();

//
//.
//   std::cout << stack.to_string();

//   String_List stack;
//   stack.push_front("4");
//   stack.push_front("2");
//   stack.insert_at_current("26");
//   stack.insert_at_current("25");
//   stack.insert_at_current("24");
//   stack.insert_at_current("23");
//   stack.insert_at_current("22");
//   stack.insert_at_current("21");
//   stack.insert_at_current("20");
//   stack.insert_at_current("19");
//   stack.insert_at_current("18");
//   stack.insert_at_current("17");
//   stack.insert_at_current("16");
//   stack.insert_at_current("15");
//   stack.insert_at_current("14");
//   stack.insert_at_current("13");
//   stack.insert_at_current("12");
//   stack.insert_at_current("11");
//   stack.insert_at_current("10");
//   stack.insert_at_current("9");
//   stack.insert_at_current("8");
//   stack.insert_at_current("7");
//   stack.insert_at_current("6");
//   stack.insert_at_current("5");
//   stack.insert_at_current("4");
//   stack.insert_at_current("3");
//   stack.insert_at_current("2");
//   stack.insert_at_current("1");
//   stack.push_back("27");

//   std::cout << stack.get_current() << std::endl;
//   std::cout << stack._prev_to_current->data << std::endl;
//   std::cout << stack.find_item("6") << std::endl;
//   stack.insert_at_current("3");
//   stack.advance_current();
////   stack.remove_at_current();
//   stack.rewind();
//   stack.clear();
//   stack.insert_at_current("1");
//   stack.rewind();
//   std::cout << stack.get_current();
//   std::cout << stack.to_string() << std:: endl;
//   std::cout << stack._tail->data;


}

int main()
{
   Tests test;
   test.testStacks();

}
