#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "CPoint.h"

using namespace std;

#ifndef CSHAPE_H_
#define CSHAPE_H_

class CShape{
  public :
    string _type;
    int    _red;
    int    _green;
    int    _blue;
    int    _opacity;

  public :
    //CShape(string type, string color, string opacity)
    CShape(const string geometry);
    ~CShape();

    void opacity(CImage* img);
};
#endif /*CSHAPE_H_*/
