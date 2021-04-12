#include "CLine.h"

CLine::CLine(string command, string type, size_t pos1){
  _type = type;

  size_t pos2 = command.find(",");
  _x1    = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _x1  << endl;

  pos1     = command.find(",", pos2+1);
  _y1    = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _y1  << endl;

  pos2 = command.find(",", pos1+1);
  _x2    = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _x2  << endl;

  pos1     = command.find(",", pos2+1);
  _y2    = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _y2  << endl;

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
  cout <<"-----------------"<<endl;
}

CLine::~CLine(){
}

void drawLine(CImage* img){
  opacity(img);
  int x, y, px, py;
  double pente, p;
  int invert = 0;
  int* x1;
  int* y1;
  int* x2;
  int* y2;
  int* tmp;
  if (abs(_y2-_y1) > abs(_x2-_x1)){
    *x1 = _y1;
    *y1 = _x1;
    *x2 = _y2;
    *y2 = _x2;
  } else {
    *x1 = _x1;
    *y1 = _y1;
    *x2 = _x2;
    *y2 = _y2;
  }
  if (*x1 > *x2) {
    invert = 1;
    tmp = x1;
    x1 = x2;
    x2 = tmp;
    tmp = y1;
    y1 = y2;
    y2 = tmp;
    tmp = y1;
  }
  x = *x1;
  y = *y1;
  pente = (*y2-*y1)/(*x2-*x1);
  p = (*y2-*y1)/(*x2-*x1);
  for (int i=0; i<(*x2-*x1+1); i++){
    x++;
    if (pente > 0.5){
      p = (*y2-*y1)/(*x2-*x1);
      if (pente < 0){
        y++;
      } else {
        y--;
      }
    } else {
      p = p + pente;
    }
    if (invert = 1) {
      px = y;
      py = x;
    } else {
      px = x;
      py = y;
    }
    CLigne* row = img->getLigne(py);
    CPixel* pix = row->getPixel(px);
    pix->RGB(_red, _green, _blue);
  }
}

void CLine::opacity(CImage* img){
  double opacity = (double)_opacity/100;
  _red   = floor(opacity*_red   + (1-opacity)*img->r_backgnd);
  _green = floor(opacity*_green + (1-opacity)*img->g_backgnd);
  _blue  = floor(opacity*_blue  + (1-opacity)*img->b_backgnd);
}
