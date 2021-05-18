#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "./Functions/Menus.h"
#include "./Functions/Functions.h"


int main(int argc, char * argv[]) {
  if(argc == 1){
    cout << "#------------------------------#"<<endl;
    cout << "| \033[41m";
    cout << " \033[42m";
    cout << " \033[43m";
    cout << " \033[44m";
    cout << " \033[0m";
    cout <<       "   VECTOR DRAWING  ";
    cout << " \033[44m";
    cout << " \033[43m";
    cout << " \033[42m";
    cout << " \033[41m";
    cout << " \033[0m |" << endl;
    cout << "#------------------------------#"<<endl;

    StartMenu();
    return 1;
  }else if(argc == 2){
    string arg = argv[1];
    if (arg == "help"){
      Help();
      return 1;
    }else{
      CDrawing *Drawing = new CDrawing(arg);
      QuickDraw(Drawing);
    }
  }else if(argc == 3){
    string arg = argv[1];
    int  scale = atoi(argv[2]);
    if(scale > 0){
      CDrawing *Drawing = new CDrawing(arg, scale);
      QuickDraw(Drawing);
    }
  }else if(argc > 3){
    cout << "Too many arguments, try ./VectorDrawing help ..." << endl;
    return 1;
  }
}
