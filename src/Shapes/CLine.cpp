#include "CLine.h"

CLine::CLine(string command, string type, size_t pos1){
  _type = type;

  size_t pos2 = command.find(",");
  _x1    = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _x1  << endl;

  pos1     = command.find(",", pos2+1);
  _y1    = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _y1  << endl;

  pos2 = command.find(",", pos1+1);
  _x2    = atoi((command.substr(pos1+2, pos2-(pos1+2))).c_str());
  cout << pos2 <<"_"<< _x2  << endl;

  pos1     = command.find(",", pos2+1);
  _y2    = atoi((command.substr(pos2+2, pos1-(pos2+2))).c_str());
  cout << pos1 <<"_"<< _y2  << endl;

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
  cout <<"-----------------"<<endl;
}

CLine::~CLine(){
}

void drawLine(CImage* img){
  //TO D0
}
