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
    int             _r_backgnd;
    int             _g_backgnd;
    int             _b_backgnd;
    int             _scale;


  public :
  //Constructors
    CDrawing();
    CDrawing(int width, int height);
    CDrawing(int width, int height, int r, int g, int b);
    CDrawing(int scale);
  //Destructor
    ~CDrawing();

  //File
    bool CreateFile(const string filename);
    bool LoadDrawing(const string filename);

  //Shapes
    bool CreateShape(const string command);
    void showShapes();
    void addShape(const string command);
    void removeShape(int index);
    void DrawShape(CImage* img, CShape* shape);

  //Image
    bool CreateImage(int width, int height);
    bool CreateImage(int width, int height, int r, int g, int b);
    bool DrawImage();

  //Properties
    bool XBorder();
    bool YBorder();
    bool ZBorder();
    bool SetSize(const string command);
    bool ResetSize();
    bool SetBackgnd(const string command);
    bool ResetBackgnd();
    bool SetScale(const string command);
    bool ResetScale();

    bool ParameterStatus(string parameter);
    bool SetParameter(string parameter, string option);
    bool WriteParameter(string parameter, string command);
};
#endif /*CSHAPE_H_*/
