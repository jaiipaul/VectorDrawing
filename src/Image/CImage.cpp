/*
 *  CImage.cpp
 *  P_Bitmap
 *
 *  Created by Le Gal on 24/10/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include "CImage.h"

CImage::CImage(int largeur, int hauteur){
    //cout << "Instanciation des lignes... " << taille << endl;
    _hauteur = hauteur;
    _largeur = largeur;
    liste = (CLigne**)new CLigne**[_hauteur];
    for(int i=0; i<_hauteur; i++){
        liste[i] = new CLigne(_largeur);
    }
}

CImage::CImage(int largeur, int hauteur, int r, int g, int b){
    //cout << "Instanciation des lignes... " << taille << endl;
    r_backgnd = r;
    g_backgnd = g;
    b_backgnd = b;
    _hauteur = hauteur;
    _largeur = largeur;
    liste = (CLigne**)new CLigne**[_hauteur];
    for(int i=0; i<_hauteur; i++){
        liste[i] = new CLigne(_largeur, r, g, b);
    }
}

CImage::~CImage(){
    for(int i=0; i<_hauteur; i++)
        delete liste[i];
    delete liste;
}

int CImage::size(){
    return _hauteur;
}

CLigne* CImage::getLigne(int position){
    if( (position >= _hauteur) ){
        cout << "CImage::getLigne => trying to access " << position << " but the line has only " << _hauteur << " data" << endl;
    }
    return (position < _hauteur)?liste[position]:NULL;
}

CPixel* CImage::getPixel(int posX, int posY){
    CLigne* ligne =  getLigne( posY );
    if( ligne == NULL) return NULL;
    return ligne->getPixel(posX);
}
