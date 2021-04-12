#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "../Image/CImage.h"

using namespace std;

#ifndef CPOINT_H_
#define CPOINT_H_

class CPoint{
  private :
    string _type;
    int    _x;
    int    _y;
    int    _red;
    int    _green;
    int    _blue;
    int    _opacity;

  public :
    CPoint(string command, string type, size_t pos1);
    ~CPoint();

    void drawPoint(CImage* img);
    void opacity(CImage* img);
};

#endif /*CPOINT_H_*/
