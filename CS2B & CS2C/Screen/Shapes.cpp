/*
 * Screen.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: mfrot
 */

#include "Shapes.h"

Screen::Screen(size_t w, size_t h)
{
   _w = w;
   _h = h;
   _pix.resize(_h, std::vector<char>(_w));
}

void Screen::fill(char c)
{
   for (size_t i = 0; i < _pix.size(); i++) {
       for (size_t j = 0; j < _pix[i].size(); j++)
       {
           _pix[i][j] = c;
       }
   }
}

std::string Screen::to_string() const
{
   std::string phrase;
   std::string draw;
   for (int i = (int)_pix.size()-1; i >= 0 && i < (int)_pix.size(); --i){
      for (int j = 0; j < (int)_pix[i].size(); j++)
      {
      draw += _pix[i][j];
      }
      //phrase += "_pix[" + std::to_string(i) + "] = '" + draw + "'" + '\n';
      phrase += draw + '\n';
      draw = "";
   }
   return phrase;
}

bool Point::draw(Screen &scr, char ch)
{
   if(_x < scr.get_w() && _y < scr.get_h())
   {
      scr.get_pix().at(_y).at(_x) = ch;
      return true;
   }
   else
      return false;
}

bool Line::draw_by_x(Screen &scr, char ch,
         size_t x1, size_t y1, size_t x2, size_t y2)
{
   if (x1 > x2)
      return draw_by_x(scr, ch, x2, y2, x1, y1);

   double dy = ((double) y2-y1)/((double) x2-x1);
   bool contained = true;
   double x = x1, y = y1;
   while (x <= x2)
   {
      contained &= Point((size_t) x, (size_t) y).draw(scr, ch);
      x += 1; y += dy;
   }

   return contained;
}

bool Line::draw_by_y(Screen &scr, char ch,
         size_t x1, size_t y1, size_t x2, size_t y2)
{
   if (y1 > y2)
      return draw_by_y(scr, ch, x2, y2, x1, y1);

   double dx = ((double) x2-x1)/((double) y2-y1);
   bool contained = true;
   double x = x1, y = y1;
   while (y <= y2)
   {
      contained &= Point((size_t) x, (size_t) y).draw(scr, ch);
      x += dx; y += 1;
   }

   return contained;
}

bool Line::draw(Screen &scr, char ch)
{
   if(abs(_x1 - _x2) <= abs(_y1 - _y2))
      return draw_by_y(scr, ch, _x1, _y1, _x2, _y2);
   else
      return draw_by_x(scr, ch, _x1, _y1, _x2, _y2);
}

bool Quadrilateral::draw(Screen &scr, char ch)
{
   Line first(_x1, _y1, _x2, _y2);
   Line second(_x2, _y2, _x3, _y3);
   Line third(_x3, _y3, _x4, _y4);
   Line fourth(_x4, _y4, _x1, _y1);


   first.draw(scr,ch);
   second.draw(scr,ch);
   third.draw(scr,ch);
   fourth.draw(scr,ch);

   return true;
}

Stick_Man::Stick_Man(size_t x, size_t y, size_t w, size_t h)
{
   _parts.clear();
   _x = x;
   _y = y;
   if(w == 0 || w == 1)
      _w = DEFAULT_W;
   else
   _w = w;
   if(h == 0 || h == 1)
      _h = DEFAULT_H;
   else
   _h = h;

   Quadrilateral *head = new Quadrilateral(_x+0, _y+_h/2, _x+0, _y+_h-1, _x+_w-1, _y+_h-1, _x+_w-1, _y+_h/2);
   Line *torso = new Line(_x+_w/2,_y+_h/2,_x+_w/2,_y+_h/4);
   Line *leftArm = new Line(_x+_w/2,_y+_h/2,_x+_w/4,_y+_h/4);
   Line *rightArm = new Line(_x+_w/2,_y+_h/2,_x+3*_w/4,_y+_h/4);
   Line *leftLeg = new Line(_x+_w/2,_y+_h/4,_x,_y);
   Line *rightLeg = new Line(_x+_w/2,_y+_h/4,_x+_w-1,_y);

   _parts.push_back(head);
   _parts.push_back(torso);
   _parts.push_back(leftArm);
   _parts.push_back(rightArm);
   _parts.push_back(leftLeg);
   _parts.push_back(rightLeg);
}

Stick_Man::~Stick_Man()
{
   for(size_t i = 0; i < _parts.size(); i++)
   {
      delete _parts[i];
      _parts[i] = nullptr;
   }
}

bool Stick_Man::draw(Screen &scr, char ch)
{
   for(size_t i = 0; i < _parts.size(); i++)
   {
      _parts[i]->draw(scr,ch);
   }
   return true;
}

