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
  protected :
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
    virtual void draw(CImage* img, int scale)=0;
    virtual void info()=0;
    int opacityR(CPixel* pix);
    int opacityG(CPixel* pix);
    int opacityB(CPixel* pix);

    int getLayer();
    string getType();
    int getXsize();
    int getYsize();
};
#endif /*CSHAPE_H_*/
