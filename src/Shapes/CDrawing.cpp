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
  //cout << _scale << endl;
}

CDrawing::CDrawing(int scale){
  cout <<"\033[33m" << "initializing drawing"<< "\033[0m" << endl;
  _size  = 0;
  _maxX  = 0;
  _maxY  = 0;
  _maxZ  = 0;
  _scale = scale;
  //cout << _scale << endl;
}

CDrawing::CDrawing(){
  //cout <<"\033[33m" << "initializing drawing"<< "\033[0m" << endl;
  _size  = 0;
  _maxX  = 0;
  _maxY  = 0;
  _maxZ  = 0;
  _scale = 1;

}
CDrawing::~CDrawing(){
    for(int i=0; i<_size; i++)
        delete _shapes[i];
    _shapes.clear();
}

bool CDrawing::CreateFile(const string filename){
  ofstream outfile;
  outfile.open(filename);
  if (outfile.is_open() == false){
    cout << "|!| Can't open file : " << filename << " ... " << endl;
    return false;
  }

  outfile << "//Drawing file : " << filename << " which contains all data to draw the picture" << endl;
  outfile << endl;
  outfile << "//PARAMETERS : " << endl;
  outfile << "//SIZE : " << endl;
  outfile << "//BACKGROUND : " << endl;
  outfile << "//SCALE : " << endl;
  outfile << endl;
  outfile << "//SHAPES : " << endl;
  outfile.close();
  return true;
  }

bool CDrawing::LoadDrawing(const string filename){
  cout << ">>> Loading drawing" << endl;
  string STRING;
  ifstream infile;
  infile.open(filename);
  if (infile.is_open() == false){
    cout << "|!| This file might not exist, can't find it..." << endl;
    return false;
  }
  getline(infile, STRING);

  while(not(infile.eof())){

    if (STRING.substr(0,2) != "//"){
      string header = STRING.substr(0,STRING.find(":")-1);
      if(header == "POINT" || header == "LINE" || header == "DISK" || header == "DISK_F" || header == "RECTANGLE" || header == "RECTANGLE_F"){
        CreateShape(STRING);
      }else if(header == "SIZE"){
        SetSize(STRING);
      }else if(header == "BACKGROUND"){
        SetBackgnd(STRING);
      }else if(header == "SCALE"){
        SetScale(STRING);
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


bool CDrawing::CreateShape(const string command){
    size_t pos = command.find(":");
    string type = command.substr(0,pos-1);
    if(type == "POINT"){
        cout <<"\033[44m"<< "POINT            " <<"\033[0m" << endl;
        CPoint* shape_p = new CPoint(command, type, pos);
        _shapes.push_back(shape_p);
        _maxX = shape_p->_x < _maxX ? _maxX : shape_p->_x;
        _maxY = shape_p->_y < _maxY ? _maxY : shape_p->_y;
        _maxZ = shape_p->_z < _maxZ ? _maxZ : shape_p->_z;
        _size++;
        cout <<"-----------------"<<endl;
    }
    else if(type == "RECTANGLE" || type == "RECTANGLE_F"){
        (type == "RECTANGLE_F")?cout <<"\033[45m"<< "RECTANGLE_F      " <<"\033[0m" << endl:cout <<"\033[45m"<< "RECTANGLE        " <<"\033[0m" << endl;
        CRectangle* shape_r = new CRectangle(command, type, pos, _scale);
        _shapes.push_back(shape_r);
        _maxX = (shape_r->_x + shape_r->_length) < _maxX ? _maxX : (shape_r->_x + shape_r->_length);
        _maxY = (shape_r->_y + shape_r->_height) < _maxY ? _maxY : (shape_r->_y + shape_r->_height);
        _maxZ = shape_r->_z < _maxZ ? _maxZ : shape_r->_z;
        _size++;
        cout <<"-----------------"<<endl;
    }
    else if(type == "DISK" || type == "DISK_F"){
        (type == "DISK_F")?cout <<"\033[42m"<< "DISK_F           " <<"\033[0m" << endl:cout <<"\033[42m"<< "DISK             " <<"\033[0m" << endl;
        CDisk* shape_d = new CDisk(command, type, pos, _scale);
        _shapes.push_back(shape_d);
        _maxX = (shape_d->_x + shape_d->_radius) < _maxX ? _maxX : (shape_d->_x + shape_d->_radius);
        _maxY = (shape_d->_y + shape_d->_radius) < _maxY ? _maxY : (shape_d->_y + shape_d->_radius);
        _maxZ = shape_d->_z < _maxZ ? _maxZ : shape_d->_z;
        _size++;
        cout <<"-----------------"<<endl;
    }
    else if(type == "LINE"){
        cout <<"\033[41m"<< "LINE             " <<"\033[0m" << endl;
        CLine* shape_l = new CLine(command, type, pos, _scale);
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
    return true;
  }

void CDrawing::showShapes(){
  for(int i = 0; i < _size; i++){
    cout << "[" << i+1 << "]" << _shapes[i]->_type << endl;
  }
}

void CDrawing::addShape(const string command){
  ofstream outfile;
  outfile.open(_filename, std::ofstream::app);
  if (outfile.is_open() == false)
    exit(EXIT_FAILURE);

  outfile << command << endl;
  outfile.close();

  CreateShape(command);
}

void CDrawing::removeShape(int index){
  string STRING;
  ifstream infile;
  infile.open(_filename);
  ofstream outfile;
  outfile.open(_filename+".temp", fstream::trunc);

  while(not(infile.eof())){
    getline(infile,STRING);
    outfile << STRING << endl;
  }
  infile.close();
  outfile.close();


  infile.open(_filename+".temp");
  outfile.open(_filename);
  if (infile.is_open() == false)
    exit(EXIT_FAILURE);
  if (outfile.is_open() == false)
    exit(EXIT_FAILURE);


  int i = 0;
  while(not(infile.eof())){
    getline(infile,STRING);
    if (STRING.substr(0,5) == "POINT" || STRING.substr(0,4) == "DISK" || STRING.substr(0,4) == "LINE" || STRING.substr(0,9) == "RECTANGLE"){
      if (i == index-1){
        i++;
      }else{
        outfile << STRING << endl;
        i++;
      }
    }else{
      outfile << STRING << endl;
    }
  }

  infile.close();
  outfile.close();

  _shapes.erase(_shapes.begin()+index-1);
  _size--;
}

/*int CDrawing::MaxZ(){
  int max = _shapes[0]->_z;
  for(int i = 0; i < _size; i++){
    max = _shapes[i]->_z < max ? max : _shapes[i]->_z;
  }
  return max;
}*/

void CDrawing::DrawShape(CImage* img, CShape* shape){
  shape->draw(img);
}


bool CDrawing::CreateImage(int width, int height){
  _img = new CImage(width, height);
  return true;
}

bool CDrawing::CreateImage(int width, int height, int r, int g, int b){
  _img = new CImage(width, height, r, g, b);
  return true;
}

bool CDrawing::DrawImage(){
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

bool CDrawing::SetSize(const string command){
  size_t pos1 = command.find(":");
  cout << pos1 << endl;
  string STRING;
  ifstream infile;
  infile.open(_filename);
  ofstream outfile;
  outfile.open(_filename+".temp", fstream::trunc);

  while(not(infile.eof())){
    getline(infile,STRING);
    if (STRING.substr(0,STRING.find(":")-1) != "//SIZE" || STRING.substr(0,STRING.find(":")-1) != "SIZE" ){
      outfile << STRING << endl;
    }else{
      outfile << endl;
      outfile << "//SIZE : ";
    }
  }
  infile.close();
  outfile.close();

  infile.open(_filename+".temp");
  outfile.open(_filename);
  if (infile.is_open() == false)
    exit(EXIT_FAILURE);
  if (outfile.is_open() == false)
    exit(EXIT_FAILURE);

  while (not(infile.eof())){
    getline(infile, STRING);
    if (STRING.substr(0,STRING.find(":")-1) == "//SIZE")
      outfile << "//" << command << endl;
    else if(STRING.substr(0,STRING.find(":")-1) == "SIZE")
      outfile << command << endl;
    else
      outfile << STRING << endl;
  }

  size_t pos2 = command.find(",");
  _maxX = (command.substr(pos1+2, pos2-(pos1+2)) != "#") ? atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str()) : _maxX;

  pos1     = command.find(";", pos2+1);
  _maxY = (command.substr(pos2+2, pos1-(pos2+2)) != "#") ? atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str()) : _maxY;

  cout << "Size set at X : ";
  cout << _maxX;
  cout << " / Y : ";
  cout << _maxY << endl;

  return true;
}

bool CDrawing::SetBackgnd(const string command){
  size_t pos1 = command.find(":");

  string STRING;
  ifstream infile;
  infile.open(_filename);
  ofstream outfile;
  outfile.open(_filename+".temp", fstream::trunc);

  while(not(infile.eof())){
    getline(infile,STRING);
    if (STRING.substr(0,STRING.find(":")-1) != "//BACKGROUND" || STRING.substr(0,STRING.find(":")-1) != "BACKGROUND" ){
      outfile << STRING << endl;
    }else{
      outfile << endl;
      outfile << "//BACKGROUND : ";
    }
  }
  infile.close();
  outfile.close();

  infile.open(_filename+".temp");
  outfile.open(_filename);
  if (infile.is_open() == false)
    exit(EXIT_FAILURE);
  if (outfile.is_open() == false)
    exit(EXIT_FAILURE);

  while (not(infile.eof())){
    getline(infile, STRING);
    if (STRING.substr(0,STRING.find(":")-1) == "//BACKGROUND")
      outfile << "//" << command << endl;
    else if(STRING.substr(0,STRING.find(":")-1) == "BACKGROUND")
      outfile << command << endl;
    else
      outfile << STRING << endl;
  }

  size_t pos2 = command.find(",");
  _r_backgnd = (command.substr(pos1+2, pos2-(pos1+2)) != "#") ? atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str()) : _r_backgnd;

  pos1     = command.find(",", pos2+1);
  _g_backgnd = (command.substr(pos2+2, pos1-(pos2+2)) != "#") ? atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str()) : _g_backgnd;

  pos2  = command.find(";", pos1+1);
  _b_backgnd = (command.substr(pos1+2, pos2-(pos1+2)) != "#") ? atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str()) : _b_backgnd;

  cout << "Background set at RED : ";
  cout << _r_backgnd;
  cout << " / GREEN : ";
  cout << _g_backgnd;
  cout << " / BLUE : ";
  cout << _b_backgnd << endl;

  return true;
}

bool CDrawing::SetScale(const string command){
  size_t pos1 = command.find(":");

  string STRING;
  ifstream infile;
  infile.open(_filename);
  ofstream outfile;
  outfile.open(_filename+".temp", fstream::trunc);

  while(not(infile.eof())){
    getline(infile,STRING);
    if (STRING.substr(0,STRING.find(":")-1) != "//SCALE" || STRING.substr(0,STRING.find(":")-1) != "SCALE" ){
      outfile << STRING << endl;
    }else{
      outfile << endl;
      outfile << "//SCALE : ";
    }
  }
  infile.close();
  outfile.close();

  infile.open(_filename+".temp");
  outfile.open(_filename);
  if (infile.is_open() == false)
    exit(EXIT_FAILURE);
  if (outfile.is_open() == false)
    exit(EXIT_FAILURE);

  while (not(infile.eof())){
    getline(infile, STRING);
    if (STRING.substr(0,STRING.find(":")-1) == "//SCALE")
      outfile << "//" << command << endl;
    else if(STRING.substr(0,STRING.find(":")-1) == "SCALE")
      outfile << command << endl;
    else
      outfile << STRING << endl;
  }

  size_t pos2 = command.find(";");
  _scale = (command.substr(pos1+2, pos2-(pos1+2)) != "#") ? atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str()) : _scale;
  cout << "Scale set at : ";
  cout << _scale << endl;

  return true;
}
