#include "CDisk.h"

CDisk::CDisk(string command, string type, size_t pos1){
  _type = type;

  size_t pos2 = command.find(",");
  _x           = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _x  << endl;

  pos1     = command.find(",", pos2+1);
  _y           = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _y  << endl;

  pos2 = command.find(",", pos1+1);
  _radius      = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _radius  << endl;

  pos1     = command.find(",", pos2+1);
  _red      = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _red  << endl;

  pos2  = command.find(",", pos1+1);
  _green         = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _green << endl;

  pos1  = command.find(",", pos2+1);
  _blue       = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _blue << endl;

  pos2  = command.find(",", pos1+1);
  _opacity        = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _opacity << endl;
}

CDisk::~CDisk(){
}

void CDisk::drawDisk(CImage* img){
  opacity(img);
  if (_type == "DISK"){
    int x = 0;
    int y = _radius;
    int m = 5 - 4*_radius;
    while (x <= y){
        CLigne* row;
        CPixel* pix;

        row = img->getLigne(_y + y);
        pix = row->getPixel(_x + x);
        pix->RGB( _red, _green, _blue);
        pix = row->getPixel(_x - x);
        pix->RGB( _red, _green, _blue);

        row = img->getLigne(_y + x);
        pix = row->getPixel(_x + y);
        pix->RGB( _red, _green, _blue);
        pix = row->getPixel(_x - y);
        pix->RGB( _red, _green, _blue);

        row = img->getLigne(_y - y);
        pix = row->getPixel(_x + x);
        pix->RGB( _red, _green, _blue);
        pix = row->getPixel(_x - x);
        pix->RGB( _red, _green, _blue);

        row = img->getLigne(_y - x);
        pix = row->getPixel(_x + y);
        pix->RGB( _red, _green, _blue);
        pix = row->getPixel(_x - y);
        pix->RGB( _red, _green, _blue);

        if(m > 0){
          y--;
          m = m - 8*y;
        }
        x++;
        m = m + 8*x + 4;
    }
  }
  if ( _type == "DISK_F"){
    for (int k=0;k<= _radius;k++){
      int x = 0;
      int y = k;
      int m = k - 1;
      while (x <= y){
          CLigne* row;
          CPixel* pix;

          row = img->getLigne(_y + y);
          pix = row->getPixel(_x + x);
          pix->RGB( _red, _green, _blue);
          pix = row->getPixel(_x - x);
          pix->RGB( _red, _green, _blue);

          row = img->getLigne(_y + x);
          pix = row->getPixel(_x + y);
          pix->RGB( _red, _green, _blue);
          pix = row->getPixel(_x - y);
          pix->RGB( _red, _green, _blue);

          row = img->getLigne(_y - y);
          pix = row->getPixel(_x + x);
          pix->RGB( _red, _green, _blue);
          pix = row->getPixel(_x - x);
          pix->RGB( _red, _green, _blue);

          row = img->getLigne(_y - x);
          pix = row->getPixel(_x + y);
          pix->RGB( _red, _green, _blue);
          pix = row->getPixel(_x - y);
          pix->RGB( _red, _green, _blue);

          if(m >= 2*x){
            m = m - 2*x-1;
            x++;
          }
          else if( m <2*(k-y)){
            m = m + 2*y - 1;
            y--;
          }
          else{
            m = m + 2*(x - y - 1);
            y--;
            x++;
          }
      }
    }
  }
}

void CDisk::opacity(CImage* img){
  double opacity = (double)_opacity/100;
  _red   = floor(opacity*_red   + (1-opacity)*img->r_backgnd);
  _green = floor(opacity*_green + (1-opacity)*img->g_backgnd);
  _blue  = floor(opacity*_blue  + (1-opacity)*img->b_backgnd);
}
