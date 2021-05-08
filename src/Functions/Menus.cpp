
#include "Menus.h"

int ShapesMenu(CDrawing *Drawing){
  string option;
  while(1){
    cout << "\033[41m";
    cout << " \033[42m\033[30mV";
    cout << "\033[43mD";
    cout << "\033[44m";
    cout << " \033[0m>>> ";
    cout << Drawing->_filename.substr(0, Drawing->_filename.find("."));
    cout << " >> SHAPES >>" ;//| ADD | REMOVE | LIST | BACK" << endl;
    cout << " | \033[47m\033[30m ADD \033[0m";
    cout << " | \033[47m\033[30m REMOVE \033[0m";
    cout << " | \033[47m\033[30m LIST \033[0m";
    cout << " | \033[43m\033[30m BACK \033[0m" << endl;

    cin >> option;
    if (option == "ADD"){
      string command = newShapeCommand(Drawing);
      Drawing->addShape(command);
    }
    else if (option == "REMOVE"){
      int index;
      Drawing->showShapes();
      cout << ">>> Shape to remove (Index) : ";
      cin  >> index;
      if(index <= Drawing->_size){
        Drawing->removeShape(index);
        cout << ">>> Shape n°" << index << " removed from drawing" << endl;
      }else{
        cout << "|!| There is no shape n°" << index << endl;
      }
    }
    else if (option == "LIST"){
      Drawing->showShapes();
    }
    else if(option == "BACK"){
      return 0;
    }
  }
}

int ParameterMenu(CDrawing* Drawing, string option){
  bool status;
  while(1){
    status = Drawing->ParameterStatus(option);
    string option2;
    cout << "\033[41m";
    cout << " \033[42m\033[30mV";
    cout << "\033[43mD";
    cout << "\033[44m";
    cout << " \033[0m>>> ";
    cout << Drawing->_filename.substr(0, Drawing->_filename.find("."));
    cout << " >> EDIT >> " << option << " >> ";

    if(status == true){
      cout << " | \033[42m\033[30m ON \033[0m";
    }else if(status == false){
      cout << " | \033[41m\033[30m OFF \033[0m";
    }
    cout << " | \033[47m\033[30m SET \033[0m";
    cout << " | \033[43m\033[30m BACK \033[0m" << endl;

    cin >> option2;
    if (option2 == "ON" || option2 == "OFF"){
      status = Drawing->SetParameter(option, option2);
    }else if( option2 == "SET"){
      string command = ParameterCommand(option);
      Drawing->WriteParameter(option, command);
    }else if( option2 == "BACK"){
      return 0;
    }
  }
  remove((Drawing->_filename+".temp").c_str());
  return 0;
}

int EditMenu(CDrawing *Drawing){
  string option;
  while(1){
    cout << "\033[41m";
    cout << " \033[42m\033[30mV";
    cout << "\033[43mD";
    cout << "\033[44m";
    cout << " \033[0m>>> ";
    cout << Drawing->_filename.substr(0, Drawing->_filename.find("."));
    cout << " >> EDIT >>" ;
    cout << " | \033[47m\033[30m SIZE \033[0m";
    cout << " | \033[47m\033[30m BACKGROUND \033[0m";
    cout << " | \033[47m\033[30m SCALE \033[0m";
    cout << " | \033[43m\033[30m BACK \033[0m" << endl;

    cin >> option;
    if(option == "SIZE" || option == "BACKGROUND" || option == "SCALE"){
      ParameterMenu(Drawing, option);
    }else if( option == "BACK"){
      return 0;
    }
  }
}

int Menu(CDrawing *Drawing){
  string option;
  while(1){
    cout << "\033[41m";
    cout << " \033[42m\033[30mV";
    cout << "\033[43mD";
    cout << "\033[44m";
    cout << " \033[0m>>> ";
    cout << Drawing->_filename.substr(0, Drawing->_filename.find("."));
    cout << " >>";
    cout << " | \033[102m\033[30m DRAW \033[0m";
    cout << " | \033[47m\033[30m EDIT \033[0m";
    cout << " | \033[47m\033[30m SHAPES \033[0m";
    cout << " | \033[47m\033[30m INF0 \033[0m";
    cout << " | \033[43m\033[30m BACK \033[0m" << endl;
    cin >> option;
    if( option == "DRAW"){
      Draw(Drawing);
    }
    else if(option == "EDIT"){
      EditMenu(Drawing);
    }
    else if(option == "SHAPES"){
      ShapesMenu(Drawing);
    }
    else if(option == "INFO"){
      Info(Drawing);
    }
    else if(option == "BACK"){
      return 0;
    }
  }
}

int StartMenu(){
  while(1){
    string option;
    cout << "\033[41m";
    cout << " \033[42m\033[30mV";
    cout << "\033[43mD";
    cout << "\033[44m";
    cout << " \033[0m>>> ";
    cout << " | \033[47m\033[30m NEW \033[0m";
    cout << " | \033[47m\033[30m OPEN \033[0m";
    cout << " | \033[41m\033[30m QUIT \033[0m" << endl;
    cin  >> option;

    if (option == "NEW"){
      CDrawing *Drawing = new CDrawing();
      cout << "Filename : ";
      string name;
      cin >> name;
      Drawing->_filename = name+".vec";
      bool create = Drawing->CreateFile(Drawing->_filename);
      if (create == true){
        cout << ">>> " << Drawing->_filename << " created" << endl;
        Menu(Drawing);
        delete Drawing;
      }
    }
    else if (option == "OPEN"){
      CDrawing *Drawing = new CDrawing();
      cout << "Filename : ";
      string name;
      cin >> name;
      Drawing->_filename = name+".vec";
      bool load = Drawing->LoadDrawing(Drawing->_filename);
      if(load == true){
        cout << ">>> " << Drawing->_filename << " loaded" << endl;
        Menu(Drawing);
        delete Drawing;
      }
    }
    else if (option == "QUIT"){
      cout << ">>> closing application..." << endl;
      return 0;
    }
  }
}
