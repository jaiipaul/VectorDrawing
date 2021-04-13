#include "CDrawing.h"

CDrawing::CDrawing(int width, int height){
  cout <<"\033[33m" << "initializing drawing"<< "\033[0m" << endl;
  CreateImage(width, height);
}

CDrawing::CDrawing(int width, int height, int r, int g, int b){
  cout << "\033[33m"<< "Initializing drawing"<< "\033[0m" << endl;
  CreateImage(width, height, r, g, b);
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
          _size++;
          cout <<"-----------------"<<endl;
          //shape_p->draw(_img);
          //DrawShape(_img, shape_p);
          //delete shape_p;
      }
      if(type == "RECTANGLE" || type == "RECTANGLE_F"){
          (type == "RECTANGLE_F")?cout <<"\033[45m"<< "RECTANGLE_F      " <<"\033[0m" << endl:cout <<"\033[45m"<< "RECTANGLE        " <<"\033[0m" << endl;
          CRectangle* shape_r = new CRectangle(STRING, type, pos);
          _shapes.push_back(shape_r);
          _size++;
          cout <<"-----------------"<<endl;
          //delete shape_r;
      }
      if(type == "DISK" || type == "DISK_F"){
          (type == "DISK_F")?cout <<"\033[42m"<< "DISK_F           " <<"\033[0m" << endl:cout <<"\033[42m"<< "DISK             " <<"\033[0m" << endl;
          CDisk* shape_d = new CDisk(STRING, type, pos);
          _shapes.push_back(shape_d);
          _size++;//_size_points++;
          cout <<"-----------------"<<endl;
          //delete shape_d;
      }
      if(type == "LINE"){
          cout <<"\033[41m"<< "LINE             " <<"\033[0m" << endl;
          CLine* shape_l = new CLine(STRING, type, pos);
          _shapes.push_back(shape_l);
          _size++;//_size_points++;
          cout <<"-----------------"<<endl;
      }

    }
    getline(infile, STRING);
  }
  infile.close();
  cout << _size << " shape(s) loaded" << endl;
  return true;
}

void CDrawing::DrawShape(CImage* img, CShape* shape){
  shape->draw(img);
}


bool CDrawing::DrawImage(){//CImage* img){
  cout <<"Start Drawing" << endl;
  for (int i = 0; i < _size; i++){
    DrawShape(_img, _shapes[i]);
    cout <<"shape " << i+1 << " " << _shapes[i]->_type << " drawn" << endl;
  }
  return true;
}
