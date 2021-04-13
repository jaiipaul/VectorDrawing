#include "CShape.h"

CShape::CShape(){
}

CShape::~CShape(){
  delete _shape;
}

void CShape::opacity(CImage* img){
  double opacity = (double)_opacity/100;
  _red   = floor(opacity*_red   + (1-opacity)*img->r_backgnd);
  _green = floor(opacity*_green + (1-opacity)*img->g_backgnd);
  _blue  = floor(opacity*_blue  + (1-opacity)*img->b_backgnd);
}
