#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "../Image/CImage.h"

using namespace std;

#ifndef CDISK_H_
#define CDISK_H_

class CDisk{
  private :
    string _type;
    int    _x1;
    int    _y1;
    int    _radius;
    int    _red;
    int    _green;
    int    _blue;
    int    _opacity;

  public :
    CDisk(string command, string type, size_t pos1);
    ~CDisk();

   void drawDisk(CImage* img);
   void opacity(CImage* img )
};

#endif /*CPOINT_H_*/
