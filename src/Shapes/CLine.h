#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "CShape.h"
#include "../Image/CImage.h"

using namespace std;

#ifndef CLINE_H_
#define CLINE_H_

class CLine : public CShape{
  private :
    int    _x1;
    int    _y1;
    int    _x2;
    int    _y2;

  public :
    CLine(string command, string type, size_t pos1, int scale);
    ~CLine();

   void draw(CImage* img);
   void draw(CImage* img, int scale);
   void info();
};

#endif /*CPOINT_H_*/
