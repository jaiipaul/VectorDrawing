#include "CRectangle.h"

CRectangle::CRectangle(string command, string type, size_t pos1, int scale){
  _type = type;
  //cout << pos1 <<"_"<< _type  << endl;
  size_t pos2 = command.find(",");
  _x           = scale*atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << "> X : " << _x;

  pos1     = command.find(",", pos2+1);
  _y           = scale*atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / Y : " << _y;

  pos2 = command.find(",", pos1+1);
  _length      = scale*atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / LENGTH : " << _length;

  pos1     = command.find(",", pos2+1);
  _height      = scale*atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / HEIGHT : " << _height;

  pos2  = command.find(",", pos1+1);
  _z           = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / Z : " << _z << endl;

  pos1  = command.find(",", pos2+1);
  _red         = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << "> RED : "<< _red;

  pos2  = command.find(",", pos1+1);
  _green       = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / GREEN : "<< _green;

  pos1  = command.find(",", pos2+1);
  _blue        = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / BLUE : "<< _blue;

  pos2  = command.find(";", pos1+1);
  _opacity     = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / OPACITY : "<< _opacity << endl;

  _Xsize = _x + _length;
  _Ysize = _y + _height;
}

CRectangle::~CRectangle(){
}

void CRectangle::draw(CImage* img){
  //int red   = CShape::opacityR(img);
  //int green = CShape::opacityG(img);
  //int blue  = CShape::opacityB(img);

  if (_type == "RECTANGLE"){
    for(int ligne =0; ligne < _height; ligne++){
      if((0 < _y + ligne) && (_y + ligne < img->_hauteur)){
        CLigne* row = img->getLigne(_y + ligne);
        if (_y+1 < ligne < _height-1){
          if((0 < _x) && (_x < img->_largeur)){
            CPixel* p = row->getPixel(_x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if( (0 < _x + _length - 1) && (_x + _length - 1 < img->_largeur)){
            CPixel* p = row->getPixel(_x + _length - 1);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
        if(ligne == 0 || ligne == _height-1){
          for(int col = 0; col<_length; col++){
            if((0 < _x + col) && (_x + col < img->_largeur)){
              CPixel* p = row->getPixel(_x + col);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }
        }
      }
    }
  }
  if ( _type == "RECTANGLE_F"){
    for(int ligne =0; ligne < _height; ligne++){
      if((0 < _y + ligne) && (_y + ligne < img->_hauteur)){
        CLigne* row = img->getLigne(_y + ligne);
        for(int col = 0; col<_length; col++){
          if( (0 < _x + col) && (_x + col < img->_largeur)){
            CPixel* p = row->getPixel(_x + col);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
      }
    }
  }
}
