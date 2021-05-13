#include "CDisk.h"

CDisk::CDisk(string command, string type, size_t pos1, int scale){
  _type = type;

  size_t pos2 = command.find(",");
  _x           = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1     = command.find(",", pos2+1);
  _y           = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

  pos2 = command.find(",", pos1+1);
  _radius      = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1     = command.find(",", pos2+1);
  _z           = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

  pos2  = command.find(",", pos1+1);
  _red         = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1  = command.find(",", pos2+1);
  _green       = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

  pos2  = command.find(",", pos1+1);
  _blue        = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());

  pos1  = command.find(";", pos2+1);
  _opacity     = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());

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

        if(0 < _y+y && _y+y < img->_hauteur){
          row = img->getLigne(_y + y);
          if(0 < _x+x && _x+x < img->_largeur){
            p = row->getPixel(_x + x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(0 < _x-x && _x-x < img->_largeur){
            p = row->getPixel(_x - x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
        if(0 < _y+x && _y+x < img->_hauteur){
          row = img->getLigne(_y + x);
          if(0 < _x+y && _x+y < img->_largeur){
            p = row->getPixel(_x + y);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(0 < _x-y && _x-y < img->_largeur){
            p = row->getPixel(_x - y);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
        if(0 < _y-y && _y-y < img->_hauteur){
          row = img->getLigne(_y - y);
          if(0 < _x+x && _x+x < img->_largeur){
            p = row->getPixel(_x + x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(0 < _x-x && _x-x < img->_largeur){
            p = row->getPixel(_x - x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
        if(0 < _y-x && _y-x < img->_hauteur){
          row = img->getLigne(_y - x);
          if(0 < _x+y && _x+y < img->_largeur){
            p = row->getPixel(_x + y);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(0 < _x-y && _x-y < img->_largeur){
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

          if(0 < _y+y && _y+y < img->_hauteur){
            row = img->getLigne(_y + y);
            if(0 < _x+x && _x+x < img->_largeur){
              p = row->getPixel(_x + x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(0 < _x-x && _x-x < img->_largeur){
              p = row->getPixel(_x - x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }
          if(0 < _y+x && _y+x < img->_hauteur){
            row = img->getLigne(_y + x);
            if(0 < _x+y && _x+y < img->_largeur){
              p = row->getPixel(_x + y);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(0 < _x-y && _x-y < img->_largeur){
              p = row->getPixel(_x - y);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }
          if(0 < _y-y && _y-y < img->_hauteur){
            row = img->getLigne(_y - y);
            if(0 < _x+x && _x+x < img->_largeur){
              p = row->getPixel(_x + x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(0 < _x-x && _x-x < img->_largeur){
              p = row->getPixel(_x - x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }
          if(0 < _y-x && _y-x < img->_hauteur){
            row = img->getLigne(_y - x);
            if(0 < _x+y && _x+y < img->_largeur){
              p = row->getPixel(_x + y);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(0 < _x-y && _x-y < img->_largeur){
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

void CDisk::draw(CImage* img, int scale){
  //int red   = CShape::opacityR(img);
  //int green = CShape::opacityG(img);
  //int blue  = CShape::opacityB(img);



  if (_type == "DISK"){
    int x = 0;
    int y = (scale*_radius-1);
    int m = 5 - 4*(scale*_radius-1);
    while (x <= y){
        CLigne* row;
        CPixel* p;

        if(0 < scale*_y+y && scale*_y+y < img->_hauteur){
          row = img->getLigne(scale*_y + y);
          if(0 < scale*_x+x && scale*_x+x < img->_largeur){
            p = row->getPixel(scale*_x + x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(0 < scale*_x-x && scale*_x-x < img->_largeur){
            p = row->getPixel(scale*_x - x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
        if(0 < scale*_y+x && scale*_y+x < img->_hauteur){
          row = img->getLigne(scale*_y + x);
          if(0 < scale*_x+y && scale*_x+y < img->_largeur){
            p = row->getPixel(scale*_x + y);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(0 < scale*_x-y && scale*_x-y < img->_largeur){
            p = row->getPixel(scale*_x - y);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
        if(0 < scale*_y-y && scale*_y-y < img->_hauteur){
          row = img->getLigne(scale*_y - y);
          if(0 < scale*_x+x && scale*_x+x < img->_largeur){
            p = row->getPixel(scale*_x + x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(0 < scale*_x-x && scale*_x-x < img->_largeur){
            p = row->getPixel(scale*_x - x);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
        }
        if(0 < scale*_y-x && scale*_y-x < img->_hauteur){
          row = img->getLigne(scale*_y - x);
          if(0 < scale*_x+y && scale*_x+y < img->_largeur){
            p = row->getPixel(scale*_x + y);
            p->RGB(opacityR(p), opacityG(p), opacityB(p));
          }
          if(0 < scale*_x-y && scale*_x-y < img->_largeur){
            p = row->getPixel(scale*_x - y);
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
    for (int k=0;k < scale*_radius;k++){
      int x = 0;
      int y = k;
      int m = k - 1;
      while (x <= y){
          CLigne* row;
          CPixel* p;

          if(0 < scale*_y+y && scale*_y+y < img->_hauteur){
            row = img->getLigne(scale*_y + y);
            if(0 < scale*_x+x && scale*_x+x < img->_largeur){
              p = row->getPixel(scale*_x + x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(0 < scale*_x-x && scale*_x-x < img->_largeur){
              p = row->getPixel(scale*_x - x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }
          if(0 < scale*_y+x && scale*_y+x < img->_hauteur){
            row = img->getLigne(scale*_y + x);
            if(0 < scale*_x+y && scale*_x+y < img->_largeur){
              p = row->getPixel(scale*_x + y);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(0 < scale*_x-y && scale*_x-y < img->_largeur){
              p = row->getPixel(scale*_x - y);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }
          if(0 < scale*_y-y && scale*_y-y < img->_hauteur){
            row = img->getLigne(scale*_y - y);
            if(0 < scale*_x+x && scale*_x+x < img->_largeur){
              p = row->getPixel(scale*_x + x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(0 < scale*_x-x && scale*_x-x < img->_largeur){
              p = row->getPixel(scale*_x - x);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
          }
          if(0 < scale*_y-x && scale*_y-x < img->_hauteur){
            row = img->getLigne(scale*_y - x);
            if(0 < scale*_x+y && scale*_x+y < img->_largeur){
              p = row->getPixel(scale*_x + y);
              p->RGB(opacityR(p), opacityG(p), opacityB(p));
            }
            if(0 < scale*_x-y && scale*_x-y < img->_largeur){
              p = row->getPixel(scale*_x - y);
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

void CDisk::info(){
  (_type == "DISK_F")?cout <<"\033[42m"<< "DISK_F           " <<"\033[0m" << endl:cout <<"\033[42m"<< "DISK             " <<"\033[0m" << endl;
  cout << "> X : "       << _x;
  cout << " / Y : "      << _y ;
  cout << " / RADIUS : " << _radius;
  cout << " / Z : "      << _z  << endl;
  cout << "> RED : "     << _red;
  cout << " / GREEN : "  << _green;
  cout << " / BLUE : "   << _blue;
  cout << " / OPACITY : "<< _opacity << endl;
  cout <<"-----------------"<<endl;
}
