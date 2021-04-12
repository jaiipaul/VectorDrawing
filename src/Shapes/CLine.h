#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "../Image/CImage.h"

using namespace std;

#ifndef CLINE_H_
#define CLINE_H_

class CLine{
  public :
    string _type;
    int    _x1;
    int    _y1;
    int    _x2;
    int    _y2;
    int    _red;
    int    _green;
    int    _blue;
    int    _opacity;

  public :
    CLine(string command, string type, size_t pos1);
    ~CLine();

   void drawLine(CImage* img);
   void opacity(CImage* img);

};

#endif /*CPOINT_H_*/
