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
    string          _filename;
    CImage*         _img;
    vector<CShape*> _shapes;
    int             _size;
    int             _maxX;
    int             _maxY;
    int             _maxZ;
    int             _scale;


  public :
    CDrawing();
    CDrawing(int width, int height);
    CDrawing(int width, int height, int r, int g, int b);
    CDrawing(int scale);
    ~CDrawing();

    bool CreateImage(int width, int height);
    bool CreateImage(int width, int height, int r, int g, int b);
    bool CreateShape(const string command);
    bool LoadDrawing(const string filename);
    bool CreateDrawing(const string filename);
    void showShapes();
    void addShape(const string command);
    void removeShape(int index);
    void DrawShape(CImage* img, CShape* shape);
    bool DrawImage();

    //Z Plan
    int  MaxZ();
    void SortZ();

};
#endif /*CSHAPE_H_*/
