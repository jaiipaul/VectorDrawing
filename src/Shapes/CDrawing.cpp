#include "CDrawing.h"
//CONSTRUCTORS------------------------------------------------------------------
CDrawing::CDrawing(int width, int height){
  CreateImage(width, height);
  _size  = 0;
  _maxX  = width;
  _maxY  = height;
  _maxZ  = 0;
  _r_backgnd = 255;
  _g_backgnd = 255;
  _b_backgnd = 255;
  _scale = 1;
}
//------------------------------------------------------------------------------
CDrawing::CDrawing(int width, int height, int r, int g, int b){
  CreateImage(width, height, r, g, b);
  _size  = 0;
  _maxX  = width;
  _maxY  = height;
  _maxZ  = 0;
  _r_backgnd = r;
  _g_backgnd = g;
  _b_backgnd = b;
  _scale = 1;
}
//------------------------------------------------------------------------------
CDrawing::CDrawing(int scale){
  _size  = 0;
  _maxX  = 0;
  _maxY  = 0;
  _maxZ  = 0;
  _r_backgnd = 255;
  _g_backgnd = 255;
  _b_backgnd = 255;
  _scale = scale;
}
//------------------------------------------------------------------------------
CDrawing::CDrawing(){
  _size  = 0;
  _maxX  = 0;
  _maxY  = 0;
  _maxZ  = 0;
  _r_backgnd = 255;
  _g_backgnd = 255;
  _b_backgnd = 255;
  _scale = 1;
}
//DESTRUCTOR--------------------------------------------------------------------
CDrawing::~CDrawing(){
    for(int i=0; i<_size; i++)
        delete _shapes[i];
    _shapes.clear();
    delete _img;
}
//FILE--------------------------------------------------------------------------
void CDrawing::SetFilename(string filename){
  _filename = filename;
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
  outfile << "//SHAPES : "<< endl;
  outfile.close();
  return true;
  }
//------------------------------------------------------------------------------
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
  UpdateSize();

  cout << _size << " shape(s) loaded" << endl;
  cout << "Max X : "<< _maxX << endl;
  cout << "Max Y : "<< _maxY << endl;
  cout << "Max Z : "<< _maxZ << endl;
  cout << "Scale : "<< _scale <<endl;
  return true;
}
//SHAPES------------------------------------------------------------------------
bool CDrawing::CreateShape(const string command){
    size_t pos = command.find(":");
    string type = command.substr(0,pos-1);
    if(type == "POINT"){
        CPoint* shape_p = new CPoint(command, type, pos);
        _shapes.push_back(shape_p);
        _size++;
    }
    else if(type == "RECTANGLE" || type == "RECTANGLE_F"){
        CRectangle* shape_r = new CRectangle(command, type, pos, _scale);
        _shapes.push_back(shape_r);
        _size++;
    }
    else if(type == "DISK" || type == "DISK_F"){
        CDisk* shape_d = new CDisk(command, type, pos, _scale);
        _shapes.push_back(shape_d);
        _size++;
    }
    else if(type == "LINE"){
        CLine* shape_l = new CLine(command, type, pos, _scale);
        _shapes.push_back(shape_l);
        _size++;
    }
    return true;
  }
//------------------------------------------------------------------------------
void CDrawing::showShapes(){
  for(int i = 0; i < _size; i++){
    cout << "[" << i+1 << "]  ";
    _shapes[i]->info();
  }
}
//------------------------------------------------------------------------------
void CDrawing::addShape(const string command){
  ofstream outfile;
  outfile.open(_filename, std::ofstream::app);
  if (outfile.is_open() == false)
    exit(EXIT_FAILURE);

  outfile << command << endl;
  outfile.close();

  CreateShape(command);
  _shapes[_size-1]->info();
  UpdateSize();
}
//------------------------------------------------------------------------------
void CDrawing::removeShape(int index){
  string STRING;
  ifstream infile;
  infile.open(_filename);
  ofstream outfile;
  outfile.open(_filename+".temp", fstream::trunc);

  while(infile.peek() != EOF){
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
  while(infile.peek() != EOF){
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

  UpdateSize();
}
//------------------------------------------------------------------------------
void CDrawing::DrawShape(CImage* img, CShape* shape){
  shape->draw(img, _scale);
}
//IMAGE-------------------------------------------------------------------------
bool CDrawing::CreateImage(int width, int height){
  _img = new CImage(width, height);
  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::CreateImage(int width, int height, int r, int g, int b){
  _img = new CImage(width, height, r, g, b);
  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::DrawImage(){
  cout <<"Start Drawing" << endl;
  ZBorder();
  for (int z = 0; z <= _maxZ; z++){
    cout << "Plan Z = " << z << endl;
    for (int i = 0; i < _size; i++){
      if(_shapes[i]->getLayer() == z){
        _img->PixelsReady();
        DrawShape(_img, _shapes[i]);
        cout <<"shape " << i+1 << " " << _shapes[i]->getType() << " drawn" << endl;
      }
    }
  }
  return true;
}
//PROPERTIES--------------------------------------------------------------------
bool CDrawing::XBorder(){
  for(int i = 0; i < _size; i++){
    _maxX = _shapes[i]->getXsize() < _maxX ? _maxX : _shapes[i]->getXsize();
  }
  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::YBorder(){
  for(int i = 0; i < _size; i++){
    _maxY = _shapes[i]->getYsize() < _maxY ? _maxY : _shapes[i]->getYsize();
  }
  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::ZBorder(){
  for(int i = 0; i < _size; i++){
    _maxZ = _shapes[i]->getLayer() < _maxZ ? _maxZ : _shapes[i]->getLayer();
  }
  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::SetSize(const string command){
  size_t pos1 = command.find(":");
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
//------------------------------------------------------------------------------
bool CDrawing::SetSize(int x, int y){

  _maxX = x;
  _maxY = y;
  cout << "Size set at X : ";
  cout << _maxX;
  cout << " / Y : ";
  cout << _maxY << endl;

  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::UpdateSize(){
  ZBorder();
  if(not(ParameterStatus("SIZE"))){
    _maxX = 0;
    _maxY = 0;
    XBorder();
    YBorder();
    cout << "Size is now X : " << _maxX << " / Y : " << _maxY << " / Z : " << _maxZ << endl;
    return true;
  }else{
    return true;
  }
}
//------------------------------------------------------------------------------
bool CDrawing::ResetSize(){
  _maxX = 0;
  _maxY = 0;
  _maxZ = 0;
  XBorder();
  YBorder();
  ZBorder();
  cout << "Size is now X : " << _maxX << " / Y : " << _maxY << " / Z : " << _maxZ << endl;
  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::SetBackgnd(const string command){
  size_t pos1 = command.find(":");
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
//------------------------------------------------------------------------------
bool CDrawing::SetBackgnd(int r, int g, int b){

  _r_backgnd = r;
  _g_backgnd = g;
  _b_backgnd = b;

  cout << "Background set at RED : ";
  cout << _r_backgnd;
  cout << " / GREEN : ";
  cout << _g_backgnd;
  cout << " / BLUE : ";
  cout << _b_backgnd << endl;

  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::ResetBackgnd(){
  _r_backgnd = 255;
  _g_backgnd = 255;
  _b_backgnd = 255;
  cout << "Background reset to white..." << endl;
  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::SetScale(const string command){
  size_t pos1 = command.find(":");
  size_t pos2 = command.find(";");
  _scale = (command.substr(pos1+2, pos2-(pos1+2)) != "#") ? atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str()) : _scale;
  cout << "Scale set at : ";
  cout << _scale << endl;

  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::SetScale(int scale){

  _scale = scale;
  cout << "Scale set at : ";
  cout << _scale << endl;

  return true;
}
//------------------------------------------------------------------------------
bool CDrawing::ResetScale(){
  _scale = 1;
  return true;
}
//PARAMETERS--------------------------------------------------------------------
bool CDrawing::ParameterStatus(string parameter){
  bool status = false;
  ifstream infile;
  infile.open(_filename);
  ofstream outfile;
  outfile.open(_filename+".temp");
  string STRING;
  while(infile.peek() != EOF){
    getline(infile, STRING);
    outfile << STRING << endl;
    if (STRING.substr(0, STRING.find(":")-1) == "//"+parameter){
      status = false;
    }else if(STRING.substr(0, STRING.find(":")-1) == parameter){
      status = true;
    }
  }
  infile.close();
  outfile.close();
  return status;
}
//------------------------------------------------------------------------------
bool CDrawing::SetParameter(string parameter, string option){
  bool status;
  cout << "Changing "<< parameter << " status..." << endl;
  ifstream infile;
  ofstream outfile;
  infile.open(_filename+".temp");
  outfile.open(_filename);
  if (infile.is_open() == false)
    exit(EXIT_FAILURE);
  if (outfile.is_open() == false)
    exit(EXIT_FAILURE);

  string STRING;
  while (infile.peek() != EOF){
    getline(infile, STRING);
    if ((option == "ON")&&(STRING.substr(0,STRING.find(":")-1) == "//"+parameter)){
      outfile << STRING.substr(2, STRING.size()-2) << endl;
      status = true;
      if(parameter == "SIZE"){
        SetSize(STRING);
      }else if(parameter == "BACKGROUND"){
        SetBackgnd(STRING);
      }else if(parameter == "SCALE"){
        SetScale(STRING);
      }
      cout << "Set " << parameter << " ON" << endl;
    }else if((option == "OFF")&&(STRING.substr(0,STRING.find(":")-1) == parameter)){
      outfile << "//"<< STRING << endl;
      status = false;
      if(parameter == "SIZE"){
        ResetSize();
      }else if(parameter == "BACKGROUND"){
        ResetBackgnd();
      }else if(parameter == "SCALE"){
        ResetScale();
      }
      cout << "Set " << parameter << " OFF" << endl;
    }else{
      outfile << STRING << endl;
    }
  }
  infile.close();
  outfile.close();
  return status;
}
//------------------------------------------------------------------------------
bool CDrawing::WriteParameter(string parameter, string command){
  bool is_param = false;
  string STRING;
  ifstream infile;
  infile.open(_filename);
  ofstream outfile;
  outfile.open(_filename+".temp", fstream::trunc);
  //if (is_param == false){
  //  outfile << "//"+parameter+" :" << endl;
  //}
  while(infile.peek() != EOF){

    getline(infile,STRING);
    if (STRING.substr(0,STRING.find(":")-1) == "//"+parameter || STRING.substr(0,STRING.find(":")-1) == parameter ){
      is_param = true;
    }
    outfile << STRING << endl;
  }
  if( is_param == false){
    outfile << "//"+parameter+" :" << endl;
  }

  infile.close();
  outfile.close();

  infile.open(_filename+".temp");
  outfile.open(_filename);
  if (infile.is_open() == false)
    exit(EXIT_FAILURE);
  if (outfile.is_open() == false)
    exit(EXIT_FAILURE);

  while (infile.peek() != EOF){
    getline(infile, STRING);
    if (STRING.substr(0,STRING.find(":")-1) == "//"+parameter)
      outfile << "//" << command << endl;
    else if(STRING.substr(0,STRING.find(":")-1) == parameter){
      outfile << command << endl;
      if (parameter == "SIZE"){
        SetSize(command);
      }else if(parameter == "BACKGROUND"){
        SetBackgnd(command);
      }else if(parameter == "SCALE"){
        SetScale(command);
      }
    }else
      outfile << STRING << endl;
  }
  return true;
}
//------------------------------------------------------------------------------
int CDrawing::getRbackgnd(){
  return _r_backgnd;
}

int CDrawing::getGbackgnd(){
  return _g_backgnd;
}

int CDrawing::getBbackgnd(){
  return _b_backgnd;
}

int CDrawing::getScale(){
  return _scale;
}

string CDrawing::getFilename(){
  return _filename;
}

CImage* CDrawing::getImg(){
  return _img;
}

int CDrawing::getMaxX(){
  return _maxX;
}

int CDrawing::getMaxY(){
  return _maxY;
}

int CDrawing::getMaxZ(){
  return _maxZ;
}

int CDrawing::getSize(){
  return _size;
}

void CDrawing::Info(){
    cout << endl;
    cout << "##----" << " PROPERTIES OF : "<< _filename.substr(0, _filename.find(".")) << " ----## " << endl;

    cout << "SIZE : "  << _maxX  << " x " << _maxY << " pixels" << endl;
    cout << "PLANS : " << _maxZ  << endl;
    cout << "BACKGROUND : " << "R:" << _r_backgnd << " G:" << _g_backgnd << " B:" << _b_backgnd << endl;
    cout << "SCALE : " << _scale << endl;
    cout << _size << " shapes" << endl;

    string str = "##---- PROPERTIES OF :  ----##";
    for(int i = 0; i < str.size() + (_filename.substr(0, _filename.find("."))).size(); i++){
      cout << "-";
    }
    cout << endl;
    cout << endl;
}
