#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "./Format/CBitmap.h"
#include "./Shapes/CDrawing.h"

int main(int argc, char * argv[]) {
    cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "(II) + Number of arguments = " << argc << endl;

    cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();


    cout << "(II) CImage pointer extraction" << endl;
    //CImage *img = new CImage(200,200);
    CDrawing *Drawing = new CDrawing(atoi(argv[2]));
    //cout<<"start loading drawing"<<endl;
    Drawing->_filename = argv[1];
    Drawing->LoadDrawing(Drawing->_filename);
    Drawing->CreateImage(Drawing->_maxX, Drawing->_maxY, Drawing->_r_backgnd, Drawing->_g_backgnd, Drawing->_b_backgnd);
    Drawing->DrawImage();

    image->setImage( Drawing->_img );
    cout << "(II) CBitmap image saving" << endl;
    string filename2 = Drawing->_filename.substr(0, Drawing->_filename.find(".")) + ".bmp";
    image->SaveBMP(filename2);

    delete Drawing;
    //delete image;
    return 1;
}
