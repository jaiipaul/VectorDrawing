#include "CDrawing.h"

CDrawing::CDrawing(int width, int height){
  cout <<"\033[33m" << "initializing drawing"<< "\033[0m" << endl;
  CreateImage(width, height);
  _size  = 0;
  _maxZ  = 0;
}

CDrawing::CDrawing(int width, int height, int r, int g, int b){
  cout << "\033[33m"<< "Initializing drawing"<< "\033[0m" << endl;
  CreateImage(width, height, r, g, b);
  _size  = 0;
  _maxZ  = 0;
}

CDrawing::~CDrawing(){
    for(int i=0; i<_size; i++)
        delete _shapes[i];

    //delete _shapes;
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
          _maxZ = _shapes[_size]->_z < _maxZ ? _maxZ : _shapes[_size]->_z;
          _size++;
          cout <<"-----------------"<<endl;
      }
      if(type == "RECTANGLE" || type == "RECTANGLE_F"){
          (type == "RECTANGLE_F")?cout <<"\033[45m"<< "RECTANGLE_F      " <<"\033[0m" << endl:cout <<"\033[45m"<< "RECTANGLE        " <<"\033[0m" << endl;
          CRectangle* shape_r = new CRectangle(STRING, type, pos);
          _shapes.push_back(shape_r);
          _maxZ = _shapes[_size]->_z < _maxZ ? _maxZ : _shapes[_size]->_z;
          _size++;
          cout <<"-----------------"<<endl;
      }
      if(type == "DISK" || type == "DISK_F"){
          (type == "DISK_F")?cout <<"\033[42m"<< "DISK_F           " <<"\033[0m" << endl:cout <<"\033[42m"<< "DISK             " <<"\033[0m" << endl;
          CDisk* shape_d = new CDisk(STRING, type, pos);
          _shapes.push_back(shape_d);
          _maxZ = _shapes[_size]->_z < _maxZ ? _maxZ : _shapes[_size]->_z;
          _size++;
          cout <<"-----------------"<<endl;
      }
      if(type == "LINE"){
          cout <<"\033[41m"<< "LINE             " <<"\033[0m" << endl;
          CLine* shape_l = new CLine(STRING, type, pos);
          _shapes.push_back(shape_l);
          _maxZ = _shapes[_size]->_z < _maxZ ? _maxZ : _shapes[_size]->_z;
          _size++;
          cout <<"-----------------"<<endl;
      }
    }
    getline(infile, STRING);
  }
  infile.close();
  cout << _size << " shape(s) loaded" << endl;
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
