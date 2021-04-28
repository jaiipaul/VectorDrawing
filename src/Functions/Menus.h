#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "../Format/CBitmap.h"
#include "../Shapes/CDrawing.h"
#include "Functions.h"

#ifndef MENUS_H_
#define MENUS_H_

int ShapesMenu(CDrawing *Drawing);

int ParameterMenu(CDrawing* Drawing, string option);

int EditMenu(CDrawing *Drawing);

int Menu(CDrawing *Drawing);

int StartMenu();

#endif/*MENUS_H_*/
