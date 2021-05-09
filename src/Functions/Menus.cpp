
#include "Menus.h"

int ShapesMenu(CDrawing* Drawing){
  string option;
  while(1){
    cout << "\033[41m";
    cout << " \033[42m\033[30mV";
    cout << "\033[43mD";
    cout << "\033[44m";
    cout << " \033[0m>>> ";
    cout << Drawing->_filename.substr(0, Drawing->_filename.find("."));
    cout << " >> SHAPES >>" ;//| ADD | REMOVE | LIST | BACK" << endl;
    cout << " | \033[47m\033[30m ADD + \033[0m";
    cout << " | \033[47m\033[30m REMOVE - \033[0m";
    cout << " | \033[47m\033[30m LIST \033[0m";
    cout << " | \033[43m\033[30m BACK < \033[0m";
    cout << " | " << endl;

    cin >> option;
    if (option == "ADD" || option == "add" || option == "+"){
      string command = newShapeCommand(Drawing);
      Drawing->addShape(command);
    }
    else if (option == "REMOVE" || option == "remove" || option == "-"){
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
    else if (option == "LIST" || option == "list" || option == "L" || option == "l"){
      Drawing->showShapes();
    }
    else if(option == "BACK" || option == "back" || option == "<"){
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
    cout << " | \033[43m\033[30m BACK < \033[0m";
    cout << " | " << endl;

    cin >> option2;
    if (option2 == "ON" || option2 == "on" || option2 == "OFF" || option2 == "off"){
      status = Drawing->SetParameter(option, option2);
    }else if( option2 == "SET" || option == "set"){
      string command = ParameterCommand(option);
      Drawing->WriteParameter(option, command);
    }else if( option2 == "BACK" || option2 == "back" || option2 == "<"){
      return 0;
    }
  }
  remove((Drawing->_filename+".temp").c_str());
  return 0;
}

int EditMenu(CDrawing* Drawing){
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
    cout << " | \033[43m\033[30m BACK < \033[0m";
    cout << " | " << endl;

    cin >> option;
    if(option == "SIZE" || option == "size" || option == "BACKGROUND" || option == "background" || option == "SCALE" || option == "scale"){
      ParameterMenu(Drawing, option);
    }else if( option == "BACK" || option == "back" || option == "<"){
      return 0;
    }
  }
}

int Menu(CDrawing* Drawing){
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
    cout << " | \033[43m\033[30m BACK < \033[0m";
    cout << " | " << endl;
    cin >> option;
    if( option == "DRAW" || option == "draw" || option == "D" || option == "d"){
      Draw(Drawing);
    }
    else if(option == "EDIT" || option == "edit" || option == "E" || option == "e"){
      EditMenu(Drawing);
    }
    else if(option == "SHAPES" || option == "shapes" || option == "S" || option == "s"){
      ShapesMenu(Drawing);
    }
    else if(option == "INFO" || option == "info" || option == "I" || option == "i"){
      Info(Drawing);
    }
    else if(option == "BACK" || option == "back" || option == "<"){
      remove((Drawing->_filename+".temp").c_str());
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
    cout << " | \033[47m\033[30m NEW + \033[0m";
    cout << " | \033[47m\033[30m OPEN > \033[0m";
    cout << " | \033[41m\033[30m QUIT X \033[0m";
    cout << " | " << endl;
    cin  >> option;

    if (option == "NEW" || option == "new" || option == "+"){
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
    else if (option == "OPEN" || option == "open" || option == ">"){
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
    else if (option == "QUIT" || option == "quit" || option == "X" || option == "x"){
      cout << ">>> closing application..." << endl;
      return 0;
    }
  }
}
