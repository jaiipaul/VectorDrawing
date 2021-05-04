/*
 *  CImage.h
 *  P_Bitmap
 *
 *  Created by Le Gal on 24/10/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "CLigne.h"

#ifndef CIMAGE_H_
#define CIMAGE_H_

class CImage{
private:
    CLigne** liste;

public:
    int _hauteur;
    int _largeur;
    int r_backgnd;
    int g_backgnd;
    int b_backgnd;

public:
    CImage(int largeur, int hauteur);
    CImage(int largeur, int hauteur, int r, int g, int b);
    ~CImage();

    int size();

    CLigne* getLigne(int position);

    CPixel* getPixel(int posX, int posY);
};

#endif /*CIMAGE_H_*/
