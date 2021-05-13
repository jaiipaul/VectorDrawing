#include "CShape.h"

CShape::CShape(){
}

CShape::~CShape(){
}

void CShape::draw(CImage* img){
  cout << "nothing to draw" << endl;
}

void CShape::draw(CImage* img, int scale){
  cout << "nothing to draw" << endl;
}


int CShape::opacityR(CPixel* pix){
  double opacity = (double)_opacity/100;
  return(floor(opacity*_red   + (1-opacity)*pix->Red()));

}

int CShape::opacityG(CPixel* pix){
  double opacity = (double)_opacity/100;
  return(floor(opacity*_green + (1-opacity)*pix->Green()));
}

int CShape::opacityB(CPixel* pix){
  double opacity = (double)_opacity/100;
  return(floor(opacity*_blue  + (1-opacity)*pix->Blue()));
}
