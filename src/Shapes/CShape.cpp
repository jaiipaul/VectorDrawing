#include "CShape.h"

CShape::CShape(){
}

CShape::~CShape(){
}

void CShape::draw(CImage* img){
  cout << "nothing to draw" << endl;
}

int CShape::opacityR(CImage* img){
  double opacity = (double)_opacity/100;
  return(floor(opacity*_red   + (1-opacity)*img->r_backgnd));

}

int CShape::opacityG(CImage* img){
  double opacity = (double)_opacity/100;
  return(floor(opacity*_green + (1-opacity)*img->g_backgnd));
}

int CShape::opacityB(CImage* img){
  double opacity = (double)_opacity/100;
  return(floor(opacity*_blue  + (1-opacity)*img->b_backgnd));
}
