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
    for(int i=0; i<_size_points; i++)
        delete _points[i];

    //delete _shapes;
    _points.clear();
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
  int point_cnt     = 0;
  int rectangle_cnt = 0;

  getline(infile, STRING);

  while(not(infile.eof())){

    if (STRING.substr(0,2) != "//"){

      size_t pos = STRING.find(":");
      string type = STRING.substr(0,pos-1);
      if(type == "POINT"){
          cout <<"\033[44m"<< "POINT            " <<"\033[0m" << endl;
          CPoint* shape = new CPoint(STRING, type, pos);
          _points.push_back(shape);
          point_cnt++;//_size_points++;
          cout << point_cnt /*_size_points*/ << " Point(s) loaded" << endl;
          cout <<"-----------------"<<endl;
      }
      if(type == "RECTANGLE" || type == "RECTANGLE_F"){
          (type == "RECTANGLE_F")?cout <<"\033[45m"<< "RECTANGLE_F      " <<"\033[0m" << endl:cout <<"\033[45m"<< "RECTANGLE        " <<"\033[0m" << endl;
          CRectangle* shape = new CRectangle(STRING, type, pos);
          _rectangles.push_back(shape);
          rectangle_cnt++;//_size_points++;
          cout << rectangle_cnt /*_size_points*/ << " Rectangle(s) loaded" << endl;
          cout <<"-----------------"<<endl;
      }

    }
    getline(infile, STRING);
  }
  infile.close();

  _size_points = point_cnt;
  _size_rectangles = rectangle_cnt;
  _size = point_cnt + rectangle_cnt;// _size_points; // + ...;
  cout << _size << " shape(s) loaded" << endl;
  return true;
}

bool CDrawing::Draw(){//CImage* img){
  for (int i = 0; i < _size_points; i++){
    _points[i]->drawPoint(_img);
    cout <<"point " << i+1 << " drawn" << endl;
  }
  for (int i = 0; i < _size_rectangles; i++){
    _rectangles[i]->drawRectangle(_img);
    cout <<"rectangle " << i+1 << " drawn" << endl;
  }
  return true;
}
