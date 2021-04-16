#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../Image/CImage.h"
#include "CShapes.h"

using namespace std;

#ifndef CDRAWING_H_
#define CDRAWING_H_

class CDrawing{
  public :
    CImage*         _img;
    vector<CShape*>  _shapes;
    //int             _selector;
    int             _size;

  public :
    //CShape(string type, string color, string opacity)
    CDrawing(int width, int height);
    CDrawing(int width, int height, int r, int g, int b);
    ~CDrawing();

    bool CreateImage(int width, int height);
    bool CreateImage(int width, int height, int r, int g, int b);
    bool LoadDrawing(const string filename);
    void DrawShape(CImage* img, CShape* shape);
    bool DrawImage();//CImage* _img);

};
#endif /*CSHAPE_H_*/
