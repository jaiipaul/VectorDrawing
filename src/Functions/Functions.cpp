#include "Functions.h"

void Draw(CDrawing *Drawing){
  cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
  cout << "(II) CBitmap object creation" << endl;
  CBitmap *image = new CBitmap();

  string filename2 = Drawing->_filename.substr(0, Drawing->_filename.find(".")) + ".bmp";
  //remove(filename2.c_str());
  cout << "(II) CImage pointer extraction" << endl;
  //if(Drawing->_img != NULL){
  //delete Drawing->_img;
  //}
  Drawing->CreateImage(Drawing->_maxX, Drawing->_maxY, Drawing->_r_backgnd, Drawing->_g_backgnd, Drawing->_b_backgnd);
  Drawing->DrawImage();

  image->setImage( Drawing->_img );
  cout << "(II) CBitmap image saving" << endl;
  image->SaveBMP(filename2);

  delete image;
}

void Info(CDrawing *Drawing){
    cout << endl;
    cout << "##----" << " PROPERTIES OF : "<< Drawing->_filename.substr(0, Drawing->_filename.find(".")) << " ----## " << endl;

    cout << "SIZE : "  << Drawing->_maxX  << " x " << Drawing->_maxY << " pixels" << endl;
    cout << "PLANS : " << Drawing->_maxZ  << endl;
    cout << "SCALE : " << Drawing->_scale << endl;
    cout << Drawing->_size << " shapes" << endl;
    cout << "------------------------------" << endl;;
}

string newShapeCommand(){
  string type;
  string red;
  string green;
  string blue;
  string opacity;
  string x;
  string y;
  string z;

  cout << ">>> New Shape creation :" << endl;
  cout << ">>> Choose type : [POINT, LINE, RECTANGLE(_F), DISK(_F)]" << endl;
  cin  >> type;

  cout << ">>> Choose color :" << endl;
  cout << " > RED = " ;
  cin  >> red;
  cout << " > GREEN = " ;
  cin  >> green;
  cout << " > BLUE = " ;
  cin  >> blue;
  cout << " > OPACITY = ";
  cin  >> opacity;
  cout << endl;

  cout << ">>> Choose location :" << endl;
  cout << " > X = ";
  cin  >> x;
  cout << " > Y = ";
  cin  >> y;
  cout << " > Z = ";
  cin  >> z;
  cout << endl;

  string command;
  if(type == "POINT"){
    command = type+" : "+x+", "+y+", "+z+", "+red+", "+green+", "+blue+", "+opacity+";";
  }
  else if(type == "RECTANGLE" || type == "RECTANGLE_F"){
    string width, height;
    cout << ">>> Choose parameters : " << endl;
    cout << " > WIDTH : ";
    cin  >> width;
    cout << " > HEIGHT : ";
    cin  >> height;
    cout << endl;
    command = type+" : "+x+", "+y+", "+width+", "+height+", "+z+", "+red+", "+green+", "+blue+", "+opacity+";";
  }
  else if(type == "DISK" || type == "DISK_F"){
    string radius;
    cout << ">>> Choose parameters : " << endl;
    cout << " > RADIUS : ";
    cin  >> radius;
    cout << endl;
    command = type+" : "+x+", "+y+", "+radius+", "+z+", "+red+", "+green+", "+blue+", "+opacity+";";
  }
  else if(type == "LINE"){
    string x2, y2;
    cout << ">>> Choose parameters : " << endl;
    cout << " > X2 : ";
    cin  >> x2;
    cout << " > Y2 : ";
    cin  >> y2;
    cout << endl;
    command = type+" : "+x+", "+y+", "+x2+", "+y2+", "+z+", "+red+", "+green+", "+blue+", "+opacity+";";
  }
  return(command);
}

string ParameterCommand(string parameter){
  string command;
  string param;
  if( parameter == "SIZE"){
    command = "SIZE : ";
    cout << " > WIDTH : ";
    cin >> param;
    command = command+param+", ";
    cout << " > HEIGHT : ";
    cin>> param;
    command = command+param+";";
  }else if(parameter == "BACKGROUND"){
    command = "BACKGROUND : ";
    cout << " > RED : ";
    cin >> param;
    command = command+param+", ";
    cout << " > GREEN : ";
    cin >> param;
    command = command+param+", ";
    cout << " > BLUE : ";
    cin >> param;
    command = command+param+";";
  }else if(parameter == "SCALE"){
    command = "SCALE : ";
    cout << " > SCALE : ";
    cin >> param;
    command = command+param+";";
  }
  cout << command << endl;
  return command;
}
