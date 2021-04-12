#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "../Image/CImage.h"

using namespace std;

#ifndef CLINE_H_
#define CLINE_H_

class CRectangle{
  private :
    string _type;
    int    _x;
    int    _y;
    int    _length;
    int    _height;
    int    _red;
    int    _green;
    int    _blue;
    int    _opacity;

  public :
    CRectangle(string command, string type, size_t pos1);
    ~CRectangle();

   void drawRectangle(CImage* img);
   void opacity(CImage* img);
};

#endif /*CPOINT_H_*/
