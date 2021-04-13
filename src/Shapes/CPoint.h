#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "../Image/CImage.h"
#include "CShape.h"

using namespace std;

#ifndef CPOINT_H_
#define CPOINT_H_

class CPoint : public CShape{
  private :
    int    _x;
    int    _y;

  public :
    CPoint(string command, string type, size_t pos1);
    ~CPoint();

    void draw(CImage* img);
};

#endif /*CPOINT_H_*/
