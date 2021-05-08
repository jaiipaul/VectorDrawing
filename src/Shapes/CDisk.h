#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "CShape.h"
#include "../Image/CImage.h"

using namespace std;

#ifndef CDISK_H_
#define CDISK_H_

class CDisk : public CShape{
  public :
    int    _x;
    int    _y;
    int    _radius;

  public :
    CDisk(string command, string type, size_t pos1, int scale);
    ~CDisk();

   void draw(CImage* img);
};

#endif /*CPOINT_H_*/
