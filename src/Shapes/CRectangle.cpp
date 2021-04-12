#include "CRectangle.h"

CRectangle::CRectangle(string command, string type, size_t pos1){
  _type = type;

  size_t pos2 = command.find(",");
  _x           = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _x  << endl;

  pos1     = command.find(",", pos2+1);
  _y           = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _y  << endl;

  pos2 = command.find(",", pos1+1);
  _length      = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _length  << endl;

  pos1     = command.find(",", pos2+1);
  _height      = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _height  << endl;

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

CRectangle::~CRectangle(){
}

void CRectangle::drawRectangle(CImage* img){
  opacity(img);
  if (_type == "RECTANGLE"){
    for(int ligne =0; ligne < _height; ligne++){
        CLigne* row = img->getLigne(_y + ligne);
        if (_y < ligne < _height){
          CPixel* p = row->getPixel(_x);
          p->RGB(_red, _green, _blue);
          p = row->getPixel(_x + _length - 1);
          p->RGB(_red, _green, _blue);
        }
        if(ligne == 0 || ligne == _height-1){
          for(int col = 0; col<_length; col++){
              CPixel* p = row->getPixel(_x + col);
              p->RGB(_red, _green, _blue);
          }
        }
      }
    }
  if ( _type == "RECTANGLE_F"){
    for(int ligne =0; ligne < _height; ligne++){
        CLigne* row = img->getLigne(_y + ligne);
        for(int col = 0; col<_length; col++){
            CPixel* p = row->getPixel(_x + col);
            p->RGB(_red, _green, _blue);
        }
     }
  }
}

void CRectangle::opacity(CImage* img){
  double opacity = (double)_opacity/100;
  _red   = floor(opacity*_red   + (1-opacity)*img->r_backgnd);
  _green = floor(opacity*_green + (1-opacity)*img->g_backgnd);
  _blue  = floor(opacity*_blue  + (1-opacity)*img->b_backgnd);
}
