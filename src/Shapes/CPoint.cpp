#include "CPoint.h"

CPoint::CPoint(string command, string type, size_t pos1){
  _type = type;

  size_t pos2 = command.find(",");
  _x         = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1     = command.find(",", pos2+1);
  _y         = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

  pos2  = command.find(",", pos1+1);
  _z         = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1  = command.find(",", pos2+1);
  _red         = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

  pos2  = command.find(",", pos1+1);
  _green       = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1  = command.find(",", pos2+1);
  _blue        = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

  pos2  = command.find(";", pos1+1);
  _opacity     = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  _Xsize = _x;
  _Ysize = _y;
}

CPoint::~CPoint(){
}

void CPoint::draw(CImage* img){
  //int red   = CShape::opacityR(img);
  //int green = CShape::opacityG(img);
  //int blue  = CShape::opacityB(img);

  if( 0 <= _x && _x < img->getWidth() && 0 <= _y && _y < img->getHeight()){
    CPixel *p = img->getPixel(_x, _y);
    p->RGB(opacityR(p), opacityG(p), opacityB(p));
  }
}

void CPoint::draw(CImage* img, int scale){
  //int red   = CShape::opacityR(img);
  //int green = CShape::opacityG(img);
  //int blue  = CShape::opacityB(img);

  if( 0 <= scale*_x && scale*_x < img->getWidth() && 0 <= scale*_y && scale*_y < img->getHeight()){
    CPixel *p = img->getPixel(scale*_x, scale*_y);
    p->RGB(opacityR(p), opacityG(p), opacityB(p));
  }
}

void CPoint::info(){
  cout <<"\033[44m"<< "POINT            " <<"\033[0m" << endl;
  cout <<"> X : " << _x;
  cout << " / Y : " << _y;
  cout << " / Z : " << _z << endl;
  cout <<  "> RED : "<< _red;
  cout << " / GREEN : "<< _green;
  cout << " / BLUE : "<< _blue;
  cout << " / OPACITY : " << _opacity << endl;
  cout <<"-----------------"<<endl;
}
