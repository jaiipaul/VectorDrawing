#include "CPoint.h"

CPoint::CPoint(string command, string type, size_t pos1){
  _type = type;

  size_t pos2 = command.find(",");
  _x    = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _x  << endl;

  pos1     = command.find(",", pos2+1);
  _y    = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _y  << endl;

  pos2  = command.find(",", pos1+1);
  _red         = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _red << endl;

  pos1  = command.find(",", pos2+1);
  _green       = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _green << endl;

  pos2  = command.find(",", pos1+1);
  _blue        = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _blue << endl;

  pos1  = command.find(";", pos2+1);
  _opacity     = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _opacity << endl;
}

CPoint::~CPoint(){
}

void CPoint::drawPoint(CImage* img){
  CPixel *p = img->getPixel(_x, _y);
  opacity(img);
  p->RGB(  _red,  _green,  _blue);
}

void CPoint::opacity(CImage* img){
  double opacity = (double)_opacity/100;
  _red   = floor(opacity*_red   + (1-opacity)*img->r_backgnd);
  _green = floor(opacity*_green + (1-opacity)*img->g_backgnd);
  _blue  = floor(opacity*_blue  + (1-opacity)*img->b_backgnd);
}
