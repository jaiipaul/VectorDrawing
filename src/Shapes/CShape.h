#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "../Image/CImage.h"
using namespace std;

#ifndef CSHAPE_H_
#define CSHAPE_H_

class CShape{
  public :
    string _type;
    int    _Xsize;
    int    _Ysize;
    int    _z;
    int    _red;
    int    _green;
    int    _blue;
    int    _opacity;

  public :
    //CShape(string type, string color, string opacity)
    CShape();
    ~CShape();

    virtual void draw(CImage* img)=0;
    void opacity(CImage* img);
};
#endif /*CSHAPE_H_*/
