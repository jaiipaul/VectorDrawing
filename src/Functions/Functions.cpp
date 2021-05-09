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
  Drawing->CreateImage(Drawing->_scale*Drawing->_maxX, Drawing->_scale*Drawing->_maxY, Drawing->_r_backgnd, Drawing->_g_backgnd, Drawing->_b_backgnd);
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
    cout << "BACKGROUND : " << "R:" << Drawing->_r_backgnd << " G:" << Drawing->_g_backgnd << " B:" << Drawing->_b_backgnd << endl;
    cout << "SCALE : " << Drawing->_scale << endl;
    cout << Drawing->_size << " shapes" << endl;

    string str = "##---- PROPERTIES OF :  ----##";
    for(int i = 0; i < str.size() + (Drawing->_filename.substr(0, Drawing->_filename.find("."))).size(); i++){
      cout << "-";
    }
    cout << endl;
    cout << endl;
}

bool check_Xlocation(int x,  CDrawing* Drawing){
  if(Drawing->ParameterStatus("SIZE") == true){
    if (x <= Drawing->_maxX){
      return true;
    }else{
      cout << "|!| X is out of image border...(maxY = " << Drawing->_maxX << " )" << endl;
      return false;
    }
  }else{
    return true;
  }
}

bool check_Ylocation(int y,  CDrawing* Drawing){
  if(Drawing->ParameterStatus("SIZE") == true){
    if (y <= Drawing->_maxY){
      return true;
    }else{
      cout << "|!| Y is out of image border... (maxY = " << Drawing->_maxY << " )" << endl;
      return false;
    }
  }else{
    return true;
  }
}

bool check_width(int width, int x_pos,  CDrawing* Drawing){
  if(Drawing->ParameterStatus("SIZE") == true){
    if (x_pos + width <= Drawing->_maxX){
      return true;
    }else{
      cout << "|!| Width too large... (max = " << Drawing->_maxX - x_pos << " )" << endl;
      return false;
    }
  }else{
    return true;
  }
}

bool check_height(int width, int y_pos,  CDrawing* Drawing){
  if(Drawing->ParameterStatus("SIZE") == true){
    if (y_pos + width <= Drawing->_maxY){
      return true;
    }else{
      cout << "|!| Heigth too large... (max = " << Drawing->_maxY - y_pos << " )" << endl;
      return false;
    }
  }else{
    return true;
  }
}

bool check_radius(int radius, int x_pos, int y_pos,  CDrawing* Drawing){
  if(Drawing->ParameterStatus("SIZE") == true){
    if (x_pos + radius > Drawing->_maxX){
      cout << "|!| Radius too large... (max = " << Drawing->_maxX - x_pos << " )" << endl;
      return false;
    }else if(y_pos + radius > Drawing->_maxY){
      cout << "|!| Radius too large... (max = " << Drawing->_maxY - y_pos << " )" << endl;
      return false;
    }else{
      return true;
    }
  }else{
    return true;
  }
}

string newShapeCommand(CDrawing *Drawing){
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
  //do {
    cout << " > X = ";
    cin  >> x;
  //} while(check_Xlocation(stoi(x), Drawing) == false);

  //do {
    cout << " > Y = ";
    cin  >> y;
  //} while(check_Ylocation(stoi(y), Drawing) == false);

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
    //do {
      cout << " > WIDTH = ";
      cin  >> width;
    //} while(check_width(stoi(width), stoi(x), Drawing) == false);
    //do {
      cout << " > HEIGHT = ";
      cin  >> height;
    //} while(check_height(stoi(height), stoi(y), Drawing) == false);
    cout << endl;
    command = type+" : "+x+", "+y+", "+width+", "+height+", "+z+", "+red+", "+green+", "+blue+", "+opacity+";";
  }
  else if(type == "DISK" || type == "DISK_F"){
    string radius;
    cout << ">>> Choose parameters : " << endl;
    //do {
      cout << " > RADIUS = ";
      cin  >> radius;
    //} while(check_radius(stoi(radius), stoi(x), stoi(y), Drawing) == false);
    cout << endl;
    command = type+" : "+x+", "+y+", "+radius+", "+z+", "+red+", "+green+", "+blue+", "+opacity+";";
  }
  else if(type == "LINE"){
    string x2, y2;
    cout << ">>> Choose parameters : " << endl;
    //do{
      cout << " > X2 = ";
      cin  >> x2;
    //} while(check_Xlocation(stoi(x2), Drawing) == false);
    //do{
      cout << " > Y2 = ";
      cin  >> y2;
    //} while(check_Ylocation(stoi(y2), Drawing) == false);
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
  //cout << command << endl;
  return command;
}
