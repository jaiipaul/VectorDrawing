#include "CPoint.h"

CPoint::CPoint(string command, string type, size_t pos1){
  _type = type;

  size_t pos2 = command.find(",");
  _x         = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout <<"> X : " << _x;

  pos1     = command.find(",", pos2+1);
  _y         = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / Y : " << _y;

  pos2  = command.find(",", pos1+1);
  _z         = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / Z : " << _z << endl;

  pos1  = command.find(",", pos2+1);
  _red         = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout <<  "> RED : "<< _red;

  pos2  = command.find(",", pos1+1);
  _green       = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / GREEN : "<< _green;

  pos1  = command.find(",", pos2+1);
  _blue        = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / BLUE : "<< _blue;

  pos2  = command.find(";", pos1+1);
  _opacity     = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / OPACITY : " << _opacity << endl;
}

CPoint::~CPoint(){
}

void CPoint::draw(CImage* img){
  CShape::opacity(img);
  CPixel *p = img->getPixel(_x, _y);
  //cout << _red << "/" << _green << "/" << _blue << endl;
  p->RGB(  _red,  _green,  _blue);
}
