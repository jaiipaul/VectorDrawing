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
    //CShape**        _shapes;
    vector<CPoint*>     _points;
    vector<CDisk*>     _disks;
    vector<CLine*>     _lines;
    vector<CRectangle*> _rectangles;
    int             _selector;
    int             _size;
    int             _size_points;
    int             _size_rectangles;
    int             _size_disks;
    int             _size_lines;
  public :
    //CShape(string type, string color, string opacity)
    CDrawing(int width, int height);
    CDrawing(int width, int height, int r, int g, int b);
    ~CDrawing();

    bool CreateImage(int width, int height);
    bool CreateImage(int width, int height, int r, int g, int b);
    bool LoadDrawing(const string filename);
    bool Draw();//CImage* _img);
};
#endif /*CSHAPE_H_*/
