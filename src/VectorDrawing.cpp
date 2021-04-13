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
    string filename2 = "Drawing.bmp";

    cout << "(II) CImage pointer extraction" << endl;
    //CImage *img = new CImage(200,200);
    CDrawing *Drawing = new CDrawing(40, 40, 255, 255, 255);
    //cout<<"start loading drawing"<<endl;
    Drawing->LoadDrawing(argv[1]);
    Drawing->DrawImage();

    image->setImage( Drawing->_img );
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);

    delete Drawing;
    //delete image;
    return 1;
}
