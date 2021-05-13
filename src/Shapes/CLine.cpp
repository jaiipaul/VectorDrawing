#include "CLine.h"

CLine::CLine(string command, string type, size_t pos1, int scale){
  _type = type;

  size_t pos2 = command.find(",");
  _x1          = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1  = command.find(",", pos2+1);
  _y1          = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

  pos2  = command.find(",", pos1+1);
  _x2          = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1  = command.find(",", pos2+1);
  _y2          = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

  pos2  = command.find(",", pos1+1);
  _z           = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1  = command.find(",", pos2+1);
  _red         = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

  pos2  = command.find(",", pos1+1);
  _green       = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1  = command.find(",", pos2+1);
  _blue        = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

  pos2  = command.find(";", pos1+1);
  _opacity     = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  _Xsize = (_x1 > _x2) ? _x1 : _x2;
  _Ysize = (_y1 > _y2) ? _y1 : _y2;
}

CLine::~CLine(){
}

void CLine::draw(CImage* img){
  //int red   = CShape::opacityR(img);
  //int green = CShape::opacityG(img);
  //int blue  = CShape::opacityB(img);


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

    if(0 < py && py < img->_hauteur){
      CLigne* row = img->getLigne(py);
      if(0 < px && px < img->_largeur){
        CPixel* pix = row->getPixel(px);
        pix->RGB(opacityR(pix), opacityG(pix), opacityB(pix));
      }
    }
    x++;
  }
}

void CLine::draw(CImage* img, int scale){
  //int red   = CShape::opacityR(img);
  //int green = CShape::opacityG(img);
  //int blue  = CShape::opacityB(img);


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
  x = (*x1)*scale;
  y = (*y1)*scale;
  pente =(double)(*y2-*y1)/(double)(*x2-*x1);
  p = 0;//(double)(*y2-*y1)/(double)(*x2-*x1);
  for (int i=0; i<(*x2-*x1)*scale; i++){
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

    if(0 < py && py < img->_hauteur){
      CLigne* row = img->getLigne(py);
      if(0 < px && px < img->_largeur){
        CPixel* pix = row->getPixel(px);
        pix->RGB(opacityR(pix), opacityG(pix), opacityB(pix));
      }
    }
    x++;
  }
}

void CLine::info(){
  cout <<"\033[41m"<< "LINE             " <<"\033[0m" << endl;
  cout << "> X1 : "       << _x1;
  cout << " / Y1 : "      << _y1;
  cout << " / X2 : "      << _x2;
  cout << " / Y2 : "      << _y2;
  cout << " / Z : "       << _z << endl;
  cout << "> RED : "      << _red;
  cout << " / GREEN : "   << _green;
  cout << " / BLUE : "    << _blue;
  cout << " / OPACITY : " << _opacity << endl;
  cout <<"-----------------"<<endl;
}
