#include "CLine.h"

CLine::CLine(string command, string type, size_t pos1, int scale){
  _type = type;

  size_t pos2 = command.find(",");
  _x1          = scale*atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << "> X1 : " << _x1;

  pos1  = command.find(",", pos2+1);
  _y1          = scale*atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / Y1 : " << _y1;

  pos2  = command.find(",", pos1+1);
  _x2          = scale*atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / X2 : " << _x2;

  pos1  = command.find(",", pos2+1);
  _y2          = scale*atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / Y2 : " << _y2;

  pos2  = command.find(",", pos1+1);
  _z           = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / Z : " << _z << endl;

  pos1  = command.find(",", pos2+1);
  _red         = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << "> RED : " << _red;

  pos2  = command.find(",", pos1+1);
  _green       = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / GREEN : " << _green;

  pos1  = command.find(",", pos2+1);
  _blue        = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / BLUE : "<< _blue;

  pos2  = command.find(";", pos1+1);
  _opacity     = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / OPACITY : " << _opacity << endl;

  _Xsize = (_x1 > _x2) ? _x1 : _x2;
  _Ysize = (_y1 > _y2) ? _y1 : _y2;
}

CLine::~CLine(){
}

void CLine::draw(CImage* img){
  CShape::opacity(img);
  int x, y, px, py;
  double pente, p;
  int invert = 0;
  int* x1;
  int* y1;
  int* x2;
  int* y2;
  int  tmp;
  if (abs(_y2-_y1) > abs(_x2-_x1)){
    x1 = &_y1;
    y1 = &_x1;
    x2 = &_y2;
    y2 = &_x2;
  } else {
    x1 = &_x1;
    y1 = &_y1;
    x2 = &_x2;
    y2 = &_y2;
  }
  if (*x2 < *x1) {
    invert = 1;
    tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
    tmp = *y1;
    *y1 = *y2;
    *y2 = tmp;
  }
  x = *x1;
  y = *y1;
  pente =(double)(*y2-*y1)/(double)(*x2-*x1);
  p = 0;//(double)(*y2-*y1)/(double)(*x2-*x1);
  for (int i=0; i<(*x2-*x1); i++){
    p = p + pente;
    if (pente >= 0){
      if (p >= 0.5){
        y++;
        p = p -1;
      }
    }
    if (pente < 0){
      if (p <= 0.5){
        y--;
        p = p + 1;
      }
    }
    px = x;
    py = y;
    CLigne* row = img->getLigne(py);
    CPixel* pix = row->getPixel(px);
    pix->RGB(_red, _green, _blue);
    x++;

  }
}
