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
    r_backgnd = 255;
    g_backgnd = 255;
    b_backgnd = 255;
    taille = hauteur;
    liste = (CLigne**)new CLigne**[taille];
    for(int i=0; i<taille; i++){
        liste[i] = new CLigne(largeur);
    }
}

CImage::CImage(int largeur, int hauteur, int r, int g, int b){
    //cout << "Instanciation des lignes... " << taille << endl;
    r_backgnd = r;
    g_backgnd = g;
    b_backgnd = b;
    taille = hauteur;
    liste = (CLigne**)new CLigne**[taille];
    for(int i=0; i<taille; i++){
        liste[i] = new CLigne(largeur, r_backgnd, g_backgnd, b_backgnd);
    }
}

CImage::~CImage(){
    for(int i=0; i<taille; i++)
        delete liste[i];
    delete liste;
}

int CImage::size(){
    return taille;
}

CLigne* CImage::getLigne(int position){
    if( (position >= taille) ){
        cout << "CImage::getLigne => trying to access " << position << " but the line has only " << taille << " data" << endl;
    }
    return (position < taille)?liste[position]:NULL;
}

CPixel* CImage::getPixel(int posX, int posY){
    CLigne* ligne =  getLigne( posY );
    if( ligne == NULL) return NULL;
    return ligne->getPixel(posX);
}
