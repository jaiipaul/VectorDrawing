#include "CDrawing.h"

CDrawing::CDrawing(int width, int height){
  cout <<"\033[33m" << "initializing drawing"<< "\033[0m" << endl;
  CreateImage(width, height);
  _size  = 0;
  _maxX  = width;
  _maxY  = height;
  _maxZ  = 0;
  _scale = 1;
}

CDrawing::CDrawing(int width, int height, int r, int g, int b){
  cout << "\033[33m"<< "Initializing drawing"<< "\033[0m" << endl;
  CreateImage(width, height, r, g, b);
  _size  = 0;
  _maxX  = width;
  _maxY  = height;
  _maxZ  = 0;
  _scale = 1;
  cout << _scale << endl;
}

CDrawing::CDrawing(int scale){
  cout <<"\033[33m" << "initializing drawing"<< "\033[0m" << endl;
  _size  = 0;
  _maxX  = 0;
  _maxY  = 0;
  _maxZ  = 0;
  _scale = scale;
  cout << _scale << endl;
}

CDrawing::~CDrawing(){
    for(int i=0; i<_size; i++)
        delete _shapes[i];
    _shapes.clear();
}

bool CDrawing::CreateImage(int width, int height){
  _img = new CImage(width, height);
  return true;
}

bool CDrawing::CreateImage(int width, int height, int r, int g, int b){
  _img = new CImage(width, height, r, g, b);
  return true;
}

bool CDrawing::LoadDrawing(const string filename){
  //_shapes = (CShape**)new CShape*[16*sizeof(CShape*)];
  cout << ">>> Loading drawing" << endl;
  string STRING;
  ifstream infile;
  infile.open(filename);
  if (infile.is_open() == false){
    exit(EXIT_FAILURE);
  }
  getline(infile, STRING);

  while(not(infile.eof())){

    if (STRING.substr(0,2) != "//"){

      size_t pos = STRING.find(":");
      string type = STRING.substr(0,pos-1);
      if(type == "POINT"){
          cout <<"\033[44m"<< "POINT            " <<"\033[0m" << endl;
          CPoint* shape_p = new CPoint(STRING, type, pos);
          _shapes.push_back(shape_p);
          _maxX = shape_p->_x < _maxX ? _maxX : shape_p->_x;
          _maxY = shape_p->_y < _maxY ? _maxY : shape_p->_y;
          _maxZ = shape_p->_z < _maxZ ? _maxZ : shape_p->_z;
          _size++;
          cout <<"-----------------"<<endl;
      }
      if(type == "RECTANGLE" || type == "RECTANGLE_F"){
          (type == "RECTANGLE_F")?cout <<"\033[45m"<< "RECTANGLE_F      " <<"\033[0m" << endl:cout <<"\033[45m"<< "RECTANGLE        " <<"\033[0m" << endl;
          CRectangle* shape_r = new CRectangle(STRING, type, pos, _scale);
          _shapes.push_back(shape_r);
          _maxX = (shape_r->_x + shape_r->_length) < _maxX ? _maxX : (shape_r->_x + shape_r->_length);
          _maxY = (shape_r->_y + shape_r->_height) < _maxY ? _maxY : (shape_r->_y + shape_r->_height);
          _maxZ = shape_r->_z < _maxZ ? _maxZ : shape_r->_z;
          _size++;
          cout <<"-----------------"<<endl;
      }
      if(type == "DISK" || type == "DISK_F"){
          (type == "DISK_F")?cout <<"\033[42m"<< "DISK_F           " <<"\033[0m" << endl:cout <<"\033[42m"<< "DISK             " <<"\033[0m" << endl;
          CDisk* shape_d = new CDisk(STRING, type, pos, _scale);
          _shapes.push_back(shape_d);
          _maxX = (shape_d->_x + shape_d->_radius) < _maxX ? _maxX : (shape_d->_x + shape_d->_radius);
          _maxY = (shape_d->_y + shape_d->_radius) < _maxY ? _maxY : (shape_d->_y + shape_d->_radius);
          _maxZ = shape_d->_z < _maxZ ? _maxZ : shape_d->_z;
          _size++;
          cout <<"-----------------"<<endl;
      }
      if(type == "LINE"){
          cout <<"\033[41m"<< "LINE             " <<"\033[0m" << endl;
          CLine* shape_l = new CLine(STRING, type, pos, _scale);
          _shapes.push_back(shape_l);
          if(shape_l->_x1 < shape_l->_x2){
            _maxX = shape_l->_x2 < _maxX ? _maxX : shape_l->_x2;
          }else{
            _maxX = shape_l->_x1 < _maxX ? _maxX : shape_l->_x1;
          }
          if(shape_l->_y1 < shape_l->_y2){
            _maxY = shape_l->_y2 < _maxY ? _maxY : shape_l->_y2;
          }else{
            _maxY = shape_l->_y1 < _maxY ? _maxY : shape_l->_y1;
          }
          _maxZ = shape_l->_z < _maxZ ? _maxZ : shape_l->_z;
          _size++;
          cout <<"-----------------"<<endl;
      }
    }
    getline(infile, STRING);
  }
  infile.close();
  cout << _size << " shape(s) loaded" << endl;
  cout << "Max X : "<< _maxX << endl;
  cout << "Max Y : "<< _maxY << endl;
  cout << "Max Z : "<< _maxZ << endl;
  return true;
}

int CDrawing::MaxZ(){
  int max = _shapes[0]->_z;
  for(int i = 0; i < _size; i++){
    max = _shapes[i]->_z < max ? max : _shapes[i]->_z;
  }
  return max;
}

void CDrawing::DrawShape(CImage* img, CShape* shape){
  shape->draw(img);
}


bool CDrawing::DrawImage(){//CImage* img){
  cout <<"Start Drawing" << endl;
  for (int z = 0; z <= _maxZ; z++){
    cout << "Plan Z = " << z << endl;
    for (int i = 0; i < _size; i++){
      if(_shapes[i]->_z == z){
        DrawShape(_img, _shapes[i]);
        cout <<"shape " << i+1 << " " << _shapes[i]->_type << " drawn" << endl;
      }
    }
  }
  return true;
}
