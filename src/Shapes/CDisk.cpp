#include "CDisk.h"

CDisk::CDisk(string command, string type, size_t pos1, int scale){
  _type = type;

  size_t pos2 = command.find(",");
  _x           = scale*atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << "> X : "<< _x;

  pos1     = command.find(",", pos2+1);
  _y           = scale*atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / Y : "<< _y ;

  pos2 = command.find(",", pos1+1);
  _radius      = scale*atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / RADIUS : "<< _radius;

  pos1     = command.find(",", pos2+1);
  _z           = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / Z : " << _z  << endl;

  pos2  = command.find(",", pos1+1);
  _red         = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << "> RED : "<< _red;

  pos1  = command.find(",", pos2+1);
  _green       = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / GREEN : "<< _green;

  pos2  = command.find(",", pos1+1);
  _blue        = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << " / BLUE : "<< _blue;

  pos1  = command.find(";", pos2+1);
  _opacity     = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << " / OPACITY : "<< _opacity << endl;

  _Xsize = _x + _radius;
  _Ysize = _y + _radius;
}

CDisk::~CDisk(){
}

void CDisk::draw(CImage* img){
  //int red   = CShape::opacityR(img);
  //int green = CShape::opacityG(img);
  //int blue  = CShape::opacityB(img);
  if (_type == "DISK"){
    int x = 0;
    int y = (_radius-1);
    int m = 5 - 4*(_radius-1);
    while (x <= y){
        CLigne* row;
        CPixel* p;

        if(_y+y < img->_hauteur){
          row = img->getLigne(_y + y);
          if(_x+x < img->_largeur){
            p = row->getPixel(_x + x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(_x-x < img->_largeur){
            p = row->getPixel(_x - x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
        if(_y+x < img->_hauteur){
          row = img->getLigne(_y + x);
          if(_x+y < img->_largeur){
            p = row->getPixel(_x + y);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(_x-y < img->_largeur){
            p = row->getPixel(_x - y);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
        if(_y-y < img->_hauteur){
          row = img->getLigne(_y - y);
          if(_x+x < img->_largeur){
            p = row->getPixel(_x + x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(_x-x < img->_largeur){
            p = row->getPixel(_x - x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
        if(_y-x < img->_hauteur){
          row = img->getLigne(_y - x);
          if(_x+y < img->_largeur){
            p = row->getPixel(_x + y);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(_x-y < img->_largeur){
            p = row->getPixel(_x - y);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }

        if(m > 0){
          y--;
          m = m - 8*y;
        }
        x++;
        m = m + 8*x + 4;
    }
  }
  if (_type == "DISK_F"){
    for (int k=0;k < _radius;k++){
      int x = 0;
      int y = k;
      int m = k - 1;
      while (x <= y){
          CLigne* row;
          CPixel* p;

          if(_y+y < img->_hauteur){
            row = img->getLigne(_y + y);
            if(_x+x < img->_largeur){
              p = row->getPixel(_x + x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(_x-x < img->_largeur){
              p = row->getPixel(_x - x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }
          if(_y+x < img->_hauteur){
            row = img->getLigne(_y + x);
            if(_x+y < img->_largeur){
              p = row->getPixel(_x + y);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(_x-y < img->_largeur){
              p = row->getPixel(_x - y);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }
          if(_y-y < img->_hauteur){
            row = img->getLigne(_y - y);
            if(_x+x < img->_largeur){
              p = row->getPixel(_x + x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(_x-x < img->_largeur){
              p = row->getPixel(_x - x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }
          if(_y-x < img->_hauteur){
            row = img->getLigne(_y - x);
            if(_x+y < img->_largeur){
              p = row->getPixel(_x + y);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(_x-y < img->_largeur){
              p = row->getPixel(_x - y);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }

          if(m >= 2*x){
            m = m - 2*x-1;
            x++;
          }
          else if( m <2*(k-y)){
            m = m + 2*y - 1;
            y--;
          }
          else{
            m = m + 2*(y - x - 1);
            y--;
            x++;
          }
      }
    }
  }
}
