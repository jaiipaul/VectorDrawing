#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "../Image/CImage.h"
#include "CShape.h"
using namespace std;

#ifndef CRECTANGLE_H_
#define CRECTANGLE_H_

class CRectangle : public CShape{
  private :
    int    _x;
    int    _y;
    int    _length;
    int    _height;

  public :
    CRectangle(string command, string type, size_t pos1, int scale);
    ~CRectangle();

   void draw(CImage* img);
   void draw(CImage* img, int scale);
   void info();
};

#endif /*CPOINT_H_*/
